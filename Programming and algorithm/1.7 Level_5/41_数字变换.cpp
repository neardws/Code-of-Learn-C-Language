// 12F:数字变换
// http://cxsjsx.openjudge.cn/practise2020pool/12F/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 给定一个包含5个数字（0-9）的字符串，例如 “02943”，请将“12345”变换到它。 你可以采取3种操作进行变换

// 1. 交换相邻的两个数字
// 2. 将一个数字加1。如果加1后大于9，则变为0
// 3. 将一个数字加倍。如果加倍后大于9,则将其变为加倍后的结果除以10的余数。

// 最多只能用第2种操作3次，第3种操作2次 求最少经过多少次操作可以完成变换。

// 输入
// 有最多 100,000 组数据
// 每组数据就是包含5个数字的字符串
// 输出
// 对每组数据，输出将"12345"变换到给定字符串所需要的最少操作步数。如果无法变换成功，输出-1
// 样例输入
// 12435
// 99999
// 12374
// 样例输出
// 1
// -1
// 3
// 提示
// 由于测试数据太多，如果对每组数据都从头进行搜索，就会超时。

#include<bits/stdc++.h>
using namespace std;
char a[6] = "12345";
bool vis[100000][4][3];
int ans[100000];
struct node{
    string a;
    int op2, op3, step;
    node(string aa, int o2, int o3, int ss = 0):a(aa),op2(o2),op3(o3), step(ss){};
};
queue<node>q;
int main(){
    memset(vis, false, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    q.push(node("12345",0,0));
    vis[12345][0][0] = true;
    ans[12345] = 0;
    while(!q.empty()){
        node no = q.front();
        q.pop();
        string temp = no.a;
        if(ans[int(atof(temp.c_str()))]==-1)ans[int(atof(temp.c_str()))] = no.step;
        //第一种操作
        for(int i = 0; i < 4; i++){
            swap(temp[i], temp[i+1]);
            if(!vis[int(atof(temp.c_str()))][no.op2][no.op3]){
                vis[int(atof(temp.c_str()))][no.op2][no.op3] = true;
                q.push(node(temp, no.op2, no.op3, no.step+1));
            }
            swap(temp[i], temp[i+1]);
        }
        //第二种操作
        if(no.op2<3){
            for(int i = 0; i < 5; i++){
                temp = no.a;
                int num = temp[i] - '0';
                num++;
                if(num==10) num = 0;
                temp[i] = '0'+num;
                if(!vis[int(atof(temp.c_str()))][no.op2+1][no.op3]){
                    vis[int(atof(temp.c_str()))][no.op2+1][no.op3] = true;
                    q.push(node(temp, no.op2+1, no.op3, no.step+1));
                }
            }
        }
        //第三种操作
        if(no.op3<2){
            for(int i = 0; i < 5; i++){
                temp = no.a;
                int num = temp[i] - '0';
                num*=2;
                if(num>9) num %= 10;
                temp[i] = '0'+num;
                if(!vis[int(atof(temp.c_str()))][no.op2][no.op3+1]){
                    vis[int(atof(temp.c_str()))][no.op2][no.op3+1] = true;
                    q.push(node(temp, no.op2, no.op3+1, no.step+1));
                }
            }
        }
    }
    while(cin>>a){
        cout<<ans[int(atof(a))]<<endl;
    }
    return 0;
}