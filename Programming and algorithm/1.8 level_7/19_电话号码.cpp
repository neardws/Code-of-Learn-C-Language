// 电话号码
// 给你一些电话号码，请判断它们是否是一致的，即是否有某个电话是另一个电话的前缀。比如：

// Emergency 911
// Alice 97 625 999
// Bob 91 12 54 26

// 在这个例子中，我们不可能拨通Bob的电话，因为Emergency的电话是它的前缀，当拨打Bob的电话时会先接通Emergency，所以这些电话号码不是一致的。
// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行是一个整数t，1 ≤ t ≤ 40，表示测试数据的数目。 每个测试样例的第一行是一个整数n，1 ≤ n ≤ 10000，其后n行每行是一个不超过10位的电话号码。
// 输出
// 对于每个测试数据，如果是一致的输出“YES”，如果不是输出“NO”。
// 样例输入
// 2
// 3
// 911
// 97625999
// 91125426
// 5
// 113
// 12340
// 123440
// 12345
// 98346
// 样例输出
// NO
// YES


// 解题思路：
// 1. 先将电话号码按照长度从小到大排序，这样可以避免重复的判断；
// 2. 从头开始遍历每一个电话号码，与其他的电话号码作比较，
// 如果它是另一个电话号码的前缀，则将该电话号码的标记数组st[j]标记为true；
// 3. 最后遍历标记数组st，如果存在st[i]为true，则表示这些电话号码不是一致的，
// 输出"NO"；否则输出"YES"。


#include<bits/stdc++.h>
using namespace std;
const int N=10010;
bool st[N]; // 标记数组，st[i]为true表示第i个电话号码是另一个电话号码的前缀
vector<string> vec; // 用vector存储电话号码
int t,n;
bool check(string a,string b) // 判断a是否是b的前缀
{
    int len=a.size();
    for(int i=0;i<len;i++)
    {
        if(a[i]!=b[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        vec.clear(); // 每组数据清空vector
        memset(st,false,sizeof(st)); // 每组数据标记数组清空
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            vec.push_back(s);
        }
        sort(vec.begin(),vec.end(),[](string a,string b){return a.size()<b.size();}); // 按照字符串长度排序
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(check(vec[i],vec[j]))
                {
                    st[j]=true;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(st[i])
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
