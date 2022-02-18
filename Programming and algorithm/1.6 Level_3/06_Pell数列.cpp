// 1788:Pell数列
// 总时间限制: 3000ms 内存限制: 65536kB
// 描述
// Pell数列a1, a2, a3, ...的定义是这样的，a1 = 1, a2 = 2, ... , an = 2 * an − 1 + an - 2 (n > 2)。
// 给出一个正整数k，要求Pell数列的第k项模上32767是多少。
// 输入
// 第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数k (1 ≤ k < 1000000)。
// 输出
// n行，每行输出对应一个输入。输出应是一个非负整数。
// 样例输入
// 2
// 1
// 8
// 样例输出
// 1
// 408
// http://noi.openjudge.cn/ch0202/1788/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[1000000] = {0};
    a[1] = 1;
    a[2] = 2;
    int b;
    for(int i = 1; i <= n; i++){
        cin>>b;
        if(a[b] != 0){
            cout<<a[b]<<endl;
        }
        else{
            for(int j = 3; j <= b; j++){
                a[j] = (2 * a[j-1] + a[j-2]) % 32767;
            }
            cout<<a[b]<<endl;
        }
    }
    return 0;
}