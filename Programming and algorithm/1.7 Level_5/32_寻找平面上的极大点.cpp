// 2704:寻找平面上的极大点
// http://noi.openjudge.cn/ch0406/2704/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 在一个平面上，如果有两个点(x,y),(a,b), 如果说(x,y)支配了(a,b)，这是指x>=a,y>=b;
// 用图形来看就是(a,b)坐落在以(x,y)为右上角的一个无限的区域内。
// 给定n个点的集合，一定存在若干个点，它们不会被集合中的任何一点所支配，这些点叫做极大值点。
// 编程找出所有的极大点，按照x坐标由小到大，输出极大点的坐标。
// 本题规定：n不超过100，并且不考虑点的坐标为负数的情况。
// 输入
// 输入包括两行，第一行是正整数n，表示是点数，
// 第二行包含n个点的坐标，坐标值都是整数，坐标范围从0到100，输入数据中不存在坐标相同的点。
// 输出
// 按x轴坐标最小到大的顺序输出所有极大点。
// 输出格式为:(x1,y1),(x2,y2),...(xk,yk)
// 注意：输出的每个点之间有","分隔,最后一个点之后没有",",少输出和多输出都会被判错
// 样例输入
// 5 
// 1 2 2 2 3 1 2 3 1 4
// 样例输出
// (1,4),(2,3),(3,1)

#include<bits/stdc++.h>
using namespace std;
//挺简单的，就是枚举每个点判断是否会被覆盖 
struct zb{  //结构体 存储 点的位置
    int x, y;
};
int n, k = 0;    // n 为点数，k 为极大点个数
zb a[110], b[110];
bool cmp(zb c, zb d){       // 自定义比较函数
    return c.x < d.x || (c.x == d.x && c.y < d.y);
}
int main(){
    cin>>n;     // 输入点数
    for(int i = 0; i < n; i++){
        cin>>a[i].x>>a[i].y;    // 输入 点的坐标
    }
    sort(a, a + n, cmp);    // 降序排序
    for(int i = 0; i < n; i++){    // 遍历寻找极大点
        int flag = 1;    // 默认为极大点
        for(int j = 0; j < n; j++){
            if(i != j){
                if(a[i].x <= a[j].x && a[i].y <= a[j].y){   // 找到比 i 大的点
                    flag = 0;
                    break;
                }
            }
        }
        if(flag){   
            b[k].x = a[i].x;    // 存储极大点信息
            b[k].y = a[i].y;
            k++;
        }
    }
    for(int i = 0; i < k-1; i++){   // 输出
        printf("(%d,%d),", b[i].x, b[i].y);
    }
    printf("(%d,%d)\n", b[k-1].x, b[k-1].y);
    return 0;
}