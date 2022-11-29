// 4110:圣诞老人的礼物-Santa Clau’s Gifts
// http://bailian.openjudge.cn/practice/4110/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 圣诞节来临了，在城市A中圣诞老人准备分发糖果，现在有多箱不同的糖果，每箱糖果有自己的价值和重量，
// 每箱糖果都可以拆分成任意散装组合带走。圣诞老人的驯鹿最多只能承受一定重量的糖果，
// 请问圣诞老人最多能带走多大价值的糖果。

// 输入
// 第一行由两个部分组成，分别为糖果箱数正整数n(1 <= n <= 100)，驯鹿能承受的最大重量正整数w（0 < w < 10000），两个数用空格隔开。
// 其余n行每行对应一箱糖果，由两部分组成，分别为一箱糖果的价值正整数v和重量正整数w，中间用空格隔开。
// 输出
// 输出圣诞老人能带走的糖果的最大总价值，保留1位小数。输出为一行，以换行符结束。
// 样例输入
// 4 15
// 100 4
// 412 8
// 266 7
// 591 2
// 样例输出
// 1193.0


/*
思路，贪心 
*/

#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;	// eps 为一个非常小的数

struct Candy{
	int v;		// 价值
	int w;		// 重量
	bool operator <  (const Candy & c) const{	// 根据单价进行排序
		return double(v)/w - double(c.v)/c.w > eps;		// 注意 eps 的使用
	}
} candies[110];	// 糖果数组

int main() {
	int n, w;	// 糖果箱数量，驯鹿载重
	cin >> n >> w;
	for(int i = 0; i < n; ++i){	
		cin >> candies[i].v >> candies[i].w;	// 输入每箱糖果的价值与重量
	}
	sort(candies, candies + n);	//大到小排序 
	int totalW = 0; 	// 当前载重
	double totalV = 0;	// 当前价值
	for(int i = 0; i < n; ++i){		// 从价值大的糖果开始装
		if(totalW + candies[i].w <= w){	// 能装下
			totalV += candies[i].v;
			totalW += candies[i].w;
		}
		else{	// 不能装下，则全装满
			totalV += candies[i].v * (double(w - totalW) / candies[i].w);
			break;
		}
	}
	printf("%.1f", totalV);	// 格式化输出
	return 0;
}

