/* 13:反向输出一个三位数

总时间限制: 1000ms 内存限制: 65536kB
描述
将一个三位数反向输出。

输入
一个三位数n。
输出
反向输出n。
样例输入
100
样例输出
001
来源
http://noi.openjudge.cn/ch0103/13/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    int x = a / 100;
    int z = a % 10;
    int y = (a - x * 100 - z) / 10;
    cout<<z<<y<<x<<endl;
    return 0;
}