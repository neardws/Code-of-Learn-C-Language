/* 33:计算分数加减表达式的值
总时间限制: 1000ms 内存限制: 65536kB
描述
编写程序，输入n的值，
求 1/1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + 1/7 - 1/8 + ... 
+ (-1)^(n-1)·1/n 的值。

输入
输入一个正整数n。1 <= n <= 1000。
输出
输出一个实数，为表达式的值，保留到小数点后四位。
样例输入
2
样例输出
0.5000
来源
http://noi.openjudge.cn/ch0105/33/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double sum = 0.0;
    for(int i = 1; i<=n; i++){
        sum += pow(-1, i-1) * 1.0 / i;
    }
    cout<<fixed<<setprecision(4)<<sum<<endl;
    return 0;
}