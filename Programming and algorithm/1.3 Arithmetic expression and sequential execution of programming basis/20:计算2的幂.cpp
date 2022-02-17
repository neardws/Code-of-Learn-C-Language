/* 20:计算2的幂

总时间限制: 1000ms 内存限制: 65536kB
描述
给定非负整数n，求2^n (次方)。

输入
一个整数n。0 <= n < 31。
输出
一个整数，即2的n次方。
样例输入
3
样例输出
8
来源


sqrt()
pow(x,y) = x^y
http://noi.openjudge.cn/ch0103/20/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin>>n;
    x = pow(2, n);
    cout<<x<<endl;
    return 0;
}