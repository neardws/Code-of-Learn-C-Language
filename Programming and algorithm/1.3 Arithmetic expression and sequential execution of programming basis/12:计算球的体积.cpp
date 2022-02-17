/* 12:计算球的体积
总时间限制: 1000ms 内存限制: 65536kB

描述
对于半径为r的球，其体积的计算公式为V=4/3*πr^3，
这里取π=3.14。

现给定r，求V。

输入
输入为一个不超过100的非负实数，即球半径，类型为double。
输出
输出一个实数，即球的体积，保留到小数点后2位。
样例输入
4
样例输出
267.95
来源
http://noi.openjudge.cn/ch0103/12/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    double r;
    double pi = 3.14;
    cin>>r;
    cout<<fixed<<setprecision(2)<<double(4)/double(3)*pi*r*r*r<<endl;
    printf("%.2lf", 4.0/3.0*pi*r*r*r)
    return 0;
}