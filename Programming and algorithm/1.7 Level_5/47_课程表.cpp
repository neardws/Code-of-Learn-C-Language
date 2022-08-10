// 课程表
// 现在你总共有n门课需要选，记为0到n-1。在选修某些课程之前需要一些先修课程。
// 例如，想要学习课程0，你需要先完成课程1，我们用一个匹配来表示他们：[0, 1]。
// 给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

// 时间限制：1000
// 内存限制：65536
// 输入
// 多组数据。每组数据第一行是n和m，n表示有n门课程，m表示有m组依赖关系，接下来的m行是依赖关系的具体信息a b，表示第a门课程依赖第b门课程。
// 0<=n <=1000，0 <= m <= 4000 两组数据之间可能有空行
// 输出
// 对每组数据，能完成输出 True，不能完成输出 False
// 样例输入
// 2 1
// 1 0

// 2 2
// 1 0
// 0 1
// 样例输出
// True
// False
// 提示
// 示例2解释： 总共有2门课程。学习课程1之前，你需要先完成课程0；并且学习课程0之前，你还应先完成课程1。这是不可能的。

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> visited;
bool valid = true;

void dfs(int u) {
    visited[u] = 1;
    for (int v: edges[u]) {
        if (visited[v] == 0) {
            dfs(v);
            if (!valid) {
                return;
            }
        }
        else if (visited[v] == 1) {
            valid = false;
            return;
        }
    }
    visited[u] = 2;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    visited.resize(numCourses);
    for (const auto& info: prerequisites) {
        edges[info[1]].push_back(info[0]);
    }
    for (int i = 0; i < numCourses && valid; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    return valid;
}

int main(){
    int n, m;
    int x;
    while(cin>>n>>m){
        edges.clear();
        for( int i = 0; i < m; i++){
            vector<int> edge;
            cin >> x;
            edge.push_back(x);
            cin >> x;
            edge.push_back(x);
            edges.push_back(edge);
        }
        if(canFinish(n, edges))
            cout<< "True" << endl;
        else
            cout<< "False" << endl;
    }
    return 0;
}
