/* 06:判断是否为两位数

总时间限制: 1000ms 内存限制: 65536kB
描述
判断一个正整数是否是两位数（即大于等于10且小于等于99）。

输入
一个正整数，不超过1000。
输出
一行。若该正整数是两位数，输出1，否则输出0。
样例输入
54
样例输出
1
来源
http://noi.openjudge.cn/ch0104/06/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    if(a>=10 && a<=99)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    return 0;
}