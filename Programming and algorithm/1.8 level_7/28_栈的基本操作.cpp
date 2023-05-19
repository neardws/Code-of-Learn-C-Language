// 栈的基本操作
// 栈是一种重要的数据结构，它具有push k和pop操作。push k是将数字k加入到栈中，pop则是从栈中取一个数出来。

// 栈是后进先出的：把栈也看成横向的一个通道，则push k是将k放到栈的最右边，而pop也是从栈的最右边取出一个数。

// 假设栈当前从左至右含有1和2两个数，则执行push 5和pop操作示例图如下：

//           push 5          pop

// 栈   1 2  ------->  1 2 5 ------>  1 2
// 现在，假设栈是空的。给定一系列push k和pop操作之后，输出栈中存储的数字。若栈已经空了，仍然接收到pop操作，
// 则输出error。
// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行为m，表示有m组测试输入，m<100。 每组第一行为n，表示下列有n行push k或pop操作。（n<150） 
// 接下来n行，每行是push k或者pop，其中k是一个整数。 （输入保证同时在栈中的数不会超过100个）
// 输出
// 对每组测试数据输出一行。该行内容在正常情况下，是栈中从左到右存储的数字，数字直接以一个空格分隔，
// 如果栈空，则不作输出；但若操作过程中出现栈已空仍然收到pop，则输出error。
// 样例输入
// 2
// 4
// push 1
// push 3
// pop
// push 5
// 1
// pop
// 样例输出
// 1 5
// error

// 解题思路：
// 可以使用STL中的stack进行实现


#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m; // 输入测试数据的组数
    while (m--) {
        int n;
        cin >> n; // 输入每组的操作数
        stack<int> s; // 声明一个栈
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            if (str == "push") {
                int k;
                cin >> k; // 输入要加入的数字
                s.push(k); // 将数字加入栈
            } else {
                if (s.empty()) {
                    cout << "error" << endl; // 栈为空，不能pop，输出error
                } else {
                    cout << s.top() << " "; // 输出栈顶元素
                    s.pop(); // 删除栈顶元素
                }
            }
        }
        cout << endl;
    }
    return 0;
}



