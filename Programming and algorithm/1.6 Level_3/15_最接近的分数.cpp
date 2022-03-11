// 7832:最接近的分数
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 分母不超过 N 且 小于 A/B 的最大最简分数是多少？

// 输入
// 三个正整数N，A，B，相邻两个数之间用单个空格隔开。
// 1 <= A < B < N <= 1000。
// 输出
// 两个正整数，分别是所求分数的分子和分母，中间用单个空格隔开。
// 样例输入
// 100 7 13
// 样例输出
// 50 93
// 来源
// 2007年我爱数学少年夏令营数学竞赛 第9题
// http://noi.openjudge.cn/ch0201/7832/


#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b;
    cin>>n>>a>>b;
    int p, q, x, y;
    p = 1, q = n;
    for(x=1; x<=n; x++)
        for(y=n; y>=1; y--)
            if(b * x < a * y && x * q > p * y){
                p = x;
                q = y;
            }
    cout<<p<<" "<<q<<endl;
    return 0;
}