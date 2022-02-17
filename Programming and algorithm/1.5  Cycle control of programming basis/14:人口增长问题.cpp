/* 14:人口增长问题
总时间限制: 1000ms 内存限制: 65536kB
描述
我国现有x亿人口，按照每年0.1%的增长速度，n年后将有多少人？
x = x+x*0.001
输入
一行，包含两个整数x和n，分别是人口基数和年数，以单个空格分隔。
输出
输出最后的人口数，以亿为单位，保留到小数点后四位。
1 <= x <= 100, 1 <= n <= 100。
样例输入
13 10
样例输出
13.1306
来源



http://noi.openjudge.cn/ch0105/14/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int x, n;
    cin>>x>>n;
    double new_x = x;
    for(int i=1; i<=n; i++)
        new_x = new_x * (1 + 0.1 / 100);
    cout<<fixed<<setprecision(4)<<new_x<<endl;
    return 0;
}