// 表达式·表达式树·表达式求值
// 众所周知，任何一个表达式，都可以用一棵表达式树来表示。例如，表达式a+b*c，可以表示为如下的表达式树：

//    +
//   / \
//  a   *
//     / \
//     b c

// 现在，给你一个中缀表达式，这个中缀表达式用变量来表示（不含数字），请你将这个中缀表达式用表达式二叉树的形式输出出来。

// 时间限制：1000
// 内存限制：65535
// 输入
// 输入分为三个部分。 第一部分为一行，即中缀表达式(长度不大于50)。中缀表达式可能含有小写字母代表变量（a-z），也可能含有运算符（+、-、*、/、小括号），不含有数字，也不含有空格。 第二部分为一个整数n(n < 10)，表示中缀表达式的变量数。 第三部分有n行，每行格式为C　x，C为变量的字符，x为该变量的值。
// 输出
// 输出分为三个部分，第一个部分为该表达式的逆波兰式，即该表达式树的后根遍历结果。占一行。 第二部分为表达式树的显示，如样例输出所示。如果该二叉树是一棵满二叉树，则最底部的叶子结点，分别占据横坐标的第1、3、5、7……个位置（最左边的坐标是1），然后它们的父结点的横坐标，在两个子结点的中间。如果不是满二叉树，则没有结点的地方，用空格填充（但请略去所有的行末空格）。每一行父结点与子结点中隔开一行，用斜杠（/）与反斜杠（\）来表示树的关系。/出现的横坐标位置为父结点的横坐标偏左一格，\出现的横坐标位置为父结点的横坐标偏右一格。也就是说，如果树高为m，则输出就有2m-1行。 第三部分为一个整数，表示将值代入变量之后，该中缀表达式的值。需要注意的一点是，除法代表整除运算，即舍弃小数点后的部分。同时，测试数据保证不会出现除以0的现象。
// 样例输入
// a+b*c
// 3
// a 2
// b 7
// c 5
// 样例输出
// abc*+
//    +
//   / \
//  a   *
//     / \
//     b c
// 37


// 解题思路：
// 首先需要将中缀表达式转化为后缀表达式（也叫逆波兰式），然后再通过后缀表达式构建表达式树。最后对表达式树进行后序遍历得到逆波兰式，中序遍历得到中缀表达式，并计算表达式的值。

// 具体步骤如下：

// 1. 将中缀表达式转化为后缀表达式。使用栈来完成转换，具体转换规则如下：
//     如果遇到操作数，直接将其输出。
//     如果遇到左括号，将其压入栈中。
//     如果遇到右括号，则将栈中的元素弹出并输出，直到遇到左括号为止，左括号不输出。
//     如果遇到操作符，若栈为空，则直接将该操作符压入栈中；否则，比较该操作符与栈顶操作符的优先级，如果该操作符优先级不高于栈顶操作符优先级，则将栈顶操作符弹出并输出，直到该操作符优先级大于栈顶操作符优先级或栈为空，最后将该操作符压入栈中。
// 2. 根据后缀表达式构建表达式树。使用栈来完成构建，具体构建规则如下：
//     如果遇到操作数，创建一个只包含该操作数的节点，将该节点压入栈中。
//     如果遇到操作符，创建一个只包含该操作符的节点，将该节点的右孩子设置为栈顶元素，将栈顶元素弹出，再将该节点的左孩子设置为栈顶元素，将该节点压入栈中。
// 3. 对表达式树进行后序遍历，得到逆波兰式；对表达式树进行中序遍历，得到中缀表达式。同时，可以计算表达式的值，方法是使用栈来完成计算，具体计算规则如下：
//     如果遇到操作数，将其入栈。
//     如果遇到操作符，将栈顶的两个元素弹出进行运算，将结果入栈。
// 在实现过程中，可以使用一个结构体来表示表达式树节点，包含左孩子、右孩子和操作符（如果是操作数则为0），同时需要记录每个节点的横坐标。在输出表达式树时，可以使用递归来完成。


#include <bits/stdc++.h>

