/* 08:多边形内角和
总时间限制: 1000ms 内存限制: 65536kB
描述
在欧几里德几何中，n边形的内角和是(n-2)*180°。
已知其中(n-1)个内角的度数，就能计算出剩下的一个未知内角的度数。
请编写一个程序，来解决这个问题。

输入
第1行只有一个整数n
第2行有(n-1)个正整数，是每个已知内角的度数。
相邻两个整数之间用单个空格隔开。
数据保证给定多边形合法。
输出
一个正整数，为未知内角的度数。
样例输入
3
45 60
样例输出
75

来源
http://noi.openjudge.cn/ch0105/08/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, du;
    cin>>n;
    int sum_du = (n - 2) * 180;
    for(int i=1; i <= n-1; i++){
        cin>>du;
        sum_du -= du;  // sum_du = sum_du - du;
    }
    cout<<sum_du<<endl;
    return 0;
}