// 11C:寻找边缘
// http://cxsjsx.openjudge.cn/practise2020pool/11C/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 给定一张 R*C 的地图，由 "X" 和 "O" 组成。

// 现在需要重新处理这张地图，找到地图边缘的那些 "O"。你需要将这些地图边缘上的 "O" 保留下来，然后将其他的 "O" 全部替换为 "X"。

// 地图边缘的 "O" 指的是那些处于第一行/列或最后一行/列上的 "O"，以及从这些 "O" 的相邻位置（上下左右）延伸出去的 "O"。

// 输入
// 第一行是一个正整数 T，表示一共有 T 组数据。
// 对于每组数据，其第一行是两个正整数 R 和 C，表示地图的大小，用一个空格分开。
// 接下来的 R 行，每行包含了 C 个字符，分别是 "X" 或 "O"。
// 其中，0 < T <= 10，0 < R, C <= 500。
// 输出
// 对于每组数据，输出 R 行，每行包含了 C 个字符，分别是 "X" 或 "O"。
// 每组数据之间需要额外输出一个空行。
// 样例输入
// 2
// 2 3
// OXX
// XXO
// 5 5
// XXXOX
// XXXOX
// XOOXX
// XXOXX
// XOXXX
// 样例输出
// OXX
// XXO

// XXXOX
// XXXOX
// XXXXX
// XXXXX
// XOXXX

// 用了比较取巧的办法，就是先把边缘的O暂时用?替代，这样就跟内部的O区别开，处理起来很方便，也不用visited数组了

#include<bits/stdc++.h>
using namespace std;
int r, c;
char a[505][505];
int dirx[4] = {0,0,1,-1};
int diry[4] = {1,-1,0,0};
void dfs(int x,  int y){
    for(int i = 0; i < 4; i++){
        int nx = x+dirx[i];
        int ny = y+diry[i];
        if(a[nx][ny]=='O'){
            a[nx][ny] = '?';
            dfs(nx, ny);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>r>>c;
        int i, j;
        for(i = 1; i <= r; i++)
            for(j = 1; j <= c; j++)
                cin>>a[i][j];
        for(i = 1; i <= r; i++){
            if(a[i][1]=='O'){
                a[i][1] = '?';
                dfs(i, 1);
            }
            if(a[i][c]=='O'){
                a[i][c] = '?';
                dfs(i, c);
            }
        }
        for(i = 1; i <= c; i++){
            if(a[1][i]=='O'){
                a[1][i] = '?';
                dfs(1, i);
            }
            if(a[r][i]=='O'){
                a[r][i] = '?';
                dfs(r, i);
            }
        }
        for(i = 1; i <= r; i++){
            for(j = 1; j <= c; j++){
                if(a[i][j]=='?')cout<<'O';
                else cout<<'X';
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}