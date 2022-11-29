// 4980:拯救行动
// http://noi.openjudge.cn/ch0205/4980/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 公主被恶人抓走，被关押在牢房的某个地方。牢房用N*M (N, M <= 200)的矩阵来表示。
// 矩阵中的每项可以代表道路（@）、墙壁（#）、和守卫（x）。 
// 英勇的骑士（r）决定孤身一人去拯救公主（a）。我们假设拯救成功的表示是“骑士到达了公主所在的位置”。
// 由于在通往公主所在位置的道路中可能遇到守卫，骑士一旦遇到守卫，必须杀死守卫才能继续前进。 
// 现假设骑士可以向上、下、左、右四个方向移动，
// 每移动一个位置需要1个单位时间，杀死一个守卫需要花费额外的1个单位时间。
// 同时假设骑士足够强壮，有能力杀死所有的守卫。

// 给定牢房矩阵，公主、骑士和守卫在矩阵中的位置，请你计算拯救行动成功需要花费最短时间。

// 输入
// 第一行为一个整数S，表示输入的数据的组数（多组输入）
// 随后有S组数据，每组数据按如下格式输入 
// 1、两个整数代表N和M, (N, M <= 200). 
// 2、随后N行，每行有M个字符。"@"代表道路，"a"代表公主，"r"代表骑士，"x"代表守卫, "#"代表墙壁。
// 输出
// 如果拯救行动成功，输出一个整数，表示行动的最短时间。
// 如果不可能成功，输出"Impossible"
// 样例输入
// 2
// 7 8
// #@#####@
// #@a#@@r@
// #@@#x@@@
// @@#@@#@#
// #@@@##@@
// @#@@@@@@
// @@@@@@@@ 
// 13 40
// @x@@##x@#x@x#xxxx##@#x@x@@#x#@#x#@@x@#@x
// xx###x@x#@@##xx@@@#@x@@#x@xxx@@#x@#x@@x@
// #@x#@x#x#@@##@@x#@xx#xxx@@x##@@@#@x@@x@x
// @##x@@@x#xx#@@#xxxx#@@x@x@#@x@@@x@#@#x@#
// @#xxxxx##@@x##x@xxx@@#x@x####@@@x#x##@#@
// #xxx#@#x##xxxx@@#xx@@@x@xxx#@#xxx@x#####
// #x@xxxx#@x@@@@##@x#xx#xxx@#xx#@#####x#@x
// xx##@#@x##x##x#@x#@a#xx@##@#@##xx@#@@x@x
// x#x#@x@#x#@##@xrx@x#xxxx@##x##xx#@#x@xx@
// #x@@#@###x##x@x#@@#@@x@x@@xx@@@@##@@x@@x
// x#xx@x###@xxx#@#x#@@###@#@##@x#@x@#@@#@@
// #@#x@x#x#x###@x@@xxx####x@x##@x####xx#@x
// #x#@x#x######@@#x@#xxxx#xx@@@#xx#x#####@
// 样例输出
// 13
// 7

#include<bits/stdc++.h>
using namespace std;
int dis[210][210];  //距离 
char mm[210][210]; //每个位置的状态 
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int main(){
	int n;
	cin>>n;		// n 表示测试数据组数
	while(n--){
		int r, c;	// 地图大小
		cin>>r>>c;
		int sx, sy, ex, ey;		// 分别表示起始和结束点位置
		memset(dis, 0x3f, sizeof(dis));  // 初始化为最大值
		memset(mm, 0, sizeof(mm));
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				cin>>mm[i][j]; //获取每个位置 
				if(mm[i][j]=='r') sx = i, sy = j, dis[i][j]=0; //起点 
				if(mm[i][j]=='a') ex = i, ey =j ; //终点 
			}
		}
		queue<pair<int, int>> q;	// 存储pair 对的队列
		q.push({sx,sy});	// 存储起点
		while(!q.empty()){	// 当队列不为空
			auto p = q.front(); //取出 
			q.pop(); //弹出 
			int x = p.first, y = p.second;	// 得到起点坐标
			for(int i = 0; i < 4; i++){ //寻找合适的点 
				int xx = x + dx[i], yy = y + dy[i];
				if(xx >= 1 && xx <= r && yy >= 1 && yy <= c){	// 在地图范围内
					if(mm[xx][yy] == '@' && dis[xx][yy] > dis[x][y] + 1){ //正常路径 
						q.push({xx,yy});
						dis[xx][yy] = dis[x][y] + 1;
					}
					if(mm[xx][yy] == 'a' && dis[xx][yy] > dis[x][y] + 1){ //公主 
						q.push({xx,yy});
						dis[xx][yy] = dis[x][y] + 1;
					}
					if(mm[xx][yy] == 'x' && dis[xx][yy] > dis[x][y] + 2){ //守卫 
						q.push({xx,yy});
						dis[xx][yy] = dis[x][y] + 2;
					}
				}
			}
		}
		if(dis[ex][ey]!= 0x3f3f3f3f)
			cout<<dis[ex][ey]<<endl; //输出 
		else
			cout<<"Impossible"<<endl;
	}
	return 0;
}
