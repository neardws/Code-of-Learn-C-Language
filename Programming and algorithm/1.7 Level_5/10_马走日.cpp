// 8465:马走日
// http://noi.openjudge.cn/ch0205/8465/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 马在中国象棋以日字形规则移动。

// 请编写一段程序，给定n*m大小的棋盘，以及马的初始位置(x，y)，要求不能重复经过棋盘上的同一个点，计算马可以有多少途径遍历棋盘上的所有点。

// 输入
// 第一行为整数T(T < 10)，表示测试数据组数。
// 每一组测试数据包含一行，为四个整数，分别为棋盘的大小以及初始位置坐标n,m,x,y。(0<=x<=n-1,0<=y<=m-1, m < 10, n < 10)
// 输出
// 每组测试数据包含一行，为一个整数，表示马能遍历棋盘的途径总数，0为无法遍历一次。
// 样例输入
// 1
// 5 4 0 0
// 样例输出
// 32

#include<bits/stdc++.h>
using namespace std;
int vis[12][12], m, n, x0, y0, ans, all; // 地图，mn，初始坐标，答案，地图位置数目
int dir[8][2] = {{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}};  //8个方向
void dfs(int x, int y, int step) {
    if (step == all) ans++;
    for (int i = 0; i < 8; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (xx >= 0 && yy >= 0 && xx < n && yy < m && !vis[xx][yy]) {
            vis[xx][yy] = 1;
            dfs(xx, yy, step + 1);
            vis[xx][yy] = 0;
        }
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(vis, 0, sizeof(vis));
        cin >> n >> m >> x0 >> y0;
        all = n * m, ans = 0, vis[x0][y0] = 1;  //初始化
        dfs(x0, y0, 1);
        cout << ans << endl;
    }
    return 0;
}
