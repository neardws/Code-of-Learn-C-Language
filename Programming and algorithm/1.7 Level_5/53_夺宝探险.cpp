// 夺宝探险

// 你无意中发现了装满了宝藏的迷宫，你想要获得尽可能多的宝藏，
// 但是迷宫里的机关阻碍了你的计划。迷宫的地面是M行N列的矩形网格，
// 每格是一块带有机关且放置了1个宝藏的地砖，宝藏一共有K种，用1-K表示其种类，
// 迷宫的入口只有一个，为迷宫的第一行第一列。地砖的机关如下：
// 1. 每次你只能踏到你与你所在地砖相邻的地砖上（即前后左右4块）；
// 2. 当你踏上某块地砖后，其上的宝藏（假设种类为k）自动归属你，
// 同时所有放置了种类为 k 的宝藏的地砖碎裂，你无法踏上，
// 你当前所在的地砖在你离开后也会立刻碎裂；
// 3. 当你无路可走的时候，你会被传送回迷宫出口，无法再进入迷宫。
// 你想知道你最多能获得多少宝藏。
// 时间限制：1000
// 内存限制：65536
// 输入
// 输入的第一行是三个用空格隔开的整数，
// 分别是M、N和K（1 <= M,N <= 20, 1 <= K <= 100） 
// 之后是M行，每行包含N个范围为1-K的整数，用空格隔开，表示放置的宝藏种类
// 输出
// 只有一行，为一个整数，表示最多能获得的宝藏个数。
// 样例输入
// 3 4 5
// 1 2 3 3
// 2 1 4 3
// 1 5 1 2
// 样例输出
// 4

#include<bits/stdc++.h>
using namespace std;
int x_i[4] = { 1, 0, -1, 0 };
int y_i[4] = { 0, 1, 0, -1 };
bool flag[100];
int ay[100][22];
void dfs(int x, int y, int& max_, int now) {
    // 状态为 当前位置，能获得的宝藏最大值，
	for (int i = 0; i < 4; i++){
		int x1 = x + x_i[i];
		int y1 = y + y_i[i];
		if (!flag[ay[x1][y1]]){
			flag[ay[x1][y1]] = true;	// 当前这个宝藏取了
			dfs(x1, y1, max_, now+1);
			flag[ay[x][y]] = false;
		}
	}
	max_ = max(max_, now);
}
int main() {
	int m, n, K;    // m, n 表示地图大小，K 表示宝藏种类
	int max_ = 1;   // 最多能获得的宝藏数量
	int now = 1;
	cin >> m >> n >> K;
	for (int i = 1; i <= m; i++)
		for (int c = 1; c <= n; c++)
			cin >> ay[i][c];
	flag[ay[1][1]] = true;	// 第一个宝藏必拿
	flag[0] = true;
	dfs(1, 1, max_, now);
	cout << max_;
}
