//  扑克牌排序
// 假设这里有36张扑克牌，分别为A1~A9,B1~B9,C1~C9,D1~D9，其中A代表方片，B代表草花，C代表红桃，D代表黑桃，
// 那么，设定如下的排序规则：
// 1.对于两张卡牌，X1Y1与X2Y2，X1与X2表示A～D，Y1与Y2表示1～9，如果X1与X2不同，那么依照D>C>B>A的方式进行排序
// 2.假如有X1与X2相同时，那么就比较Y1与Y2的大小。
// 例如，对于如下的四张牌，有如下的升序排序结果：
// D3，C4，A4，C1
// 升序排序的结果为A4，C1，C4，D3
// 有人提出了如下的排序策略：
// 先建立9个队列，用于存放点数的大小，将卡牌依点数存放入各自的队列之中，然后再按队列1到队列9依次出队。
// 例如，对于上面的结果，依次进队后，结果如下：
// 队列1：C1；队列3：D3，队列4：C4，A4
// 将其依次出队后，结果为C1，D3，C4，A4
// 然后，再建立4个队列，用于存放花色。将卡牌依花色A～D存放入队列1～4中，然后再按队列1到队列4依次出队。
// 例如，对于上面刚刚出队的序列C1，D3，C4，A4，将其依次进队，结果如下：
// 队列1：A4；队列3：C1，C4；队列4：D3
// 将其依次出队后，结果为A4，C1，C4，D3，排序结束。

// 请根据上面的算法，编写一个用队列对扑克牌排序的程序，要求依照上面的排序规则，根据先花色后点数的方法进行排序。

// 时间限制：1000
// 内存限制：65536
// 输入
// 输入分为两行，第一行为一个整数n，表示一共有n张牌（1<=n<=100） 第二行用XY的形式表示每一张牌，其中X为A～D，Y为1～9
// 输出
// 输出三个部分 第一个部分为第一次进队出队的结果，用Queue1:...表示，共9行，结果用空格分隔，
// 下同 第二部分为第二次进队出队的结果，用QueueA:...表示，共4行 第三部分为一行，即将卡牌排序后的结果（升序排序）
// 样例输入
// 8
// D8 A6 C3 B8 C5 A1 B5 D3
// 样例输出
// Queue1:A1
// Queue2:
// Queue3:C3 D3
// Queue4:
// Queue5:C5 B5
// Queue6:A6
// Queue7:
// Queue8:D8 B8
// Queue9:
// QueueA:A1 A6
// QueueB:B5 B8
// QueueC:C3 C5
// QueueD:D3 D8
// A1 A6 B5 B8 C3 C5 D3 D8
// 提示
// 第二次入队出队时，可以复用第一次时9个队列中的4个。所以其实只需要开辟9个队列即可。


// 这道题需要使用两次队列操作进行排序。首先，按照点数大小将卡牌存储到9个队列中，
// 然后再按照花色将卡牌存储到4个队列中。最后将4个队列按顺序依次出队即可得到排序结果。

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

// 定义卡牌的结构体，包括花色和点数
struct Card {
    char suit;  // 花色
    int value;  // 点数
};

// 比较函数，用于卡牌排序
bool cmp(Card a, Card b) {
    if (a.suit != b.suit) {
        // 如果花色不同，按照 D > C > B > A 的顺序进行排序
        return a.suit > b.suit;
    } else {
        // 如果花色相同，按照点数进行排序
        return a.value < b.value;
    }
}

