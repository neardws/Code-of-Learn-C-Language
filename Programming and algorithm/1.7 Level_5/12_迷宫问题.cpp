// 7084:迷宫问题
// http://noi.openjudge.cn/ch0205/7084/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 定义一个二维数组： 

// int maze[5][5] = {

// 0, 1, 0, 0, 0,

// 0, 1, 0, 1, 0,

// 0, 0, 0, 0, 0,

// 0, 1, 1, 1, 0,

// 0, 0, 0, 1, 0,

// };

// 它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。



// 输入
// 一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
// 输出
// 左上角到右下角的最短路径，格式如样例所示。
// 样例输入
// 0 1 0 0 0
// 0 1 0 1 0
// 0 0 0 0 0
// 0 1 1 1 0
// 0 0 0 1 0
// 样例输出
// (0, 0)
// (1, 0)
// (2, 0)
// (2, 1)
// (2, 2)
// (2, 3)
// (2, 4)
// (3, 4)
// (4, 4)



#include<bits/stdc++.h>
using namespace std;
struct aa
{
	int x,y,f;
}q[123];
int main()
{
	int i,k=0,j,tx,ty,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},head=0,tail=1,a[5][5],v[5][5]={0},answer[30][3];
	for(i=0;i<=4;i++)
        for(j=0;j<=4;j++)
            cin>>a[i][j];
	q[1].x=0;
	q[1].y=0;
	q[1].f=0;
	v[0][0]=1;
	head=0;
	tail=1;
	while(head<tail)
	{
		head++;
		for(i=0;i<4;i++)
		{
			tx=dx[i]+q[head].x;
			ty=dy[i]+q[head].y;
			if(tx>=0&&ty>=0&&tx<=4&&ty<=4&&a[tx][ty]!=1&&v[tx][ty]==0)
			{
				tail++;
				q[tail].x=tx;
				q[tail].y=ty;
				q[tail].f=head;
				v[tx][ty]=1;
				if(tx==4&&ty==4)
				{
					while(tail!=0)
					{
						k++;
						answer[k][1]=q[tail].x;
						answer[k][2]=q[tail].y;
						tail=q[tail].f;
					}
					for(j=k;j!=0;j--)
					{
						printf("(%d, %d)",answer[j][1],answer[j][2]);
						cout<<endl;
					}
					return 0;
				}
			}
		}
	}
}
