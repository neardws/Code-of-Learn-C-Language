// 6187:称体重
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 赵、钱、孙、李四个人中既有大人也有小孩，给他们称体重时发现，
// 他们每个人的体重都不一样，且体重（单位：公斤）恰好是10的整数倍，
// 且他们的体重都不高 于50公斤，
// 已知赵、钱两人的体重之和恰好等于孙、李两人的体重之和；
// 赵、李两人的体重之和大于孙、钱两人的体重之和，
// 并且赵、孙俩人的体重之和还小于钱的体重。
// 请编写一个程序，按照体重从小到大的顺序，
// 打印出四人的姓氏的首字母和体重数。
// 输入
// 无
// 输出
// 打印出四人的姓氏的首字母（小写）和体重数
// （每人一行，姓名首字母和体重数之间用空格隔开）。
// 样例输入
// 无
// 样例输出
// z 10
// q 20
// s 30
// l 40
// （以上输出仅用于说明格式）

#include<bits/stdc++.h>
using namespace std;
struct name {
    char name;
    int weight;
} n[4];
bool cmp(name a, name b) { return a.weight < b.weight; }
int main() {
    int z, q, s, l;
    for (z = 10; z <= 50; z += 10)
        for (q = 10; q <= 50; q += 10)
            for (s = 10; s <= 50; s += 10)
                for (l = 10; l <= 50; l += 10) {
                    if (z + q == s + l && z + l > s + q && z + s < q) {
                        n[0].name = 'z'; n[0].weight = z;
                        n[1].name = 'q'; n[1].weight = q;
                        n[2].name = 's'; n[2].weight = s;
                        n[3].name = 'l'; n[3].weight = l;
                        sort(n, n + 4, cmp);
                        for (int i = 0; i < 4; i++) {
                            cout << n[i].name << " " << (n[i].weight) << endl;
                        }
                    }
                }
    return 0;
}

