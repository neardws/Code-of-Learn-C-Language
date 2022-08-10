// 2990:符号三角形
// http://noi.openjudge.cn/ch0205/2990/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 符号三角形的第1行有n个由“+”和”-“组成的符号 ，以后每行符号比上行少1个，2个同号下面是”+“，2个异号下面是”-“ 。
// 计算有多少个不同的符号三角形，使其所含”+“ 和”-“ 的个数相同。

// n=7时的1个符号三角形如下:
// + + - + - + +
// + - - - - +
// - + + + -
// - + + -
// - + -
// - -
// +
// 输入
// 每行1个正整数n<=24,n=0退出.
// 输出
// n和符号三角形的个数.
// 样例输入
// 15
// 16
// 19
// 20
// 0
// 样例输出
// 15 1896
// 16 5160
// 19 32757
// 20 59984

//为了便与运算'-'用1表示，'+'用0表示 '^'异或运算

#include <bits/stdc++.h>
using namespace std;

int half;
int n[30]={0};
int sum[30]={0}; //sum计算符号三角形的个数 
int count_number=0; // count_number用于统计负号的个数
int a[30][30]; //存储符号三角形
int times=0; //times记录输入n的次数

void backtrack(int t)
{
    if(count_number>half || (t*(t+1)/2-count_number>half)) return; //如果负号的个数超过一半结束此次枚举
    int i,j;
    if(t==n[times])
        sum[times]++;
    else
    {
        for(i=0;i<2;i++)
        {
            a[0][t]=i; //第一行第t个字符
            count_number=count_number+i; //统计‘-’个数，因为‘0’表示‘+’，‘1’表示‘-’
            for(j=1;j<=t;j++)
            {
                a[j][t-j]=a[j-1][t-j]^a[j-1][t-j+1]; //推导出下面n-1行符号的情况
                count_number+=a[j][t-j];
            }
            backtrack(t+1);
            for(j=1;j<=t;j++)
            {
                count_number-=a[j][t-j];
            }
            count_number=count_number-i;
        }
    }
}

int main()
{
    int i,j,k;
    scanf("%d",&n[times]);
    for(i=0;i<n[times];i++)
        for(j=0;j<n[times];j++)
            a[i][j]=0; //将数组置零
    while(n[times]&&n[times]<=24&&n[times]>=0)
    {
        if(n[times]==0)
            break;
        if((n[times]*(n[times]+1)/2)%2==1) //判断符号总数是否为奇数
        {
            times++;
            scanf("%d",&n[times]);
            continue;
        }
        else
        {
            half=n[times]*(n[times]+1)/4;
            backtrack(0); //递推穷举所有情况
            count_number=0;
        }
        scanf("%d",&n[++times]);
    }
    for(i=0;i<times;i++)
        printf("%d %d\n",n[i],sum[i]) ;
    return 0;
}