// 7834:分成互质组
// http://noi.openjudge.cn/ch0205/7834/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 给定n个正整数，将它们分组，使得每组中任意两个数互质。至少要分成多少个组？

// 输入
// 第一行是一个正整数n。1 <= n <= 10。
// 第二行是n个不大于10000的正整数。
// 输出
// 一个正整数，即最少需要的组数。
// 样例输入
// 6
// 14 20 33 117 143 175
// 样例输出
// 3
// 来源
// 2008年第十三届“华罗庚金杯”少年数学邀请赛 决赛第5题

#include<bits/stdc++.h>
using namespace std;

int n, a[15];
int f[15];//f[i]==x表示a[i]分到第x组
int total;//记录不同的方案数目

int gcd(int a,int b)
{  return a%b==0?b:gcd(b,a%b); }

void fun(int i)//判断a[i]分到哪一个组
{
    int t,j,k,flag;
    int ff[15]={0};//ff[i]==1

    if(i==n) return;
    else
    {
        t=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(ff[j]==0)//表示a[j] 所在分组未曾检验过，那就要检验该分组
            {
                flag=1;
                for(k=j;k>=0;k--)//扫描寻找a[j]所在分组的所有元素
                {
                    if(f[k]==f[j])//若a[k]和a[j]同一个分组
                    {
                        ff[k]=1;
                        if(gcd(a[k],t)!=1) flag=0;//a[k]和a[i]不互质
                    }
                }
                if(flag==1) { f[i]=f[j]; break; }//a[i]和a[j]所在组的所有元素都互质，可以加入a[j]所在组
            }
        }
        if(f[i]==0) f[i]=++total;//假如扫描先前所有组，都不能够把a[i]加进去，那a[i]自己形成一个新的组
        if(i<n) fun(i+1);//寻找下一个元素的分组
        else return ;
    }
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        f[i]=0;//f[i]=0表示a[i]未分组
    }
    f[0]=1;//a[0] 分到第一组
    total=1;//至少会有一个分组
    fun(1);
    printf("%d\n",total);
    return 0;
}
