// 1799:最短前缀
// http://noi.openjudge.cn/ch0406/1799/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 一个字符串的前缀是从该字符串的第一个字符起始的一个子串。
// 例如 "carbon"的字串是: "c", "ca", "car", "carb", "carbo", 和 "carbon"。
// 注意到这里我们不认为空串是字串, 但是每个非空串是它自身的字串. 我们现在希望能用前缀来缩略的表示单词。
// 例如, "carbohydrate" 通常用"carb"来缩略表示. 现在给你一组单词, 要求你找到唯一标识每个单词的最短前缀
// 在下面的例子中，"carbohydrate" 能被缩略成"carboh", 但是不能被缩略成"carbo" (或其余更短的前缀) 因为已经有一个单词用"carbo"开始
// 一个精确匹配会覆盖一个前缀匹配，例如，前缀"car"精确匹配单词"car". 
// 因此 "car" 是 "car"的缩略语是没有二义性的 , “car”不会被当成"carriage"或者任何在列表中以"car"开始的单词.

// 输入
// 输入包括至少2行，至多1000行. 每行包括一个以小写字母组成的单词，单词长度至少是1，至多是20.

// 输出
// 输出的行数与输入的行数相同。每行输出由相应行输入的单词开始，后面跟着一个空格接下来是相应单词的没有二义性的最短前缀标识符。

// 样例输入
// carbohydrate
// cart
// carburetor
// caramel
// caribou
// carbonic
// cartilage
// carbon
// carriage
// carton
// car
// carbonate

// 样例输出
// carbohydrate carboh
// cart cart
// carburetor carbu
// caramel cara
// caribou cari
// carbonic carboni
// cartilage carti
// carbon carbon
// carriage carr
// carton carto
// car car
// carbonate carbona

// 来源
// 翻译自Rocky Mountain 2004

#include<bits/stdc++.h>
using namespace std;
//可以用枚举
//枚举关键是子串的长度要从0循环到len，因为substr（x,y)，y是结束字符的后一位位置 
string a[1100];
int main(){
    int n=0;
    while(cin>>a[n])n++;
    for(int i=0;i<n;i++){
        int len=a[i].size();
        for(int j=0;j<=len;j++){//到Len 
            string tmp=a[i].substr(0,j);
            int flag=1;
            for(int k=0;k<n;k++){
                if(i!=k&&tmp==a[k].substr(0,j)){
                    flag=0;
                    break;
                }
            }
            if(flag||j==len){
                cout<<a[i]<<" "<<tmp<<endl;
                break;
            }
        }
    }
}