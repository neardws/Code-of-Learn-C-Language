// 课程冲突
// 小 A 修了 n 门课程, 第 i 门课程是从第 ai 天一直上到第 bi 天。

// 定义两门课程的冲突程度为 : 有几天是这两门课程都要上的。

// 例如 a1=1,b1=3,a2=2,b2=4 时, 这两门课的冲突程度为 2。

// 现在你需要求的是这 n 门课中冲突程度最大的两门课的冲突程度。
// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行一个正整数 n 表示课程数量。 接下来 n 行,每行两个正整数 ai,bi。 2 ≤ n≤ 1000, 1 ≤ ai ≤ bi ≤ 1000。
// 输出
// 输出一个整数表示最大的冲突程度
// 样例输入
// 3
// 1 3
// 2 4
// 5 5
// 样例输出
// 2

#include<bits/stdc++.h>
using namespace std;
struct project {    // 定义结构体
    int start;      // 课程开始时间
    int end;        // 课程结束时间
    project(int a,int b):   // 构造函数
        start(a),end(b){}   // 初始化
    bool operator <(const project A)const {     // 运算符重载
        if (start == A.start)   // 如果开始时间相同
            return end < A.end; // 则按结束时间排序
        else                    // 否则
            return start < A.start;     // 按开始时间排序
    }
};

int main() {
    int n;
    cin >> n;
    vector<project>alls;    // 定义一个 动态数组 vector，用来存储所有课程
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        alls.push_back(project(a,b));   // 将课程添加到动态数组中
    }
    sort(alls.begin(), alls.end());     // 对动态数组进行排序
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (alls[i].end - alls[i].start < result)   // 如果课程的结束时间减去开始时间小于结果
            continue;                               // 则跳过
        for (int j = i + 1; j < n; j++) {
            if (alls[j].start > alls[i].end)        // 如果课程的开始时间大于结束时间
                break;                              // 则跳过
            int t = min(alls[i].end, alls[j].end) - alls[j].start + 1;      // 计算冲突程度
            result = max(t, result);        // 更新结果
        }
    }
    cout << result << endl;
    return 0;
}