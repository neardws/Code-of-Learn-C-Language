/* 08:温度表达转化
总时间限制: 1000ms 内存限制: 65536kB
描述
利用公式 C = 5 * (F-32) / 9 
（其中C表示摄氏温度，F表示华氏温度） 进行计算转化。

输入
输入一行，包含一个实数f，表示华氏温度。（f >= -459.67）
输出
输出一行，包含一个实数，表示对应的摄氏温度，
要求精确到小数点后5位。
样例输入
41
样例输出
5.00000
提示
C/C++,使用double
来源
http://noi.openjudge.cn/ch0103/08/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    double f;
    cin>>f;
    printf("%.5lf\n", 5*(f-32)/9);
    cout<<fixed<<setprecision(5)<<5*(f-32)/9<<endl;
    return 0;
}