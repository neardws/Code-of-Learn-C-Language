// 城堡问题
//     1   2   3   4   5   6   7  
//    #############################
//  1 #   |   #   |   #   |   |   #
//    #####---#####---#---#####---#
//  2 #   #   |   #   #   #   #   #
//    #---#####---#####---#####---#
//  3 #   |   |   #   #   #   #   #
//    #---#########---#####---#---#
//  4 #   #   |   |   |   |   #   #
//    #############################
//            (图 1)

//    #  = Wall   
//    |  = No wall
//    -  = No wall
// 图1是一个城堡的地形图。请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。城堡被分割成m×n(m≤50，n≤50)个方块，每个方块可以有0~4面墙。
// 时间限制：1000
// 内存限制：65536
// 输入
// 程序从标准输入设备读入数据。第1、2行每行1个整数，分别是南北向、东西向的方块数。在接下来的输入行里，每个方块用一个数字(0≤p≤50)描述。用一个数字表示方块周围的墙，1表示西墙，2表示北墙，4表示东墙，8表示南墙。每个方块用代表其周围墙的数字之和表示。城堡的内墙被计算两次，方块(1,1)的南墙同时也是方块(2,1)的北墙。输入的数据保证城堡至少有两个房间。
// 输出
// 输出2行，每行一个数，表示城堡的房间数、城堡中最大房间所包括的方块数。结果显示在标准输出设备上。
// 样例输入
// 4 
// 7 
// 11 6 11 6 3 10 6 
// 7 9 6 13 5 15 5 
// 1 10 12 7 13 7 5 
// 13 11 10 8 10 12 13 
// 样例输出
// 5
// 9


// 解题思路：
// 题目要求我们计算城堡一共有多少房间，以及最大的房间有多大。我们可以通过深度优先搜索算法来解决。

// 我们首先需要用二维数组 castle 来存储城堡的地形图。然后，我们从 (1, 1) 开始遍历城堡地形图，对于每个未被访问过的格子，我们递归地访问它相邻的格子，并统计房间数和最大房间大小。

// 在深度优先搜索时，我们需要判断当前格子的每个墙是否存在，如果不存在则继续递归搜索下一个格子。同时，我们需要使用 visited 数组来记录已经访问过的格子，以避免重复访问。

// 最后，我们输出房间数和最大房间大小即可。


#include <bits/stdc++.h>
using namespace std;

const int MAX_M = 50;
const int MAX_N = 50;

int m, n;  // 城堡的南北向和东西向的方块数
int castle[MAX_M][MAX_N];  // 城堡的地形图
bool visited[MAX_M][MAX_N];  // 标记是否访问过

// dfs 函数用于深度优先搜索城堡
// (i, j) 表示当前搜索的格子坐标
// num_rooms 表示已经统计的房间数
// max_room_size 表示最大房间大小
// curr_room_size 表示当前房间大小
void dfs(int i, int j, int& num_rooms, int& max_room_size, int& curr_room_size) {
    visited[i][j] = true;
    curr_room_size++;

    // 判断当前格子的每个墙是否存在，如果不存在则继续递归搜索下一个格子
    if ((castle[i][j] & 1) == 0 && !visited[i][j-1]) {
        dfs(i, j-1, num_rooms, max_room_size, curr_room_size);
    }
    if ((castle[i][j] & 2) == 0 && !visited[i-1][j]) {
        dfs(i-1, j, num_rooms, max_room_size, curr_room_size);
    }
    if ((castle[i][j] & 4) == 0 && !visited[i][j+1]) {
        dfs(i, j+1, num_rooms, max_room_size, curr_room_size);
    }
    if ((castle[i][j] & 8) == 0 && !visited[i+1][j]) {
        dfs(i+1, j, num_rooms, max_room_size, curr_room_size);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> castle[i][j];
        }
    }

    int num_rooms = 0;  // 房间数
    int max_room_size = 0;  // 最大房间大小
    int curr_room_size = 0;  // 当前房间大小

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                num_rooms++;
                curr_room_size = 0;
                dfs(i, j, num_rooms, max_room_size, curr_room_size);
                max_room_size = max(max_room_size, curr_room_size);
            }
        }
    }

    cout << num_rooms << endl;
    cout << max_room_size << endl;

    return 0;
}
