// 1789:算24
// http://noi.openjudge.cn/ch0205/1789/
// 总时间限制: 3000ms 内存限制: 65536kB
// 描述
// 给出4个小于10个正整数，你可以使用加减乘除4种运算以及括号把这4个数连接起来得到一个表达式。
// 现在的问题是，是否存在一种方式使得得到的表达式的结果等于24。

// 这里加减乘除以及括号的运算结果和运算的优先级跟我们平常的定义一致（这里的除法定义是实数除法）。

// 比如，对于5，5，5，1，我们知道5 * (5 – 1 / 5) = 24，因此可以得到24。又比如，对于1，1，4，2，我们怎么都不能得到24。
// 输入
// 输入数据包括多行，每行给出一组测试数据，包括4个小于10个正整数。最后一组测试数据中包括4个0，表示输入的结束，这组数据不用处理。
// 输出
// 对于每一组测试数据，输出一行，如果可以得到24，输出“YES”；否则，输出“NO”。
// 样例输入
// 5 5 5 1
// 1 1 4 2
// 0 0 0 0
// 样例输出
// YES
// NO

#include<bits/stdc++.h>
using namespace std;
bool Op(double a[],int n)
{
    double Next[5];//用来保存下一次运算数据
    if(n==1&&abs(a[0]-24)<0.00001)
                //因为是实数，所以不能直接进行判断
        return true;
    if(n==1)
        return false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int t=1;
            for(int k=0;k<n;k++){
                if(k!=i&&k!=j)
                    Next[t++]=a[k];//保存没有进行运算的数字
                }
    //各种运算都进行一次来搜索，保存在第一个里面，方便判断
            Next[0]=a[i]+a[j];
            if(Op(Next,n-1))return true;
            Next[0]=a[i]-a[j];
            if(Op(Next,n-1))return true;
            Next[0]=a[j]-a[i];
            if(Op(Next,n-1))return true;
            Next[0]=a[i]*a[j];
            if(Op(Next,n-1))return true;
            Next[0]=a[i]/a[j];
            if(Op(Next,n-1))return true;
            Next[0]=a[j]/a[i];
            if(Op(Next,n-1))return true;
        }
    }
    return false;
}
int main()
{
    while(1){
        double a[5];
        int sum=0;
        for(int i=0;i<4;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum==0)
            break;
        if(Op(a,4))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}