/* 18:点和正方形的关系

总时间限制: 1000ms 内存限制: 65536kB
描述
有一个正方形，四个角的坐标（x,y)分别是（1，-1），（1，1），（-1，-1），（-1，1），x是横轴，y是纵轴。写一个程序，判断一个给定的点是否在这个正方形内（包括正方形边界）。

输入
输入一行，包括两个整数x、y，以一个空格分开，表示坐标(x,y)。
输出
输出一行，如果点在正方形内，则输出yes，否则输出no。
样例输入
1 1
样例输出
yes
来源
http://noi.openjudge.cn/ch0104/18/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int x, y;
    cin>>x>>y;
    if(-1 <= x && x <= 1)
        if(-1 <= y && y <= 1)
            cout<<"yes";
        else
            cout<<"no";
    else
        cout<<"no";
    return 0;
}