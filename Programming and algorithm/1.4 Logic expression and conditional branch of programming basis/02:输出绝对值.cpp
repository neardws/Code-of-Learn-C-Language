/* 02:输出绝对值

总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个浮点数，输出这个浮点数的绝对值。
fabs() 输出绝对值的函数

输入
输入一个浮点数，其绝对值不超过10000。
输出
输出这个浮点数的绝对值，保留到小数点后两位。

样例输入
-3.14
样例输出
3.14
来源

http://noi.openjudge.cn/ch0104/02/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    double a;
    cin>>a;
    cout<<fixed<<setprecision(2)<<fabs(a)<<endl;
    return 0;
}