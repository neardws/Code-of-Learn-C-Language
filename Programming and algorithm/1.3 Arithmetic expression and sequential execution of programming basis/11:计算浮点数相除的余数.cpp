/* 11:计算浮点数相除的余数
总时间限制: 1000ms 内存限制: 65536kB
描述
计算两个双精度浮点数a和b的相除的余数，
a和b都是正数的。
这里余数（r）的定义是：a = k * b + r，
其中 k是整数， 0 <= r < b。

输入
输入仅一行，包括两个双精度浮点数a和b。
输出
输出也仅一行，a÷b的余数
样例输入
73.263 0.9973
样例输出
0.4601
提示
注意：输出时小数尾部没有多余的0，可以用下面这种格式：
double x;
x = 1.33;
printf("%g", x);
来源
http://noi.openjudge.cn/ch0103/11/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    double a, b;
    cin>>a>>b;
    int c = a/b;
    double r = a - c * b;
    printf("%g\n", r);
    return 0;
}