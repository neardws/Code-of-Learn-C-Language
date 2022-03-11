// 8755:砝码称重
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 设有1g、2g、3g、5g、10g、20g的砝码各若干枚（其总重<=1000），
// 要求：计算用这些砝码能称出的不同重量的个数，但不包括一个砝码也不用的情况。

// 输入
// 一行，包括六个正整数a1,a2,a3,a4,a5,a6，
// 表示1g砝码有a1个，2g砝码有a2个，……，20g砝码有a6个。
// 相邻两个整数之间用单个空格隔开。
// 输出
// 以“Total=N”的形式输出，其中N为可以称出的不同重量的个数。
// 样例输入
// 1 1 0 0 0 0
// 样例输出
// Total=3
// 提示
// 样例给出的砝码可以称出1g，2g，3g三种不同的重量。
// 来源
// NOIP1996复赛 提高组 第四题

#include <bits/stdc++.h>
using namespace std;
int v[1010];
int main(){
    int a,b,c,d,e,f,ans=0;
    cin>>a>>b>>c>>d>>e>>f;
    for(int i=0;i<=a;i++)
        for(int j=0;j<=b;j++)
            for(int k=0;k<=c;k++)
                for(int l=0;l<=d;l++)
                    for(int m=0;m<=e;m++)
                        for(int n=0;n<=f;n++)
                            v[i+j*2+k*3+l*5+m*10+n*20]=1;
    for(int i=1;i<=1000;i++)
        if(v[i])ans++;
    printf("Total=%d",ans);
    return 0;
}

