// 哥斯拉大战金刚

// 众所周知，哥斯拉和金刚是时代仇敌，大战一触即发。
// 金刚为了打败哥斯拉，要先前往地心空洞获得战斧。
// 金刚现在所在之处可以被视为一个n*m的网格图，S表示金刚目前的位置，
// T表示地心空洞的入口，X表示障碍物，.表示平地。
// 在前往地心空洞之前，金刚必须先获得一系列打开地心空洞的钥匙
// （在地图上通过数字1,2,…,k表示），
// 并且获得i类钥匙的前提是金刚已经获得了1,2,…,i-1类钥匙，
// 金刚在拿到地图上所有种类的钥匙之后即可前往地心空洞的入口。
// 另外，同一种类的钥匙可能有多把，金刚只需获得其中任意一把即可。
// 金刚每一步可以朝上下左右四个方向中的一个移动一格，值得注意的是，
// 哥斯拉为了阻挠金刚的计划，还在地图上设置了q个陷阱（在网格图中用G表示），
// 金刚第一次进入某个陷阱需要花费额外的一步来破坏陷阱（这之后该陷阱即可被视为平地）。
// 为了更好的掌握全局，请你帮金刚计算到达地心空洞入口所需要花费的最少步数。
// 输入数据保证有解。

// 时间限制：6000
// 内存限制：262144

// 输入
// 第一行输入两个整数n, m，表示网格图的大小。 
// 接下来n行，每行输入m个字符，表示地图 
// 1 ≤ n,m ≤ 100 1 ≤ k ≤ 9 1 ≤ q ≤ 7

// 输出
// 输出一行包含一个整数，表示金刚到达地心空洞入口所需要花费的最少步数。

// 样例输入
// 5 5
// XX13X
// X.GXX
// S…T
// XXGXX
// …2

// 样例输出
// 24

// 解题思路

// 思路：广搜题，属于较为复杂的一种，既要收集钥匙也要破坏陷阱。
// 去重：xy坐标+钥匙+陷阱分布
// 地图上的标识有
// ‘.’：平地；‘X’：障碍，不能通过；‘T’：终点；‘S’：起点；‘G’：陷阱；1~9的数字：钥匙
// 起点和没有拿完钥匙的终点，不能拿的钥匙，破坏完的陷阱都当做平地处理


#include<bits/stdc++.h>
using namespace std;
struct point {
    int x, y;       // x, y坐标
    short keys;     // keys表示现在收集的钥匙种数
    short fighted;  // fighted表示是否已经消灭陷阱
    int steps;      // steps记录此时的步数
    short layout;   // layout是陷阱的分布（用short变量表示）
    point(int inx, int iny, short k, short f, int s, short l):x(inx),y(iny),keys(k),fighted(f),steps(s),layout(l){}
};
char flags[105][105][10][130];
int n, m;       // 地图大小
int k, q;       // k 为钥匙数量，q 为陷阱数量
char maze[105][105];           // 地图信息
vector< pair <int, int> > traps;   // 陷阱信息
int dx[4] = { -1, 1, 0, 0 };   // 4个方向
int dy[4] = { 0, 0, -1, 1 };
int findTraps(int x, int y) {  // 是第几个陷阱
    for (int i = 0; i < q; i++) {
        if (traps[i].first == x && traps[i].second == y)
            return i;
    }
}
int main() {
    cin >> n >> m;          // 输入地图大小
    int startx, starty;     // 起始位置
    q = 0;                  // k 为钥匙数量，q 为陷阱数量        
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') {    // ‘S’：起点
                startx = i;
                starty = j;
            }
            if (maze[i][j] == 'G') {    // ‘G’：陷阱
                q++;
                traps.push_back(make_pair(i, j));
            }
            if (maze[i][j] > '0' && maze[i][j] <= '9')
                // 1~9的数字：钥匙
                k = max(k, maze[i][j] - '0');
        }
    }
    queue<point> myqueues;
    short oriLayout = (1 << q) - 1;     // 表示陷阱状态
    myqueues.push(point(startx, starty, 0, 0, 0, oriLayout));
    memset(flags, 0, sizeof(flags));
    flags[startx][starty][0][oriLayout] = 1;
    while (!myqueues.empty()) {
        point top = myqueues.front();
        myqueues.pop();
        if (maze[top.x][top.y] == 'T' && top.keys == k) { 
            // ‘T’：终点
            cout << top.steps << endl;
            break;
        }
        if (maze[top.x][top.y] == 'G' && top.fighted == 0) {
            // ‘G’：陷阱
            int index = findTraps(top.x, top.y);
            short layout = top.layout & (~(1 << index));
            myqueues.push(point(top.x, top.y, top.keys, 1, top.steps + 1, layout));
            flags[top.x][top.y][top.keys][layout] = 1;
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int tx = top.x + dx[i];
            int ty = top.y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m)
                // 地图外
                continue;
            if (maze[tx][ty] == 'X')
                //‘X’：障碍，不能通过
                continue;
            else if (maze[tx][ty] == 'G') {
                // ‘G’：陷阱
                if (flags[tx][ty][top.keys][top.layout])
                    // 走过
                    continue;
                int index = findTraps(tx, ty);
                if ((top.layout >> index) & 1) // 还没打掉陷阱
                    myqueues.push(point(tx, ty, top.keys, 0, top.steps + 1, top.layout));
                else
                    myqueues.push(point(tx, ty, top.keys, 1, top.steps + 1, top.layout));
                flags[tx][ty][top.keys][top.layout] = 1;
            }
            else if (maze[tx][ty] == '.' || maze[tx][ty] == 'S' || maze[tx][ty] == 'T') {
                // ‘.’：平地；‘T’：终点；‘S’：起点
                if (flags[tx][ty][top.keys][top.layout])
                    continue;
                myqueues.push(point(tx, ty, top.keys, 0, top.steps + 1, top.layout));
                flags[tx][ty][top.keys][top.layout] = 1;
            }
            else {
                int key = maze[tx][ty] - '0';   // 当前的key
                if (key == top.keys + 1) {      // 下一把key
                    if (flags[tx][ty][key][top.layout])
                        continue;
                    myqueues.push(point(tx, ty, key, 0, top.steps + 1, top.layout));
                    flags[tx][ty][key][top.layout] = 1;
                }
                else {
                    if (flags[tx][ty][top.keys][top.layout])
                        continue;
                    myqueues.push(point(tx, ty, top.keys, 0, top.steps + 1, top.layout));
                    flags[tx][ty][top.keys][top.layout] = 1;
                }
            }
        }
    }
    return 0;
}
