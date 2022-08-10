// 6044:鸣人和佐助
// http://noi.openjudge.cn/ch0205/6044/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述

// 佐助被大蛇丸诱骗走了，鸣人在多少时间内能追上他呢？
// 已知一张地图（以二维矩阵的形式表示）以及佐助和鸣人的位置。
// 地图上的每个位置都可以走到，只不过有些位置上有大蛇丸的手下，需要先打败大蛇丸的手下才能到这些位置。
// 鸣人有一定数量的查克拉，每一个单位的查克拉可以打败一个大蛇丸的手下。
// 假设鸣人可以往上下左右四个方向移动，每移动一个距离需要花费1个单位时间，打败大蛇丸的手下不需要时间。
// 如果鸣人查克拉消耗完了，则只可以走到没有大蛇丸手下的位置，不可以再移动到有大蛇丸手下的位置。
// 佐助在此期间不移动，大蛇丸的手下也不移动。请问，鸣人要追上佐助最少需要花费多少时间？

// 输入
// 输入的第一行包含三个整数：M，N，T。代表M行N列的地图和鸣人初始的查克拉数量T。0 < M,N < 200，0 ≤ T < 10
// 后面是M行N列的地图，其中@代表鸣人，+代表佐助。*代表通路，#代表大蛇丸的手下。
// 输出
// 输出包含一个整数R，代表鸣人追上佐助最少需要花费的时间。如果鸣人无法追上佐助，则输出-1。
// 样例输入
// 样例输入1
// 4 4 1
// #@##
// **##
// ###+
// ****

// 样例输入2
// 4 4 2
// #@##
// **##
// ###+
// ****
// 样例输出
// 样例输出1
// 6

// 样例输出2
// 4

#include<bits/stdc++.h>
using namespace std;
int row, col, orin, sx, sy;//行，列，起始查克拉数，鸣人起始横坐标，纵坐标
int minstep = 0x3f3f3f3f;
int step[205][205][15];
/*三维数组记录（鸣人所在的横坐标，纵坐标，以及剩余的查克拉数量）
某状态的已经走了的步数的最小值*/
char map[205][205];//整个地图
int visited[205][205];//标记数组
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };//方向数组
void dfs(int x, int y, int n, int nowstp) {
	if (x<1 || x>row || y<1 || y>col || visited[x][y]) return;
	if (nowstp >= minstep || nowstp >= step[x][y][n] || n < 0) return; //剪枝
	step[x][y][n] = nowstp;//更新step
	if (map[x][y] == '#') n--;//消耗查克拉
	else if (map[x][y] == '+') {//深搜终止条件
		if (nowstp < minstep) minstep = nowstp;
		return;
	}
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {//向各个方向进行深搜
		int nowx = x + dx[i];
		int nowy = y + dy[i];
		dfs(nowx, nowy, n, nowstp + 1);
	}
	visited[x][y] = 0;//回溯，换条路
}
int main() {
	cin >> row >> col >> orin;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> map[i][j];
			if (map[i][j] == '@') sx = i, sy = j;//找到起始坐标
		}
	}
	memset(step, 0x3f, sizeof(step));
	dfs(sx, sy, orin, 0);
	if (minstep == 0x3f3f3f3f) cout << "-1" << endl;
	else cout << minstep << endl;
	return 0;
}
