// 3527:胡
// http://noi.openjudge.cn/ch0406/3527/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 对于一个元素为数字1-9的集合A（每个数字的数量不超过4个，集合中元素的数量不超过14个），判断其是否满足如下规则：
// 集合 A 可以分割为若干个由3个数字组成的集合Bo...Bn和一个由2个数字组成的集合C。
// 其中Bo...Bn需要满足每个集合中的数字均相等或者依次递增一（例如 5 5 5以及4 5 6均满足条件）；C中的两个数字相等
// 显然，当集合中的元素个数等于3n+2（n=0，1..4）时才有可能满足上述条件，
// 我们将元素个数不为3n+2的集合称为“相公”的集合，满足上述条件的集合称为能够“胡”的集合，否则则是“不胡”的集合
// 输入
// 输入的每一行包括一组测试数据，测试数据的开头为0表示测试结束；每一组数据由若干个1-9的数字组成，数字之间用空格隔开
// 输出
// 每一行输出对应一行输入的结果，对于“相公”的集合输出“XIANGGONG”；对于满足“胡”的集合，输出“HU”；否则输出“BUHU”
// 样例输入
// 1 2
// 4 4
// 1 1 1 2 3 4 5 6 7 8 9 9 9
// 1 1 1 2 3 4 5 6 7 8 9 9 9 9
// 0
// 样例输出
// BUHU
// HU
// XIANGGONG
// HU


#include<bits/stdc++.h>
using namespace std ;

const int HASH = 9 ;
char ss[71] ;
int have[11], n ;
long long base[11] ;
set< long long > s;  // long long 类型的 set 容器

void Init( ) {
    int m = strlen( ss ) ;      // 字符串长度
    n = 0 ;     // 数字的个数
    memset( have , 0 , sizeof(have) ) ;
    for( int i = 0 ; i < m ; ++i ){
        if( ss[i] < '0' || ss[i] > '9' )    // 不是数字
            continue ;
        ++have[ss[i]-'0'] , ++n ;  // have 为 每种数字的数量， n 为总数量
    }
}

bool dfs( int now , bool er , long long sta ) {
    // now 遍历到第几种数字  er 为是否能胡   sta 为当前状态
    if( s.find( sta ) != s.end( ) ) 
        return 0 ;
    while( !have[now] && now <= 9 ) 
        ++now ;
    if( now == 10 )   // 遍历到最后一种数字
        return er ;
    if( have[now] && have[now+1] && have[now+2] ){  // 满足一组 递增 例如，4，5，6
        --have[now] , --have[now+1] , --have[now+2] ;   // 相应减去
        if( dfs( now+1 , er , sta - base[now] - base[now+1] - base[now+2] ) ) 
            return 1 ;
        ++have[now] , ++have[now+1] , ++have[now+2] ;  // 回溯
    }
    if( have[now] >= 3 ){   // 满足一组 3个相同， 例如 3，3，3
        have[now] -= 3 ;    
        if( dfs( now+1 , er , sta - base[now]*3 ) ) 
            return 1 ;
        have[now] += 3 ;
    }
    if( have[now] >= 2 && (!er) ){  // 满足一对， 例如，6，6
        have[now] -= 2 ;
        if( dfs( now+1 , 1 , sta - base[now]*2 ) ) 
            return 1 ;
        have[now] += 2 ;
    }
    s.insert( sta ) ;   // 将该状态加到 set 中
    return false ;
}

void Solve( ){
    if( ( n - 2 ) % 3 ) {   // 不等于0，相公
        puts( "XIANGGONG" ) ; return ; }
    s.clear( ) ; 
    long long sta = 0ll ;   // 状态信息
    for( int i = 1 ; i <= 9 ; ++i ) 
        sta += have[i] * base[i] ;  
    if( dfs( 1 , 0 , sta ) ) 
        puts( "HU" ) ; 
    else 
        puts( "BUHU" ) ;
}

int main( ){
    base[1] = 1 ;
    for( int i = 2 ; i <= 9 ; ++ i ) 
        base[i] = base[i-1] * HASH;
    // base = {1, 9, 81, ...}
    while( 1 ) {
        cin.getline( ss , 56 ) ;
        if( ss[0] == '0' ) 
            break ;
        Init( ) ;
        Solve( ) ;
    }
    return 0 ;
}