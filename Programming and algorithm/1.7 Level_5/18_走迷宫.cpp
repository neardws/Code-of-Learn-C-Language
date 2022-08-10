// 2753:走迷宫
// http://noi.openjudge.cn/ch0205/2753/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 一个迷宫由R行C列格子组成，有的格子里有障碍物，不能走；有的格子是空地，可以走。
// 给定一个迷宫，求从左上角走到右下角最少需要走多少步(数据保证一定能走到)。只能在水平方向或垂直方向走，不能斜着走。
// 输入
// 第一行是两个整数，Ｒ和Ｃ，代表迷宫的长和宽。（ 1<= R，C <= 40)
// 接下来是Ｒ行，每行Ｃ个字符，代表整个迷宫。
// 空地格子用'.'表示，有障碍物的格子用'#'表示。
// 迷宫左上角和右下角都是'.'。
// 输出
// 输出从左上角走到右下角至少要经过多少步（即至少要经过多少个空地格子）。计算步数要包括起点和终点。
// 样例输入
// 5 5
// ..###
// #....
// #.#.#
// #.#.#
// #.#..
// 样例输出
// 9


#include<bits/stdc++.h>
using namespace std;
int r,c,f[100][100],minc=1000;
char a[100][100];
const int d[4][4]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y,int cur){
    if(x==r&&y==c) { if (cur<minc) minc=cur; return;}
    for(int i=0;i<=3;i++){
        int xx=x+d[i][0],yy=y+d[i][1];
        if(a[xx][yy]&&!f[xx][yy]) {
            f[xx][yy]=1;
            dfs(xx,yy,cur+1);
            f[xx][yy]=0;
        }
    }
}
int main(){
    cin>>r>>c;
    char ch;
    memset(a,0,sizeof(a));//0代表不能通过，这样相当于在外圈加了一圈边界。
    memset(f,0,sizeof(f));
    for(int i=1;i<=r;i++)
        for (int j=1;j<=c;j++){
            cin>>ch;
            if (ch=='.') a[i][j]=1;
        }
    f[1][1]=1;
    dfs(1,1,1);
    cout<<minc<<endl;
    return 0;
}