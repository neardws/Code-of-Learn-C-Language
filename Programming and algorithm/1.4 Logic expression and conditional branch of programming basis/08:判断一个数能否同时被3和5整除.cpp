/* 08:判断一个数能否同时被3和5整除

总时间限制: 1000ms 内存限制: 65536kB
描述
判断一个数n 能否同时被3和5整除

输入
输入一行，包含一个整数n。（ -1,000,000 < n < 1,000,000）
输出
输出一行，如果能同时被3和5整除输出YES，否则输出NO
样例输入
15
样例输出
YES
来源
http://noi.openjudge.cn/ch0104/08/
 */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n % 3 == 0 && n % 5 == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}