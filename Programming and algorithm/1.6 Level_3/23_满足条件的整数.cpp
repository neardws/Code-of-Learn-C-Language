// 1943:满足条件的整数
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 假设a、b、c均为整数，且满足a，b，c 大于1，并且小于等于100，
// 找出所有符合条件：“a2+ b2= c2”的整数组。

// 输入
// 无。
// 输出
// 按a从小到大的顺序输出所有满足条件的整数组
// （若a相同，则按b从小到大的顺序输出），每行一组，
// 每一组数据的输出样式为： 
// a*a + b*b = c*c

// 注意：
// 1）为避免重复输出，要求a<=b；
// 2）加号和等号左右各有一个空格，除此之外无多余空格。

// 样例输入
// 无
// 样例输出
// 无


#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    for(a = 1; a <= 100; a++){
        for(b = 1; b <= 100; b++){
            for(c = 1; c <= 100; c++){
                if(a <= b && a * a + b * b == c * c){
                    cout<<a<<"*"<<a<<" + "<<b<<"*"<<b<<" = "<<c<<"*"<<c<<endl;
                }
            }
        }
    }
    return 0;
}