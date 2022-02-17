/* 10:有一门课不及格的学生

总时间限制: 1000ms 内存限制: 65536kB
描述
给出一名学生的语文和数学成绩，判断他是否恰好有一门课不及格（成绩小于60分）。

输入
一行，包含两个在0到100之间的整数，分别是该生的语文成绩和数学成绩。
输出
若该生恰好有一门课不及格，输出1；否则输出0。

样例输入
50 80
样例输出
1

来源
http://noi.openjudge.cn/ch0104/10/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    cin>>a>>b;
    if((a<60 && b>=60) || (a>=60 && b<60))
        cout<<1<<endl;
    else
        cout<<0<<endl;
    return 0;
}