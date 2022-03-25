// 2722:和数
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 给定一个正整数序列，判断其中有多少个数，等于数列中其他两个数的和。 
// 比如，对于数列1 2 3 4, 这个问题的答案就是2, 
// 因为3 = 2 + 1, 4 = 1 + 3。

// 输入
// 共两行，第一行是数列中数的个数n ( 1 <= n <= 100)，
// 第二行是由n个不大于10000的正整数组成的数列，
// 相邻两个整数之间用单个空格隔开。
// 输出
// 一个整数，即数列中等于其他两个数之和的数的个数。
// 样例输入
// 4
// 1 2 3 4
// 样例输出
// 2
// http://noi.openjudge.cn/ch0201/2722/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[100];
    int b[100]={0};
    for(int i=0;i<n;i++)
        cin>>a[i];
    int sum = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<n;k++)
                if(a[i]+a[j] == a[k])
                    b[k] = 1;
        }
    }
    for(int i=0;i<n;i++)
        sum += b[i];
    cout<<sum<<endl;
    return 0;
}