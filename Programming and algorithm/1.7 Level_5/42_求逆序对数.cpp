// 0809:求逆序对数
// http://dsa.openjudge.cn/sort/0809/
// 总时间限制: 500ms 内存限制: 65536kB
// 描述
// 对于一个长度为 N 的整数序列A，满足i < j 且 Ai > Aj 的数对 (i, j) 称为整数序列A的一个逆序

// 请求出整数序列A的所有逆序对个数

// 输入
// 输入包含多组测试数据，每组测试数据有两行
// 第一行为整数N(1 <= N <= 20000)，当输入0时结束
// 第二行为N个整数，表示长为N的整数序列
// 输出
// 每组数据对应一行，输出逆序对的个数
// 样例输入
// 5
// 1 2 3 4 5
// 5
// 5 4 3 2 1
// 1
// 1
// 0
// 样例输出
// 0
// 10
// 0

// 可以用归并排序计算逆序对数，在归并排序中的交换次数就是这个序

#include<bits/stdc++.h>
using namespace std;

int n;      // n 为整数序列长度
int nums[20005];    // 存储每个数
int tmp[20005];     // 临时存储
int cnt;    // 逆序对个数

void mergesort(int l, int r){   // 归并排序
    if(l >= r)    // 结束条件
        return;
    int m = (l + r) / 2;    // 取中点
    int i = l, j = m + 1, k = 0;
    while(i <= m && j <= r){
        if(nums[i] > nums[j]){  // 判断是否逆序
            tmp[k++] = nums[j++];
            cnt += m - i + 1;   // 统计交换次数
        }
        else{
            tmp[k++] = nums[i++];
        }
    }
    while(i <= m) 
        tmp[k++] = nums[i++];   // 将剩下的i 存储到 tmp 中
    while(j <= r) 
        tmp[k++] = nums[j++];   // 将剩下的j 存储到 tmp 中
    for(i = 0; i < k; i++)    
        nums[i + l] = tmp[i];   // 重新赋值
}

void mergearray(int l, int r){  // l为数组首， r为数组尾
    if(l >= r)    // 首超过尾
        return;
    int m = (l + r) / 2;    // 取中间值
    mergearray(l, m);       // 递归
    mergearray(m + 1, r);   // 递归
    mergesort(l, r);        // 归并排序
}

int main(){
    while(~scanf("%d", &n) && n){ //~scanf("%d", &n)的返回值永不为0
        cnt = 0;    // 逆序对数量 初始化为 0
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);    // 输入 每个数字
        }
        mergearray(0, n - 1);   // 利用归并排序进行统计
        printf("%d\n", cnt);
    }
    return 0;
}