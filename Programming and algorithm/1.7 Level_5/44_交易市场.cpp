// F:交易市场
// http://cxsjsx.openjudge.cn/2021finalpractise/F/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 市场里面一共有n种物品，有m种交易途径，每个交易途径可以由(x,y,z)表示，
// 意思是可以用第x种物品换成第y种物品，并且得到z元的收益（z均大于0）。
// 最开始你只有第一种物品，请问最多可以赚取多少收益。

// 输入
// 第一行两个正整数n和m(n ≤ 1000，m ≤ 4000)
// 接下来m行，每行三个正整数x, y, z，意思是可以用第x种物品换成第y种物品，并且得到z元的收益。（1 ≤ x,y ≤ n, 1 ≤ z ≤ 100）
// 输出
// 一个整数表示最大收益，如果可以赚取无穷多的收益则输出1000000000
// 样例输入
// 3 3
// 1 2 2
// 2 3 3
// 1 3 4
// 样例输出
// 5

// 这道题用动态规划可以做。采用我为人人型递推。

// dp[i]表示最后是第i种物品时的最大价值，无穷多的收益等于出现环，要判断环所以要记录路径。扫描到每个转换关系时更新目标节点的dp。

// 注意这道题还有广搜的思想，动态规划的节点顺序是用队列来决定，有的节点根本到不了就不用考虑它的转换关系。有的节点增加了转换关系就应该重新计算。



#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
struct exchangeTo {
    int target;
    int p;
    exchangeTo(int a, int b) :target(a), p(b) {}
};
struct path {
    int pre;
    int val;
}dp[1005];
map<int, vector<exchangeTo> >tables;
bool inPath(int n, int k) {
    while (k != -1) {
        if (n == k)
            return true;
        k = dp[k].pre;
    }
    return false;
}
int main() {
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tables[x].push_back(exchangeTo(y, z));
    }
    dp[1].val = 0, dp[1].pre = 0;
    bool done = false;
    int result = 0;
    queue<int>myqueues;
    myqueues.push(1);
    while (!myqueues.empty()) {
        int top = myqueues.front();
        myqueues.pop();
        if (!tables[top].empty()) {
            vector<exchangeTo>::iterator ii;
            for (ii = tables[top].begin(); ii != tables[top].end(); ii++) {
                if (inPath(ii->target, top))
                {
                    result = INF;
                    done = true;
                    break;
                }
                if (dp[top].val + ii->p > dp[ii->target].val) {
                    dp[ii->target].val = dp[top].val + ii->p;
                    dp[ii->target].pre = top;
                    myqueues.push(ii->target);//注意这里的更新
                }
                result = max(result, dp[ii->target].val);
            }
            if (done)break;
        }
    }
    cout << result << endl;
    return 0;
}