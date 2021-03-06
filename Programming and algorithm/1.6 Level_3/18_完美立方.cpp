// 1812:完美立方
// 形如a3= b3 + c3 + d3的等式被称为完美立方等式。
// 例如123= 63 + 83 + 103 。
// 编写一个程序，对任给的正整数N (N≤100)，
// 寻找所有的四元组(a, b, c, d)，
// 使得a3 = b3 + c3 + d3，其中a,b,c,d 大于 1, 小于等于N，且b<=c<=d。
// 输入
// 一个正整数N (N≤100)。
// 输出
// 每行输出一个完美立方。输出格式为：
// Cube = a, Triple = (b,c,d)
// 其中a,b,c,d所在位置分别用实际求出四元组值代入。
// 请按照a的值，从小到大依次输出。
// 当两个完美立方等式中a的值相同，则b值小的优先输出、
// 仍相同则c值小的优先输出、再相同则d值小的先输出。
// 样例输入
// 24
// 样例输出
// Cube = 6, Triple = (3,4,5)
// Cube = 12, Triple = (6,8,10)
// Cube = 18, Triple = (2,12,16)
// Cube = 18, Triple = (9,12,15)
// Cube = 19, Triple = (3,10,18)
// Cube = 20, Triple = (7,14,17)
// Cube = 24, Triple = (12,16,20)
// http://noi.openjudge.cn/ch0201/1812/

#include<bits/stdc++.h>
using namespace std;
//4重循环，关键是该break的时候尽早，省了很多无用功 
int n,a,b,c,d,a3,b3,c3,d3;
int main() {
    cin>>n;
    for(int a=2;a<=n;a++){
        a3=a*a*a;
        for(int b=2;b<=n;b++){
            b3=b*b*b;
            if(b3>=a3)
                break;
            for(int c=b;c<=n;c++){
                c3=c*c*c;
                if(c3+b3>=a3)
                    break;
                for(int d=c;d<=n;d++){
                    d3=d*d*d;
                    if(d3+c3+b3>a3)
                        break;
                    if(d3+c3+b3==a3){
                        cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
                    }
                }
            }
        }
    }
    return 0;
}