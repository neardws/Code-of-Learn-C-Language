// 1751:分解因数
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 给出一个正整数a，要求分解成若干个正整数的乘积，
// 即a = a1 * a2 * a3 * ... * an，
// 并且1 < a1 <= a2 <= a3 <= ... <= an，
// 问这样的分解的种数有多少。注意到a = a也是一种分解。
// 输入
// 第1行是测试数据的组数n，后面跟着n行输入。
// 每组测试数据占1行，包括一个正整数a (1 < a < 32768)
// 输出
// n行，每行输出对应一个输入。输出应是一个正整数，指明满足要求的分解的种数
// 样例输入
// 2
// 2
// 20
// 样例输出
// 1
// 4
// http://noi.openjudge.cn/ch0202/1751/

#include<bits/stdc++.h>
using namespace std;
int tot=0;
void find(int a,int b){
    for(int i=b;i<=sqrt(a);++i){
        if(a%i==0)//找到可以被分解的数
            find(a/i,i);
    }
    tot++;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        tot=0;
        int a;
        cin>>a;
        find(a,2);
        cout<<tot<<endl;
    }
    return 0;
}