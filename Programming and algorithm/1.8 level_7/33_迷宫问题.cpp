// 迷宫问题
// 定义一个二维数组： 

// int maze[5][5] = {

// 0, 1, 0, 0, 0,

// 0, 1, 0, 1, 0,

// 0, 0, 0, 0, 0,

// 0, 1, 1, 1, 0,

// 0, 0, 0, 1, 0,

// };

// 它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，
// 要求编程序找出从左上角到右下角的最短路线。

// 时间限制：1000
// 内存限制：65536
// 输入
// 一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
// 输出
// 左上角到右下角的最短路径，格式如样例所示。
// 样例输入
// 0 1 0 0 0
// 0 1 0 1 0
// 0 0 0 0 0
// 0 1 1 1 0
// 0 0 0 1 0
// 样例输出
// (0, 0)
// (1, 0)
// (2, 0)
// (2, 1)
// (2, 2)
// (2, 3)
// (2, 4)
// (3, 4)
// (4, 4)


// 解题思路：
// 这道题可以使用广度优先搜索（BFS）来解决。从起点开始进行BFS搜索，将所有能够到达的点加入队列中，
// 并记录它们的前驱节点（即到达它们的点），直到搜索到终点为止。然后根据记录的前驱节点信息，
// 从终点开始反向遍历，即可得到最短路径。

// 具体实现时，我们可以用一个二维数组记录每个位置是否已经访问过，用两个变量记录起点和终点的位置，
// 然后定义一个队列，每次将能够到达的点加入队列中。在队列中，我们需要记录每个点的坐标和它的前驱节点
// （即到达它的点），用一个二维数组记录即可。最终根据前驱节点信息反向遍历，即可得到最短路径。


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5;
int maze[MAXN][MAXN]; // 迷宫
bool vis[MAXN][MAXN]; // 标记每个位置是否已经访问过
int pre[MAXN][MAXN]; // 前驱节点，即到达该位置的前一个位置
int sx, sy, ex, ey; // 起点和终点的坐标

// 广度优先搜索函数，返回从起点到终点的最短路线
void bfs() {
    // 初始化队列和标记数组
    queue<pair<int, int>> q;
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    // 将起点加入队列，并标记为已访问
    q.push(make_pair(sx, sy));
    vis[sx][sy] = true;

    // 开始搜索
    while (!q.empty()) {
        // 取出队首位置
        int x = q.front().first, y = q.front().second;
        q.pop();
        // 如果搜索到了终点，退出循环
        if (x == ex && y == ey) {
            break;
        }
        // 遍历当前位置的上下左右四个相邻位置
        if (x-1 >= 0 && maze[x-1][y] == 0 && !vis[x-1][y]) {
            q.push(make_pair(x-1, y));
            vis[x-1][y] = true;
            pre[x-1][y] = x * MAXN + y; // 记录前驱节点
        }
        if (x+1 < MAXN && maze[x+1][y] == 0 && !vis[x+1][y]) {
            q.push(make_pair(x+1, y));
            vis[x+1][y] = true;
            pre[x+1][y] = x * MAXN + y;
        }
        if (y-1 >= 0 && maze[x][y-1] == 0 && !vis[x][y-1]) {
            q.push(make_pair(x, y-1));
            vis[x][y-1] = true;
            pre[x][y-1] = x * MAXN + y;
        }
        if (y+1 < MAXN && maze[x][y+1] == 0 && !vis[x][y+1]) {
            q.push(make_pair(x, y+1));
            vis[x][y+1] = true;
            pre[x][y+1] = x * MAXN + y;
        }
    }
}

int main() {
    // 读入迷宫
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 0 && i == 0 && j == 0) {
                sx = i;
                sy = j;
            }
            if (maze[i][j] == 0 && i == MAXN-1 && j == MAXN-1) {
                ex = i;
                ey = j;
            }
        }
    }

    // 进行广度优先搜索
    bfs();

    // 输出路径
    int x = ex, y = ey;
    while (pre[x][y] != -1) {
        int px = pre[x][y] / MAXN, py = pre[x][y] % MAXN;
        x = px;
        y = py;
        cout << "(" << x << ", " << y << ")" << endl;
    }
    cout << "(" << sx << ", " << sy << ")" << endl;

    return 0;
}

