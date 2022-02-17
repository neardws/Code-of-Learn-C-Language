/* 13:乘方计算
总时间限制: 1000ms 内存限制: 65536kB
描述
给出一个整数a和一个正整数n，求a^n(a的n次方)。

输入
一行，包含两个整数a和n。-1000000 <= a <= 1000000，1 <= n <= 10000。
输出
一个整数，即乘方结果。
题目保证最终结果的绝对值不超过1000000。

样例输入
2 3
样例输出
8
来源


http://noi.openjudge.cn/ch0105/13/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, n;
    cin>>a>>n;
    long x = a;
    for(int i=1; i<=n-1; i++)
        x *= long(a);
    cout<<x<<endl;
    return 0;
}