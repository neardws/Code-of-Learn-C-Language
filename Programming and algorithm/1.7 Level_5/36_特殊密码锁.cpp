// 8469:特殊密码锁
// http://noi.openjudge.cn/ch0406/8469/
// 总时间限制: 1000ms 内存限制: 1024kB
// 描述
// 有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。

// 然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。
// 当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。

// 当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。

// 输入
// 两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。
// 输出
// 至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
// 样例输入
// 011
// 000
// 样例输出
// 1

#include<bits/stdc++.h>
using namespace std;

string obj, ori, tep;
int cnt1, cnt2, n;

void flip(int i){						//改变按钮状态 
	tep[i] ^= 1;							//0^1=1  1^1=0
}

int check() {
	int cnt = 0;
	for(int i = 0; i < n - 2; i++){		//循环判断 
		if(tep[i] != obj[i]){
			cnt++;						//不同则计数加一 
			flip(i + 1);				//按动不同的后一个 
			flip(i + 2);				//改变按动的后一个 
		}
	}
	if(tep[n-2] != obj[n-2]) {			//防止数组越界 单独判断倒数第二个 
		cnt++;
		flip(n - 1);
	}
	if(tep[n-1] != obj[n-1])			//前面的已经确定，最后一个不能更改 
		cnt = 1e5;						//若最后一个不同，则该方案不可行 
	return cnt;
}

int main() {
	cin>>ori>>obj;		// 输入原始和目标密码
	n = ori.length();	// 密码长度
	if(n == 1) {
		if(ori == obj)					//长度为1的单独判断 
			cout<<0;
		else
			cout<<1;
		return 0;						//直接返回，不需后面操作 
	}
	tep = ori;							//复制初始状态 
	cnt1++;
	flip(1);							//改变第二个 
	flip(0); 							//改变第一个 
	cnt1 += check();					//第一种情况 
	tep = ori; 							//恢复初始状态 
	cnt2 = check();						//第二种情况 
	int ans = 1e5;						//答案输出 
	ans = min(ans, cnt1);
	ans = min(ans, cnt2);
	if(ans < 100)
		cout<<ans;
	else
		cout<<"impossible";
	return 0; 
}
