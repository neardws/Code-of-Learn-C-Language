// 问题求解
// 给定一个正整数N，求最小的M满足比N大且M与N的二进制表示中有相同数目的1。

// 举个例子，假如给定N为78，二进制表示为1001110，包含4个1，那么最小的比N大的并且二进制表示中只包含4个1的数是83，
// 其二进制是1010011，因此83就是答案。

// 时间限制：1000
// 内存限制：65536
// 输入
// 输入若干行，每行一个数N(1 ≤ N ≤ 1000000)，如果这行为0表示输入结束。
// 输出
// 对于每个N,输出对应的M。
// 样例输入
// 1
// 2
// 3
// 4
// 78
// 0
// 样例输出
// 2
// 4
// 5
// 8
// 83

#include<bits/stdc++.h>
using namespace std; 
int a[1000];
int onecheck(int a)
{
    int j,i=~0,count=0;
    i=a&i;
    for(j=0;j<30;j++)
    {
        if(i%2==1)count++;
        i/=2;
    }
    return count;
}

int main()
{
    int i,j;
    while(cin>>i&&i!=0)
    {
        for(j=i+1;;j++)
        {
        if(onecheck(i)==onecheck(j))
        {
            cout<<j<<endl;
            break;
        }
        }
    }
    return 0;
}
