/* 06:浮点数向零舍入

总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个单精度浮点数，将其向零舍入到整数。

说明：向零舍入的含义是，正数向下舍入，负数向上舍入。

提示：可以使用强制类型转换来实现。

输入
一个单精度浮点数。
输出
一个整数，即向零舍入到整数的结果。
样例输入
2.3
样例输出
2
来源
http://noi.openjudge.cn/ch0102/06/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    float a;
    cin>>a;
    cout<<int(a)<<endl;
    return 0;
}
