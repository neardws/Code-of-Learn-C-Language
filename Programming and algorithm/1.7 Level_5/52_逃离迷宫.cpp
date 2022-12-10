// 逃离迷宫

// 你在一个地下迷宫中找到了宝藏，但是也触发了迷宫机关，
// 导致迷宫将在T分钟后坍塌，为此你需要在T分钟内逃离迷宫，
// 你想知道你能不能逃离迷宫。
// 迷宫是一个边长为m的正方形，其中"S"表示你所在的位置，
// "E"表示迷宫出口，"."是可以随意走动的区域，"#"是不可穿行的墙壁，
// 每次你可以耗费1分钟在区域间移动（上下左右四个方向）。
// 时间限制：1000
// 内存限制：65536
// 输入
// 输入包含多组数组，第一行是一个整数K（1 <= K <= 10)，表示有K组数据。
// 接下来每组数组包含整数m(2<=m<=10)和整数T，m表示正方形迷宫的边长，
// T表示坍塌时间。其后是一个m*m的字符矩阵，包含字符"S", "E", "."和"#"。
// 输出
// 每组数据输出一行，输出“YES"或者"NO"，表示是否可以在坍塌之前逃离
// （也就是说移动次数是否可以不超过T）。
// 样例输入
// 2
// 4 7 
// S...
// ###.
// .#E.
// ..#.	
// 3 4
// S..
// ..#
// .#E
// 样例输出
// YES
// NO

#include<bits/stdc++.h>
using namespace std;

struct node{    // 结构体，当前位置和步数
	int x, y, step;
};

int xarray[4] = { 1, 0, -1, 0 };		//  右  下  左  上
int yarray[4] = { 0, 1, 0, -1 };

// start 起始节点，end 结束节点，array
void BFS(node start, node& end, char array[12][12], bool flag[20][20]) {
	queue<node> q;      // 队列
	q.push(start);      // 起点入队
	while(!q.empty()){     
		node temp = q.front();
		if (temp.x == end.x && temp.y == end.y){    // 到达终点
			end.step = temp.step;
			break;
		}
		else{
			q.pop();
			node next;
			for (int i = 0; i < 4; i++){
				next.x = temp.x + xarray[i];    
				next.y = temp.y + yarray[i];
				if (array[next.x][next.y] != '#' && !flag[next.x][next.y]){
                    // 新位置不为墙 且 未访问
					next.step = temp.step + 1;
					q.push(next);
					flag[next.x][next.y] = true;
				}
			}
		}
	}
}

int main(){
	int numbers;	    // 测试数据组数
    cin >> numbers;
	while (numbers--) {
		int js; 
        cin >> js;      // 地图边长
		int time;	
        cin >> time;    // 剩余时间
		bool flag[20][20] = { false };
		node start;     // 开始节点
		node end;       // 结束节点
		char array[12][12];     // 地图信息
		for (int r = 0; r < 12; r++) {
			fill(array[r], array[r] + 12, '#');
		}
		//	对迷宫的赋值
		for (int r = 1; r < js + 1; r++){
			for (int c = 1; c < js + 1; c++){
				cin >> array[r][c];
				if (array[r][c] == 'S'){    // 起始点
					start.x = r;	
                    start.y = c;	
                    start.step = 0;
				}
				if (array[r][c] == 'E'){    // 结束点
					end.x = r;	
                    end.y = c; 
                    end.step = 0;
				}
			}
		}
		BFS(start, end, array, flag);
		if (end.step != 0 && end.step <= time)
			cout << "YES";
		else
			cout << "NO";
	}
}

