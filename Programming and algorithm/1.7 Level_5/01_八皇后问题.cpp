// 1700:八皇后问题
// http://noi.openjudge.cn/ch0205/1700/
// 总时间限制: 10000ms 内存限制: 65536kB
// 描述
// 在国际象棋棋盘上放置八个皇后，要求每两个皇后之间不能直接吃掉对方。
// 输入
// 无输入。
// 输出
// 按给定顺序和格式输出所有八皇后问题的解（见Sample Output）。
// 样例输入
// 样例输出
// No. 1
// 1 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 1 0 
// 0 0 0 0 1 0 0 0 
// 0 0 0 0 0 0 0 1 
// 0 1 0 0 0 0 0 0 
// 0 0 0 1 0 0 0 0 
// 0 0 0 0 0 1 0 0 
// 0 0 1 0 0 0 0 0 
// No. 2
// 1 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 1 0 
// 0 0 0 1 0 0 0 0 
// 0 0 0 0 0 1 0 0 
// 0 0 0 0 0 0 0 1 
// 0 1 0 0 0 0 0 0 
// 0 0 0 0 1 0 0 0 
// 0 0 1 0 0 0 0 0 
// No. 3
// 1 0 0 0 0 0 0 0 
// 0 0 0 0 0 1 0 0 
// 0 0 0 0 0 0 0 1 
// 0 0 1 0 0 0 0 0 
// 0 0 0 0 0 0 1 0 
// 0 0 0 1 0 0 0 0 
// 0 1 0 0 0 0 0 0 
// 0 0 0 0 1 0 0 0 
// No. 4
// 1 0 0 0 0 0 0 0 
// 0 0 0 0 1 0 0 0 
// 0 0 0 0 0 0 0 1 
// 0 0 0 0 0 1 0 0 
// 0 0 1 0 0 0 0 0 
// 0 0 0 0 0 0 1 0 
// 0 1 0 0 0 0 0 0 
// 0 0 0 1 0 0 0 0 
// No. 5
// 0 0 0 0 0 1 0 0 
// 1 0 0 0 0 0 0 0 
// 0 0 0 0 1 0 0 0 
// 0 1 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 1 
// 0 0 1 0 0 0 0 0 
// 0 0 0 0 0 0 1 0 
// 0 0 0 1 0 0 0 0 
// No. 6
// 0 0 0 1 0 0 0 0 
// 1 0 0 0 0 0 0 0 
// 0 0 0 0 1 0 0 0 
// 0 0 0 0 0 0 0 1 
// 0 1 0 0 0 0 0 0 
// 0 0 0 0 0 0 1 0 
// 0 0 1 0 0 0 0 0 
// 0 0 0 0 0 1 0 0 
// No. 7
// 0 0 0 0 1 0 0 0 
// 1 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 1 
// 0 0 0 1 0 0 0 0 
// 0 1 0 0 0 0 0 0 
// 0 0 0 0 0 0 1 0 
// 0 0 1 0 0 0 0 0 
// 0 0 0 0 0 1 0 0 
// No. 8
// 0 0 1 0 0 0 0 0 
// 1 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 1 0 
// 0 0 0 0 1 0 0 0 
// 0 0 0 0 0 0 0 1 
// 0 1 0 0 0 0 0 0 
// 0 0 0 1 0 0 0 0 
// 0 0 0 0 0 1 0 0 
// No. 9
// 0 0 0 0 1 0 0 0 
// 1 0 0 0 0 0 0 0 
// 0 0 0 1 0 0 0 0 
// 0 0 0 0 0 1 0 0 
// 0 0 0 0 0 0 0 1 
// 0 1 0 0 0 0 0 0 
// 0 0 0 0 0 0 1 0 
// 0 0 1 0 0 0 0 0 
// ...以下省略
// 提示
// 此题可使用函数递归调用的方法求解。
// 来源
// 计算概论05


#include<bits/stdc++.h>
using namespace std;
int arr[8];     //存储皇后的位置，思考为什么一维数组就可以存储了呢
int all = 0;    //表示目前解的个数
void print() {  //输出
    all++;
    cout << "No. " << all << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << ((arr[j] == i) ? 1 : 0) << " ";
        }
        cout << endl;
    }
}
bool judge(int n) {  //判断是否可行
    for (int i = 0; i < n; i++) {
        if (arr[n] == arr[i] || (n - i == arr[n] - arr[i] || n - i == arr[i] - arr[n]))
            return false;
    }
    return true;
}
void check(int n) {  //给棋子赋位置
    if (n == 8) {   // 找到一种可能解
        print();
        return;
    }
    for (int i = 0; i < 8; i++) {
        arr[n] = i;     // 给当前位置赋值
        if (judge(n)) {     // 判断是否可行
            check(n + 1);   // 递归调用，继续给下一个旗子赋位置
        }
    }
}
int main() {
    check(0);
}
