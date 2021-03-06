/* 19:救援
总时间限制: 1000ms 内存限制: 65536kB
描述
救生船从大本营出发，营救若干屋顶上的人回到大本营，屋顶数目以及每个屋顶的坐标 
和人数都将由输入决定，求出所有人都到达大本营并登陆所用的时间。 

在直角坐标系的原点是大本营，救生船每次从大本营出发，救了人之后将人送回大本营。
坐标系中的点代表屋顶，每个屋顶由其位置坐标和其上的人数表示。
救生船每次从大本营出发，以速度50米/分钟驶向下一个屋顶，
达到一个屋顶后，救下其上的所有人，每人上船1分钟，船原路返回，
达到大本营，每人下船0.5 分钟。假设原点与任意一个屋顶的连线不穿过其它屋顶。

输入
第一行，一个整数，表示屋顶数n。
接下来依次有n行输入，每一行上包含两个表示屋顶相对于大本营的平面坐标位置的
实数（单位是米）、
一个表示人数的整数，数之间以一个空格分开。
输出
一行，救援需要的总时间，精确到分钟 (向上取整)。
样例输入
1
30 40 3
样例输出
7
来源
ceil()函数是向上取整
floor()函数是向下取整
http://noi.openjudge.cn/ch0105/19/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double time = 0.0;
    double x, y;
    int number;
    for(int i=1; i<=n; i++){
        cin>>x>>y>>number;
        time += sqrt(x*x + y*y) * 2 / 50.0 + 1.5 * number;
    }
    cout<<ceil(time)<<endl;
    return 0;
}