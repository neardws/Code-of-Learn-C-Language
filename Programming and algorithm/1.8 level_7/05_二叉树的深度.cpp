// 二叉树的深度
// 给定一棵二叉树，求该二叉树的深度
// 二叉树深度定义：从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的节点个数为树的深度
// 时间限制：1000
// 内存限制：65535
// 输入
// 第一行是一个整数n，表示二叉树的结点个数。二叉树结点编号从1到n，根结点为1，n <= 10 接下来有n行，依次对应二叉树的n个节点。 每行有两个整数，分别表示该节点的左儿子和右儿子的节点编号。如果第一个（第二个）数为-1则表示没有左（右）儿子
// 输出
// 输出一个整型数，表示树的深度
// 样例输入
// 3
// 2 3
// -1 -1
// -1 -1
// 样例输出
// 2

// 解题思路：
// 题目要求我们计算给定二叉树的深度。我们可以使用递归算法来解决。

// 二叉树的深度可以定义为根节点到叶节点的最长路径上的节点数。因此，我们可以使用递归算法来计算二叉树的深度。对于每个节点，我们可以递归地计算其左子树和右子树的深度，然后取其最大值加一即为该节点的深度。递归结束条件为节点为空，此时返回 0。

// 最终，我们可以将递归计算得到的每个节点的深度取最大值即为二叉树的深度。

// 在主函数中，我们首先读入二叉树的结点个数 n。然后，我们创建一个根节点为 1 的二叉树，并按照输入的节点编号和左右儿子编号构建二叉树。如果某个节点的左儿子或右儿子为 -1，则表示该节点没有左儿子或右儿子。

// 最后，我们调用 maxDepth 函数计算二叉树的深度，并输出结果。

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归函数，用于计算二叉树的深度
int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);  // 递归计算左子树的深度
    int rightDepth = maxDepth(root->right);  // 递归计算右子树的深度

    return max(leftDepth, rightDepth) + 1;  // 取左右子树深度的最大值加一，即为当前节点的深度
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = new TreeNode(1);
    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        if (left != -1) {
            TreeNode* leftNode = new TreeNode(left);
            root->left = leftNode;
        }
        if (right != -1) {
            TreeNode* rightNode = new TreeNode(right);
            root->right = rightNode;
        }
    }

    cout << maxDepth(root) << endl;  // 输出二叉树的深度

    return 0;
}
