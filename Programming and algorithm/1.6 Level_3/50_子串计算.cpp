// 子串计算
// 给出一个只包含0和1的字符串（长度在1到100之间），求其每一个子串出现的次数。

// 时间限制：1000
// 内存限制：65536
// 输入
// 一行，一个01字符串。
// 输出
// 对所有出现次数在1次以上的子串，输出该子串及出现次数，中间用单个空格隔开。按子串的字典序从小到大依次输出，每行一个。
// 样例输入
// 10101
// 样例输出
// 0 2
// 01 2
// 1 3
// 10 2
// 101 2

#include<bits/stdc++.h>
using namespace std;
struct obj{
    char str[105];
    int count;
};
struct obj b[60000];
int indexOfBArr=0; //b[]的下标,indexOfBArr表示b[]真正使用的行数

void fun(char temp[]){//扫描b[]的每一行对应的子串，检验是否已经保存temp[]这个子串。
    int i;
    if(indexOfBArr==0) { strcpy(b[0].str,temp);  b[0].count=1; indexOfBArr++; return;}
    for(i=0;i<indexOfBArr;i++){
        if(strcmp(b[i].str,temp)==0){ 
            b[i].count++; 
            return;
        }
    }
    strcpy(b[indexOfBArr].str,temp);
    b[indexOfBArr].count=1;
    indexOfBArr++;
}
int cmp(const void *a,const void *b){
    struct obj x,y;
    x=*(struct obj *)a;
    y=*(struct obj *)b;
    return strcmp(x.str,y.str);
}

int main(int argc, char *argv[]){
    char a[105],temp[105];
    int i,j,len,k,t;

    scanf("%s",a);
    len=strlen(a);

    //枚举所有子串
    for(i=0;i<len;i++){//枚举子串的开始点
        k=0;
        for(j=i;j<len;j++)//枚举子串的结束点
        {
            temp[k]=a[j];
            k++;
            temp[k]='\0';
            fun(temp);//扫描b[]的每一行对应的子串，检验是否已经保存temp[]这个子串。
        }
    }
    qsort(b,indexOfBArr,sizeof(b[0]),cmp);

    for(i=0;i<indexOfBArr;i++){
        if(b[i].count>1)
            printf("%s %d\n",b[i].str,b[i].count);
    }/**/
    return 0;
}
