/* 07:奥运奖牌计数
总时间限制: 1000ms 内存限制: 65536kB
描述
2008年北京奥运会，A国的运动员参与了n天的决赛项目(1≤n≤17)。
现在要统计一下A国所获得的金、银、铜牌数目及总奖牌数。

输入
输入n＋1行，第1行是A国参与决赛项目的天数n，其后n行，
每一行是该国某一天获得的金、银、铜牌数目，以一个空格分开。
输出
输出1行，包括4个整数，为A国所获得的金、银、铜牌总数及总奖牌数，以一个空格分开。
样例输入
3
1 0 3
3 1 0
0 3 0
样例输出
4 4 3 11
来源
http://noi.openjudge.cn/ch0105/07/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int jing, ying, tong;
    int sum_jing=0, sum_ying=0, sum_tong=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>jing>>ying>>tong;
        sum_jing += jing;
        sum_ying += ying;
        sum_tong += tong;
    }
    int sum = sum_jing + sum_ying + sum_tong;
    cout<<sum_jing<<" "<<sum_ying<<" "<<sum_tong<<" "<<sum<<endl;
    return 0;
}