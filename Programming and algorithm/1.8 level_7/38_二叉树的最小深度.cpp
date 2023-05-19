// 111. 二叉树的最小深度
// 给定一个二叉树，找出其最小深度。

// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

// 说明：叶子节点是指没有子节点的节点。

// 示例 1：

// 输入：root = [3,9,20,null,null,15,7]
// 输出：2
// 示例 2：

// 输入：root = [2,null,3,null,4,null,5,null,6]
// 输出：5

// 提示：

// 树中节点数的范围在 [0, 105] 内
// -1000 <= Node.val <= 1000

// 解题思路：
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
// 我们可以使用广度优先搜索（BFS）来解决这个问题。
// 从根节点开始，逐层遍历二叉树的节点，直到找到第一个叶子节点为止。返回的就是最小深度。

// 具体步骤如下：
// 1. 若根节点为空，则返回0。
// 2. 初始化一个队列，并将根节点加入队列。
// 3. 初始化一个变量depth，表示深度，初始值为1。
// 4. 进入循环，直到队列为空。
//    - 4.1 遍历当前队列中的所有节点，将它们的左右子节点加入队列。
//    - 4.2 如果当前节点没有左右子节点，说明找到了最小深度的叶子节点，返回depth。
//    - 4.3 否则，depth加1。
//    - 4.4 将当前节点出队。
// 5. 如果循环结束后仍然没有找到叶子节点，返回0。


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

int minDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    int depth = 1;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // 如果当前节点没有左右子节点，即为叶子节点
            if (node->left == NULL && node->right == NULL) {
                return depth;
            }

            if (node->left != NULL) {
                q.push(node->left);
            }

            if (node->right != NULL) {
                q.push(node->right);
            }
        }
        depth++;
    }

    return 0;
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

    cout << minDepth(root) << endl;

    return 0;
}
