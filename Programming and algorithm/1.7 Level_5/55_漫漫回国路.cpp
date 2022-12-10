// 漫漫回国路
// 2020年5月，国际航班机票难求。一位在美国华盛顿的中国留学生，因为一些原因必须在本周内回到北京。现在已知各个机场之问的航班情况，求问他回不回得来（不考虑转机次数和机票价格）。
// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行为case个数n(n ＜10)。 每一个case，第一行为机场个数N，NS10。之后的N行，每一行包含N个整数。第i （1sisN)行的第j (1sjsN)
// 个整数代表从第i个机场出发到第个机场的能买到的航班的最低票价t （0 <t <10000）。如果不幸没有航班，那么用-1表示。第i行第i个整数为0。
// 起点华盛顿杜勒斯国际机场的编号为1，终点北京
// 首都国际机场的编号为N。
// 输出
// 每一个case一行。能够回国，输出字符串：
// YES。如果无法回国，输出字符串：NO

#include <bits/stdc++.h>
using namespace std;
int caseNumber;  // 案例个数
char cmap[11][11];     // 地图
int n;   // 地图大小
bool isfound;
int main() {
    cin >> caseNumber;
    for(int k = 1; k <= caseNumber; k++){
        queue<int> q;
        bool visited[11] = {false};
        isfound = false;
        cin >> n;  
        for (int i = 0; i < n; i++)  //输入
            for (int j = 0; j < n; j++) {
                cin >> cmap[i][j];
            }
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {  //宽度优先搜索
            int i = q.front();  // 得到队首的位置
            q.pop();    // 将队首元素出队
            for (int j = 0; j <= n; j++) {   
                if(cmap[i][j] != -1 && cmap[i][j] != 0 && !visited[j]){
                    int new_i = j;
                    if (new_i == n-1){
                        isfound = true;
                        break;
                    }
                    visited[new_i] = true;  // 防止走回头路
                    q.push(new_i);   // 将该点入队
                }
            }
        }
        if(isfound)
            cout << "YES" << endl;  // 找到
        else
            cout << "NO" << endl;
    }
    return 0;
}