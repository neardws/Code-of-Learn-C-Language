// 12G:忍者道具
// http://cxsjsx.openjudge.cn/practise2020pool/12G/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 忍者道具有很多种，苦无，飞镖，震爆弹。
// L君热衷于收集忍者道具，现在他有N个道具，每个道具的重量分别是C1、C2…CN。
// 现在他想把这N个道具装到载重量为W的工具包里，请问他最少需要多少个工具包？

// 输入
// 第一行包含两个用空格隔开的整数，N和W。
// 接下来N行每行一个整数，其中第i+1行的整数表示第i个道具的重量Ci。
// 输出
// 输出一个整数，最少需要多少个工具包。
// 样例输入
// 5 1996
// 1
// 2
// 1994
// 12
// 29
// 样例输出
// 2
// 提示
// 对于100%的数据，1<=N<=18，1<=Ci<=W<=10^8。

#include<bits/stdc++.h>
using namespace std;
int a[20];      // 道具重量
int bag[20];    // 背包容量
int ans = 1<<30;       // 初始化为一个大数
int n, w;      // n 为道具数量，w 为背包容量
void dfs(int x, int sum){ //正在放第x个物品，已经用了sum个背包
    if(sum >= ans) 
        return;
    if(x == n + 1){     // 放了最后一件物品
        ans = min(ans, sum);    // 重量取最小
        return;
    }
    for(int i = 1; i <= sum; i++){  // 放在已有背包里
        if(bag[i] >= a[x]){     // 背包 i 可装下
            bag[i] -= a[x];     // 容量减少
            dfs(x + 1, sum);    // 物品+1，背包不变
            bag[i] += a[x];     // 回溯
        }
    }
    bag[sum + 1] -= a[x]; // 或者新开一个背包
    dfs(x + 1, sum + 1);  // 物品+1，背包+1  
    bag[sum + 1] += a[x]; // 回溯
}
int main(){
    cin>>n>>w;  // 输入道具数量和背包容量
    for(int i = 1; i <= n; i++)
        cin>>a[i];      // 输入每件道具的重量
    for(int i = 1; i <= n; i++)
        bag[i] = w;     // 背包容量进行初始化
    dfs(1, 1);      // 正在放第一件道具，已经用了一个背包
    cout<<ans<<endl;
    return 0;
}