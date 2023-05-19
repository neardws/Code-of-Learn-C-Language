// 257. 二叉树的所有路径
// 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

// 叶子节点 是指没有子节点的节点。


// 示例 1：


// 输入：root = [1,2,3,null,5]
// 输出：["1->2->5","1->3"]
// 示例 2：

// 输入：root = [1]
// 输出：["1"]


// 提示：

// 树中节点的数目在范围 [1, 100] 内
// -100 <= Node.val <= 100

// 题目要求找出二叉树中所有从根节点到叶子节点的路径。路径定义为从根节点到叶子节点经过的节点值，使用箭头 "->" 连接。

// 为了求解这个问题，我们可以使用深度优先搜索（DFS）遍历二叉树，并在遍历的过程中记录路径。当遍历到叶子节点时，将路径转换为字符串形式，并保存到结果集中。

// 算法步骤：
// 1. 定义一个结果集 `result`，用于保存所有路径的字符串表示。
// 2. 调用递归函数 `dfs`，传入根节点、当前路径的字符串 `path` 以及结果集 `result`。
// 3. 在 `dfs` 函数中：
//    - 如果当前节点为空，直接返回。
//    - 将当前节点的值转换为字符串，并添加到路径 `path` 中。
//    - 如果当前节点为叶子节点，将路径 `path` 添加到结果集 `result` 中。
//    - 递归遍历当前节点的左子树，传入更新后的路径 `path`。
//    - 递归遍历当前节点的右子树，传入更新后的路径 `path`。
// 4. 返回结果集 `result`。

#include <bits/stdc++.h>
using namespace std;

// 二叉树的节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, string path, vector<string>& result) {
    if (root == NULL)
        return;

    // 将当前节点的值转换为字符串，并添加到路径中
    path += to_string(root->val);

    // 如果当前节点是叶子节点，将路径添加到结果集中
    if (root->left == NULL && root->right == NULL) {
        result.push_back(path);
        return;
    }

    // 非叶子节点，继续遍历左子树和右子树
    path += "->";
    dfs(root->left, path, result);
    dfs(root->right, path, result);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    dfs(root, "", result);
    return result;
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

    vector<string> paths = binaryTreePaths(root);

    // 输出结果
    for (string path : paths) {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}
