// 6264:走出迷宫
// http://noi.openjudge.cn/ch0205/6264/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 当你站在一个迷宫里的时候，往往会被错综复杂的道路弄得失去方向感，如果你能得到迷宫地图，事情就会变得非常简单。 
// 假设你已经得到了一个n*m的迷宫的图纸，请你找出从起点到出口的最短路。

// 输入
// 第一行是两个整数n和m(1<=n,m<=100)，表示迷宫的行数和列数。
// 接下来n行，每行一个长为m的字符串，表示整个迷宫的布局。字符'.'表示空地，'#'表示墙，'S'表示起点,'T'表示出口。
// 输出
// 输出从起点到出口最少需要走的步数。
// 样例输入
// 3 3
// S#T
// .#.
// ...
// 样例输出
// 6


#include <bits/stdc++.h>
using namespace std;
char map[110][110];
int m, n, step[110][110], dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int main() {
    queue<int> q;
    cin >> m >> n;
    for (int i = 0; i < m; i++)  //输入
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') q.push(i * n + j);
        }
    while (!q.empty()) {  //BFS
        int x = q.front() / n, y = q.front() % n;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0], yy = y + dir[i][1];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && map[xx][yy] != '#') {
                step[xx][yy] = step[x][y] + 1;
                if (map[xx][yy] == 'T') cout << step[xx][yy] << endl;  // 找到
                map[xx][yy] = '#';
                q.push(xx * n + yy);
            }
        }
    }
}
