/* 08:打印字符

总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个ASCII码，输出对应的字符。

输入
一个整数，即字符的ASCII码，保证存在对应的可见字符。
输出
一行，包含相应的字符。
样例输入
65
样例输出
A
来源
http://noi.openjudge.cn/ch0102/08/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    printf("%c\n", a);
    return 0;
}