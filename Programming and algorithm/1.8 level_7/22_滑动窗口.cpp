// 滑动窗口
// 给定一个长度为n（n<=10^6）的数组。有一个大小为k的滑动窗口从数组的最左端移动到最右端。
// 你可以看到窗口中的k个数字。窗口每次向右滑动一个数字的距离。
// 下面是一个例子：
// 数组是 [1 3 -1 -3 5 3 6 7]， k = 3。

// 窗口位置	                   最小值 最大值
// [1  3  -1] -3  5  3  6  7 	-1	3
//  1 [3  -1  -3] 5  3  6  7 	-3	3
//  1  3 [-1  -3  5] 3  6  7 	-3	5
//  1  3  -1 [-3  5  3] 6  7 	-3	5
//  1  3  -1  -3 [5  3  6] 7 	3	6
//  1  3  -1  -3  5 [3  6  7]	3	7


// 你的任务是得到滑动窗口在每个位置时的最大值和最小值。

// 时间限制：20000
// 内存限制：65536
// 输入
// 输入包括两行。 第一行包括n和k，分别表示数组的长度和窗口的大小。 第二行包括n个数字。
// 输出
// 输出包括两行。 第一行包括窗口从左至右移动的每个位置的最小值。 
// 第二行包括窗口从左至右移动的每个位置的最大值。
// 样例输入
// 8 3
// 1 3 -1 -3 5 3 6 7
// 样例输出
// -1 -3 -3 -3 3 3
// 3 3 5 5 6 7

// 解题思路：

// 这道题可以用双端队列来解决。

// 首先，遍历数组前k个数字，将它们的下标压入双端队列qmin和qmax中。
// 如果当前数字小于等于qmin的末尾的数字，就弹出末尾的数字；
// 如果当前数字大于等于qmax的末尾的数字，就弹出末尾的数字。

// 然后，从k开始遍历数组，如果当前数字小于等于qmin的末尾的数字，就弹出末尾的数字；
// 如果当前数字大于等于qmax的末尾的数字，就弹出末尾的数字。
// 将当前下标压入qmin和qmax中。如果qmin的头部的下标在滑动窗口外，就弹出头部的数字；
// 如果qmax的头部的下标在滑动窗口外，就弹出头部的数字。最后输出当前窗口的最小值和最大值。

// 这个过程的时间复杂度为O(n)，因为每个数字只会压入队列和弹出队列一次。


#include<bits/stdc++.h>
using namespace std;
const int N=1000005; // 定义数组长度
int a[N]; // 定义数组a存储输入的数字
deque<int>qmin,qmax; // 定义双端队列qmin存储最小值，qmax存储最大值
int main()
{
    int n,k;
    cin>>n>>k; // 读入数组长度和窗口的大小
    for(int i=0;i<n;i++)
    {
        cin>>a[i]; // 读入数字
    }
    for(int i=0;i<k;i++)
    {
        while(!qmin.empty()&&a[i]<=a[qmin.back()]) // 如果当前数字小于等于末尾的数字
        {
            qmin.pop_back(); // 弹出末尾的数字
        }
        while(!qmax.empty()&&a[i]>=a[qmax.back()]) // 如果当前数字大于等于末尾的数字
        {
            qmax.pop_back(); // 弹出末尾的数字
        }
        qmin.push_back(i); // 将当前下标压入qmin
        qmax.push_back(i); // 将当前下标压入qmax
    }
    cout<<a[qmin.front()]; // 输出第一个最小值
    for(int i=k;i<n;i++)
    {
        while(!qmin.empty()&&a[i]<=a[qmin.back()]) // 如果当前数字小于等于末尾的数字
        {
            qmin.pop_back(); // 弹出末尾的数字
        }
        while(!qmax.empty()&&a[i]>=a[qmax.back()]) // 如果当前数字大于等于末尾的数字
        {
            qmax.pop_back(); // 弹出末尾的数字
        }
        qmin.push_back(i); // 将当前下标压入qmin
        qmax.push_back(i); // 将当前下标压入qmax
        while(!qmin.empty()&&qmin.front()<=i-k) // 如果qmin的头部的下标在滑动窗口外
        {
            qmin.pop_front(); // 弹出头部的数字
        }
        while(!qmax.empty()&&qmax.front()<=i-k) // 如果qmax的头部的下标在滑动窗口外
        {
            qmax.pop_front(); // 弹出头部的数字
        }
        cout<<" "<<a[qmin.front()]; // 输出当前窗口的最小值
    }
    cout<<endl; // 换行
    cout<<a[qmax.front()]; // 输出第一个最大值
    for(int i=k;i<n;i++)
    {
        while(!qmin.empty()&&a[i]<=a[qmin.back()]) // 如果当前数字小于等于末尾的数字
        {
            qmin.pop_back(); // 弹出末尾的数字
        }
        while(!qmax.empty()&&a[i]>=a[qmax.back()]) // 如果当前数字大于等于末尾的数字
        {
            qmax.pop_back(); // 弹出末尾的数字
        }
        qmin.push_back(i); // 将当前下标压入qmin
        qmax.push_back(i); // 将当前下标压入qmax
        while(!qmin.empty()&&qmin.front()<=i-k) // 如果qmin的头部的下标在滑动窗口外
        {
            qmin.pop_front(); // 弹出头部的数字
        }
        while(!qmax.empty()&&qmax.front()<=i-k) // 如果qmax的头部的下标在滑动窗口外
        {
            qmax.pop_front(); // 弹出头部的数字
        }
        cout<<" "<<a[qmax.front()]; // 输出当前窗口的最大值
    }
    cout<<endl; // 换行
    return 0;
}
