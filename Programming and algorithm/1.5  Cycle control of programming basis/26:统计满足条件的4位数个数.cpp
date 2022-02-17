/* 26:统计满足条件的4位数个数

总时间限制: 1000ms 内存限制: 65536kB
描述
给定若干个四位数，求出其中满足以下条件的数的个数： 

个位数上的数字减去千位数上的数字，再减去百位数上的数字， 
再减去十位数上的数字的结果大于零。

输入
输入为两行，第一行为四位数的个数n，
第二行为n个的四位数，数与数之间以一个空格分开。(n <= 100)
输出
输出为一行，包含一个整数，表示满足条件的四位数的个数。
样例输入
5
1234 1349 6119 2123 5017
样例输出
3

来源
http://noi.openjudge.cn/ch0105/26/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, number, sum = 0;
    cin>>n;
    for(int i=1; i <= n; i++){
        cin>>number;
        int ge = number % 10;
        int qian = number / 1000;
        int bai = (number - qian * 1000) / 100;
        int shi = (number - qian * 1000 - bai * 100) / 10; 
        if(ge - qian - bai - shi > 0)
            sum += 1;
    }
    cout<<sum<<endl;
    return 0;
}