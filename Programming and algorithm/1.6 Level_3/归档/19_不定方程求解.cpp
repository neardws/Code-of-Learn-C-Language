// 7650:不定方程求解
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 给定正整数a，b，c。
// 求不定方程 ax+by=c 关于未知数x和y的所有非负整数解组数。
// 输入
// 一行，包含三个正整数a，b，c，两个整数之间用单个空格隔开。
// 每个数均不大于1000。
// 输出
// 一个整数，即不定方程的非负整数解组数。
// 样例输入
// 2 3 18
// 样例输出
// 4
// 来源
// 《奥数典型题举一反三（小学六年级）》 (ISBN 978-7-5445-2883-2) 第四章 第二讲 例1
// http://noi.openjudge.cn/ch0201/7650/




// 解题
// a,b,c均为正整数故ax+by=c有确切的正整数解
// 双重循环遍历
// 可以根据界限缩小范围ax+by=c==a=(c-bx)/a==a<c/a

#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, num = 0;
    cin >> a >> b >> c;
    int aa = c / a;
    int bb = c / b;
    for (int i = 0; i <= aa; i++) {
        for (int j = 0; j <= bb; j++) {
            if (a * i + b * j == c) {
                num++;
            }
        }
    }
    cout<<num<<endl;
}