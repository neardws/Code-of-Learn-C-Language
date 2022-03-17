// 表达式求值
// 输入一个布尔表达式，请你输出它的真假值。
// 比如：( V  V ) & F & ( F  V )
// V表示true，F表示false，&表示与，表示或，!表示非。
// 上式的结果是F

// 时间限制：1000
// 内存限制：65536
// 输入
// 输入包含多行，每行一个布尔表达式，表达式中可以有空格，总长度不超过1000
// 输出
// 对每行输入，如果表达式为真，输出V,否则出来F
// 样例输入
// ( V  V ) & F & ( F V)
// !V  V & V & !F & (F  V ) & (!F  F  !V & V)
// (F&FV!V&!F&!(FF&V))
// 样例输出
// F
// V
// V

// 本题的思路是，将中缀表达式转化为前缀表达式在计算，只是代码实现比较麻烦。
// 中缀转前缀的步骤如下：
// (1) 首先构造一个运算符栈(也可放置括号)，
// 运算符(以括号分界点)在栈内遵循越往栈顶优先级不降低的原则进行排列。
// (2)从右至左扫描中缀表达式，从右边第一个字符开始判断：
// 如果当前字符是数字，则分析到数字串的结尾并将数字串直接输出。
// 如果是运算符，则比较优先级。
// 如果当前运算符的优先级大于等于栈顶运算符的优先级(当栈顶是括号时，直接入栈)，
// 则将运算符直接入栈；否则将栈顶运算符出栈并输出，
// 直到当前运算符的优先级大于等于栈顶运算符的优先级(当栈顶是括号时，直接入栈)，
// 再将当前运算符入栈。
// 如果是括号，则根据括号的方向进行处理。
// 如果是右括号，则直接入栈；
// 否则，遇左括号前将所有的运算符全部出栈并输出，
// 遇右括号后将左右的两括号一起删除。
// (3) 重复上述操作(2)直至扫描结束，
// 将栈内剩余运算符全部出栈并输出，
// 再逆缀输出字符串。中缀表达式也就转换为前缀表达式了。


#include<bits/stdc++.h>
using namespace std;
char calculate(char x, char y, char oper){// 计算 x oper y
    bool a=(x=='V'),b=(y=='V'),ans;
    if(oper=='|') 
        ans=(a||b);
    else if(oper=='&') 
        ans=(a&&b);
    return 
        ans?'V':'F';
}
char reverse(char x){ //将逻辑值取反。其实就是‘！’运算符
    if(x=='V')
        return 'F';
    return 'V';
}
int main(){
    string in;
    int i,j,len;
    while(getline(cin,in)){
        stack<char> Oper,num; //oper保存运算符，num保存运算结果
        queue<char> s;        //s就是前缀表达式
        len=in.length();
        i=len;
        in=" "+in;
        while(i>0){// 从右往左，中缀表达式转前缀表达式
            if(in[i]==' '){
                i--;continue;
            }
            else if(isalpha(in[i])) 
                s.push(in[i--]);//isalpha()函数：如果参数是字母字符，函数返回非零值，否则返回零值
            else if(in[i]=='!')  
                s.push(in[i--]);    //最高级的运算，直接进入表达式(这里主要是因为！运算符是单目运算符)
            else{
                if(in[i]=='&'||in[i]=='|'||in[i]==')')  //低级运算，进栈
                    Oper.push(in[i--]);
                else if(in[i]=='('){  //一个括号结束，弹出中间的所有运算符
                    while(Oper.top()!=')'){
                        s.push(Oper.top());
                        Oper.pop();
                    }
                    Oper.pop();
                    i--;
                }
            }
        }
        while(!Oper.empty())  //栈中剩下的运算符
            s.push(Oper.top()),Oper.pop();
        while(!s.empty()){  //计算前缀表达式
            char ch=s.front(); s.pop();
            if(isalpha(ch))  num.push(ch);
            else Oper.push(ch);
            if(!num.empty()&&!Oper.empty()&&Oper.top()=='!'){  //单目运算符‘！’；
                char x=num.top();
                num.pop();Oper.pop();
                num.push(reverse(x));
            }
            else if(num.size()>=2&&!Oper.empty()){  //双目运算符
                char oper=Oper.top(),x,y;
                Oper.pop();
                x=num.top();num.pop();
                y=num.top();num.pop();
                num.push(calculate(x,y,oper));
            }
        }
        cout<<num.top()<<endl;
    }
}

