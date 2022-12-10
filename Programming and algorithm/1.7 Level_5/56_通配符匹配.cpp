// 通配符匹配
// 给定一个字符串s和一个字符模式p，请实现一个支持？和*的通配符匹配功能。
// 其中’？可以匹配任何单个字符，如a?c'可以成功
// 匹配'aac,abc'等字符串，但不可匹配'ac',aaac'等字符串。
// ，可以匹配任意长度字符串（包括空字符串），如'a*c'可以成功匹配'ac','abdc','abc', 'aaac'等字符串，但不可匹配'acb’，‘cac'等字符串。
// 两个字符串完全匹配才算匹配成功。
// 时间限制：2000
// 内存限制：262144
// 输入
// 输入为一个数字n表示测试字符串与字符模式对数，换行。(n§30)后续2n行为每组匹配的s与
// p，每行字符串后换行。s非空，只包含从a-z的小写字母。p非空，只包含从a-z的小写字母，以及字符？和*。字符串s和p的长度均小于50
// 输出
// 每一组匹配串匹配成功输出yes',否则输出'no'。

#include<bits/stdc++.h>
using namespace std;

//如果s和p中字符匹配，则分别自增i和j
//否则如果p中当前字符为星号，则标记iStar和jStar，同时自增j
//否则如果iStar >= 0，表示之前匹配过星号，因为星号可以匹配任意字符串，所以继续递增i，同时移动j为jStar下一个字符
//否则返回false
bool isMatch(string s, string p) {
    //i为s的指针，j为p的指针
    //iStar记录当p中遇到‘*’时，当前i位置
    //jStar记录当p中遇到‘*’时，当前j位置
    int i = 0, j = 0, iStar = -1, jStar = -1, m = s.size(), n = p.size();
    //以i指针未到m为条件
    while (i < m){
        //如果当前字符匹配或者p[j]为？时都匹配，两个指针指向下一个字符
        if (j < n && (s[i] == p[j] || p[j] == '?')){
            ++i;
            ++j;
        }//判断p[j]为 '*'的情况，使用iStar记录i的位置，jStar记录j的位置，i不动，j往后移动来匹配当前i
        else if (j < n &&  p[j] == '*'){
            iStar = i;
            jStar = j++;
        }//如果匹配 '*'后面不成功，那么iStar向后移动位置，j重置到'*'的下一个字符
        else if (iStar >= 0){
            i = ++iStar;
            j = jStar + 1;
        }//其他情况都返回false
        else 
            return false;
    }
    //如果j后面还有'*'，就都删除
    while (j < n && p[j] == '*') 
        ++j;
    return j == n;
}

int main(){
	int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string num1;
        string num2;
        cin>> num1 >> num2;
        if (isMatch(num1, num2))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
	return 0;
}
