// 1792:迷宫
// http://noi.openjudge.cn/ch0205/1792/
// 总时间限制: 3000ms 内存限制: 65536kB
// 描述
// 一天Extense在森林里探险的时候不小心走入了一个迷宫，迷宫可以看成是由n * n的格点组成，
// 每个格点只有2种状态，.和#，前者表示可以通行后者表示不能通行。
// 同时当Extense处在某个格点时，他只能移动到东南西北(或者说上下左右)四个方向之一的相邻格点上，
// Extense想要从点A走到点B，问在不走出迷宫的情况下能不能办到。如果起点或者终点有一个不能通行(为#)，则看成无法办到。
// 输入
// 第1行是测试数据的组数k，后面跟着k组输入。每组测试数据的第1行是一个正整数n (1 <= n <= 100)，表示迷宫的规模是n * n的。
// 接下来是一个n * n的矩阵，矩阵中的元素为.或者#。
// 再接下来一行是4个整数ha, la, hb, lb，描述A处在第ha行, 第la列，B处在第hb行, 第lb列。
// 注意到ha, la, hb, lb全部是从0开始计数的。
// 输出
// k行，每行输出对应一个输入。能办到则输出“YES”，否则输出“NO”。
// 样例输入
// 2
// 3
// .##
// ..#
// #..
// 0 0 2 2
// 5
// .....
// ###.#
// ..#..
// ###..
// ...#.
// 0 0 4 0
// 样例输出
// YES
// NO


#include<bits/stdc++.h>
using namespace std;
int n, ha, la, hb, lb;
int map[110][110]; //地图
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //四方
bool dfs(int x, int y) {
    if (x == hb + 1 && y == lb + 1) return true;
    int xx, yy;
    for (int i = 0; i < 4; i++) {
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if (map[xx][yy] != 1) {
            map[xx][yy] = 1;
            if (dfs(xx, yy)) return true;
        }
    }
    return false;
}
int main() {
    int k;
    char temp;
    cin >> k;
    while (k--) {
        cin >> n;
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {//这里是将字符转化为数字了，也可以不转化
                if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
                    map[i][j] = 1;
                else {
                    cin >> temp;
                    map[i][j] = temp == '#' ? 1 : 0;
                }
            }
        }
        cin >> ha >> la >> hb >> lb;
        if (map[ha + 1][la + 1] == 1 || map[hb + 1][lb + 1] == 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << (dfs(ha + 1, la + 1) ? "YES" : "NO") << endl;
    }
}