int main() {
    int n;
    cin >> n;

    // 建立 9 个队列，用于存储不同点数的卡牌
    queue<Card> q1, q2, q3, q4, q5, q6, q7, q8, q9;

    // 将卡牌按照点数大小存储到对应队列中
    for (int i = 0; i < n; i++) {
        char suit;
        int value;
        cin >> suit >> value;
        Card card = {suit, value};
        switch (value) {
            case 1: q1.push(card); break;
            case 2: q2.push(card); break;
            case 3: q3.push(card); break;
            case 4: q4.push(card); break;
            case 5: q5.push(card); break;
            case 6: q6.push(card); break;
            case 7: q7.push(card); break;
            case 8: q8.push(card); break;
            case 9: q9.push(card); break;
            default: break;
        }
    }

    // 输出第一次进队出队的结果
    cout << "Queue1:";
    while (!q1.empty()) {
        cout << q1.front().suit << q1.front().value << " ";
        q1.pop();
    }
    cout << endl;

    cout << "Queue2:";
    while (!q2.empty()) {
        cout << q2.front().suit << q2.front().value << " ";
        q2.pop();
    }
    cout << endl;

    cout << "Queue3:";
    while (!q3.empty()) {
        cout << q3.front().suit << q3.front().value << " ";
        q3.pop();
    }
    cout << endl;

    cout << "Queue4:";
    while (!q4.empty()) {
        cout << q4.front().suit << q4.front().value << " ";
        q4.pop();
    }
    cout << endl;

    cout << "Queue5:";
    while (!q5.empty()) {
        cout << q5.front().suit << q5.front().value << " ";
        q5.pop();
    }
    cout << endl;
        cout << "Queue6:";
    while (!q6.empty()) {
        cout << q6.front().suit << q6.front().value << " ";
        q6.pop();
    }
    cout << endl;

    cout << "Queue7:";
    while (!q7.empty()) {
        cout << q7.front().suit << q7.front().value << " ";
        q7.pop();
    }
    cout << endl;

    cout << "Queue8:";
    while (!q8.empty()) {
        cout << q8.front().suit << q8.front().value << " ";
        q8.pop();
    }
    cout << endl;

    cout << "Queue9:";
    while (!q9.empty()) {
        cout << q9.front().suit << q9.front().value << " ";
        q9.pop();
    }
    cout << endl;

    // 建立 4 个队列，用于存储不同花色的卡牌
    queue<Card> qa, qb, qc, qd;

    // 将卡牌按照花色存储到对应队列中
    while (!q1.empty()) {
        switch (q1.front().suit) {
            case 'A': qa.push(q1.front()); break;
            case 'B': qb.push(q1.front()); break;
            case 'C': qc.push(q1.front()); break;
            case 'D': qd.push(q1.front()); break;
            default: break;
        }
        q1.pop();
    }
    while (!q2.empty()) {
        switch (q2.front().suit) {
            case 'A': qa.push(q2.front()); break;
            case 'B': qb.push(q2.front()); break;
            case 'C': qc.push(q2.front()); break;
            case 'D': qd.push(q2.front()); break;
            default: break;
        }
        q2.pop();
    }
    while (!q3.empty()) {
        switch (q3.front().suit) {
            case 'A': qa.push(q3.front()); break;
            case 'B': qb.push(q3.front()); break;
            case 'C': qc.push(q3.front()); break;
            case 'D': qd.push(q3.front()); break;
            default: break;
        }
        q3.pop();
    }
    while (!q4.empty()) {
        switch (q4.front().suit) {
            case 'A': qa.push(q4.front()); break;
            case 'B': qb.push(q4.front()); break;
            case 'C': qc.push(q4.front()); break;
            case 'D': qd.push(q4.front()); break;
            default: break;
        }
        q4.pop();
    }
    while (!q5.empty()) {
        switch (q5.front().suit) {
            case 'A': qa.push(q5.front()); break;
            case 'B': qb.push(q5.front()); break;
            case 'C': qc.push(q5.front()); break;
            case 'D': qd.push(q5.front()); break;
            default: break;
        }
        q5.pop();
    }
    while (!q6.empty()) {
        switch (q6.front().suit) {
            case 'A': qa.push(q6.front()); break;
            case 'B': qb.push(q6.front()); break;
            case 'C': qc.push(q6.front()); break;
            case 'D': qd.push(q6.front()); break;
            default: break
        q6.pop();
    }
    while (!q7.empty()) {
        switch (q7.front().suit) {
            case 'A': qa.push(q7.front()); break;
            case 'B': qb.push(q7.front()); break;
            case 'C': qc.push(q7.front()); break;
            case 'D': qd.push(q7.front()); break;
            default: break;
        }
        q7.pop();
    }
    while (!q8.empty()) {
        switch (q8.front().suit) {
            case 'A': qa.push(q8.front()); break;
            case 'B': qb.push(q8.front()); break;
            case 'C': qc.push(q8.front()); break;
            case 'D': qd.push(q8.front()); break;
            default: break;
        }
        q8.pop();
    }
    while (!q9.empty()) {
        switch (q9.front().suit) {
            case 'A': qa.push(q9.front()); break;
            case 'B': qb.push(q9.front()); break;
            case 'C': qc.push(q9.front()); break;
            case 'D': qd.push(q9.front()); break;
            default: break;
        }
        q9.pop();
    }

    // 输出第二次进队出队的结果
    cout << "QueueA:";
    while (!qa.empty()) {
        cout << qa.front().suit << qa.front().value << " ";
        qa.pop();
    }
    cout << endl;

    cout << "QueueB:";
    while (!qb.empty()) {
        cout << qb.front().suit << qb.front().value << " ";
        qb.pop();
    }
    cout << endl;

    cout << "QueueC:";
    while (!qc.empty()) {
        cout << qc.front().suit << qc.front().value << " ";
        qc.pop();
    }
    cout << endl;

    cout << "QueueD:";
    while (!qd.empty()) {
        cout << qd.front().suit << qd.front().value << " ";
        qd.pop();
    }
    cout << endl;

    // 将卡牌存储到 vector 中，用于排序
    vector<Card> cards;
    while (!qa.empty()) {
        cards.push_back(qa.front());
        qa.pop();
    }
    while (!qb.empty()) {
        cards.push_back(qb.front());
        qb.pop();
    }
    while (!qc.empty()) {
        cards.push_back(qc.front());
        qc.pop();
    }
    while (!qd.empty()) {
        cards.push_back(qd.front());
        qd.pop();
    }

    // 对卡牌进行排序
    sort(cards.begin(), cards.end(), cmp);

    // 输出排序后的结果
    for (int i = 0; i < n; i++) {
        cout << cards[i].suit << cards[i].value << " ";
    }
    cout << endl;

    return 0;
}




