// 晶矿的个数

// 在某个区域发现了一些晶矿，已经探明这些晶矿总共有分为两类，为红晶矿和黑晶矿。
// 现在要统计该区域内红晶矿和黑晶矿的个数。假设可以用二维地图m[][]来描述该区域，
// 若m[i][j]为#表示该地点是非晶矿地点，若m[i][j]为r表示该地点是红晶矿地点，
// 若m[i][j]为b表示该地点是黑晶矿地点。
// 一个晶矿是由相同类型的并且上下左右相通的晶矿点组成。
// 现在给你该区域的地图，求红晶矿和黑晶矿的个数。

// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行为k，表示有k组测试输入。 每组第一行为n，表示该区域由n*n个地点组成，
// 3 <= n<= 30 接下来n行，每行n个字符，表示该地点的类型。
// 输出
// 对每组测试数据输出一行，每行两个数字分别是红晶矿和黑晶矿的个数，一个空格隔开。
// 样例输入
// 2
// 6
// r##bb#
// ###b##
// #r##b#
// #r##b#
// #r####
// ######
// 4
// ####
// #rrb
// #rr#
// ##bb
// 样例输出
// 2 2
// 1 2


#include<bits/stdc++.h>
using namespace std;

struct node{        // 坐标
	int x, y;
};

int xarray[4] = { 1,0,-1,0 };		//  右  下  左  上
int yarray[4] = { 0,1,0,-1 };

void BFS( node start, char array[64][64], bool flag[64][64], char C1) {
    // start 起始点， array 地图信息，flag 是否访问，C1 晶矿类型
	queue<node>q;
	q.push(start);
	while (!q.empty()) {
		node temp = q.front();
		flag[temp.x][temp.y] = true;        // 已访问
		q.pop();
		node next;
		for (int i = 0; i < 4; i++){
			next.x = temp.x + xarray[i];
			next.y = temp.y + yarray[i];
			if (array[next.x][next.y] == C1 && !flag[next.x][next.y]){
				q.push(next);
			}
		}
	}
}

int main(){
	int numbers;	    // 测试数据组数
    cin >> numbers;     // 多少组测试数据
	while (numbers--){
		int js;         // 地图大小
        cin >> js;
		char array[64][64];
		for (int r = 0; r < 12; r++){
			fill(array[r], array[r] + 12, '#');
		}
	    //	对矿井的赋值
		for (int r = 1; r < js+1; r++){
			for (int c = 1; c < js+1; c++){
				cin >>array[r][c] ;     // 输入地图信息
			}
		}
		bool flag[64][64] = {false};
		int red = 0, black = 0;     // 红、黑晶矿的数量
		for (int r = 1; r < js+1; r++){
			for (int c = 1; c < js+1; c++){
				if (!flag[r][c] && array[r][c] == 'r'){
					red++;          // 红矿 + 1
					node A;         // 起始点
					A.x = r;
					A.y = c;
					BFS(A, array, flag, 'r');
				}
				else if (!flag[r][c] && array[r][c] == 'b'){
					black++;
					node A;
					A.x = r;
					A.y = c;
					BFS(A, array, flag, 'b');
				}
			}
		}
		cout << red << " " << black << endl;
	}
    return 0;
}

