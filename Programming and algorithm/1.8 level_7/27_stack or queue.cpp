// stack or queue
// 栈和队列都是常用的线性结构，它们都提供两个操作：
// Push：加入一个元素。
// Pop：弹出一个元素。
// 不同的是，栈是”先进后出”，而队列则是”先进先出”。
// 给出一个线性结构的进出顺序，判定这个结构是栈还是队列。
// 时间限制：1000
// 内存限制：65535
// 输入
// 第一行输入一个整数t，代表有t组测试数据 对于每组测试数据，第一行输入一个整数n，代表操作的次数。 随后输入n行，每行包含两个整数 type val。 当type = 1时，表示该次操作为push操作，val表示进入的数字。当type=2时，表示该次操作为pop操作，val代表出来的数字。 3<=n<=2000
// 输出
// 每组测试数据输出一行。 输出该组数据对应的线性结构，”Stack” 或者 “Queue”。 题目保证是栈或者队列的一种。
// 样例输入
// 2
// 6
// 1 1
// 1 2
// 1 3
// 2 3
// 2 2
// 2 1
// 4
// 1 1
// 1 2
// 2 1
// 2 2
// 样例输出
// Stack
// Queue

// 解题思路：
// 定义两个队列，一个是栈，另一个是队列。对于每个操作，如果是push操作，
// 将该数字压入栈和队列中；如果是pop操作，判断该数字从栈和队列中弹出的顺序是否相同，
// 如果相同，说明该组数据是栈，反之是队列。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // 输入测试数据组数
    while (t--) {
        int n;
        cin >> n; // 输入操作次数
        queue<int> q, s; // 分别创建队列和栈
        int flag1 = 1, flag2 = 1; // flag1 记录是否是队列，flag2 记录是否是栈
        for (int i = 0; i < n; i++) {
            int type, val;
            cin >> type >> val;
            if (type == 1) { // 如果是 push 操作
                q.push(val); // 在队列末尾加入元素
                s.push(val); // 在栈顶加入元素
            } else { // 如果是 pop 操作
                int q1 = q.front(); // 记录队列的队首元素
                q.pop(); // 弹出队列的队首元素
                int s1 = s.top(); // 记录栈的栈顶元素
                s.pop(); // 弹出栈的栈顶元素
                if (q1 != val) flag1 = 0; // 如果队列的队首元素与输入的元素不同，则不是队列
                if (s1 != val) flag2 = 0; // 如果栈的栈顶元素与输入的元素不同，则不是栈
            }
        }
        if (flag1 == 1) cout << "Queue" << endl; // 如果是队列，输出 Queue
        if (flag2 == 1) cout << "Stack" << endl; // 如果是栈，输出 Stack
    }
    return 0;
} 
