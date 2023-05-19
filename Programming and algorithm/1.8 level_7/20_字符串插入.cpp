// 字符串插入
// 有两个字符串str和substr，str的字符个数不超过10，substr的字符个数为3。（
// 字符个数不包括字符串结尾处的'\0'。）将substr插入到str中ASCII码最大的那个字符后面，
// 若有多个最大则只考虑第一个。
// 时间限制：1000
// 内存限制：65536
// 输入
// 输入包括若干行，每一行为一组测试数据，格式为 str substr
// 输出
// 对于每一组测试数据，输出插入之后的字符串。
// 样例输入
// abcab eee
// 12343 555
// 样例输出
// abceeeab
// 12345553

// 解题思路：

// 1. 遍历原字符串str，找到ASCII码最大的字符；
// 2. 将substr插入到ASCII码最大字符的下一个位置；
// 3. 输出插入后的字符串。

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str,substr;
    while(cin>>str>>substr) // 循环读入字符串和子字符串
    {
        int len=str.size(); // 获取字符串str的长度
        int maxn=0; // 初始化ASCII码最大值
        int pos=0; // 初始化ASCII码最大字符的位置
        for(int i=0;i<len;i++)
        {
            if(str[i]>maxn) // 如果当前字符的ASCII码比maxn大
            {
                maxn=str[i]; // 更新ASCII码最大值
                pos=i; // 更新ASCII码最大字符的位置
            }
        }
        str.insert(pos+1,substr); // 在ASCII码最大字符的下一个位置插入substr
        cout<<str<<endl; // 输出插入后的字符串
    }
    return 0;
}
