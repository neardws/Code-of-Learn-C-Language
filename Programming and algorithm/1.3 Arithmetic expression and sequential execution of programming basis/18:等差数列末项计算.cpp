/* 18:等差数列末项计算

总时间限制: 1000ms 内存限制: 65536kB
描述
给出一个等差数列的前两项a1，a2，求第n项是多少。

输入
一行，包含三个整数a1，a​2，n。-100 <= a1,a​2 <= 100，0 < n <= 1000。
输出
一个整数，即第n项的值。
样例输入
1 4 100
样例输出
298
来源



http://noi.openjudge.cn/ch0103/18/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a1, a2, n;
    cin>>a1>>a2>>n;
    cout<<a1 + (n - 1) * (a2 - a1) <<endl;
    return 0;
}