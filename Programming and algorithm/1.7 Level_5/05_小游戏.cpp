// 1804:小游戏
// http://noi.openjudge.cn/ch0205/1804/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 一天早上，你起床的时候想：“我编程序这么牛，为什么不能靠这个赚点小钱呢？”
// 因此你决定编写一个小游戏。
// 游戏在一个分割成w * h个正方格子的矩形板上进行。
// 如图所示，每个正方格子上可以有一张游戏卡片，当然也可以没有。
// 当下面的情况满足时，我们认为两个游戏卡片之间有一条路径相连：
// 路径只包含水平或者竖直的直线段。路径不能穿过别的游戏卡片。
// 但是允许路径临时的离开矩形板。下面是一个例子： 
// 这里在 (1, 3)和 (4, 4)处的游戏卡片是可以相连的。
// 而在 (2, 3) 和 (3, 4) 处的游戏卡是不相连的，
// 因为连接他们的每条路径都必须要穿过别的游戏卡片。

// 你现在要在小游戏里面判断是否存在一条满足题意的路径能连接给定的两个游戏卡片。
// 输入
// 输入包括多组数据。一个矩形板对应一组数据。
// 每组数据包括的第一行包括两个整数w和h (1 <= w, h <= 75)，
// 分别表示矩形板的宽度和长度。
// 下面的h行，每行包括w个字符，表示矩形板上的游戏卡片分布情况。
// 使用‘X’表示这个地方有一个游戏卡片；使用空格表示这个地方没有游戏卡片。

// 之后的若干行上每行上包括4个整数x1, y1, x2, y2 (1 <= x1, x2 <= w, 1 <= y1, y2 <= h)。
// 给出两个卡片在矩形板上的位置（注意：矩形板左上角的坐标是(1, 1)）。
// 输入保证这两个游戏卡片所处的位置是不相同的。如果一行上有4个0，表示这组测试数据的结束。

// 如果一行上给出w = h = 0，那么表示所有的输入结束了。
// 输出
// 对每一个矩形板，输出一行“Board #n:”，这里n是输入数据的编号。
// 然后对每一组需要测试的游戏卡片输出一行。这一行的开头是“Pair m: ”，
// 这里m是测试卡片的编号（对每个矩形板，编号都从1开始）。
// 接下来，如果可以相连，找到连接这两个卡片的所有路径中包括线段数最少的路径，
// 输出“k segments.”，这里k是找到的最优路径中包括的线段的数目；
// 如果不能相连，输出“impossible.”。

// 每组数据之后输出一个空行。
// 样例输入
// 5 4
// XXXXX
// X   X
// XXX X
//  XXX 
// 2 3 5 3
// 1 3 4 4
// 2 3 3 4
// 0 0 0 0
// 0 0
// 样例输出
// Board #1:
// Pair 1: 4 segments.
// Pair 2: 3 segments.
// Pair 3: impossible.
// 来源
// 翻译自Mid-Central European Regional Contest 1999的试题


#include <bits/stdc++.h>
using namespace std;

int w, h;
int dir[8] = {0, -1, 1, 0, 0, 1, -1, 0}; //每两个数对应一个移动方向，顺序为上、右、下、左
const int SIZE = 80;
bool board[SIZE][SIZE];        //存储棋盘，有卡片为true，空为false
int seg[SIZE][SIZE][4];     //存储从点(curX,curY)开始，第一步方向是r，最少需要多少条线段到达目标点
const int INF = 99999999;   //因为+1操作，不能用INT_MAX
int startX, startY, endX, endY; //起点坐标和终点坐标

int dfs(int curX, int curY, int d){  //d是direction的缩写，表示方向
    //记忆化存储，已经计算过就不用再次计算了
    if (seg[curX][curY][d]){
        return seg[curX][curY][d];
    }

    //终点到终点不用走，需要0条线段
    if (curX == endX && curY == endY){
        for (int i = 0; i < 4; i++){
            seg[curX][curY][i] = 0;
        }
        return 0;
    }

    //带卡片的格子走不到终点，用INF来表示
    if (board[curY][curX]){
        for (int i = 0; i < 4; i++){ //四个方向
            seg[curX][curY][i] = INF;
        }
        return INF;
    }

    seg[curX][curY][d] = INF;
    int nextX = curX + dir[2 * d];     // 得到下一步的X坐标
    int nextY = curY + dir[2 * d + 1]; // 得到下一步的Y坐标
    if (nextX >= 0 && nextX <= w + 1 && nextY >= 0 && nextY <= h + 1){  // 下一步在棋盘范围内
        for (int i = 0; i < 4; i++){//四个方向
            seg[nextX][nextY][i] = dfs(nextX, nextY, i);
            if (i == d){ //前进方向不变，到下一个节点的线段数量不变
                seg[curX][curY][d] = min(seg[nextX][nextY][i], seg[curX][curY][d]);
            }
            else{       //前进方向改变，到下一个节点的线段数量+1
                seg[curX][curY][d] = min(seg[nextX][nextY][i] + 1, seg[curX][curY][d]);
            }
        }
    }
    return seg[curX][curY][d];
}

int main(){
    int T = 1; //第几组数据
    while (cin >> w >> h){
        if (w == 0 && h == 0){
            break;  //所有输入都结束了
        }

        memset(board, false, sizeof(board)); //初始化所有格子没有卡片

        for (int i = 1; i <= h; i++){    //行
            cin.get();  //读取空格或回车或制表符

            char c;
            for (int j = 1; j <= w; j++){ //列
                cin.get(c);
                if (c == 'X'){
                    board[i][j] = true;    //有卡片
                }
            }
        }

        cout << "Board #" << T << ":" << endl;

        int group = 1;  //第几组数据
        while (cin >> startX >> startY >> endX >> endY){
            if ((startX | endX | startY | endY) == 0){
                break; //四个0表示本组测试结束
            }

            memset(seg, 0, sizeof(seg));

            int ans = INF;
            for (int i = 0; i < 4; i++){//四个方向
                int nextX = startX + dir[2 * i];
                int nextY = startY + dir[2 * i + 1];
                int cnt = INF;
                for (int j = 0; j < 4; j++){//四个方向
                    int temp = dfs(nextX, nextY, j);
                    if (i == j){ //方向相同说明没有拐弯，线段数量不变
                        cnt = min(cnt, temp);
                    }
                    else{        //拐弯，线段数量增加
                        cnt = min(cnt, temp + 1);
                    }
                }
                ans = min(ans, cnt);
            }
            ans += 1; //在计算的过程中实际上差了1，因为第一次挪动时没有算

            cout << "Pair " << group << ": ";
            group++;

            if (ans >= INF){
                cout << "impossible." << endl;
            }
            else{
                cout << ans << " segments." << endl;
            }
        }//内层while结束

        cout << endl;
        T++; //下一轮游戏
    }//外层while结束

    return 0;
}

