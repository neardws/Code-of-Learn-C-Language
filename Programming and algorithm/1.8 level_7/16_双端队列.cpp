// 双端队列
// 定义一个双端队列，进队操作与普通队列一样，从队尾进入。出队操作既可以从队头，也可以从队尾。编程实现这个数据结构。

// 时间限制：1000
// 内存限制：65535
// 输入
// 第一行输入一个整数t，代表测试数据的组数。 每组数据的第一行输入一个整数n，表示操作的次数。 接着输入n行，每行对应一个操作，首先输入一个整数type。 当type=1，进队操作，接着输入一个整数x，表示进入队列的元素。 当type=2，出队操作，接着输入一个整数c，c=0代表从队头出队，c=1代表从队尾出队。 n <= 1000
// 输出
// 对于每组测试数据，输出执行完所有的操作后队列中剩余的元素,元素之间用空格隔开，按队头到队尾的顺序输出，占一行。如果队列中已经没有任何的元素，输出NULL。
// 样例输入
// 2
// 5
// 1 2
// 1 3
// 1 4
// 2 0
// 2 1
// 6
// 1 1
// 1 2
// 1 3
// 2 0
// 2 1
// 2 0
// 样例输出
// 3
// NULL

// 使用一个数组来存储双端队列的元素。双端队列的两端分别使用两个指针来指向，队头指针front指向队头元素的前一个位置，
// 队尾指针rear指向队尾元素的位置。当front和rear相等时，队列为空。

// 对于进队操作，只需要将元素插入到队尾即可。对于出队操作，需要根据给定的参数判断是从队头还是队尾出队，并更新相应的指针。

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;  // 双端队列的最大长度

class Deque {
public:
    Deque() : front(-1), rear(-1) {}

    // 进队操作
    void push_back(int x) {
        // 如果队列已满，直接返回
        if ((rear + 1) % MAXN == front) {
            return;
        }
        rear = (rear + 1) % MAXN;
        data[rear] = x;
        if (front == -1) {
            front = rear;
        }
    }

    // 从队头出队（c = 0），或者从队尾出队（c = 1）
    void pop(int c) {
        // 如果队列为空，直接返回
        if (front == -1) {
            return;
        }
        if (c == 0) {
            front = (front + 1) % MAXN;
        } else {
            rear = (rear - 1 + MAXN) % MAXN;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        }
    }

    // 判断队列是否为空
    bool empty() const {
        return front == -1;
    }

    // 获取队头元素
    int frontValue() const {
        return data[front];
    }

    // 获取队尾元素
    int backValue() const {
        return data[rear];
    }

private:
    int data[MAXN];  // 存储双端队列的元素
    int front, rear;  // 队头和队尾指针
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Deque dq;
        for (int i = 0; i < n; i++) {
            int type, x;
            cin >> type;
            if (type == 1) {
                cin >> x;
                dq.push_back(x);
            } else {
                int c;
                cin >> c;
                dq.pop(c);
            }
        }

        // 输出结果
        if (dq.empty()) {
            cout << "NULL";
        } else {
            cout << dq.frontValue();
            int p = (dq.front + 1) % MAXN;
            while (p != (dq.rear + 1) % MAXN) {
                cout << " " << dq.data[p];
                p = (p + 1) % MAXN;
            }
        }
        cout << endl;
    }

    return 0;
}
