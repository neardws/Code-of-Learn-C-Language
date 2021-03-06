// 666:放苹果
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，
// 问共有多少种不同的分法？
// （用K表示）5，1，1和1，5，1 是同一种分法。
// 输入
// 第一行是测试数据的数目t（0 <= t <= 20）。
// 以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
// 输出
// 对输入的每组数据M和N，用一行输出相应的K。
// 样例输入
// 1
// 7 3
// 样例输出
// 8






// 这个问题用递归的思维来做，我们需要明确，它应该有两个参数，一个是苹果的数量m，一个是盘子的数量n。

// 然后我们再根据m与n的比较来划分情况，注意，它的重复条件。
// 1.当m>n（苹果更多）时，每个盘子肯定至少有一个苹果，所以我们需要考虑的就是如何把m-n个苹果放入n个盘子里面, 或者空一个盘子。
// 2.当m<n（盘子多）时，这时候其实就相当于要把m个苹果放入m个盘子里。
// 3.当m=n（苹果和盘子一样多时），我们可以分为每一个都放一个苹果，也就是1次，还有当空出盘子放的情况。

#include<bits/stdc++.h>
using namespace std;
int func(int m, int n){
    if(n==0 || m==0){
        return 0;
    }
    if(n==m){
        return 1+func(m,n-1);
    }
    if(m<n){
        return func(m,m);
    }
    if(m>n){
        return func(m-n,n)+func(m,n-1);
    }
}
int main(){
    int k=0;
    cin>>k;
    while(k){
        int n,m;
        cin>>m>>n;
        cout<<func(m,n)<<endl;
        k--;
    }
    return 0;
}