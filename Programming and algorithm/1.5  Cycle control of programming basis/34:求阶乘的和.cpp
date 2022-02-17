/* 34:求阶乘的和
总时间限制: 1000ms 内存限制: 65536kB
描述
给定正整数n，求不大于n的正整数的阶乘的和（即求1!+2!+3!+...+n!）

输入
输入有一行，包含一个正整数n（1 < n < 12）。
输出
输出有一行：阶乘的和。
样例输入
5
样例输出
153
来源
http://noi.openjudge.cn/ch0105/34/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long sum = 0;
    for(int i=1; i<=n; i++){
        long long x = 1;
        for(int j=1; j<=i; j++){
            x *= j;
        }
        sum += x;
    }
    cout<<sum<<endl;
    return 0;
}