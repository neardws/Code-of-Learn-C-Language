/* 05:整数大小比较

总时间限制: 1000ms 内存限制: 65536kB
描述
输入两个整数，比较它们的大小。

输入
一行，包含两个整数x和y，中间用单个空格隔开。
0 <= x < 2^32, -2^31 <= y < 2^31。
输出
一个字符。
若x > y，输出 > ；
若x = y，输出 = ；
若x < y，输出 < ；
样例输入
1000 100
样例输出
>
 */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int x, y;
    cin>>x>>y;
    if(x > y)
        cout<<'>'<<endl;
    else if (x == y)
        cout<<'='<<endl;
    else
        cout<<'<'<<endl;
    return 0;
}