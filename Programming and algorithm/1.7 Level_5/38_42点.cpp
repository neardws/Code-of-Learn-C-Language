// 11F:42点
// http://cxsjsx.openjudge.cn/practise2020pool/11F/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 42是：

// 组合数学上的第5个卡特兰数
// 字符'*'的ASCII码
// 钼的原子序数
// 6与9的乘积结果的13进制表示
// 生命、宇宙以及任何事情的终极答案
// 以及……表达式(1+5)/2*(6-4)*7的值
// 因此，小机器人Marvin发明了这个叫42点的小游戏。在这个游戏中，玩家会获得n个数。
// 玩家需要使用'+'、'-'、'*'、'/'、'('、')'以及这n个数构成一个合法的中缀表达式，并使得该表达式的值为42。
// n个数之间的顺序可以改变。表达式运算过程中只能出现整数。

// 由于过于抑郁，Marvin无力完成这个游戏，于是来找你帮忙。你的任务是对于给定的n个数，判断他们是否能根据上述游戏规则算出42。

// 输入
// 第一行为一个数n，1<=n<=6。
// 第二行为n个数，每个数均为[1,13]范围内的整数。
// 输出
// 输出一行，若可以算出42则输出“YES”，否则输出“NO”（注意大小写）。
// 样例输入
// 6
// 1 5 2 6 4 7
// 样例输出
// YES

#include<bits/stdc++.h>
using namespace std;
vector<int> ele;
int n;
bool dfs(int m){
    if(m == 1){
        if(ele[0] == 42)
            return true;
        return false;
    }
    for(int i = 0; i < m - 1; ++i)
        for(int j = i + 1; j < m; ++j){
            int t1 = ele[i], t2 = ele[j];
            ele[i] = t1 + t2;
            ele[j] = ele[m - 1];
            if(dfs(m - 1))
                return true;
            ele[i] = t1 - t2;
            if(dfs(m - 1))
                return true;
            ele[i] = t2 - t1;
            if(dfs(m - 1))
                return true;
            ele[i] = t1 * t2;
            if(dfs(m - 1))
                return true;
            if(t2 != 0 && abs(t1) % abs(t2) == 0){
                ele[i] = t1 / t2;
                if(dfs(m - 1))
                    return true;
            }
            else if(t1 != 0 && abs(t2) % abs(t1) == 0){
                ele[i] = t2 / t1;
                if(dfs(m - 1))
                    return true;
            }
            ele[i] = t1, ele[j] = t2;
        }
    return false;
}

int main(){
    cin >> n;
    int t;
    for(int i = 0; i < n; ++i){
        cin >> t;
        ele.push_back(t);
    }
    if(dfs(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}