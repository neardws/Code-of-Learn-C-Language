/* 25:求特殊自然数
总时间限制: 1000ms 内存限制: 65536kB
描述
一个十进制自然数,它的七进制与九进制表示都是三位数，
且七进制与九进制的三位数码表示顺序正好相反。
编程求此自然数,并输出显示。

输入
无。
输出
三行：
第一行是此自然数的十进制表示；
第二行是此自然数的七进制表示；
第三行是此自然数的九进制表示。
样例输入
（无）
样例输出
（不提供）
来源
http://noi.openjudge.cn/ch0105/25/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=0; i <= 6; i++){
        for(int j=0; j <= 6; j++){
            for(int k=0; k <= 6; k++){
                if(i*7*7 + j*7 + k == k*9*9 + j*9 + i && i*7*7 + j*7 + k != 0){
                    cout<<i*7*7 + j*7 + k<<endl;
                    cout<<i<<j<<k<<endl;
                    cout<<k<<j<<i<<endl;
                }
            }
        }
    }

    //第二种解法
    // int i, j, k;
    // for(int m = 1; m <= 810; m++){
    //     i = m / 49;
    //     k = m % 7;
    //     j = (m - i * 49 - k) / 7;
    //     if (i*7*7 + j*7 + k == k*9*9 + j*9 + i)
    //     {
    //         cout<<m<<endl;
    //         return 0;
    //     }
    // }
}

