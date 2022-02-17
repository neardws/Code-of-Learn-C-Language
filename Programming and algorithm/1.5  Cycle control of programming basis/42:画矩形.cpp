/* 42:画矩形
总时间限制: 1000ms 内存限制: 65536kB
描述
根据参数，画出矩形。
输入
输入一行，包括四个参数：前两个参数为整数，依次代表矩形的高和宽
（高不少于3行不多于10行，宽不少于5列不多于10列）；
第三个参数是一个字符，表示用来画图的矩形符号；
第四个参数为1或0，0代表空心，1代表实心。
输出
输出画出的图形。
样例输入
7 7 @ 0
样例输出
@@@@@@@
@     @
@     @
@     @
@     @
@     @
@@@@@@@
来源
http://noi.openjudge.cn/ch0105/42/ */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int h, w;
    char c;
    int t;
    cin>>h>>w>>c>>t;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if (t == 0){
                if (i > 1 && i < h && j > 1 && j < w)
                    cout<<" ";
                else
                    cout<<c;
            }
            else{
                cout<<c;
            }
        }
        cout<<endl;
    }
    return 0;
}