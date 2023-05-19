// 合影效果
// 小云和朋友们去爬香山，为美丽的景色所陶醉，想合影留念。
// 如果他们站成一排，男生全部在左（从拍照者的角度），并按照从矮到高的顺序从左到右排，
// 女生全部在右，并按照从高到矮的顺序从左到右排，请问他们合影的效果是什么样的
// （所有人的身高都不同）？

// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行是人数n（2 <= n <= 40，且至少有1个男生和1个女生）。
//  后面紧跟n行，每行输入一个人的性别（男male或女female）和身高（浮点数，单位米），
//  两个数据之间以空格分隔。
// 输出
// n个浮点数，模拟站好队后，拍照者眼中从左到右每个人的身高。
// 每个浮点数需保留到小数点后2位，相邻两个数之间用单个空格隔开。
// 样例输入
// 6
// male 1.72
// male 1.78
// female 1.61
// male 1.65
// female 1.70
// female 1.56
// 样例输出
// 1.65 1.72 1.78 1.70 1.61 1.56

// 解题思路：

// 1. 首先，我们定义了一个结构体person，包含了每个人的性别和身高。
// 2. 定义一个cmp函数，主要作用是比较每两个人的身高。
//     - 如果当前人的性别是男性，那么把他的身高与另一个人的身高进行比较，返回较低的身高。
//     - 如果当前人的性别是女性，那么把他的身高与另一个人的身高进行比较，返回较高的身高。
// 3. 对人的身高进行排序，使用sort函数。
// 4. 最后，循环输出每个人的身高，保留两位小数，中间用空格隔开。

#include <bits/stdc++.h>
using namespace std;

// 定义一个人的结构体
struct person {
    string gender;  // 性别
    double height;  // 身高
};

// 用于排序的比较函数
bool cmp(person a, person b) {
    if (a.gender == "male") {
        // 如果是男生，按照身高从小到大排序
        return a.height < b.height;
    } else {
        // 如果是女生，按照身高从大到小排序
        return a.height > b.height;
    }
}

int main() {
    int n;
    cin >> n;  // 输入人数
    person p[n];  // 定义一个人数组
    for (int i = 0; i < n; i++) {
        cin >> p[i].gender >> p[i].height;  // 输入每个人的性别和身高
    }
    sort(p, p + n, cmp);  // 对人数组排序
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << p[i].height << " ";  // 输出每个人的身高，保留2位小数
    }
    cout << endl;  // 换行
    return 0;
}

