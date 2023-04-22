// 区间合并
// 给定 n 个闭区间 [ai; bi]，其中i=1,2,...,n。任意两个相邻或相交的闭区间可以合并为一个闭区间。
// 例如，[1;2] 和 [2;3] 可以合并为 [1;3]，[1;3] 和 [2;4] 可以合并为 [1;4]，但是[1;2] 和 [3;4] 不可以合并。

// 我们的任务是判断这些区间是否可以最终合并为一个闭区间，如果可以，将这个闭区间输出，否则输出no。

// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行为一个整数n，3 ≤ n ≤ 50000。表示输入区间的数量。 之后n行，在第i行上（1 ≤ i ≤ n），为两个整数 ai 和 bi ，
// 整数之间用一个空格分隔，表示区间 [ai; bi]（其中 1 ≤ ai ≤ bi ≤ 10000）。
// 输出
// 输出一行，如果这些区间最终可以合并为一个闭区间，输出这个闭区间的左右边界，用单个空格隔开；否则输出 no。
// 样例输入
// 5
// 5 6
// 1 5
// 10 10
// 6 9
// 8 10
// 样例输出
// 1 10

// 可以使用贪心算法来解决。先将区间按照左端点从小到大排序，然后从左到右扫描这些区间，
// 如果当前区间和上一个区间相交或相邻，则将它们合并，否则就不能合并。最终得到的区间即为所求。

#include <bits/stdc++.h>
using namespace std;

// 定义区间结构体
struct Interval {
    int left;
    int right;

    Interval(int l, int r) : left(l), right(r) {}
};

// 判断两个区间是否相交或相邻
bool isOverlap(const Interval& a, const Interval& b) {
    return a.right >= b.left;
}

int main() {
    int n;
    cin >> n;

    // 读入所有区间
    vector<Interval> intervals;
    for (int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        intervals.push_back(Interval(left, right));
    }

    // 将区间按照左端点从小到大排序
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.left < b.left;
    });

    // 合并区间
    Interval result = intervals[0];
    for (int i = 1; i < n; i++) {
        if (isOverlap(result, intervals[i])) {
            result.right = max(result.right, intervals[i].right);
        } else {
            cout << "no" << endl;
            return 0;
        }
    }

    // 输出结果
    cout << result.left << " " << result.right << endl;

    return 0;
}
