// 棋盘问题
// 在一个给定形状的棋盘（形状可能是不规则的）
// 上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一
// 列，请编桯求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
// 时间限制：1000
// 内存限制：65536
// 输入
// 输入含有多组测试数据。每组数据的第一行是两个正整数，nk，用一个空格隔开，表示了将在一个nxn的矩阵内描述棋盘，以及摆放棋子的数目。
// n≤=8,k <=n当为-1-1时表示输人结束。随后的n行描述了棋盘的形状：每行有n个字符，其中
// ＃ 表示棋盘区域， ．表示空白区域(数据保证不出现多余的空白行或者空白列）。
// 输出
// 对于每一组数据，给出一行输出，输出摆放的方案数目C（数据保证C<2^31）。

// 解题思路：

// 使用回溯算法来解决问题，递归地尝试不同的摆放方案。
// 定义一个辅助函数is_valid，用于检查当前位置是否可以放置棋子，满足不在同一行和同一列的条件。
// 在主函数中，循环读取输入，直到输入为-1 -1表示结束。
// 对于每组测试数据，读取棋盘形状和摆放棋子的数目。
// 调用回溯函数backtrack，传入棋盘、棋子数目和初始计数器。
// 在回溯函数中，遍历棋盘的每个位置，如果当前位置可以放置棋子，则进行放置，并递归地处理下一个棋子。
// 递归结束条件为所有棋子都被放置完毕，此时将计数器加1。
// 回溯过程中，需要进行合适的回溯操作，将已经放置的棋子撤销，继续尝试其他位置。
// 最后输出摆放方案的数目。

#include <iostream>
#include <vector>
using namespace std;

int count = 0;

bool is_valid(vector<vector<char>>& board, int row, int col) {
    int n = board.size();

    // 检查同一行是否已经有棋子
    for (int j = 0; j < n; j++) {
        if (board[row][j] == 'Q') {
            return false;
        }
    }

    // 检查同一列是否已经有棋子
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    return true;
}

void backtrack(vector<vector<char>>& board, int k, int row) {
    int n = board.size();

    if (k == 0) {
        count++;  // 找到一种摆放方案，计数器加1
        return;
    }

    for (int i = row; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '#') {
                if (is_valid(board, i, j)) {
                    board[i][j] = 'Q';  // 放置棋子
                    backtrack(board, k - 1, i + 1);  // 递归处理下一个棋子
                    board[i][j] = '#';  // 撤销棋子的放置，进行回溯
                }
            }
        }
    }
}

int main() {
    while (true) {
        int n, k;
        cin >> n >> k;

        if (n == -1 && k == -1) {
            break;
        }

        vector<vector<char>> board(n, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        count = 0;  // 初始化计数器为0
        backtrack(board, k, 0);
        cout << count << endl;
    }

    return 0;
}
