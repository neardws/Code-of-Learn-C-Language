// 2971:抓住那头牛
// http://noi.openjudge.cn/ch0205/2971/
// 总时间限制: 2000ms 内存限制: 65536kB
// 描述
// 农夫知道一头牛的位置，想要抓住它。
// 农夫和牛都位于数轴上，农夫起始位于点N(0<=N<=100000)，
// 牛位于点K(0<=K<=100000)。农夫有两种移动方式：

// 1、从X移动到X-1或X+1，每次移动花费一分钟
// 2、从X移动到2*X，每次移动花费一分钟

// 假设牛没有意识到农夫的行动，站在原地不动。
// 农夫最少要花多少时间才能抓住牛？

// 输入
// 两个整数，N和K
// 输出
// 一个整数，农夫抓到牛所要花费的最小分钟数
// 样例输入
// 5 17
// 样例输出
// 4

#include <bits/stdc++.h>
using namespace std;

#define max_n 100001
int n, k;   // n 表示为农夫的位置, k 表示为 牛的位置
int cur, res;   // cur 表示当前元素, res 表示花费时间
int closed[max_n], d[3]; //closed数组储存最小分钟数，且标记已经访问 
queue<int> open;    // 队列容器，用来存储遍历位置

void bfs(){     // 宽度优先搜索
    //初始化closed数组，其中的值全为-1
    fill(closed, closed+max_n, -1);
    //将起点加入open队列 
    open.push(n);
    closed[n] = 0;

    while (!open.empty()){    
        //若当前值为终点，则退出循环 
        cur = open.front();     // 取出队首元素
        open.pop();     //删除队首元素
        if (cur == k)   
            break;

        //三种选择 
        d[0] = cur - 1;
        d[1] = cur + 1;
        d[2] = cur * 2;

        //对三种选择bfs 
        for (int i = 0; i < 3; i++){
            //注意数据不能越界且不能被访问 
            if (d[i] >= 0 && d[i] < max_n && closed[d[i]] == -1){
                open.push(d[i]);
                closed[d[i]] = closed[cur] + 1;
            }
        }
    }

    res = closed[k];
    cout << res << endl;
}

int main() {
    cin >> n >> k;   // n 表示为农夫的位置, k 表示为 牛的位置
    bfs();
    return 0;
}