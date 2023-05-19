// 奇怪的括号
// 某天小A和同学在课堂上讨论到：“栈这种数据结构真是太优美了，既简单用途又广泛。”小B仰慕
// 小A许久，于是他拿出了自己在网上抄写的一道题问小A，如何判断括号是否匹配呢

// 时间限制：1000
// 内存限制：65536
// 输入
// 多组数据，每组数据占一行，且都是由(、)、[、]、*、/这六种字符组成。
// 输出
// 每组数据输出一行，如果括号能匹配成功，输出True，否则输出False。括号匹配规则是：
//  ( 和 ) 匹配 [ 和 ] 匹配 /* 和 */ 匹配 如果含有冗余字符也算匹配失败，例如 /***/ 是匹配失败的因为中间多了一个*。
// 样例输入
// ()/*[()]*/
//. */**/
// 样例输出
// True
// False

// 本题可以使用栈来判断括号是否匹配。具体地，我们依次扫描字符串中的每个字符，如果是左括号，则将其入栈；
// 如果是右括号，则判断栈顶元素是否是与之匹配的左括号，如果匹配，则将栈顶元素出栈，否则说明括号不匹配，直接输出 False。
// 如果扫描完整个字符串后，栈为空，则说明括号匹配成功，输出 True，否则输出 False。

// 需要注意的是，题目中还有一个特殊的规则，即 /* 和 */ 可以匹配。我们可以把这两个字符视为一对括号，
// 使用一个标志变量来记录是否遇到了这两个字符。如果遇到了 /*，则将标志变量设置为 true，直到遇到了 */，
// 则将标志变量设置为 false。在匹配括号的过程中，如果遇到了 ，则需要判断前面是否有一个 /*，
// 如果有，则说明这是一个 /，可以直接入栈。

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    bool isComment = false;  // 标志变量，记录是否处于注释中
    for (char c : s) {
        if (c == '(' || c == '[' || c == '/') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                return false;
            }
            st.pop();
        } else if (c == '*') {
            if (!st.empty() && st.top() == '/') {
                st.pop();
                isComment = true;
            }
        } else if (c == '/') {
            if (!st.empty() && st.top() == '*') {
                st.pop();
                isComment = false;
            } else {
                st.push(c);
            }
        } else if (!isComment) {  // 如果不是括号或注释中的字符，则说明括号不匹配
            return false;
        }
    }
    return st.empty();
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (isValid(s)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    return 0;
}
