/* 04:填空：类型转换1

总时间限制: 1000ms 内存限制: 65536kB
描述
有两个变量a和b，在执行了如下代码后：

a = 32768;
b = a;
printf("%d %d\n", a, b);
输出两个数：32768 -32768

请问a和b分别是以下哪种类型？

A. bool   B. char   C. short   D. int   
E. float   F. double

输入
无。
输出
一行，包含两个大写字母，分别代表变量a和b的类型标号。中间用一个空格隔开。
样例输入
无
样例输出
A B
// 仅作格式示例，非正确答案 
来源
http://noi.openjudge.cn/ch0102/04/
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    short b;
    a = 32768;
    b = a;
    printf("D C\n");
    // printf("%d %d\n", a, b);
    return 0;
}