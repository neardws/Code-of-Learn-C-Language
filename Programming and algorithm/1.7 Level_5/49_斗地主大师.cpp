// 斗地主大师

// 斗地主大师今天有 P 个欢乐豆，他夜观天象，算出了一个幸运数字 Q，
// 如果他能有恰好 Q 个欢乐豆，就可以轻松完成程设大作业了。

// 斗地主大师显然是斗地主大师，可以在斗地主的时候轻松操控游戏的输赢。
// 1. 他可以轻松赢一把，让自己的欢乐豆变成原来的 Y 倍
// 2. 他也可以故意输一把，损失 X 个欢乐豆
// (注意欢乐豆显然不能变成负数，所以如果手里没有 X 个豆就不能用这个能力)
// 而斗地主大师还有一种怪癖，扑克除去大小王只有 52 张，
// 所以他一天之内最多只会打 52 把斗地主。
// 斗地主大师希望你能告诉他，为了把P个欢乐豆变成 Q 个，
// 他至少要打多少把斗地主？

// 时间限制：1000
// 内存限制：65536

// 输入
// 第一行4个正整数 P, Q, X, Y，0< P, X, Q <= 2^31, 1< Y <= 225
// 输出
// 输出一个数表示斗地主大师至少要用多少次能力 
// 如果打了 52 次斗地主也不能把 P 个欢乐豆变成 Q 个，
// 请输出一行 “Failed”

// 样例输入
// 输入样例1：
// 2 2333 666 8
// 输入样例2：
// 1264574 285855522 26746122 3

// 样例输出
// 输出样例1：
// Failed
// 输出样例2：
// 33

// 提示
// 可以考虑深搜 要用long long

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	int P;  // 欢乐豆数量
	int Q;  // 目标欢乐豆数量
	int X;  // 输一次损失欢乐豆数量
	int Y;  // 赢一次欢乐豆翻Y倍

	int min_ok_play_count; //最少需要打多少次牌
	int max_play_count;    //打牌的最大次数
	
	//t: 当前有多少个欢乐豆, step: 步骤数
	void dfs(int step, long long t){
		if(step > 52) 
            return;
		//剪枝，如果 t 大于 Q 的时候再翻 Y 倍，那么后面全是 X 操作都没用
		if(t > Q + (52 - step) * X) 
            return;		
		if(t == Q) {    // 到达目标数量
			min_ok_play_count = min(min_ok_play_count, step);
            // 得到最小步数
			return;
		}
		dfs(step + 1, t * Y);   // 翻倍
		if(t > X) 
            dfs(step + 1, t - X);   // 输一把
	}
	
public:	
	void load(int max_play_count){
		scanf("%d%d%d%d", &P, &Q, &X, &Y);
		this->max_play_count = max_play_count;
	}
	
	void play_count(){
		//设置比52大，用来判断52次内P变成Q是否可行
		min_ok_play_count = max_play_count + 100;
		dfs(0, P);
		if(min_ok_play_count == max_play_count + 100){
			printf("Failed");			
		}else{
			printf("%d", min_ok_play_count);
		}
	}
};

int main(){
	Solution s;
	s.load(52);
	s.play_count();
	return 0;
}
