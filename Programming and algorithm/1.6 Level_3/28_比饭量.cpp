// 6188:比饭量
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 3个人比饭量，每人说了两句话： 
// A说：B比我吃的多，C和我吃的一样多 
// B说：A比我吃的多，A也比C吃的多 
// C说：我比B吃得多，B比A吃的多。 
// 事实上，饭量和正确断言的个数是反序的关系。 
// 请编程按饭量的大小输出3个人的顺序。

// 输入
// 无输入
// 输出
// 按照饭量大小输出3人顺序，比如：
// ABC
// 样例输入
// 无
// 样例输出
// 无

// 解析

// 顺序定为012
// 那么反序即为210
// 那么各项和为2

#include<bits/stdc++.h>
using namespace std;
struct ABC {
    char c;
    int food;
} abc[3];
bool cmp(ABC a, ABC b) { return a.food < b.food; }
int main() {
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            for (int c = 0; c < 3; c++) {
                int aa = (b > a) + (c == a);
                int bb = (a > b) + (a > c);
                int cc = (c > b) + (b > a);
                if (a + aa == 2 && b + bb == 2 && c + cc == 2) {
                    abc[0].c = 'A'; abc[0].food = a;
                    abc[1].c = 'B'; abc[1].food = b;
                    abc[2].c = 'C'; abc[2].food = c;
                    sort(abc, abc + 3, cmp);
                    for (int i = 0; i < 3; i++) {
                        cout << abc[i].c;
                    }
                }
            }
        }
    }
}

