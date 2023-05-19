// 226. 翻转二叉树
// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

// 示例 1：

// 输入：root = [4,2,7,1,3,6,9]
// 输出：[4,7,2,9,6,3,1]
// 示例 2：

// 输入：root = [2,1,3]
// 输出：[2,3,1]
// 示例 3：

// 输入：root = []
// 输出：[]

// 提示：

// 树中节点数目范围在 [0, 100] 内
// -100 <= Node.val <= 100

// 题目要求翻转一棵二叉树并返回翻转后的根节点。
// 我们可以使用递归或迭代的方法解决该问题。

// 解题思路：
// 1. 如果根节点为空，直接返回空。
// 2. 交换根节点的左右子节点。
// 3. 递归调用翻转左右子树。
// 4. 返回翻转后的根节点。

#include <bits/stdc++.h>
using namespace std;

// 定义二叉树节点的结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 处理特殊情况，根节点为空，直接返回
        if (root == nullptr) {
            return nullptr;
        }

        // 交换根节点的左右子节点
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // 递归翻转左右子树
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

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

// 辅助函数，按照中序遍历打印二叉树
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    Solution solution;

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

    // 翻转二叉树
    TreeNode* invertedRoot = solution.invertTree(root);

    // 输出翻转后二叉树中序遍历结果
    inorderTraversal(invertedRoot);
    cout << endl;

    return 0;
}
