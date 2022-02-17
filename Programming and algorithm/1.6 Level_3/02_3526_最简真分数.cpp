/*
3526:最简真分数

总时间限制: 1000ms 内存限制: 65536kB
描述
给出n个正整数，任取两个数分别作为分子和分母组成最简真分数，编程求共有几个这样的组合。

输入
第一行是一个正整数n（n<=600）。
第二行是n个不同的整数，相邻两个整数之间用单个空格隔开。整数大于1且小于等于1000。
输出
一个整数，即最简真分数组合的个数。
样例输入
7
3 5 7 9 11 13 15
样例输出
17
http://noi.openjudge.cn/ch0201/3526/
*/

#include<bits/stdc++.h>
using namespace std;

bool isRelativelyPrim(int a, int b){
    for(int i = 2; i <= b; i++){
        if(b % i == 0 && a % i == 0) 
            return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(a[j] < a[i] && isRelativelyPrim(a[i], a[j])){
                sum += 1;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}