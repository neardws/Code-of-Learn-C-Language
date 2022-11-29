// 666:放苹果
// http://noi.openjudge.cn/ch0205/666/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
// （用K表示）5，1，1和1，5，1 是同一种分法。
// 输入
// 第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
// 输出
// 对输入的每组数据M和N，用一行输出相应的K。
// 样例输入
// 1
// 7 3
// 样例输出
// 8
// 来源
// lwx@POJ


#include<bits/stdc++.h>
using namespace std;
int t;  //测试数据数量
int n;  //苹果数 
int m;  //盘子数
int tot = 0;  //最多有几种放法
int f(int a, int b){    // a 表示苹果数量, b 表示盘子数量
    if(a <= 1 || b <= 1)    //当只有一个苹果或一个盘时，只有一种放法 
        return 1;
    if(a < b) // 苹果数 < 盘数
        return f(a, a);     // 苹果数<盘数，则最多只有a个盘有苹果
    else    // 盘数 <= 苹果数
        return f(a, b-1) + f(a-b, b); //如果有一个盘子不放，则有 f(a,b-1)种；如果每个都放，则相当于 f(a-b,b)
} 
int main(){
    cin>>t;
    for(int i = 1; i <= t; i++){
        cin>>m>>n;
        cout<<f(m,n)<<endl;
    } 
    return 0; 
}
