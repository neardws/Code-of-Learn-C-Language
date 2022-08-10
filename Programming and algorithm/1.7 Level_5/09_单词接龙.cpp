// 8783:单词接龙
// http://noi.openjudge.cn/ch0205/8783/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，
// 且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），
// 在两个单词相连时，其重合部分合为一部分，例如beast和astonish，
// 如果接成一条龙则变为beastonish，另外相邻的两部分不能存在包含关系，例如at和atide间不能相连。

// 输入
// 输入的第一行为一个单独的整数n(n<=20)表示单词数，以下n行每行有一个单词（只含有大写或小写字母，长度不超过20），
// 输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在。
// 输出
// 只需输出以此字母开头的最长的“龙”的长度。
// 样例输入
// 5
// at
// touch
// cheat
// choose
// tact
// a
// 样例输出
// 23
// 提示
// 连成的“龙”为atoucheatactactouchoose
// 来源
// NOIP2000复赛 普及组 第四题

#include<bits/stdc++.h>
using namespace std;
struct node{
	string s;
	int len;
	int v;
}node[25];
int n;
int ans;
void dfs(int x,int len){
	for(int i=1;i<=n;i++){//遍历所有可能的连接 
		if(node[i].v<2){//如果遍历次数少于两次 
			for(int j=0;j<node[x].len;j++){//从上一个字符串的第一个元素开始匹配 
				if(node[x].s[j]==node[i].s[0]){//如果匹配到第一个相同就进入if 
					int k=1;
					int flag=1;
					for(int l=j+1;l<node[x].len&&k<node[i].len;k++,l++)//从上一个字符串相同元素开始匹配，如果匹配到尾，证明可以尾加 
						if(node[x].s[l]!=node[i].s[k]){//如果不能匹配到尾，不能尾加 
							flag=0;
							break;
						}
					if(flag){//如果匹配到尾了，进入这个单词的匹配（深搜） 
						node[i].v++;
						dfs(i,len+node[i].len-k);//k是匹配的长度，最后需要减去相同的长度 
						node[i].v--;
					}
				}
			}
		}
	}
	if(len>ans)
		ans=len;
}
int main(){
	while(cin>>n)
	{
		for(int i=1;i<=n;i++){
			cin>>node[i].s;
			node[i].len=node[i].s.size();
			node[i].v=0;
		}
		cin>>node[0].s;//题目指定开头，所以把开头放在0下标这里。 
		node[0].len=node[0].s.size();
		ans=0;
		dfs(0,node[0].len);
		cout<<ans<<endl;
	}
	return 0;
}
