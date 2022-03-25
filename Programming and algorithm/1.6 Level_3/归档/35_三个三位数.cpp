// 8757:三个三位数
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 将1，2，…，9共9个数分成三组，分别组成三个三位数，
// 且使这三个三位数构成    1:2:3
// 试求出所有满足条件的三个三位数。
// 例如：三个三位数192，384，576满足以上条件。
// 输入
// 无。
// 输出
// 每行三个三位数，为满足条件的一种方案。
// 这三个三位数按从小到大的方式给出，相邻两个数之间用单个空格隔开。
// 请按照第一个三位数从小到大的顺序依次输出每种方案。
// 样例输入
// 无
// 样例输出
// 不提供
// 来源
// NOIP1998复赛 普及组 第一题

#include<bits/stdc++.h>
using namespace std;
bool exitsZero(int n){
    while(n){
        if(n%10==0)
            return true;
        n/=10;
    }
    return false;
}
bool sameNumber(int a, int b, int c){
    int n[10]={0};
    while(a){
        n[a%10]=1;
        a/=10;
    }
    while(b){
        n[b%10]=1;
        b/=10;
    }
    while(c){
        n[c%10]=1;
        c/=10;
    }
    int sum = 0;
    for(int i=1;i<=9;i++){
        sum += n[i];
    }
    if(sum==9)
        return false;
    return true;
}
int main(){
    for(int i=100; i <= 999/3; i++){
        if(exitsZero(i) || exitsZero(i*2) || exitsZero(i*3))
            continue;
        if(sameNumber(i, i*2, i*3))
            continue;
        cout<<i<<" "<<i*2<<" "<<i*3<<endl;
    }
    return 0;
}