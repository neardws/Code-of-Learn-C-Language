// 1749:数字方格
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述

// 如上图，有3个方格，每个方格里面都有一个整数a1，a2，a3。
// 已知0 <= a1, a2, a3 <= n，
// 而且a1 + a2是2的倍数，
// a2 + a3是3的倍数， 
// a1 + a2 + a3是5的倍数。
// 你的任务是找到一组a1，a2，a3，使得a1 + a2 + a3最大。

// 输入
// 一行，包含一个整数n (0 <= n <= 100)。
// 输出
// 一个整数，即a1 + a2 + a3的最大值。
// 样例输入
// 3
// 样例输出
// 5
// http://noi.openjudge.cn/ch0201/1749/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a1, a2, a3;
    int max = 0;
    for (a1 = 0; a1 <= n; a1++){
        for (a2 = 0; a2 <= n; a2++){
            for (a3 = 0; a3 <= n; a3++){
                if (((a1 + a2) % 2 == 0) && ((a2 + a3) % 3 == 0) && ((a1 + a2 + a3) % 5 == 0)){
                    if (a1 + a2 + a3 > max){
                        max = a1 + a2 + a3;
                    }
                }
            }
        }
    }
    cout<<max<<endl;
    return 0;
}
