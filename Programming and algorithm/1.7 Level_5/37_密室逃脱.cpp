// 14H:密室逃脱
// http://cxsjsx.openjudge.cn/practise2020pool/14H/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 小Y喜欢玩密室逃脱，每次游戏开始时，小Y会进入一个密室，她需要按照顺序解开各个隐藏线索才能成功逃脱密室。
// 小Y非常聪明，解开线索对她来说并不难，但是她有一点懒，她希望在通关过程中移动次数最少。请你帮小Y计算她至少要移动多少次才能成功通关。
// 密室是m行n列的格子矩阵，小Y从左上角(1,1)进入密室，密室中有三种格子:
// 墙，以数字0标记
// 路，以数字1标记
// 隐藏线索处，以数字( > 1)标记, 代表该线索的难度 

// 小Y需要按照难度递增的顺序解开各个线索，逃脱密室。

// 输入
// 第一行是一个整数 T，表示输入包含 T 组数据，分别是不同的游戏中小Y所处的密室。

// 对于每组数据，第一行包括两个整数：m（1 <= m <= 100）、n（1 <= n <= 100）。

// 接下来 m 行，每行有n个数字，第 i 行的第 j 个数字表示密室中第 i 行第 j 列的格子的类型。

// 题目保证进入密室处(1,1)不是墙壁，线索的难度都不相同。
// 输出
// 对于每组数据，你需要输出一个整数，表示小Y在这个密室中至少要移动多少次才能成功通关。

// 如果小Y不可能解开所有线索，输出-1.
// 样例输入
// 2
// 3 3
// 1 3 2
// 1 0 4
// 10 6 5
// 3 3
// 1 3 2
// 0 0 0
// 10 6 5
// 样例输出
// 8
// -1
// 提示
// 样例解释：由于需要按难度顺序解开线索，在第一组数据中，小Y第一次移动到3时不能解密，在完成2之后需要回到3.最后小Y解开10时，她成功通关。
// 来源
// 李拙

// 题解

// 用坐标+线索数表示状态，但是空间和时间都不够……其实每一层（线索数）不需要搜完，每种线索只有一个，先到肯定更好。
// 只用开一个100*100的数组记录当前线索数下该点是否来过，用一个key来记录当前的线索数，每次找到下一个线索就更新key，
// 把o数组都置成0，小于key的点都不用搜了

#include<bits/stdc++.h>
using namespace std;
int a[110][110], tot, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, n, m, key;
using P = pair <int, int>;
P num[10010];
bool ol[110][110];
bool compare(P x, P y)
{
    return a[x.first][x.second] < a[y.first][y.second];
}
struct point
{
    int x, y, key, dis;
    point(int x, int y, int key, int dis): x(x), y(y), key(key), dis(dis){}
    point(){}
};
bool ok(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y])
    {
        return 1;
    }
    return 0;
}
int bfs()
{
    queue <point> q;
    point t;
    int tx, ty, tk = 1;
    tk = a[0][0] == 2 ? 2 : 1;
    q.push(point(0, 0, tk, 0));
    ol[0][0] = 1;
    key = tk;
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        if (t.key == tot + 1)
        {
            return t.dis;
        }
        if (t.key < key)
        {
            continue;
        }
        for (int i = 0; i < 4; ++i)
        {
            tx = t.x + dx[i];
            ty = t.y + dy[i];
            if (ok(tx, ty))
            {
                tk = t.key;
                if (a[tx][ty] == t.key + 1)
                {
                    key = tk = a[tx][ty];
                    memset(ol, 0, sizeof(ol));
                    q.push(point(tx, ty, tk, t.dis + 1));
                    ol[tx][ty] = 1;
                    break;
                }
                if (!ol[tx][ty])
                {
                    q.push(point(tx, ty, tk, t.dis + 1));
                    ol[tx][ty] = 1;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int t, i, j;
    scanf("%d", &t);
    while (t--)
    {
        tot = 0;
        memset(ol, 0, sizeof(ol));
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                scanf("%d", &a[i][j]);
                if (a[i][j] > 1)
                {
                    num[tot++] = make_pair(i, j);
                }
            }
        }
        sort(num, num + tot, compare);
        for (i = 0; i < tot; ++i)
        {
            a[num[i].first][num[i].second] = i + 2;
        }
        printf("%d\n", bfs());
    }
    return 0;
}