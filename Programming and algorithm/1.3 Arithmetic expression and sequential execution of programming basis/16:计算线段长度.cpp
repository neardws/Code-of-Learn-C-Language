/* 16:计算线段长度

总时间限制: 1000ms 内存限制: 65536kB
描述
已知线段的两个端点的坐标A（Xa,Ya），B（Xb，Yb），
求线段AB的长度。

sqrt() 开方函数
sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya))

输入
共两行。
第一行是两个实数Xa，Ya，即A的坐标。
第二行是两个实数Xb，Yb，即B的坐标。
输入中所有实数的绝对值均不超过10000。
输出
一个实数，即线段AB的长度，保留到小数点后3位。
样例输入
1 1
2 2
样例输出
1.414
来源
http://noi.openjudge.cn/ch0103/16/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    double xa, ya;
    double xb, yb;
    cin>>xa>>ya;
    cin>>xb>>yb;
    cout<<fixed<<setprecision(3)<<sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb))<<endl;
    return 0;
}