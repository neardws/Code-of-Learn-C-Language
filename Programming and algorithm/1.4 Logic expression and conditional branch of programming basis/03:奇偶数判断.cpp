/* 03:奇偶数判断

总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个整数，判断该数是奇数还是偶数。

输入
输入仅一行，一个大于零的正整数n。
输出
输出仅一行，如果n是奇数，输出odd；如果n是偶数，输出even。
样例输入
5
样例输出
odd
来源
http://noi.openjudge.cn/ch0104/03/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    if(a % 2 == 0)
        cout<<"even"<<endl;
    else
        cout<<"odd"<<endl;
    return 0;
}