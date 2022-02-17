/*1750:全排列

总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。 我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。

输入
输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
输出
输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：

已知S = s1s2...sk , T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。
样例输入
abc
样例输出
abc
acb
bac
bca
cab
cba
http://noi.openjudge.cn/ch0202/1750/
*/

#include<bits/stdc++.h>
using namespace std;
string list_str[100];

void permute(string str, int start, int end) {
    if (start == end) {
        // cout << "start == end" << endl;
        // return;        
        list_str->push_back(str);
    }
    else{
        for (int i = start; i <= end; i++) {
            // cout<<"******************************"<<endl;
            // cout<<"i:"<<i<<endl;
            // cout<<str<<endl;
            // cout<<"swap:"<<str[start]<<" "<<str[i]<<endl;
            swap(str[i], str[start]);
            // cout<<str<<endl;
            permute(str, start + 1, end);  // 递归调用, n-1 的全排列
            
            // cout<<str<<endl;
            // cout<<"swap:"<<str[i]<<" "<<str[start]<<endl;
            swap(str[i], str[start]);
            // cout<<str<<endl;
        }
    }
}

int main(){
    string s;
    cin>>s;
    if (s.size() == 1)
        cout<<s<<endl;
    else
        permute(s, 0, s.size() - 1);
    return 0;
}
