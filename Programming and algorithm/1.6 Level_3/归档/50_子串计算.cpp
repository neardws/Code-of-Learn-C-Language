// 2472:子串计算
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 给出一个只包含0和1的字符串（长度在1到100之间），求其每一个子串出现的次数。

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
    char str[105];  //字符串，用来存储子串
    int count;  //出现次数
};
struct obj b[60000];    //用来存储子串数组
int indexOfBArr=0;      //b[]的下标,indexOfBArr表示b[]真正使用的行数

void fun(char temp[]){      //扫描b[]的每一行对应的子串，检验是否已经保存temp[]这个子串。
    int i;
    if(indexOfBArr == 0) {      //如果b[]为空，则直接将temp[]放入b[]
        strcpy(b[0].str,temp);  //将temp[]放入b[]，strcpy 函数用来拷贝字符串
        b[0].count=1;           //计数器设置为1
        indexOfBArr++;          //b[]的下标加1
        return;
    }
    for(i=0; i < indexOfBArr; i++){     //遍历b[]
        if(strcmp(b[i].str,temp)==0){   //如果b[]中已经存在temp[]这个子串，则计数器加1
            b[i].count++;               //计数器加1
            return;
        }
    }
    strcpy(b[indexOfBArr].str,temp);    //如果b[]中不存在temp[]这个子串，则将temp[]放入b[]
    b[indexOfBArr].count=1;             //计数器设置为1
    indexOfBArr++;                      //b[]的下标加1
}
int cmp(const void *a, const void *b){   //用来排序的函数
    struct obj x,y;
    x=*(struct obj *)a;              //将a指针指向的结构体拷贝到x中
    y=*(struct obj *)b;              //将b指针指向的结构体拷贝到y中
    return strcmp(x.str,y.str);      //比较x.str和y.str的字符串，strcmp函数用来比较字符串
}

int main(){
    char a[105],temp[105];
    int i,j,len,k,t;

    scanf("%s",a);
    // cin>>a;

    len=strlen(a);

    //枚举所有子串
    for(i=0;i<len;i++){         //枚举子串的开始点
        k=0;
        for(j=i;j<len;j++)      //枚举子串的结束点
        {
            temp[k]=a[j];
            k++;
            temp[k]='\0';       //字符串结束符
            fun(temp);          //扫描b[]的每一行对应的子串，检验是否已经保存temp[]这个子串。
        }
    }
    qsort(b,indexOfBArr,sizeof(b[0]),cmp);  //快速排序

    for(i=0;i<indexOfBArr;i++){
        if(b[i].count>1)        //如果出现次数大于1，则输出
            printf("%s %d\n",b[i].str,b[i].count);
            // cout<<b[i].str<<" "<<b[i].count<<endl;
    }
    return 0;
}
