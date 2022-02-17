/* 09:奇数求和
总时间限制: 1000ms 内存限制: 65536kB
描述
计算非负整数 m 到 n（包括m 和 n ）之间的所有奇数的和，
其中，m 不大于 n，且n 不大于300。
例如 m=3, n=12, 其和则为：3+5+7+9+11=35。

输入
两个数 m 和 n，两个数以一个空格分开，其中 0 <= m <= n <= 300 。
输出
输出一行，包含一个整数，表示m 到 n（包括m 和 n ）之间的所有奇数的和
样例输入
7 15
样例输出
55
来源


http://noi.openjudge.cn/ch0105/09/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int sum = 0;
    int m, n;
    cin>>m>>n;
    for(int i = m; i <= n; i++){
        if(i % 2 != 0)
            sum += i;
    }
    cout<<sum<<endl;
    return 0;
}