// 2723:因子问题
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 任给两个正整数N、M，求一个最小的正整数a，使得a和(M-a)都是N的因子。

// 输入
// 包括两个整数N、M。N不超过1,000,000。
// 输出
// 输出一个整数a，表示结果。如果某个案例中满足条件的正整数不存在，则在对应行输出-1
// 样例输入
// 35 10
// 样例输出
// 5
// http://noi.openjudge.cn/ch0201/2723/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int a = 1;
    while(a <= n){
        if(n % a == 0 && n % (m - a) == 0){
            cout<<a<<endl;
            return 0;
        }
        a++;
    }
    cout<<-1<<endl;
    return 0;
}