// 7827:质数的和与积
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 两个质数的和是S，它们的积最大是多少？

// 输入
// 一个不大于10000的正整数S，为两个质数的和。
// 输出
// 一个整数，为两个质数的最大乘积。数据保证有解。
// 样例输入
// 50
// 样例输出
// 589
// 来源
// 《奥数典型题举一反三（小学五年级）》 (ISBN 978-7-5445-2882-5) 第三章 第二讲 例1
// http://noi.openjudge.cn/ch0201/7827/



#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if (n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main(){
    int s;
    cin>>s;
    for(int i = s / 2; i >= 2; i--){
        if(isPrime(i) && isPrime(s - i)){
            cout<<i * (s - i)<<endl;
            return 0;
        }
    }
    return 0;
}