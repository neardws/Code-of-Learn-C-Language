/* 17:计算三角形面积

总时间限制: 1000ms 内存限制: 65536kB
描述
平面上有一个三角形，它的三个顶点坐标分别为(x1, y1), (x2, y2), (x3, y3)，
那么请问这个三角形的面积是多少。

输入
输入仅一行，包括6个单精度浮点数，分别对应x1, y1, x2, y2, x3, y3。
输出
输出也是一行，输出三角形的面积，精确到小数点后两位。
样例输入
0 0 4 0 0 3
样例输出
6.00
提示
海伦公式 
来源
http://noi.openjudge.cn/ch0103/17/
 */

#include<bits/stdc++.h>
using namespace std;
int main(){
    float x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    float a = sqrt((x1 - x2) * (x1 -x2) + (y1 - y2) * (y1 -y2));
    float b = sqrt((x1 - x3) * (x1 -x3) + (y1 - y3) * (y1 -y3));
    float c = sqrt((x2 - x3) * (x2 -x3) + (y2 - y3) * (y2 -y3));
    float q = 0.5 * (a + b + c);
    float m = sqrt(q * (q - a) * (q - b) * (q - c));
    cout<<fixed<<setprecision(2)<<m<<endl;
    return 0;
}