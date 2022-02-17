/* 27:级数求和
总时间限制: 1000ms 内存限制: 65536kB
描述
已知：Sn= 1＋1／2＋1／3＋…＋1／n。
显然对于任意一个整数K，当n足够大的时候，Sn大于K。
现给出一个整数K（1<=k<=15），要求计算出一个最小的n；使得Sn＞K。
输入
一个整数K。
输出
一个整数n。
样例输入
1
样例输出
2
来源
http://noi.openjudge.cn/ch0105/27/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    double sn = 1.0;
    int n = 1;
    while (sn <= double(k)){
        n += 1;
        sn += 1.0 / n;
    }
    cout<<n<<endl;
    return 0;
}