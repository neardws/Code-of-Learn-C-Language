// 中缀表达式的值
// 中缀表达式的值
// 人们熟悉的四则运算表达式称为中缀表达式，例如(23+34*45/(5+6+7))。
// 在程序设计语言中，可以利用堆栈的方法把中缀表达式转换成保值的后缀表达式（又称逆波兰表示法），
// 并最终变为计算机可以直接执行的指令，得到表达式的值。 给定一个中缀表达式，编写程序，利用堆栈的方法，计算表达式的值。
// 时间限制：200
// 内存限制：65536
// 输入
// 第一行为测试数据的组数N 接下来的N行，每行是一个中缀表达式。表达式中只含数字、四则运算符和圆括号，
// 操作数都是正整数，数和运算符、括号之间没有空格。中缀表达式的字符串长度不超过600。
// 输出
// 对每一组测试数据输出一行，为表达式的值
// 样例输入
// 3
// 3+5*8
// (3+5)*8
// (23+34*45/(5+6+7))
// 样例输出
// 43
// 64
// 108
// 提示
// 注意：运算过程均为整数运算（除法运算'/'即按照C++定义的int除以int的结果，
// 测试数据不会出现除数为0的情况），输出结果也为整数（可能为负）。 中间计算结果可能为负。
// 运行测试

// 解题思路如下：
// 读入中缀表达式，并利用堆栈将其转换为后缀表达式。
// 遍历后缀表达式，遇到操作数就将其压入操作数堆栈，遇到运算符就从操作数堆栈中弹出两个操作数进行运算，
// 并将结果压入操作数堆栈。
// 遍历完后缀表达式之后，操作数堆栈中的元素就是最终结果。
// 输出结果。

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    scanf("%d%*c",&N); //%*c用于读取换行符，避免影响下一次读取
    while(N--)
    {
        char a[1001],b[1001];
        gets(a); //读取中缀表达式
        stack<char> hou; //存储运算符的堆栈
        stack<int> ji; //存储操作数的堆栈
        int i,h=0;
        int len=strlen(a);
        for(i=0; i<len; i++)
        {
            if(isalnum(a[i])) //如果是数字或字母，则将其拷贝到后缀表达式中
            {
                while(isalnum(a[i])&&i<len)
                {
                    b[h++]=a[i++];
                }
                b[h++]='!'; //使用'!'分隔不同的操作数
            }
            if(a[i]=='(')hou.push(a[i]); //左括号入栈
            if(a[i]=='*'||a[i]=='/'){ //乘、除法
                while(!hou.empty()&&hou.top()!='('&&(hou.top()=='*'||hou.top()=='/')){
                    b[h++]=hou.top(); //将优先级比当前运算符高的运算符出栈
                    hou.pop();
                }
                    hou.push(a[i]); //当前运算符入栈
            }
            if(a[i]=='+'||a[i]=='-') //加、减法
            {
                while(!hou.empty()&&hou.top()!='('&&(hou.top()=='*'||hou.top()=='/'||hou.top()=='+'||hou.top()=='-'))
                {
                    b[h++]=hou.top(); //将优先级比当前运算符高的运算符出栈
                    hou.pop();
                }
                hou.push(a[i]); //当前运算符入栈
            }
            if(a[i]==')') //右括号
            {
                while(!hou.empty()&&hou.top()!='(')
                {
                    b[h++]=hou.top(); //将栈中的运算符出栈，直到遇到左括号
                    hou.pop();
                }
                hou.pop(); //弹出左括号
            }
        }
        while(!hou.empty()) //将栈中剩余的运算符出栈
        {
            b[h++]=hou.top();
            hou.pop();
        }
                int T[100]= {0}, G=0; //T数组用于存储操作数，G表示T数组的下标
        int a1,a2;
        int ans;
        for(i=0; i<h; i++) //遍历后缀表达式
        {
            if(isalnum(b[i])) //如果是操作数
            {
                while(b[i]!='!'&&i<h) //拼接操作数，直到遇到'!'
                {
                    T[G]=T[G]*10+(b[i]-'0');
                    i++;
                }
                if(b[i]=='!')
                {
                    ji.push(T[G]);
                    G++;
                }
            }
 
            if(b[i]=='+') //加法
            {
                if(!ji.empty())
                {
                    a1=ji.top();
                    ji.pop();
                }
                if(!ji.empty())
                {
                    a2=ji.top();
                    ji.pop();
                }
                ans=a1+a2;
                ji.push(ans); //将计算结果压入堆栈
            }
            if(b[i]=='*') //乘法
            {
                if(!ji.empty())
                {
                    a1=ji.top();
                    ji.pop();
                }
                if(!ji.empty())
                {
                    a2=ji.top();
                    ji.pop();
                }
                ans=a1*a2;
                ji.push(ans); //将计算结果压入堆栈
            }
            if(b[i]=='-') //减法
            {
                if(!ji.empty())
                {
                    a1=ji.top();
                    ji.pop();
                }
                if(!ji.empty())
                {
                    a2=ji.top();
                    ji.pop();
                }
                ans=a2-a1;
                ji.push(ans); //将计算结果压入堆栈
            }
            if(b[i]=='/') //除法
            {
                if(!ji.empty())
                {
                    a1=ji.top();
                    ji.pop();
                }
                if(!ji.empty())
                {
                    a2=ji.top();
                    ji.pop();
                }
                ans=a2/a1;
                ji.push(ans); //将计算结果压入堆栈
            }
        }
        if(!ji.empty()){ans=ji.top();} //最终结果
        printf("%d\n",ans); //输出结果
    }
    return 0;
}
