// 快速堆猪
// 小明有很多猪，他喜欢玩叠猪游戏，就是将猪一头头叠起来。猪叠上去后，还可以把顶上的猪拿下来。小明知道每头猪的重量，而且他还随时想知道叠在那里的猪最轻的是多少斤。
// 时间限制：1000
// 内存限制：65536
// 输入
// 有三种输入 1)push n n是整数(0<=0 <=20000)，表示叠上一头重量是n斤的新猪 2)pop 表示将猪堆顶的猪赶走。如果猪堆没猪，就啥也不干 3)min 表示问现在猪堆里最轻的猪多重。如果猪堆没猪，就啥也不干 输入总数不超过100000条
// 输出
// 对每个min输入，输出答案。如果猪堆没猪，就啥也不干
// 样例输入
// pop
// min
// push 5
// push 2
// push 3
// min
// push 4
// min
// 样例输出
// 2
// 2

// 解题思路：
// 考虑用堆来维护小明叠猪游戏中的猪堆。每次push操作时，将新的猪加入堆中；每次pop操作时，将堆顶元素删除；每次min操作时，返回堆顶元素的值即可。
// priority_queue是C++ STL库中的队列实现优先队列的模板类，它具有如下三个模板参数：

// T：存储在队列中的元素类型；
// Container：使用哪种类型的容器来存储元素，默认是vector，也可以是deque等容器；
// Compare：用于定义优先级的比较函数对象，默认是less<T>，也可以是greater<T>等函数对象。
// 这里使用greater<int>表示构建小根堆，因为小根堆的堆顶元素是最小的。


#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > q; // 定义小根堆

    string op; // 操作类型：push、pop、min
    int n; // 猪的重量
    while (cin >> op) {
        if (op == "push") {
            cin >> n;
            q.push(n); // 将新的猪加入小根堆
        } else if (op == "pop") {
            if (!q.empty()) {
                q.pop(); // 将堆顶元素删除
            }
        } else if (op == "min") {
            if (!q.empty()) {
                cout << q.top() << endl; // 返回堆顶元素的值
            }
        }
    }
    return 0;
}
