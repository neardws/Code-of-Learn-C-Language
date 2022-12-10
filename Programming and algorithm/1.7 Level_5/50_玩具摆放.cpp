// 玩具摆放
// 在一个4*4的方框内摆放了若干个相同的玩具。

// 某人想通过移动玩具，将这些玩具重新摆放成为他心中理想的状态。
// 要求每次移动时，只能将某一个玩具向上下左右四个方向之一移动一步。
// 不能将玩具移出方框，并且移动的目标位置不能已经放置有玩具。
// 请你用最少的移动次数将初始的玩具状态移动到他心中的目标状态。

// 时间限制：10000
// 内存限制：524288

// 输入
// 前 4 行表示玩具的初始状态，每行 4个数字 1 或 0，1 表示方格中放置了玩具，
// 0 表示没有放置玩具。 接着是一个空行。接下来 4 行表示玩具的目标状态，
// 每行 4 个数字 1 或 0，意义同上。

// 输出
// 一个整数，所需要的最少移动次数。保证初始状态可以达到目标状态。

// 样例输入
// 1111
// 0000
// 1110
// 0010

// 1010
// 0101
// 1010
// 0101

// 样例输出
// 4
// 提示
// 可以考虑将玩具局面表示为一个16 bit的整数，
// 设置一个标志数组用来判重，用这个整数做下标找其对应标志位

#include<bits/stdc++.h>
using namespace std;

const int dx[5]={0,0,0,1,-1};   // 4 个方向
const int dy[5]={0,1,-1,0,0};
const int n = 4;
bool goal[5][5];    // 目标状态
int vis[65536];
struct state{
    bool board[5][5]; 
    int step;
}start;             // 起始状态
queue<state> Q;     // 队列

// 内联函数，判断是否结束
inline bool is_finished(state tmp){
    register int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(goal[i][j]^tmp.board[i][j]) // 异或
                return 0;
    return 1;
}

// 内联函数，将当前状态映射到 int 整型数
inline int change(state tmp){
    register int i, j;
    int res = 0;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            res = (res << 1) | tmp.board[i][j];  
    return res;
}

inline int BFS(){
    memset(vis, 0x3f3f3f3f, sizeof(vis));
    Q.push(start);        // 起始位置入队
    while(!Q.empty()){    // 队列不为空
        state now = Q.front();  // 取队首
        Q.pop();                // 出队
        if(is_finished(now))    // 是否结束
            return now.step;    
        int BIN = change(now);
        if(vis[BIN] <= now.step)
            continue;
        vis[BIN] = now.step;
        register int i, j, k;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                for(k = 1; k <= 4; k++){
                    if(i + dx[k] > n || j + dy[k] > n || i + dx[k] < 1 || j + dy[k] < 1)
                        // 在地图外
                        continue;
                    if(now.board[i][j] == now.board[i + dx[k]][j + dy[k]])
                        // 已有玩具 或 均为空
                        continue;
                    swap(now.board[i][j], now.board[i + dx[k]][j + dy[k]]);
                    // 交换位置
                    now.step ++;    // 步骤+1
                    Q.push(now);    // 入队
                    now.step --;    // 回溯
                    swap(now.board[i][j], now.board[i + dx[k]][j + dy[k]]);
                    // 交换回来
                }
    }
    return -1;
}

int main(){
    register int i, j;  // i, j 会频繁调用
    start.step = 0;
    // 输入初始状态
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++){
            char tmp;
            cin>>tmp;
            start.board[i][j] = (tmp == '0') ? 0 : 1;
        }
    // 输入目标状态
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++){
            char tmp;
            cin>>tmp;
            goal[i][j] = (tmp == '0') ? 0 : 1;
        }
    cout<<BFS()<<endl;
    return 0;
}
