/* 43:质因数分解

总时间限制: 1000ms 内存限制: 65536kB
描述
已知正整数 n 是两个不同的质数的乘积，试求出较大的那个质数。

输入
输入只有一行，包含一个正整数 n。

对于60%的数据，6 ≤ n ≤ 1000。
对于100%的数据，6 ≤ n ≤ 2*10^9。
输出
输出只有一行，包含一个正整数 p，即较大的那个质数。
样例输入
21
样例输出
7
来源
http://noi.openjudge.cn/ch0105/43/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 2; i <= sqrt(n); i++){
        bool flag = true;
        int num = i;
        if(num != 2){
            for (int j = 2; j <= sqrt(num); j++){
                if(num % j == 0)
                    flag = false;  
            }
        }
        if(flag){
            if(n % num == 0)
                cout<<n/num<<endl;
        }
    }
    return 0;
}