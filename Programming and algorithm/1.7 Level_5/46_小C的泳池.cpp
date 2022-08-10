// G:小C的泳池
// http://cxsjsx.openjudge.cn/2021finalpractise/G/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 小C在一个排水系统不太好的学校上学。又是一个下雨天，学校里高低不平积了很多水。
// 小C突发奇想：如果大雨一直下，多久以后我可以在学校里游泳呢？

// 学校是 N x N 的坐标方格 grid 中，每一个方格的值 grid(i,j)表示在位置 (i,j) 的高度。
// 现在开始下雨了。当时间为 t 时，此时雨水导致方格中任意位置的水位为 t 。
// 你可以从一个方格游向四周相邻的任意一个方格，但是前提是此时水位必须同时淹没这两个方格。假定小C的游动是不耗时的。

// 现在小C从坐标方格的左上(0,0)出发。最少耗时多久他才能到达坐标方格的右下平台 (N-1, N-1)？
// 输入
// 第一行有一个整数N，以下是一个N*N的方阵，代表各处的高度。
// 输入范围：
// 2 ≤ N ≤ 300
// 0 ≤ Height ≤ 10000000
// 输出
// 输出一个整数，代表最少等待时间T
// 样例输入
// 样例输入1：
// 2
// 0 2
// 1 3

// 样例输入2：
// 5
// 0 1 2 3 4
// 24 23 22 21 5
// 12 13 14 15 16
// 11 17 18 19 20
// 10 9 8 7 6
// 样例输出
// 样例输出1：
// 3

// 样例输出2：
// 16
// 提示
// 样例1：时间为3时，才可以游向平台(1,1)，此时水位为3。
// 样例2：时间为16时，水位为16，此时才能保证(0,0)和(4,4)是联通的（请自行找出一条通路）。


// 这道题长着迷宫的样子，但是与迷宫无关，转换一下题意，问的就是从（0，0）到（N-1，N-1）的各条路径最大值中的最小值。

// 一开始尝试了深搜和广搜但是都TLE了，试图使用记忆性递归式的动态规划，但是此处不能用动态规划，因为不满足无后效性，不同的路径最大值不同。

// 这道题正确的思路是用二分来做，L是方格中的最小值，R是最大值，二分尝试能否到达右下角。

#include<bits/stdc++.h>
using namespace std;
int maze[305][305];
bool reach[305][305];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N;
struct point {
    int x, y;
    point(int a,int b):x(a),y(b){}
};
bool canreach(int t) {
    if (maze[0][0] > t)
        return false;
    memset(reach, 0, sizeof(reach));
    reach[0][0] = 1;
    queue<point>myqueues;
    myqueues.push(point(0, 0));
    while (!myqueues.empty()) {
        point top = myqueues.front();
        myqueues.pop();
        if (top.x == N - 1 && top.y == N - 1)
            return true;
        for (int i = 0; i < 4; i++) {
            int tx = top.x + dx[i];
            int ty = top.y + dy[i];
            if (tx < 0 || tx >= N || ty < 0 || ty >= N)
                continue;
            if (reach[tx][ty])
                continue;
            if (maze[tx][ty] > t)
                continue;
            reach[tx][ty] = 1;
            myqueues.push(point(tx, ty));
        }
    }
    return false;
}
int main() {
    memset(maze, 0, sizeof(maze));
    cin >> N;
    int L = 10000000, R = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
            L = min(maze[i][j], L);
            R = max(maze[i][j], R);
        }
    }
    int result= 10000000;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (canreach(mid)) {
            R = mid - 1;
            result = min(result, mid);
        }
        else
            L = mid + 1;
    }
    cout << result << endl;
    return 0;
}