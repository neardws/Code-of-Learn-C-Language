// 637. 二叉树的层平均值
// 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。
// 与实际答案相差 10^-5 以内的答案可以被接受。

// 示例 1：

// 输入：root = [3,9,20,null,null,15,7]
// 输出：[3.00000,14.50000,11.00000]
// 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
// 因此返回 [3, 14.5, 11] 。
// 示例 2:
// 输入：root = [3,9,20,15,7]
// 输出：[3.00000,14.50000,11.00000]

// 提示：

// 树中节点数量在 [1, 104] 范围内
// -231 <= Node.val <= 231 - 1

// 题目要求计算二叉树每一层节点的平均值，并以数组的形式返回结果。

// 为了解决这个问题，我们可以使用广度优先搜索（BFS）遍历二叉树的每一层，并计算每一层节点的平均值。

// 算法步骤：
// 1. 定义一个队列 `q`，用于广度优先搜索遍历二叉树的节点。
// 2. 定义一个数组 `averages`，用于存储每一层节点的平均值。
// 3. 将根节点入队。
// 4. 开始广度优先搜索：
//    - 在每一层遍历开始前记录当前队列的大小（即当前层的节点个数）。
//    - 定义变量 `sum` 用于累加当前层节点的值。
//    - 遍历当前层的节点：
//      - 弹出队首节点，并将其值累加到 `sum` 中。
//      - 将当前节点的左子节点入队（如果有）。
//      - 将当前节点的右子节点入队（如果有）。
//    - 计算当前层节点的平均值，并将其存入 `averages` 数组中。
// 5. 返回 `averages` 数组。


#include <bits/stdc++.h>
using namespace std;

// 二叉树的节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> averages;
    if (root == NULL)
        return averages;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        double sum = 0;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        double average = sum / size;
        averages.push_back(average);
    }

    return averages;
}

// 辅助函数，根据输入构建二叉树
TreeNode* buildTree(const vector<int>& nums, int index) {
    if (index >= nums.size() || nums[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nums[index]);
    root->left = buildTree(nums, 2 * index + 1);
    root->right = buildTree(nums, 2 * index + 2);
    return root;
}

// 测试样例
int main() {
    // 读取输入的二叉树
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') {
            break;
        }
    }

    // 构建二叉树
    TreeNode* root = buildTree(nums, 0);

    vector<double> averages = averageOfLevels(root);

    // 输出结果
    for (double average : averages) {
        cout << average << " ";
    }
    cout << endl;

    return 0;
}