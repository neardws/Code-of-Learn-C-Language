//  表达式求值
// 求一个可能包含加、减、乘、除、乘方运算的中缀表达式的值。
// 在计算机中，我们常用栈来解决这一问题。首先将中缀表达式转换到后缀表达式，然后对后缀表达式求值。
// 加、减、乘、除、乘方分别用+，-，*, /, ^来表示。表达式可以有圆括号()。
// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行为测试数据的组数N。 接下来的N行，每行是一个中缀表达式。 每个表达式中，圆括号、运算符和运算数相互之间都用空格分隔，运算数是整数。一般运算数可正可负（负数的符号和数字之间无空格），指数一定为自然数(0和正整数)。不必考虑除0的情况。每个运算数均可由int放下。不必考虑溢出。中缀表达式的字符串长度不超过600。乘方的优先级比乘除都高，结合性是向左结合，如2 ^ 3 ^ 4表示( 2 ^ 3 ) ^ 4 = 4096。除法的商向下取整。
// 输出
// 对每一组测试数据输出一行，为表达式的值
// 样例输入
// 2
// 31 * ( 5 - ( -3 + 25 ) ) + 70 ^ 2
// 2 * 5 + 6 * ( 7 - 8 ) + 6
// 样例输出
// 4373
// 10

// 思路：
// 1.定义一个运算符栈和一个操作数栈，以及一个后缀表达式字符串。
// 2.遍历中缀表达式，如果遇到操作数，则直接放入后缀表达式中。
// 3.如果遇到左括号，将其压入运算符栈中。
// 4.如果遇到右括号，则将运算符栈中的运算符弹出，直到弹出左括号，并将这一对括号内的操作符放入后缀表达式中。
// 5.如果遇到运算符，则将其与运算符栈中的运算符进行比较，如果优先级高，则将其压入运算符栈中；否则，将运算符栈中的运算符弹出，直到该运算符的优先级高于栈顶运算符，并将这些运算符放入后缀表达式中，最后将该运算符压入运算符栈中。
// 6.遍历完中缀表达式后，将运算符栈中的运算符依次弹出，放入后缀表达式中。
// 7.遍历后缀表达式，将操作数放入操作数栈中，遇到运算符时，弹出栈顶的两个操作数进行运算，并将结果压入操作数栈中。
// 8.遍历完后缀表达式后，操作数栈中的栈顶元素即为表达式的值。

#include <bits/stdc++.h>
using namespace std;

// 定义运算符优先级
int priority(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

// 将中缀表达式转换为后缀表达式
string infixToPostfix(const string& infix) {
    string postfix;
    stack<char> opStack;

    istringstream iss(infix);

    string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            while (!opStack.empty() && opStack.top() != '(' && priority(token[0]) <= priority(opStack.top())) {
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            opStack.push(token[0]);
        } else if (token == "(") {
            opStack.push('(');
        } else if (token == ")") {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == '(') {
                opStack.pop();
            }
        } else {
            postfix += token;
            postfix += ' ';
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        postfix += ' ';
        opStack.pop();
    }

    return postfix;
}

// 后缀表达式求值
int postfixEvaluate(const string& postfix) {
    stack<int> operandStack;

    istringstream iss(postfix);

    string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            int y = operandStack.top();
            operandStack.pop();
            int x = operandStack.top();
            operandStack.pop();
            if (token == "+") {
                operandStack.push(x + y);
            } else if (token == "-") {
                operandStack.push(x - y);
            } else if (token == "*") {
                operandStack.push(x * y);
            } else if (token == "/") {
                operandStack.push(x / y);
            } else if (token == "^") {
                operandStack.push(pow(x, y));
            }
        } else {
            operandStack.push(stoi(token));
        }
    }

    return operandStack.top();
}

int main() {
    int n;
    cin >> n;

    cin.ignore(); // 忽略第一行末尾的换行符

    for (int i = 0; i < n; i++) {
        string infix;
        getline(cin, infix);

        string postfix = infixToPostfix(infix);
        int result = postfixEvaluate(postfix);

        cout << result << endl;
    }

    return 0;
}


