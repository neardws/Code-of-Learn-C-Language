// 生日相同 2.0
// 生日相同 2.0
// 在一个有180人的大班级中，存在两个人生日相同的概率非常大，现给出每个学生的名字，出生月日。试找出所有生日相同的学生。
// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行为整数n，表示有n个学生，n ≤ 180。此后每行包含一个字符串和两个整数，
// 分别表示学生的名字（名字第一个字母大写，其余小写，不含空格，且长度小于20）和出生月(1 ≤ m ≤ 12)日(1 ≤ d ≤ 31)。名字、月、日之间用一个空格分隔
// 输出
// 每组生日相同的学生，输出一行，其中前两个数字表示月和日，后面跟着所有在当天出生的学生的名字，
// 数字、名字之间都用一个空格分隔。对所有的输出，要求按日期从前到后的顺序输出。 
// 对生日相同的名字，按名字从短到长按序输出，长度相同的按字典序输出。如没有生日相同的学生，输出”None”
// 样例输入
// 6
// Avril 3 2
// Candy 4 5
// Tim 3 2
// Sufia 4 5
// Lagrange 4 5
// Bill 3 2
// 样例输出
// 3 2 Tim Bill Avril
// 4 5 Candy Sufia Lagrange

// 解题思路如下：

// 定义一个结构体 student，包含学生的姓名和生日（月、日）。
// 定义一个二维数组 b，用于存储生日相同的学生个数。
// b[i][j] 表示生日为月份 i 和日期 j 的学生个数。
// 读入每个学生的姓名和生日，并按照生日进行排序。
// 遍历排序后的学生数组，统计每个生日的学生人数，并将结果存储在数组 b 中。
// 遍历 b 数组，找到生日相同的学生，并输出生日和姓名。
// 需要注意的是，输出时需要按照生日从前往后的顺序输出，
// 对于生日相同的学生，需要按照姓名从短到长、长度相同的按照字典序排序。
// 另外，如果没有生日相同的学生，需要输出 None。

// 因为学生人数最多为 180，因此可以使用冒泡排序、插入排序、归并排序等排序算法，
// 时间复杂度为 $O(n^2)$ 或 $O(n\log n)$，可以满足本题要求。
// 本题的代码中使用了快速排序，时间复杂度为 $O(n\log n)$。


#include<bits/stdc++.h>
using namespace std;

// 学生结构体，包含姓名和生日（月、日）
struct student
{
    char name[21];
    int m;
    int d;
};

// 学生结构体比较函数，用于排序。按照月、日、姓名的字典序排序
int comp(const student &a, const student &b)
{
    if (a.m < b.m) return 1;
    if (a.m > b.m) return 0;
    if (a.d < b.d) return 1;
    if (a.d > b.d) return 0;
    if (strlen(a.name) < strlen(b.name)) return 1;
    if (strlen(a.name) > strlen(b.name)) return 0;
    if (strcmp(a.name, b.name) < 0) return 1;
    if (strcmp(a.name, b.name) > 0) return 0;
    return 0;
}

int main()
{
    // b数组用于存储生日相同的学生个数
    int b[13][32] = {0};
    int n;
    bool bl = false; // 标记是否有生日相同的学生

    student a[181];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s%d%d", &a[i].name, &a[i].m, &a[i].d);
    }

    sort(a + 1, a + n + 1, comp); // 按照生日排序

    for (int i = 1; i <= n; ++i)
    {
        b[a[i].m][a[i].d]++; // 统计生日相同的学生个数
    }

    // 遍历b数组，找到生日相同的学生并输出
    for (int i = 1; i <= 12; ++i)
    {
        for (int k = 1; k <= 31; ++k)
        {
            if (b[i][k] > 1) // 生日相同的学生个数大于1
            {
                printf("%d %d ", i, k); // 输出生日
                for (int j = 1; j <= n; ++j)
                {
                    if (a[j].m == i && a[j].d == k)
                        printf("%s ", a[j].name); // 输出生日相同的学生的姓名
                }
                printf("\n");
                bl = true;
            }
        }
    }

    if (bl == false) printf("None"); // 没有生日相同的学生
    return 0;
}
