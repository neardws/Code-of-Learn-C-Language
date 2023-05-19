// 1758:二叉树

// 总时间限制: 1000ms 内存限制: 65536kB
// 描述

// 如上图所示，由正整数1, 2, 3, ...组成了一棵无限大的二叉树。
// 从某一个结点到根结点（编号是1的结点）都有一条唯一的路径，
// 比如从10到根结点的路径是(10, 5, 2, 1)，从4到根结点的路径是(4, 2, 1)，
// 从根结点1到根结点的路径上只包含一个结点1，因此路径就是(1)。
// 对于两个结点x和y，假设他们到根结点的路径分别是(x1, x2, ... ,1)和
// (y1, y2, ... ,1)（这里显然有x = x1，y = y1），那么必然存在两个正整数i和j，
// 使得从xi 和 yj开始，有xi = yj , xi + 1 = yj + 1, xi + 2 = yj + 2,... 
// 现在的问题就是，给定x和y，要求xi（也就是yj）。
// 输入
// 输入只有一行，包括两个正整数x和y，这两个正整数都不大于1000。
// 输出
// 输出只有一个正整数xi。
// 样例输入
// 10 4
// 样例输出
// 2

// 这道题的目标是找到两个节点x和y在它们到根节点的路径上第一个相同的节点xi。
// 可以通过比较它们的路径来解决这个问题。

// 解题思路：
// 1. 分别计算节点x和y到根节点1的路径，可以使用循环或递归实现。
// 2. 将路径存储在两个数组中，分别是xPath和yPath。
// 3. 从路径的末尾开始向前比较xPath和yPath的元素，直到找到第一个不相等的元素。
// 4. 第一个不相等的元素的下一个元素即为xi，输出该值。


#include <bits/stdc++.h>
using namespace std;

// 计算节点node到根节点1的路径
vector<int> calculatePath(int node) {
    vector<int> path;
    while (node != 1) {
        path.push_back(node);
        node /= 2;  // 根据题目中二叉树的性质，父节点的编号是当前节点编号除以2
    }
    path.push_back(1);  // 加入根节点
    return path;
}

int main() {
    int x, y;
    cin >> x >> y;

    // 计算节点x和y到根节点的路径
    vector<int> xPath = calculatePath(x);
    vector<int> yPath = calculatePath(y);

    // 从路径末尾开始向前比较，找到第一个不相等的节点
    int xi = 0;
    int i = xPath.size() - 1;
    int j = yPath.size() - 1;
    while (i >= 0 && j >= 0 && xPath[i] == yPath[j]) {
        xi = xPath[i];
        i--;
        j--;
    }

    cout << xi << endl;  // 输出xi

    return 0;
}
