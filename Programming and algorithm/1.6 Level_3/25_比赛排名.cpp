// 2673:比赛排名

// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 5名运动员参加100米赛跑，各自对比赛结果进行了预测：
// A说：E是第1名。
// B说：我是第2名。
// C说：A肯定垫底。
// D说：C肯定拿不了第1名。
// E说：D应该是第1名。
// 比赛结束后发现，只有获第1名和第2名的选手猜对了，
// E不是第2名和第3名，没有出现名次并列的情况。
// 请编程判断5位选手各是第几名。

// 输入
// 无
// 输出
// 输出要求：按ABCDE的顺序输出5行，其中第1行是A的名次，
// 第2行是B的名次，
// 第3行是C的名次，第4行是D的名次，第5行是E的名次。
// 样例输入
// 样例输出

#include<bits/stdc++.h>
using namespace std;
int a, b, c, d, e;
bool isA(int a) {
    if (a <= 2)
        return e == 1;
    else
        return e != 1;
}
bool isB(int b) { return (b <= 2) ? b == 2 : b != 2; }
bool isC(int c) { return (c <= 2) ? a == 5 : a != 5; }
bool isD(int d) { return (d <= 2) ? c != 1 : c == 1; }
bool isE(int e) {
    if (e == 2 || e == 3)
        return false;
    if (e <= 2)
        return d == 1;
    else
        return d != 1;
}

int main() {
    for (a = 1; a <= 5; a++) {
        for (b = 1; b <= 5; b++) {
            //循环，5重，如果有相等即继续，也可以最后判断时直接判断是否相等，这样效率高些
            if (b == a)
                continue;
            for (c = 1; c <= 5; c++) {
                if (c == a || c == b)
                    continue;
                for (d = 1; d <= 5; d++) {
                    if (d == a || d == b || d == c)
                        continue;
                    for (e = 1; e <= 5; e++) {
                        if (e == a || e == b || e == c || e == d)
                            continue;
                        if (isA(a) && isB(b) && isC(c) && isD(d) && isE(e)) {//判断
                            cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
                        }
                    }
                }
            }
        }
    }
}
