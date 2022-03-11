// 1973:确定进制

// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 6*9 = 42 对于十进制来说是错误的，但是对于13进制来说是正确的。
// 即, 6(13) * 9(13) = 42(13)， 而 42(13) = 4 * 131+ 2 * 130= 54(10)。 
// 你的任务是写一段程序读入三个整数p、q和 r，然后确定一个进制 B(2<=B<=16) 使得 p * q = r. 
// 如果 B有很多选择, 输出最小的一个。例如： p = 11, q = 11, r = 121. 
// 则有 11(3) * 11(3) = 121(3) 因为 11(3) = 1 * 31+ 1 * 30= 4(10) 
// 和 121(3) = 1 * 32+ 2 * 31+ 1 * 30= 16(10)。 
// 对于进制 10,有 11(10) * 11(10) = 121(10)。这种情况下，应该输出 3。如果没有合适的进制，则输出 0。

// 输入
// 一行，包含三个整数p、q、r，相邻两个整数之间用单个空格隔开。 p、q、r的所有位都是数字，并且1 <= p、q、r <= 1,000,000。
// 输出
// 一个整数：即使得p * q = r成立的最小的B。如果没有合适的B，则输出 0。
// 样例输入
// 6 9 42
// 样例输出
// 13
// 来源
// Taejon 2002, POJ 1331, 程序设计实习07

#include<bits/stdc++.h>
using namespace std;
long long to_base(long long n, int b){
    if(n == 0) 
        return 0;
    long long m = n;
    long long sum = 0;
    int j = 0;
    while(m){
        if(b <= m % 10)
            return -1;
        long long bb = 1;
        for(int i = 1; i <= j; i++)
            bb *= b;
        sum += m % 10 * bb;
        m /= 10;
        j++;
    }
    return sum;
}

int main(){
    long long p, q, r;
    cin>>p>>q>>r;
    int ans = 0;
    for(int i = 2; i <= 16; i++){
        long long base_p = to_base(p, i);
        if(base_p == -1)
            continue;
        long long base_q = to_base(q, i);
        if(base_q == -1)
            continue;
        long long base_r = to_base(r, i);
        if(base_r == -1)
            continue;
        if(base_p * base_q == base_r){
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}