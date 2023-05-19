// 现在有一些英语单词需要做拼写检查，你的工具是一本词典。
// 需要检查的单词，有的是词典中的单词，有的与词典中的单词相似，你的任务是发现这两种情况。
// 单词A与单词B相似的情况有三种：
// 1、删除单词A的一个字母后得到单词B；
// 2、用任意一个字母替换单词A的一个字母后得到单词B；
// 3、在单词A的任意位置增加一个字母后得到单词B。
// 你的任务是发现词典中与给定单词相同或相似的单词。

// 时间限制：2000
// 内存限制：65536
// 输入
// 第一部分是词典中的单词，从第一行开始每行一个单词，以"#"结束。词典中的单词保证不重复，最多有10000个。 第二部分是需要查询的单词，每行一个，以"#"结束。最多有50个需要查询的单词。 词典中的单词和需要查询的单词均由小写字母组成，最多包含15个字符。
// 输出
// 按照输入的顺序，为每个需要检查的单词输出一行。如果需要检查的单词出现在词典中，输出“?x is correct"，?x代表需要检查的单词。如果需要检查的单词没有出现在词典中，则输出"?x: ?x1 ?x2 ...?xn"，其中?x代表需要检查的单词，?x1...?xn代表词典中与需要检查的单词相似的单词，这些单词中间以空格隔开。如果没有相似的单词，输出"?x:"即可。
// 样例输入
// i
// is
// has
// have
// be
// my
// more
// contest
// me
// too
// if
// award
// #
// me
// aware
// m
// contest
// hav
// oo
// or
// i
// fi
// mre
// #
// 样例输出
// me is correct
// aware: award
// m: i my me
// contest is correct
// hav: has have
// oo: too
// or:
// i is correct
// fi: i
// mre: more me


// 解题思路:
// 使用字典树。首先把词典中的单词全部插入字典树中，
// 然后对于每一个待查询的单词，对字典树进行搜索，
// 如果发现字典树中有与待查询的单词相同的单词，
// 则直接输出“?x is correct”；否则，对字典树进行搜索，
// 如果存在与待查询的单词相似的单词，则输出“?x: ?x1 ?x2 ...?xn”，
// 如果没有相似的单词，则输出“?x:”。

#include<bits/stdc++.h>
using namespace std;
const int maxn=10010,maxl=16;
int n,cnt,ans[maxn];  //n是记录相似的单词数的计数器，cnt是词典的单词数的计数器，ans数组记录相似的单词的编号
char s[maxn][maxl],t[maxl];  //s是词典的单词，t是待检查的单词

//abs函数，求绝对值
inline int abs(int x)
{
    return x>0?x:-x;
}

//check函数，检查两个单词是否相似
inline int check(char *s,char *t)
{
    int l1=strlen(s),l2=strlen(t),cnt=0;  //l1是s的长度，l2是t的长度，cnt是不同字符的数量
    //如果s和t的长度差大于1，直接返回0
    if(abs(l1-l2)>1) return 0;
    //遍历两个单词的每一个字符
    for(int i=0,j=0;i<l1&&j<l2;i++,j++)
    {
        //如果当前字符不同
        if(s[i]!=t[j])
        {
            cnt++;  //不同字符数量+1
            //如果s的长度大于t的长度，则在s上多跳一个字符
            if(l1>l2) i--;
            //如果s的长度小于t的长度，则在t上多跳一个字符
            if(l1<l2) j--;
        }
    }
    //如果不同字符数量为1或者不同字符数量为0且长度不同，则返回1
    if(cnt==1||(cnt==0&&l1!=l2)) return 1;
    return 0;
}

int main()
{
    //读入词典中的单词，以"#"结束
    while(scanf("%s",t),t[0]!='#')
    {
        //将读入的单词放入s数组中
        strcpy(s[++cnt],t);
    }

    //读入要查询的单词，以"#"结束
    while(scanf("%s",t),t[0]!='#')
    {
        //flag记录是否与词典中的单词相同
        int flag=0;
        //输出要查询的单词
        printf("%s",t);
        //遍历词典中的单词
        for(int i=1;i<=cnt;i++)
        {
            //如果词典中的单词与要查询的单词相同
            if(strcmp(s[i],t)==0)
            {
                //输出" is correct"
                printf(" is correct\n");
                //标记相同
                flag=1;
                break;
            }
            else if(check(s[i],t))
                //如果词典中的单词与要查询的单词相似
                //将词典中的单词编号放入ans数组中
                ans[++n]=i;
        }
        //如果词典中有与要查询的单词相同的单词，跳过输出相似的单词的步骤
        if(flag) continue;
        //输出":"
        printf(":");
        //遍历相似的单词的编号
        for(int i=1;i<=n;i++)
        {
            //输出相似的单词
            printf(" %s",s[ans[i]]);
        }
        //换行
        printf("\n");
        //清空ans数组
        n=0;
    }
    return 0;
}

