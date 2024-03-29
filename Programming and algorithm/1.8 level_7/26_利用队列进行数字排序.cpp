// 利用队列进行数字排序
// 对于N个数字，有人提出了如下的排序策略：

// 例如，对于数字53、47、85、38、64、23

// 先建立10个队列(0到9），用于存放数字的大小，将这N个数字依个位存放入各自的队列之中，
// 然后再按队列0到队列9依次出队。

// 例如，对于上面的数字，依次进队后，结果如下：

// 队列3：53、23　队列4：64　队列5：85　队列7：47　队列8：38

// 将其依次出队后，结果为53,23,64,85,47,38

// 然后，再将方才出队后的队对，依照十位放入各自的队列之中，然后再按队列0到队列9依次出队

// 例如，对于上面刚刚出队的序列53,23,64,85,47,38，将其依次进队，结果如下：

// 队列2：23　队列3：38　队列4：47　队列5：53　队列6：64　队列8：85

// 将其依次出队后，结果为23,38,47,53,64,85.因为这组数字最大只是两位数，所以排序结束。

// 如果还有更大的数字，那么，接下来就是其百位、千位……（如果位数不够，就补0.比如最大的数字是四位数，
// 那么数字23就当成0023处理）

// 请根据上述算法，对这些数字进行排序


// 时间限制：1000
// 内存限制：65535
// 输入
// 分为两行，第一行为一个数字N(1 <= N <= 1000)，表示数字的个数 第二行为N个数字（都是非负数），以空格相隔，最大的数字不超过9999
// 输出
// 输出两个部分 第一个部分为第一次进队出队的结果，先显示一行：Step1. 之后用Queue0:...表示，共10行，结果用空格分隔，下同 之后为第二次进队出队的结果（如果需要第二次进队出队的话），先显示一行：Step2. 之后仍然用Queue0:...表示，共10行 之后如果需要的话，则分别显示第三次、第四次的进队出队结果 第二部分为一行，即将数字排序后的结果（升序排序）
// 样例输入
// 20
// 41 67 34 0 69 24 78 58 62 64 5 45 81 27 61 91 95 42 27 36
// 样例输出
// Step1.
// Queue0:0
// Queue1:41 81 61 91
// Queue2:62 42
// Queue3:
// Queue4:34 24 64
// Queue5:5 45 95
// Queue6:36
// Queue7:67 27 27
// Queue8:78 58
// Queue9:69
// Step2.
// Queue0:0 5
// Queue1:
// Queue2:24 27 27
// Queue3:34 36
// Queue4:41 42 45
// Queue5:58
// Queue6:61 62 64 67 69
// Queue7:78
// Queue8:81
// Queue9:91 95
// 0 5 24 27 27 34 36 41 42 45 58 61 62 64 67 69 78 81 91 95

// 解题思路：桶排序。

// 桶排序的思路：

// 1. 首先建立10个桶，分别存储0到9的数字。
// 2. 对于每一个数字，将其依次放入各自对应的桶中。
// 3. 按照桶的顺序，从0到9遍历每一个桶，并将桶内的数字依次放入答案中。
// 4. 重复步骤2和3，将数字按照更高位排序。

// 该题实现方法：

// 1. 建立桶队列，每一个队列存储每一个数字的某一位数字。
// 2. 对于每一个数字，将其依次放入各自对应的队列中。
// 3. 按照队列的顺序，从0到9遍历每一个队列，并将队列内的数字依次放入答案中。
// 4. 重复步骤2和3，将数字按照更高位排序。

// 代码实现时需要注意的地方：

// 1. 利用队列实现桶排序，需要注意队列的创建和存储数字的方法。
// 2. 每一次排序后，需要将排序后的数字重新存入队列中，以便下一次排序。
// 3. 输出格式需要注意，具体详见题目描述。


#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, a[N];
int p[15][N];  //每一位的数字的队列
void work(int k)
{
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        int x = a[i];
        int t = (x / (int)pow(10, k - 1)) % 10;  //获取第k位的数字
        p[t][num++] = x;  //放入队列
    }
    num = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(p[i][j] != 0)  //如果队列不为空
            {
                a[num++] = p[i][j];  //从队列中取出数字
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int k = 1;  //从个位开始
    int flag = 1;  //判断是否有更高位
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= pow(10, k))  //如果有更高位的数字
        {
            flag = 0;
            break;
        }
    }
    int step = 1;
    while(!flag)
    {
        cout << "Step" << step << "." << endl;
        memset(p, 0, sizeof p);  //清空队列
        work(k);
        for(int i = 0; i < 10; i++)
        {
            cout << "Queue" << i << ":";
            for(int j = 0; j < N; j++)
            {
                if(p[i][j] != 0)
                    cout << " " << p[i][j];
            }
            cout << endl;
        }
        k++;
        flag = 1;
        for(int i = 0; i < n; i++)
        {
            if(a[i] >= pow(10, k))
            {
                flag = 0;
                break;
            }
        }
        step++;
    }
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}