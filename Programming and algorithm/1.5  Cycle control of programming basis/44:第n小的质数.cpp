/* 44:第n小的质数
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个正整数n，求第n小的质数。

输入
一个不超过10000的正整数n。
输出
第n小的质数。
样例输入
10
样例输出
29

http://noi.openjudge.cn/ch0105/44/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i = 2;
    while (n > 0){
        int num = i;
        bool flag = true;
        for (int j = 2; j <= sqrt(num); j++){
            if(num % j == 0)
                flag = false;  
        }
        if (flag){
            if(n == 1){
                cout<<num<<endl;
                return 0;
            }
            n -= 1;
        }
        i++;
    }
}