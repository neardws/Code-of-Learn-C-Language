// 543. 二叉树的直径
// 给定一棵二叉树，你需要计算它的直径长度。
// 一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
// 这条路径可能穿过也可能不穿过根结点。

// 示例 :
// 给定二叉树

//           1
//          / \
//         2   3
//        / \     
//       4   5    
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。



// 注意：两结点之间的路径长度是以它们之间边的数目表示。

// 题目要求计算二叉树的直径长度，直径长度定义为任意两个节点路径长度中的最大值。
// 路径可以穿过根节点，也可以不穿过根节点。

// 为了计算直径长度，我们可以使用深度优先搜索（DFS）来遍历二叉树的每个节点，
// 并计算经过该节点的最长路径（即左子树深度 + 右子树深度）。

// 算法步骤：
// 1. 定义一个变量 `maxDiameter`，用于记录直径长度的最大值。
// 2. 调用递归函数 `getDiameter`，传入根节点作为参数。
// 3. 在 `getDiameter` 函数中：
//    - 如果当前节点为空，则返回0。
//    - 递归计算当前节点的左子树深度，将结果保存在变量 `leftDepth` 中。
//    - 递归计算当前节点的右子树深度，将结果保存在变量 `rightDepth` 中。
//    - 计算当前节点的直径长度，即左子树深度 + 右子树深度。
//    - 更新 `maxDiameter` 为当前直径长度和 `maxDiameter` 的较大值。
//    - 返回当前节点的深度，即左子树深度和右子树深度中的较大值加1。
// 4. 返回 `maxDiameter`。


#include <bits/stdc++.h>
using namespace std;

// 二叉树的节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getDiameter(TreeNode* root, int& maxDiameter) {
    if (root == NULL)
        return 0;

    int leftDepth = getDiameter(root->left, maxDiameter);
    int rightDepth = getDiameter(root->right, maxDiameter);

    int diameter = leftDepth + rightDepth;
    maxDiameter = max(maxDiameter, diameter);

    return max(leftDepth, rightDepth) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxDiameter = 0;
    getDiameter(root, maxDiameter);
    return maxDiameter;
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

    int diameter = diameterOfBinaryTree(root);
    cout <<  diameter << endl;

    return 0;
}
