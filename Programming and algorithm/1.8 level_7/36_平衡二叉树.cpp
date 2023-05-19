// 110. 平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树。

// 本题中，一棵高度平衡二叉树定义为：

// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

// 示例 1：

// 输入：root = [3,9,20,null,null,15,7]
// 输出：true
// 示例 2：


// 输入：root = [1,2,2,3,3,null,null,4,4]
// 输出：false
// 示例 3：

// 输入：root = []
// 输出：true

// 提示：

// 树中的节点数在范围 [0, 5000] 内
// -104 <= Node.val <= 104

// 解题思路：
// 题目要求判断给定的二叉树是否是高度平衡的二叉树，其中高度平衡二叉树的定义是：
// 二叉树的每个节点的左右子树的高度差的绝对值不超过1。

// 为了解决这个问题，我们可以使用递归的方法。对于每个节点，
// 我们可以通过计算其左子树和右子树的高度来判断其是否平衡。
// 如果左右子树的高度差超过1，或者左子树或右子树不是平衡二叉树，
// 则该节点及其子树不是平衡二叉树。

// 具体的解题思路如下：

// 定义一个辅助函数getHeight，用于计算给定节点的高度。如果节点为空，返回0；
// 否则，返回节点的左右子树高度的较大值加1。
// 定义主函数isBalanced，用于判断给定的二叉树是否是平衡二叉树。
// 如果根节点为空，直接返回true，因为空树也是平衡二叉树。
// 否则，使用递归判断根节点的左右子树是否是平衡二叉树。
// 如果左子树或右子树不是平衡二叉树，返回false。
// 否则，判断根节点的左右子树高度差的绝对值是否大于1，如果大于1，返回false；
// 否则，返回true。


#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 计算二叉树的高度
    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

    // 判断二叉树是否是高度平衡的
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);
        if (!leftBalanced || !rightBalanced) {
            return false;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return std::abs(leftHeight - rightHeight) <= 1;
    }
};

// 构建二叉树
TreeNode* buildTree(const std::vector<std::string>& nodes) {
    if (nodes.empty()) {
        return nullptr;
    }

    std::queue<TreeNode*> nodeQueue;
    TreeNode* root = new TreeNode(std::stoi(nodes[0]));
    nodeQueue.push(root);

    int i = 1;
    while (!nodeQueue.empty() && i < nodes.size()) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        // 构建左子树
        if (i < nodes.size() && nodes[i] != "null") {
            node->left = new TreeNode(std::stoi(nodes[i]));
            nodeQueue.push(node->left);
        }
        i++;

        // 构建右子树
        if (i < nodes.size() && nodes[i] != "null") {
            node->right = new TreeNode(std::stoi(nodes[i]));
            nodeQueue.push(node->right);
        }
        i++;
    }

    return root;
}

// 将输入的字符串按照指定的分隔符拆分成字符串数组
std::vector<std::string> splitString(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    Solution solution;

    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> nodes = splitString(input, ',');

    TreeNode* root = buildTree(nodes);

    bool balanced = solution.isBalanced(root);
    std::cout << (balanced ? "true" : "false") << std::endl;

    return 0;
}
