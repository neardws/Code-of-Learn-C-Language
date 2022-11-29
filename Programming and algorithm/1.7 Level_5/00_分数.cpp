// 分数
// [问题描述]
// 高考分数刚刚公布。共有n个人参加了考试。
// 为了便于填报志愿,教育部把所有考生的成绩平均分为m档,保证n是m的倍数。
// 考试成绩名次在(k-1)(n/m)+1名到k(n/m)名的考生被分在第k档(（k=1,2,3，…,m)：
// 并列第i名的所有考生都算第i名。小林刚参加完高考，迫切想知道自己被分在了第几档。
// [输入格式]
// 第1行两个正整数n和m, n、m≤1000, 保证n是m的倍数。
// 按下来的n行,每行一个整数a，表示第i个考生的成绩。
// 最后一行一个正整数x, 1≤x≤n,表示询问第×个考生被分在哪一档。
// [输出格式]
// 一行一个数，表示他被分在哪一档。
// [输入样例]
// 3 3
// 632
// 651
// 624
// 3
// [输出样例]
// 3

#include<bits/stdc++.h>
using namespace std;
static const int MaxN = 1000;
int n, m, x;  // n 表示学生数量，m表示档位数量，x表示查询第x位学生

struct student {    // 学生结构体
	int x, mark, rank;  // x 表示学生的顺序，mark 为成绩，rank 为排名
} student_array[MaxN + 1] = {-1};   // 学生结构体数组，初始化为-1

inline bool compare( student s1, student s2 ) {
    // 内联函数，实现学生结构体的比较
	return s1.mark > s2.mark;   // 直接通过成绩比较
}

void Get_Rank() {    // 获得每位学生的排名
	int Now_Rank = 0, tag = 1; 
	for ( register int i = 1; i <= n; ++i ) {
        // 成绩不同，直接排名增加
		if ( student_array[i].mark != student_array[i - 1].mark ) {
			Now_Rank += tag;
			student_array[i].rank = Now_Rank;
			tag = 1;
		}
		else{ // 成绩相同，并列排名
            student_array[i].rank = Now_Rank;
            ++tag;
        } 
	}
}

int main() {
	cin >> n >> m;
	for ( register int i = 1; i <= n; ++i )  {
		student_array[i].x = i;         // 记录输入顺序
		cin >> student_array[i].mark;   // 学生成绩
	}
	cin >> x;
    // 直接通过 sort 函数进行排序
	sort( student_array + 1, student_array + n + 1, compare );
	Get_Rank();   // 得到每个人的排名
	for ( int i = 1; i <= m; ++i ) {  // i 表示档位
		int low = ( i - 1 ) * ( n / m ) + 1;  // 档位最低
		int high = i * ( n / m );   // 档位最高
		for ( register int j = 1; j <= n; ++j ) {
			if ( student_array[j].rank > high ) 
                break;
			if ( student_array[j].rank < low ) 
                continue;
			if ( student_array[j].x == x) {
				cout << i; putchar( '\n' ); return 0;
			}
		}
	}
	return 0;
}
