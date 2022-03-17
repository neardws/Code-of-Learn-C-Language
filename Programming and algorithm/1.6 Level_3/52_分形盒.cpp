// 分形盒
// 分形，通常被定义为一个粗糙或零碎的几何形状，可以分成数个部分，
// 且每一部分都（至少近似地）是整体缩小后的形状，即具有自相似的性质。
// 它跟分数维、自组织、非线性系统和混沌等具有非常重要的联系。
// 分形盒就是这样一种分形，它的定义如下：
// 维度是1的分形盒：

// X

// 维度是2的分形盒：

// X  X

//   X

// X  X

// 如果已知维度是(n-1)的分形盒，那么维度是n的分形盒的递归定义如下所示：

// Box(n-1)               Box(n-1)

//               Box(n-1)

// Box(n-1)               Box(n-1)   

// 你的任务是画一个维度为n的分形盒。

// 时间限制：1000
// 内存限制：65536
// 输入
// 输入包含多组测试数据。每一行包含一个正整数n表示分形盒的维度，n不大于7；最后一行是一个-1，表示输入结束。
// 输出
// 对于每组测试数据，输出要求维度的分形盒，注意X为大写字母。每组测试数据之后包含一行，改行只包含一个破折号。
// 样例输入
// 1
// 2
// 3
// 4
// -1
// 样例输出
// X
// -
// X X
//  X
// X X
// -
// X X   X X
//  X     X
// X X   X X
//    X X
//     X
//    X X
// X X   X X
//  X     X
// X X   X X
// -
// X X   X X         X X   X X
//  X     X           X     X
// X X   X X         X X   X X
//    X X               X X
//     X                 X
//    X X               X X
// X X   X X         X X   X X
//  X     X           X     X
// X X   X X         X X   X X
//          X X   X X
//           X     X
//          X X   X X
//             X X
//              X
//             X X
//          X X   X X
//           X     X
//          X X   X X
// X X   X X         X X   X X
//  X     X           X     X
// X X   X X         X X   X X
//    X X               X X
//     X                 X
//    X X               X X
// X X   X X         X X   X X
//  X     X           X     X
// X X   X X         X X   X X
// -

#include<bits/stdc++.h>
using namespace std;
//7度盒分形 最大规模n=3^6=729
#define MAX 730

char maps[MAX][MAX];

void printBox(int n, int x, int y){
    //递归边界
    if (n == 1){
        maps[x][y] = 'X';
    }
    else{
        //n-1度盒分形的规模m
        int m = pow(3, n - 2); 
        //左上方的n-1度盒分形
        printBox(n - 1, x, y);
        //右上方的n-1度盒分形
        printBox(n-1, x+2*m, y);
        //中间的n-1度盒分形
        printBox(n - 1, x , y + 2 * m);
        //左下方的n-1度盒分形
        printBox(n - 1, x + m, y + m);
        //右下方的n-1度盒分形
        printBox(n-1,x+2*m,y+2*m);
    }
}

int main(){
    int n ;
    cin >> n;
    while (n != -1){
        int size = pow(3, n - 1);
        //初始化
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                maps[i][j] = ' ';
                maps[i][size] = '\0';
            }
        }
        printBox(n, 0, 0);
        //输出
        for (int i = 0; i < size; i++)
            printf("%s\n", maps[i]);
        cout << "-"<<endl;
        cin >> n;
    }
    return 0;
}

