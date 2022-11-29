// F:交易市场
// http://cxsjsx.openjudge.cn/2021finalpractise/F/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 市场里面一共有 n 种物品，有m种交易途径，每个交易途径可以由(x,y,z)表示，
// 意思是可以用第 x 种物品换成第 y 种物品，并且得到z元的收益（z均大于0）。
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

// dp[i]表示最后是第i种物品时的最大价值，无穷多的收益等于出现环，要判断环所以要记录路径。
// 扫描到每个转换关系时更新目标节点的dp。

// 注意这道题还有广搜的思想，动态规划的节点顺序是用队列来决定，
// 有的节点根本到不了就不用考虑它的转换关系。有的节点增加了转换关系就应该重新计算。

#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000      // 定义最大值
struct exchangeTo { // 结构体，存储交换信息
    int target;     // 交换物品
    int p;          // 价格
    exchangeTo(int a, int b) :target(a), p(b) {}
};
struct path {       // 结构体，记录交换路径
    int pre;        // 前一个节点
    int val;        // 当前取得的价值
}dp[1005];  // dp[i]表示最后是第i种物品时的最大价值
map<int, vector<exchangeTo> >tables;    // 存储每个物品可交换物品的信息
bool inPath(int n, int k) { // n 为交换目标， k 为被换的物品
    while (k != -1) {   
        if (n == k)     // 判断 n 是否出现在 k 的交换路径中
            return true;
        k = dp[k].pre;
    }
    return false;
}
int main() {
    memset(dp, -1, sizeof(dp));     // dp 全初始化为 -1
    int n, m;       // n 种物品，m 种交易手段
    cin >> n >> m;  
    for (int i = 0; i < m; i++) {
        int x, y, z;      // 第x种物品换成第y种物品，并且得到z元的收益
        cin >> x >> y >> z;
        tables[x].push_back(exchangeTo(y, z));  // 往向量容器中添加元素
    }
    dp[1].val = 0, dp[1].pre = 0;   // 最开始你只有第一种物品，没有交换
    bool done = false;  
    int result = 0;     // 最大价值
    queue<int> myqueues;
    myqueues.push(1);
    while (!myqueues.empty()) {
        int top = myqueues.front();
        myqueues.pop();
        if (!tables[top].empty()) {     // 交换序列不为空
            vector<exchangeTo>::iterator ii;
            for (ii = tables[top].begin(); ii != tables[top].end(); ii++) {
                // 遍历交换序列
                if (inPath(ii->target, top)) {  // 在交换路径中
                    result = INF;   // 死循环，可以无限交换
                    done = true;    // 结束
                    break;
                }
                if (dp[top].val + ii->p > dp[ii->target].val) {
                    // 交换 ii 的价值 比 原始目标值大
                    dp[ii->target].val = dp[top].val + ii->p;   // 更新
                    dp[ii->target].pre = top;   
                    myqueues.push(ii->target); //注意这里的更新
                }
                result = max(result, dp[ii->target].val);  // 更新最大值
            }
            if (done)
                break;
        }
    }
    cout << result << endl;
    return 0;
}