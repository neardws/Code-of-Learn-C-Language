// 逆波兰表达式
// 逆波兰表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的逆波兰表示法为+ 2 3。
// 逆波兰表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，
// 例如(2 + 3) * 4的逆波兰表示法为* + 2 3 4。本题求解逆波兰表达式的值，其中运算符包括+ - * /四个。
// 时间限制：1000
// 内存限制：65536
// 输入
// 输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。
// 输出
// 输出为一行，表达式的值。 可直接用printf("%f\n", v)输出表达式的值v。
// 样例输入
//. * + 11.0 12.0 + 24.0 35.0
// 样例输出
// 1357.000000

// 这道题的解题思路如下：

// 读入逆波兰表达式，按空格分隔读入运算符和操作数。
// 如果遇到操作数，则将其转换为浮点数并压入栈中。
// 如果遇到运算符，则从栈中弹出相应数量的操作数进行运算，并将运算结果压入栈中。
// 遍历完逆波兰表达式之后，栈中仅剩的元素就是最终结果。
// 输出结果。


#include <bits/stdc++.h>

using namespace std;

const int N = 40;
char a[N];
stack<double> st;

int main()
{
    while (~scanf("%s", a)) { //按空格分隔读入运算符和操作数
        if (a[0] == '+') { //加法
            double x = st.top(); st.pop();
            double y = st.top(); st.pop();
            st.push(x + y);
        } else if (a[0] == '-') { //减法
            double x = st.top(); st.pop();
            double y = st.top(); st.pop();
            st.push(y - x);
        } else if (a[0] == '*') { //乘法
            double x = st.top(); st.pop();
            double y = st.top(); st.pop();
            st.push(x * y);
        } else if (a[0] == '/') { //除法
            double x = st.top(); st.pop();
            double y = st.top(); st.pop();
            st.push(y / x);
        } else { //操作数
            st.push(atof(a)); //将字符串转换为浮点数并压入栈
        }
    }
    printf("%.6lf\n", st.top()); //输出最终结果
    return 0;
}

