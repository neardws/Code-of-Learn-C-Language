/*11:整数的个数
总时间限制: 1000ms 内存限制: 65536kB
描述
给定k（1< k < 100）个正整数，
其中每个数都是大于等于1，小于等于10的数。
写程序计算给定的k个正整数中，1，5和10出现的次数。

输入
输入有两行：
第一行包含一个正整数k，第二行包含k个正整数，每两个正整数用一个空格分开。
输出
输出有三行，第一行为1出现的次数，，第二行为5出现的次数，第三行为10出现的次数。
样例输入
5
1 5 8 10 5 
样例输出
1
2
1
来源
http://noi.openjudge.cn/ch0105/11/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    int num;
    int sum_one=0, sum_five=0, sum_ten=0;
    for(int i=1; i<=k; i++){
        cin>>num;
        if(num == 1)
            sum_one += 1;
        if(num == 5)
            sum_five += 1;
        if(num == 10)
            sum_ten += 1;
    }
    cout<<sum_one<<endl<<sum_five<<endl<<sum_ten<<endl;
    return 0;
}
