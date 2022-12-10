// 课程表
// 现在你总共有n门课需要选，记为0到n-1。在选修某些课程之前需要一些先修课程。
// 例如，想要学习课程0，你需要先完成课程1，我们用一个匹配来表示他们：[0, 1]。
// 给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

// 时间限制：1000
// 内存限制：65536
// 输入
// 多组数据。每组数据第一行是n和m，n表示有n门课程，m表示有m组依赖关系，
// 接下来的m行是依赖关系的具体信息a b，表示第a门课程依赖第b门课程。
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
// 示例2解释： 总共有2门课程。学习课程1之前，你需要先完成课程0；
// 并且学习课程0之前，你还应先完成课程1。这是不可能的。

#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > edges;  // 存储依赖关系
vector <int> visited;    // 记录每门课是否访问
bool valid = true;  // 假设可以完成所有课程

void dfs(int u) {
    visited[u] = 1;     // 设置已访问
    for (int i = 0; i <= edges[u].size(); i++) {     // 遍历每一个完成u 后需要完成的课程
        int v = edges[u][i];
        if (visited[v] == 0) {  // 未访问    
            dfs(v);             
            if (!valid) {
                return;
            }
        }
        else if (visited[v] == 1) { // 已访问，出错
            valid = false;      // 设置不能完成
            return;
        }
    }
    visited[u] = 2;
}

bool canFinish(int numCourses, vector < vector < int > >& prerequisites) {
    // numCourses 课程数量， prerequisites 依赖关系
    edges.resize(numCourses);   // 更新大小
    visited.resize(numCourses);
    for (int i = 0; i < prerequisites.size(); i ++) { // 更改依赖的结构
        edges[prerequisites[i][1]].push_back(prerequisites[i][0]);  // edges[先完成].push_back(后完成)
    }
    for (int i = 0; i < numCourses && valid; ++i) { // 遍历每一门课
        if (!visited[i]) {  // 没有访问
            dfs(i);
        }
    }
    return valid;
}

int main(){
    int n, m;   // n表示有n门课程，m表示有m组依赖关系
    int x;
    while(cin>>n>>m){
        edges.clear();
        for( int i = 0; i < m; i++){
            vector<int> edge;   // 存储依赖信息，第a门课程依赖第b门课程
            cin >> x;           // 第a门课
            edge.push_back(x);
            cin >> x;           // 第b门课
            edge.push_back(x);
            edges.push_back(edge);
        }
        if(canFinish(n, edges))     // 判断是否能完成
            cout<< "True" << endl;
        else
            cout<< "False" << endl;
    }
    return 0;
}
