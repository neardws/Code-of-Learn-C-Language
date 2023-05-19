// 由中根序列和后根序列重建二叉树
// 我们知道如何按照三种深度优先次序来周游一棵
// 二叉树，来得到中根序列、前棖序列和后根序列。反过来，如果给定二叉树的中根序列和后根
// 序列，或者給定中根序列和前根序列，可以重建
// 一二叉树。本题输入一棵二叉树的中根序列和后根序列，要求在内存中重建二叉树，最后输出这棵二叉树的前根序列。
// 用不同的整数来唯一标识二叉树的每一个结点，下面的二叉树
// 5
// ハ
// 9 67
//   /
// 32
// 中根序列是9 5 32 67
// 后根序列9 32 67 5
// 前根序列5 9 67 32
// El PRE: 1000
// 内存限制：65536

// 重建二叉树
// 给定一棵二叉树的前序遍历和中序遍历的结果，求其后序遍历。
// 时间限制：1000
// 内存限制：65536
// 输入
// 输入可能有多组，以EOF结束。 每组输入包含两个字符串，分别为树的前序遍历和中序遍历。每个字符串中只包含大写字母且互不重复。
// 输出
// 对于每组输入，用一行来输出它后序遍历结果。
// 样例输入
// DBACEGF ABCDEFG
// BCAD CBAD
// 样例输出
// ACBFGED
// CDAB

// 解题思路：
// 题目要求通过给定的前序遍历和中序遍历结果，还原出原来的二叉树，并输出其后序遍历结果。我们可以通过递归的方式来实现。
// 首先，我们可以根据前序遍历的结果确定根节点，然后在中序遍历结果中找到该节点的位置，将中序遍历结果划分为左子树和右子树两部分。接着，递归处理左子树和右子树，并将它们作为当前节点的左右子节点。
// 最后，输出后序遍历结果即可。

// 其中，我们利用一个哈希表 in_map 来记录中序遍历结果中每个节点值对应的位置，以便快速地找到根节点在中序遍历结果中的位置。

// 在主函数中，我们使用 while (cin >> preorder >> inorder) 来循环读入多组输入，并对每组输入进行处理。对于每组输入，我们先根据中序遍历结果建立哈希表，然后调用 buildTree 函数来构建二叉树，最后调用 postorderTraversal 函数输出后序遍历结果。

#include <bits/stdc++.h>
using namespace std;

// TreeNode 结构体表示二叉树的节点
struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

// buildTree 函数用于构建二叉树
TreeNode* buildTree(string preorder, string inorder, int pre_left, int pre_right, int in_left, int in_right, unordered_map<char, int>& in_map) {
    if (pre_left > pre_right) {
        return nullptr;
    }

    // 前序遍历的第一个节点是根节点
    char root_val = preorder[pre_left];
    TreeNode* root = new TreeNode(root_val);

    // 在中序遍历结果中找到根节点位置，划分出左子树和右子树
    int in_root_idx = in_map[root_val];
    int left_tree_size = in_root_idx - in_left;

    // 递归处理左子树和右子树
    root->left = buildTree(preorder, inorder, pre_left+1, pre_left+left_tree_size, in_left, in_root_idx-1, in_map);
    root->right = buildTree(preorder, inorder, pre_left+left_tree_size+1, pre_right, in_root_idx+1, in_right, in_map);

    return root;
}

// postorderTraversal 函数用于后序遍历二叉树
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val;
}

int main() {
    string preorder, inorder;
    while (cin >> preorder >> inorder) {
        int n = preorder.size();
        unordered_map<char, int> in_map;
        for (int i = 0; i < n; i++) {
            in_map[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder, inorder, 0, n-1, 0, n-1, in_map);
        postorderTraversal(root);
        cout << endl;
    }
    return 0;
}

