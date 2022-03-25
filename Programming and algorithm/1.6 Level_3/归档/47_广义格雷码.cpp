// 广义格雷码
// 在一组数的编码中，若任意两个相邻（首尾也视为相邻）的代码只有一位二进制数不同，则称这种编码为格雷码。如四位格雷码：

// 0000、0001、0011、0010、0110、0111、0101、0100、1100、1101、1111、1110、1010、1011、1001、1000

// 现在将格雷码扩展至其他进制，仍然是相邻两个数只能有一位不同。
// 输入两个正整数n,m分别表示长度和进制，
// 每行输出一个n位m进制数，输出任意一种编码即可。
// （提示：putchar输出效率更高）

// 时间限制：1000
// 内存限制：65536
// 输入
// 一行，两个整数n,m。其中 2 ≤ n ≤ 12 ,2 ≤ m ≤ 10 且mn ≤ 500000
// 输出
// 任意一种编码方案，每个编码一行。相邻两个编码相差一位。第一个编码和最后一个编码算相邻
// 样例输入
// 2 3
// 样例输出
// 00
// 10
// 20
// 21
// 01
// 11
// 12
// 22
// 02

#include<bits/stdc++.h>
using namespace std;
string  a[12][50010];	// 存储蛇形矩阵
bool flag[12][50010];	// 表示是否已经输出
queue<string> q;
int n,m;

int main(){
	cin>>n>>m;   	// n为长度，m为进制
	string temp = "";	// 临时存储
	if(n==1){		//n为1的时候
		for(int i=0; i<m; i++){
			cout<<i<<endl;
		}
		return 0;
	}
	//n大于2的时候 
	for(int i=0; i<m; i++){
		q.push(temp+char(i+48));	//i=0,把字符0入队, 48 为字符0的ASCII码
	}
	for(int time=2; time<=n; time++){
		memset(flag, 0, sizeof(bool)*12*50010);	//每次清空
		int size=q.size(),l=0;	//l这里赋值0  因为要从1开始 
		while(!q.empty()){
			a[0][++l]=q.front();
			cout<<a[0][l]<<endl;
			q.pop();
		}
		//复制一份 其他行数的
		for(int i=1;i<m;i++){
			for(int j=1;j<=size;j++){
				a[i][j]=a[0][j];
			}
		}
		// // show
		for(int i=0;i<m;i++){
			for(int j=1;j<=size;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}	 
		//添加前面一个值: 0 至 (m-1) 
		for(int i=0;i<m;i++){
			for(int j=1;j<=size;j++){
				a[i][j]=char(i+48)+a[i][j];
				flag[i][j]=true;
			}
		}
		// // show
		for(int i=0;i<m;i++){
			for(int j=1;j<=size;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		//蛇形取值
		int t=size*m;//t表示当前总个数 
		//保存第一行到q队列中 
		for(int i=1;i<=size;i++){
			q.push(a[0][i]);
			flag[0][i]=false;
			t--;
		}
		int x=0,y=size;
		while(t>0){
			while(flag[x+1][y]&&t>0){
				flag[++x][y]=false;
				q.push(a[x][y]);t--;
			}//向下 
			if(flag[x][y-1]&&t>0){
				flag[x][--y]=false;
				q.push(a[x][y]);t--;
			}//向左一位 
			while(flag[x-1][y]&&t>0){
				flag[--x][y]=false;
				q.push(a[x][y]);t--;
			}//向上
			if(flag[x][y-1]&&t>0){
				flag[x][--y]=false;
				q.push(a[x][y]);t--;
			}//再向左一位 
		}
	}
	//输出 
	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}	
	return 0;
} 