using namespace std;

// 表达式树节点
struct TreeNode {
    char op;
    TreeNode* left;
    TreeNode* right;
    int x;  // 节点横坐标
    TreeNode(char c) : op(c), left(NULL), right(NULL), x(-1) {}
};

// 根据中缀表达式获取后缀表达式（逆波兰式）
vector<char> getPostfixExpression(string s) {
    stack<char> opStack;
    vector<char> postfixExp;
    map<char, int> opPriority;  // 操作符优先级
    opPriority['+'] = opPriority['-'] = 1;
    opPriority['*'] = opPriority['/'] = 2;
    opPriority['('] = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isalpha(c)) {  // 操作数直接输出
            postfixExp.push_back(c);
        } else if (c == '(') {  // 左括号入栈
            opStack.push(c);
        } else if (c == ')') {  // 右括号弹出栈中元素直到遇到左括号
            while (opStack.top() != '(') {
                postfixExp.push_back(opStack.top());
                opStack.pop();
            }
            opStack.pop();  // 弹出左括号
        } else {  // 操作符
            while (!opStack.empty() && opPriority[c] <= opPriority[opStack.top()]) {
                postfixExp.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(c);
        }
    }
    while (!opStack.empty()) {  // 将栈中剩余的元素弹出
        postfixExp.push_back(opStack.top());
        opStack.pop();
    }
    return postfixExp;
}

// 根据后缀表达式构建表达式树
TreeNode* buildExpressionTree(vector<char>& postfixExp, map<char, int>& varValues) {
    stack<TreeNode*> nodeStack;
    for (char c : postfixExp) {
        if (isalpha(c)) {  // 操作数创建节点并入栈
            TreeNode* node = new TreeNode(c);
            node->x = varValues[c];
            nodeStack.push(node);
        } else {  // 操作符创建节点并弹出两个子节点
            TreeNode* node = new TreeNode(c);
            node->right = nodeStack.top();
            nodeStack.pop();
            node->left = nodeStack.top();
            nodeStack.pop();
            nodeStack.push(node);
        }
    }
    return nodeStack.top();
}

// 获取表达式树的高度
int getHeight(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

// 打印表达式树
void printExpressionTree(TreeNode* root, int depth, int pos) {
    if (!root) {
        return;
    }
    // 先打印右子树
    printExpressionTree(root->right, depth + 1, pos + 1);
    // 打印当前节点
    for (int i = 0; i < depth; i++) {
        cout << " ";
    }
    cout << root->op << "(" << root->x << ")" << endl;
    // 打印左子树
    printExpressionTree(root->left, depth + 1, pos - 1);

    return;
}

// 计算表达式树的值
int calculateExpressionTree(TreeNode* root) {
    if (!root) {
        return 0;
    }
    if (isalpha(root->op)) {  // 叶子节点是变量，返回其值
        return root->x;
    }
    int leftVal = calculateExpressionTree(root->left);
    int rightVal = calculateExpressionTree(root->right);
    switch (root->op) {  // 根据操作符计算值
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        default: return 0;
    }
}

int main() {
    // 读入中缀表达式
    string infixExp;
    cin >> infixExp;

    // 读入变量个数和值
    int n;
    cin >> n;
    map<char, int> varValues;
    for (int i = 0; i < n; i++) {
        char var;
        int value;
        cin >> var >> value;
        varValues[var] = value;
    }

    // 获取后缀表达式
    vector<char> postfixExp = getPostfixExpression(infixExp);

    // 构建表达式树
    TreeNode* root = buildExpressionTree(postfixExp, varValues);

    // 输出逆波兰式（后根遍历结果）
    for (char c : postfixExp) {
        cout << c;
    }
    cout << endl;

    // 输出表达式树
    int height = getHeight(root);
    int width = 2 * height - 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << " ";
        }
        printExpressionTree(root, 0, height - i - 1);
        cout << endl;
    }

    // 计算表达式的值
    int result = calculateExpressionTree(root);
    cout << result << endl;

    return 0;
}

