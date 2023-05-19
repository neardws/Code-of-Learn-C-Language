// 662. 二叉树最大宽度
// 给你一棵二叉树的根节点 root ，返回树的 最大宽度 。

// 树的 最大宽度 是所有层中最大的 宽度 。

// 每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。
// 将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的 null 节点，这些 null 节点也计入长度。

// 题目数据保证答案将会在  32 位 带符号整数范围内。


// 示例 1：


// 输入：root = [1,3,2,5,3,null,9]
// 输出：4
// 解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。
// 示例 2：


// 输入：root = [1,3,2,5,null,null,9,6,null,7]
// 输出：7
// 解释：最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。
// 示例 3：


// 输入：root = [1,3,2,5]
// 输出：2
// 解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。


// 提示：

// 树中节点的数目范围是 [1, 3000]
// -100 <= Node.val <= 100


// 题目要求找到二叉树的最大宽度，其中宽度定义为每一层最左和最右非空节点之间的距离（包括空节点）。
// 我们可以使用层序遍历的方式来解决这个问题。

// 算法步骤：
// 1. 定义一个队列，用于层序遍历二叉树。队列中的每个元素包含节点的指针和该节点在当前层的位置编号。
// 2. 初始化最大宽度为0。
// 3. 开始层序遍历，首先将根节点入队，位置编号为0。
// 4. 在每一层遍历开始前记录当前队列的大小（即当前层的节点个数）。
// 5. 遍历当前层的节点：
//    - 弹出队首节点，并记录其位置编号为left。
//    - 如果节点有左子节点，则将左子节点入队，并记录其位置编号为left*2。
//    - 如果节点有右子节点，则将右子节点入队，并记录其位置编号为left*2+1。
//    - 更新最大宽度为当前层的最右节点位置减去最左节点位置加1。
// 6. 返回最大宽度。


#include <bits/stdc++.h>
using namespace std;

// 二叉树的节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL)
        return 0;

    int maxWidth = 0;
    queue<pair<TreeNode*, long long>> q; // 队列中存储节点和其位置编号
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        long long left = q.front().second;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front().first;
            long long pos = q.front().second;
            q.pop();

            if (node->left) {
                q.push({node->left, pos * 2});
            }
            if (node->right) {
                q.push({node->right, pos * 2 + 1});
            }

            maxWidth = max(maxWidth, (int)(pos - left + 1));
        }
    }

    return maxWidth;
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

    int maxWidth = widthOfBinaryTree(root);
    cout << maxWidth << endl;

    return 0;
}
