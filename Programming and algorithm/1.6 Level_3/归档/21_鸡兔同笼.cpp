// 1752:鸡兔同笼

// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 一个笼子里面关了鸡和兔子（鸡有2只脚，兔子有4只脚，没有例外）。
// 已经知道了笼子里面脚的总数a，
// 问笼子里面至少有多少只动物，至多有多少只动物。

// 输入
// 一行，一个正整数a (a < 32768)。
// 输出
// 一行，包含两个正整数，第一个是最少的动物数，
// 第二个是最多的动物数，两个正整数用一个空格分开。
// 如果没有满足要求的答案，则输出两个0，中间用一个空格分开。
// 样例输入
// 20
// 样例输出
// 5 10

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    int min=a, max=0;
    for(int x = 0; x <= a/2; x++){
        for(int y = 0; y <= a/4; y++){
            if(2 * x + 4 * y == a){
                if(x + y < min) 
                    min = x + y;
                if(x + y > max)
                    max = x + y;
            }
        }
    }
    if(min==a && max == 0) 
        cout<<0<<" "<<0<<endl;
    else 
        cout<<min<<" "<<max<<endl;
    return 0;
}