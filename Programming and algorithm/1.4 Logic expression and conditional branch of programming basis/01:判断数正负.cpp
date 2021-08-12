/* 01:判断数正负

总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个整数N，判断其正负。

输入
一个整数N(-109 <= N <= 109)
输出
如果N > 0, 输出positive;
如果N = 0, 输出zero;
如果N < 0, 输出negative
样例输入
1
样例输出
positive
来源
http://noi.openjudge.cn/ch0104/01/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    if(a > 0)
        cout<<"positive\n";
    else if (a == 0)
        cout<<"zero\n";
    else
        cout<<"negative\n";
    return 0;
}