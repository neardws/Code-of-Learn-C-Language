/* 28:分离整数的各个数位

总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个整数，要求从个位开始分离出它的每一位数字。

输入
输入一个整数，整数在1到100000000之间。
输出
从个位开始按照从低位到高位的顺序依次输出每一位数字。
数字之间以一个空格分开。
样例输入
123
样例输出
3 2 1

来源
http://noi.openjudge.cn/ch0105/28/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n > 0){
        cout<<n%10<<" ";
        n = n / 10;
    }
    return 0;
}