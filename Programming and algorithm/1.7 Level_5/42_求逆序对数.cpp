// 0809:求逆序对数
// http://dsa.openjudge.cn/sort/0809/
// 总时间限制: 500ms 内存限制: 65536kB
// 描述
// 对于一个长度为N的整数序列A，满足i < j 且 Ai > Aj.的数对(i,j)称为整数序列A的一个逆序

// 请求出整数序列A的所有逆序对个数

// 输入
// 输入包含多组测试数据，每组测试数据有两行
// 第一行为整数N(1 <= N <= 20000)，当输入0时结束
// 第二行为N个整数，表示长为N的整数序列
// 输出
// 每组数据对应一行，输出逆序对的个数
// 样例输入
// 5
// 1 2 3 4 5
// 5
// 5 4 3 2 1
// 1
// 1
// 0
// 样例输出
// 0
// 10
// 0

#include<bits/stdc++.h>
using namespace std;

int n,nums[20005],tmp[20005],cnt;

void mergesort(int l,int r)
{
    if(l>=r)    return;
    int m=(l+r)/2;
    int i=l,j=m+1,k=0;
    while(i<=m&&j<=r){
        if(nums[i]>nums[j]){
            tmp[k++]=nums[j++];
            cnt+=m-i+1;
        }
        else{
            tmp[k++]=nums[i++];
        }
    }
    while(i<=m) tmp[k++]=nums[i++];
    while(j<=r) tmp[k++]=nums[j++];
    for(i=0;i<k;i++)    nums[i+l]=tmp[i];
}

void mergearray(int l,int r){
    if(l>=r)    return;
    int m=(l+r)/2;
    mergearray(l,m);
    mergearray(m+1,r);
    mergesort(l,r);
}

int main()
{
    while(~scanf("%d",&n)&&n){
        cnt=0;
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        mergearray(0,n-1);
        printf("%d\n",cnt);
    }
    return 0;
}