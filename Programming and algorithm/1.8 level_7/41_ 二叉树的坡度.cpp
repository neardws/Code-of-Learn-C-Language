// 563. 二叉树的坡度
// 给你一个二叉树的根节点 root ，计算并返回 整个树 的坡度 。

// 一个树的 节点的坡度 定义即为，该节点左子树的节点之和和右子树节点之和的 差的绝对值 。
// 如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。
// 空结点的坡度是 0 。
// 整个树 的坡度就是其所有节点的坡度之和。

// 示例 1：

// 输入：root = [1,2,3]
// 输出：1
// 解释：
// 节点 2 的坡度：|0-0| = 0（没有子节点）
// 节点 3 的坡度：|0-0| = 0（没有子节点）
// 节点 1 的坡度：|2-3| = 1（左子树就是左子节点，所以和是 2 ；右子树就是右子节点，所以和是 3 ）
// 坡度总和：0 + 0 + 1 = 1
// 示例 2：

// 输入：root = [4,2,9,3,5,null,7]
// 输出：15
// 解释：
// 节点 3 的坡度：|0-0| = 0（没有子节点）
// 节点 5 的坡度：|0-0| = 0（没有子节点）
// 节点 7 的坡度：|0-0| = 0（没有子节点）
// 节点 2 的坡度：|3-5| = 2（左子树就是左子节点，所以和是 3 ；右子树就是右子节点，所以和是 5 ）
// 节点 9 的坡度：|0-7| = 7（没有左子树，所以和是 0 ；右子树正好是右子节点，所以和是 7 ）
// 节点 4 的坡度：|(3+5+2)-(9+7)| = |10-16| = 6（左子树值为 3、5 和 2 ，和是 10 ；右子树值为 9 和 7 ，和是 16 ）
// 坡度总和：0 + 0 + 0 + 2 + 7 + 6 = 15
// 示例 3：

// 输入：root = [21,7,14,1,1,2,2,3,3]
// 输出：9

// 提示：

// 树中节点数目的范围在 [0, 104] 内
// -1000 <= Node.val <= 1000

// 题目要求计算二叉树的坡度，其中节点的坡度定义为该节点左子树节点之和与右子树节点之和的差的绝对值。
// 整个树的坡度是所有节点坡度之和。

// 为了计算坡度，我们可以使用深度优先搜索（DFS）遍历二叉树的每个节点，
// 同时计算节点的子树节点之和。在遍历过程中，累加节点的坡度，
// 并计算左子树节点之和和右子树节点之和。

// 算法步骤：
// 1. 定义一个全局变量 `totalTilt`，用于记录整个树的坡度之和。
// 2. 调用递归函数 `getTilt`，传入根节点作为参数。
// 3. 在 `getTilt` 函数中：
//    - 如果当前节点为空，则返回0。
//    - 递归计算当前节点的左子树节点之和，将结果保存在变量 `leftSum` 中。
//    - 递归计算当前节点的右子树节点之和，将结果保存在变量 `rightSum` 中。
//    - 计算当前节点的坡度，即左子树节点之和与右子树节点之和的差的绝对值，
//    累加到 `totalTilt` 中。
//    - 返回当前节点的节点之和，即左子树节点之和、右子树节点之和和当前节点值的和。
// 4. 返回 `totalTilt`。

#include <bits/stdc++.h>
using namespace std;

// 二叉树的节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归函数，计算节点的坡度并返回节点之和
int getTilt(TreeNode* root, int& totalTilt) {
    if (root == NULL)
        return 0;

    // 递归计算左子树节点之和
    int leftSum = getTilt(root->left, totalTilt);

    // 递归计算右子树节点之和
    int rightSum = getTilt(root->right, totalTilt);

    // 计算当前节点的坡度
    int tilt = abs(leftSum - rightSum);
    totalTilt += tilt;

    // 返回节点之和（包括左子树、右子树和当前节点的值）
    return leftSum + rightSum + root->val;
}

// 计算二叉树的坡度
int findTilt(TreeNode* root) {
    int totalTilt = 0;
    getTilt(root, totalTilt);
    return totalTilt;
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

    int tilt = findTilt(root);
    cout << tilt << endl;

    return 0;
}


