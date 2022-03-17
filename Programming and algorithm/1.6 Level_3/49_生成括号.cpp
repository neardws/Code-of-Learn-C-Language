// 生成括号
// Paul是一名数学专业的同学，在课余选修了C++编程课，
// 现在他能够自己写程序判断判断一个给定的由'('和')'组成的字符串是否是正确匹配的。
// 可是他不满足于此，想反其道而行之，设计一个程序，能够生成所有合法的括号组合，
// 请你帮助他解决这个问题。
// 时间限制：1000
// 内存限制：65536
// 输入
// 输入只有一行N，代表生成括号的对数（1 ≤ N ≤ 10)。
// 输出
// 输出所有可能的并且有效的括号组合，按照字典序进行排列，每个组合占一行。
// 样例输入
// 3
// 样例输出
// ((()))
// (()())
// (())()
// ()(())
// ()()()

// 分析：

// 必须以左括号开始
// 右括号数量等于左括号数量
// 每个位置要么是左括号，要么是右括号，n对括号，2n个字符，共有 2 的 2n 次幂种可能
// 每个位置生成左括号或者右括号，可以使用递归
// 先处理字符串是否是合理的组合，设置计数变量，遇到左括号 +1，遇到右括号 -1。过程中，计数为负就不是合理组合，最终结果为0就是合理组合。

#include<bits/stdc++.h>
using namespace std;
vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n <= 0) return res;
    dfs(n, "", res, 0, 0);
    return res;
}
void dfs(int n, string path, vector<string>& res, int open, int close) {
    if (open > n || close > open) 
        return;
    if (path.length() == 2 * n) {
        res.push_back(path);
        return;
    }
    dfs(n, path + "(", res, open + 1, close);
    dfs(n, path + ")", res, open, close + 1);
}
int main(){
    int n;
    cin>>n;
    vector<string> res = generateParenthesis(n);
    for(int i =0; i < res.size(); i ++) {
        cout<<res[i]<<endl;
    }
    return 0;
}