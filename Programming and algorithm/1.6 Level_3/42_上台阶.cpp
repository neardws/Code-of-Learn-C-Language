// 3525:上台阶
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 楼梯有n(100 > n > 0)阶台阶, 上楼时可以一步上1阶,也可以一步上2阶,也可以一步上3阶，
// 编程计算共有多少种不同的走法。
// 主要注意与之前的题目，这里的题目是可以一步上1、2、3阶楼梯。
// 考虑递推式
// f(n) = f(n-1) + f(n-2) + f(n-3)  (n>=3)
// n 表示 为 n 阶的走法
// 考虑递推边界
// f(1) = 1
// f(2) = 2
// f(3) = 4

// 输入
// 输入的每一行包括一组测试数据，即为台阶数n。最后一行为0，表示测试结束。
// 输出
// 每一行输出对应一行输入的结果，即为走法的数目。
// 样例输入
// 1
// 2
// 3
// 4
// 0
// 样例输出
// 1
// 2
// 4
// 7

#include<bits/stdc++.h>
using namespace std;
int tot=0;
int find(int n){
    if(n==1)
        return 1;
    else if(n==2) 
        return 2;
    else if(n==3) 
        return 4;
    else return 
        find(n-3)+find(n-2)+find(n-1);
}
int main() {
    int a, b;
    while(cin>>a){
        if(a==0)
            break;
        else
            cout<<find(a)<<endl;
    }
    return 0;
}