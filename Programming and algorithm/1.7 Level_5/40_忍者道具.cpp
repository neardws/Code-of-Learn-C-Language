// 12G:忍者道具
// http://cxsjsx.openjudge.cn/practise2020pool/12G/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 忍者道具有很多种，苦无，飞镖，震爆弹。L君热衷于收集忍者道具，现在他有N个道具，每个道具的重量分别是C1、C2…CN。
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
int a[20];
int bag[20];
int ans = 1<<30;
int n, w;
void dfs(int x, int sum){ //正在放第x个物品，已经用了sum个背包
    if(sum>=ans) return;
    if(x==n+1){
        ans = min(ans,sum);
        return;
    }
    for(int i = 1; i <= sum; i++){ //放在已有背包里
        if(bag[i]>=a[x]){
            bag[i] -= a[x];
            dfs(x+1, sum);
            bag[i] += a[x];
        }
    }
    bag[sum+1]-=a[x]; //或者新开一个背包
    dfs(x+1, sum+1);
    bag[sum+1]+=a[x];
}
int main(){
    cin>>n>>w;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i <= n; i++)
        bag[i] = w;
    dfs(1, 1);
    cout<<ans<<endl;
    return 0;
}