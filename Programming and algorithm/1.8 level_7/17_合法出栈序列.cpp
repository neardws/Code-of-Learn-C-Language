// 合法出栈序列
// 给定一个由不同小写字母构成的长度不超过8的字符串x，现在要将该字符串的字符依次压入栈中，然后再全部弹出。

// 要求左边的字符一定比右边的字符先入栈，出栈顺序无要求。

// 再给定若干字符串，对每个字符串，判断其是否是可能的x中的字符的出栈序列。

// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行是原始字符串x 后面有若干行，每行一个字符串
// 输出
// 对除第一行以外的每个字符串，判断其是否是可能的出栈序列。如果是，输出"YES"，否则，输出"NO"
// 样例输入
// abc
// abc
// bca
// cab
// 样例输出
// YES
// YES
// NO

// 可以使用一个栈来模拟出栈的过程。具体地，我们依次将x中的字符压入栈中，然后按照给定的字符串的顺序依次出栈，如果出栈的字符和当前栈顶元素相同，则将栈顶元素出栈，否则将给定字符串的下一个字符入栈，直到所有的字符都出栈。
// 对于每个给定的字符串，我们可以按照上述方法进行模拟，如果最终栈为空，则该字符串是一个可能的出栈序列，否则不是。

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 判断str是否是x的一个合法出栈序列
bool isValid(string x, string str) {
    stack<char> st;
    int i = 0, j = 0;
    while (i < x.length()) {
        st.push(x[i++]);  // x中的字符依次入栈
        while (!st.empty() && j < str.length() && st.top() == str[j]) {
            st.pop();  // 如果栈顶元素和给定字符串的当前字符相同，则出栈
            j++;
        }
    }
    return st.empty();  // 如果最终栈为空，则说明该字符串是一个可能的出栈序列
}

int main() {
    string x;
    cin >> x;

    string str;
    while (cin >> str) {
        if (isValid(x, str)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
