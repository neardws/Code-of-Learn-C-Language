/* 17:斐波那契数列
总时间限制: 1000ms 内存限制: 65536kB
描述
斐波那契数列是指这样的数列: 数列的第一个和第二个数都为1，
接下来每个数都等于前面2个数之和。
给出一个正整数k，要求斐波那契数列中第k个数是多少。

输入
输入一行，包含一个正整数k。（1 <= k <= 46）
输出
输出一行，包含一个正整数，表示斐波那契数列中第k个数的大小
样例输入
19
样例输出
4181

来源
http://noi.openjudge.cn/ch0105/17/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    if(k==1 || k==2){
        cout<<1<<endl;
    }
    else{
        int i=1, j=1, num;
        for(int m=1; m <= k-2; m++){
            num = i + j;
            i = j;
            j = num;
        }
        cout<<num<<endl;
    }
    return 0;
}