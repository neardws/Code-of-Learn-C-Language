// 1998:寻找Nemo
// http://noi.openjudge.cn/ch0205/1998/
// 总时间限制: 2000ms 内存限制: 65536kB
// 描述
// Nemo 是个顽皮的小孩. 一天他一个人跑到深海里去玩. 可是他迷路了. 于是他向父亲 Marlin 发送了求救信号.
// 通过查找地图 Marlin 发现那片海像一个有着墙和门的迷宫.所有的墙都是平行于 X 轴或 Y 轴的. 
// 墙的厚度可以忽略不计.所有的门都开在墙上并且长度为1. Marlin 只能穿过有门的墙. 
// 因为穿过墙是有危险的 (门旁可能会藏有巨毒的水母), Marlin 想穿过尽量少的门找到 Nemo.
// 图-1 显示了一个迷宫的样例及 Marlin 找到 Nemo的路线.

// 我们假设 Marlin 的初始位置在 (0, 0). 给定 Nemo 的位置和墙及门的位置情况,请你写一个程序计算 Marlin 要找到 Nemo最少要穿过多少道门.
// 输入
// 输入有多组测试数据. 每组测试数据以两个非零整数 M 和 N 开始. M 表示迷宫中墙的数目, N 表示门的数目. 
// 接下来有 M 行, 每行包含四个整数描述一堵墙,其格式如下: 
// x y d t 
// (x, y) 表示墙的左下角, d 是墙的方向 -- 0 表示它与 X-轴平行, 1 表示它与 Y-轴平行, t 表示墙的长度. 墙的两个顶点坐标在[1,199]. 
// 接下来有 N 行,用来描述门的情况: 
// x y d 
// x, y, d 与门的描述含义相同. 因为门的长度是 1, t 被省略了. 
// 每组测试数据的最后一行包含两个正的浮点数: 
// f1 f2 
// (f1, f2) 给出了 Nemo 的位置. 它不在墙和门上.
// 输出
// 对于每组测试数据，输出一行，该行包含 Marlin 找到 Nemo需要穿过的最少的门数. 如果他不可能找到 Nemo, 输出 -1.
// 样例输入
// 8 9
// 1 1 1 3
// 2 1 1 3
// 3 1 1 3
// 4 1 1 3
// 1 1 0 3
// 1 2 0 3
// 1 3 0 3
// 1 4 0 3
// 2 1 1
// 2 2 1
// 2 3 1
// 3 1 1
// 3 2 1
// 3 3 1
// 1 2 0
// 3 3 0
// 4 3 1
// 1.5 1.5
// 4 0
// 1 1 0 1
// 1 1 1 1
// 2 1 1 1
// 1 2 0 1
// 1.5 1.7
// -1 -1
// 样例输出
// 5
// -1
// 来源
// Beijing 2004 English 2049

#include<bits/stdc++.h>
using namespace std;
//[0]: up [1]:down [2]:left [3]:right
//1:wall 2:door 0:void
int ans,F[4][2]={{-1,0},{1,0},{0,-1},{0,1}},walked[220][220],r,c;
double Nemox, Nemoy;
struct MAZE{int Around[4];} maze[220][220],Clear;
void flag(int x,int y,int tot)
{
    if(x==(int)Nemox && y==(int)Nemoy)
    {
        ans=min(ans,tot);
        return;
    }
    if(walked[x][y]<=tot && walked[x][y]!=-1) return;
    walked[x][y]=tot;
    for(int i=0;i<4;i++)
    {
        int sx=x+F[i][0],sy=y+F[i][1];
        if(sx<0 || sx>=r || sy<0 || sy>=c) continue;
        if(maze[x][y].Around[i]==2) flag(sx,sy,tot+1);
        if(maze[x][y].Around[i]==0) flag(sx,sy,tot);
    }
}
int main()
{
    memset(Clear.Around,0,sizeof(Clear.Around));
    while(true)
    {
        for(int i=0;i<220;i++)
            for(int j=0;j<220;j++)
                maze[i][j]=Clear;
        memset(walked,-1,sizeof(walked));
        r=c=-1e8;
        ans=1e8;
        int Wall,Door;
        scanf("%d%d",&Wall,&Door);
        if(Wall==-1 && Door==-1) break;
        for(int i=0;i<Wall;i++) //Set The Wall
        {
            int x,y,Long,f;
            scanf("%d%d%d%d",&x,&y,&f,&Long);
            for(int j=0;j<Long;j++)
                if(f)
                {
                    maze[x][y+j].Around[0]=1;
                    if(x-1>=0) maze[x-1][y+j].Around[1]=1;
                    c=max(c,y+j+8);
                }
                else
                {
                    maze[x+j][y].Around[2]=1;
                    if(y-1>=0) maze[x+j][y-1].Around[3]=1;
                    r=max(x,x+j+8);
                }
        }
        for(int i=0;i<Door;i++) //Set The Door
        {
            int x,y,f;
            scanf("%d%d%d",&x,&y,&f);
            if(f)
            {
                maze[x][y].Around[0]=2;
                if(x-1>=0) maze[x-1][y].Around[1]=2;
                c=max(c,y+8);
            }
            else
            {
                maze[x][y].Around[2]=2;
                if(y-1>=0) maze[x][y-1].Around[3]=2;
                r=max(x,x+8);
            }
        }
        scanf("%lf%lf",&Nemox,&Nemoy);
        if(Nemox<0 || Nemox>=200 || Nemoy<0 || Nemoy>=200)
        {
            printf("0\n");
            continue;
        }
        r=max(r,(int)Nemox+8);c=max(c,(int)Nemoy+8);
        flag(0,0,0);
        printf("%d\n",ans==1e8? -1:ans);
    }
    return 0;
}