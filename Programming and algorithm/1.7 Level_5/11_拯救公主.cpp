// 7221:拯救公主
// http://noi.openjudge.cn/ch0205/7221/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 多灾多难的公主又被大魔王抓走啦！国王派遣了第一勇士阿福去拯救她。
// 身为超级厉害的术士，同时也是阿福的好伙伴，你决定祝他一臂之力。
// 你为阿福提供了一张大魔王根据地的地图，上面标记了阿福和公主所在的位置，
// 以及一些不能够踏入的禁区。
// 你还贴心地为阿福制造了一些传送门，通过一个传送门可以瞬间转移到任意一个传送门，
// 当然阿福也可以选择不通过传送门瞬移。
// 传送门的位置也被标记在了地图上。
// 此外, 你还查探到公主所在的地方被设下了结界, 需要集齐K种宝石才能打开。
// 当然, 你在地图上也标记出了不同宝石所在的位置。
// 你希望阿福能够带着公主早日凯旋。于是在阿福出发之前，
// 你还需要为阿福计算出他最快救出公主的时间。
// 地图用一个RxC的字符矩阵来表示。
// 字符S表示阿福所在的位置, 字符E表示公主所在的位置, 字符#表示不能踏入的禁区，
// 字符$表示传送门，字符.表示该位置安全, 数字字符0至4表示了宝石的类型。
// 阿福每次可以从当前的位置走到他上下左右四个方向上的任意一个位置，但不能走出地图边界。
// 阿福每走一步需要花费1个单位时间, 从一个传送门到达另一个传送门不需要花费时间。
// 当阿福走到宝石所在的位置时, 就视为得到了该宝石，不需要花费额外时间。

// 输入
// 第一行是一个正整数T（1 <= T <= 10），表示一共有T组数据。
// 每一组数据的第一行包含了三个用空格分开的正整数R、C（2 <= R, C <= 200）和K，
// 表示地图是一个R×C的矩阵，
// 而阿福需要集齐K种宝石才能够打开拘禁公主的结界。
// 接下来的R行描述了地图的具体内容，每一行包含了C个字符。
// 字符含义如题目描述中所述。保证有且仅有一个S和E。$的数量不超过10个。
// 宝石的类型在数字0至4范围内，即不会超过5种宝石。
// 输出
// 对于每一组数据，输出阿福救出公主所花费的最少单位时间。
// 若阿福无法救出公主，则输出“oop!”（只输出引号里面的内容，不输出引号）。
// 每组数据的输出结果占一行。
// 样例输入
// 1
// 7 8 2
// ........
// ..S..#0.
// .##..1..
// .0#.....
// ...1#...
// ...##E..
// ...1....
// 样例输出
// 11

// 这道题就是一道迷宫的升级版…所以我们继续使用迷宫的广度优先搜索模板——求得最短路径（时间）。 
// 选好模板后就要对模板进行修改了。

// 1. 由于有多组数据，我们可以将要使用的变量全部定义在循环内部，
//     每一次循环结束后都会被释放，下一次重新定义就避免了清0变量的操作。
// 2. 对输入进行修改——在迷宫中加入了传送门。
//     我们需要定义一个二维int数组（door_coord）——第一维表示传送门的个数，
//     第二维表示传送门的坐标和一个int变量（sdoor_coord）表示传送门的个数。
//     然后在输入的for循环中，在判断起点位置的下方同时判断是否是传送门，
//     若是，则存入door_coord。
// 3. 我们还需要一些变量，如判断是否重复走到同一个位置的数组（walked），
//     我们可以用一个三维bool数组表示——第一、二维表示坐标，第三维表示宝石种类，
//     注意第三维——不能直接使用宝石的数量，因为可能它获得了不同的宝石但是宝石的总数量相同！
//     因此我们可以用二进制表示获得的宝石种类（例如：获得宝石0,3 –> 2进制：01001[2]=9[10]）。
// 4. 结构体需要增加一些变量——bool变量（enchantment）表示结界是否存在（true表示有结界）；
//     bool数组（get_jewel）表示获得的宝石。
// 5. 对广度优先搜索进行改变。
//     在判断是否超界或是否为墙完毕后，判断该位置是不是宝石（即字符是不是‘0’到‘4’之间的字符）。
//     如果是，则将get_jewel的值改变。
//     遍历 get_jewel，将获得宝石的二进制表示（参照3）和获得宝石的总数量统计出来，
//     然后判断是否走了重复的路（用walked）。
//     若不是，则判断得到的宝石数量是否达标，若是，则将enchantment改为false（结界消失）。
//     如果是传送门，则遍历door_coord，将除它本身的传送门存入队列。
//     如果找到终点，则判断enchantment是否为false，
//     若是，则输出，作找到路径的标记并且结束数据；
//     若enchantment为true，注意不要退出本次循环，将终点当做道路进行下一次移动。
// 6. 若没有找到则输出“oop!”。

#include<bits/stdc++.h>
using namespace std;
struct POINT{
    int x, y, tot; //坐标，步数
    bool get_jewel[7], enchantment; //找到的宝石，结界
} point, door;  // point 表示起点
int main(){
    int k, F[4][2]={-1, 0, 1, 0, 0, -1, 0, 1};
    scanf("%d", &k);  // k 表示数据的组数
    for(int kk = 1; kk <= k; kk++){
        /*定义*/
        queue<POINT> que; //队列
        int r, c; // 地图大小
        int needkind;   // 需要的宝石种类
        int door_coord[15][2] = {}; // 传送门坐标
        int sdoor_coord = 0; //传送门个数
        char maze[205][205] = {};   //迷宫
        bool walked[205][205][35] = {}; //已经走过的路，第三维是宝石数(2进制)
        bool finish = false; //是否完成
        /*输入*/
        scanf("%d%d%d", &r, &c, &needkind);
        for(int i = 0; i < r; i++){
            scanf("%s", maze[i]);  // 输入地图信息
            for(int j = 0; j < c; j++){
                if(maze[i][j] == 'S'){   //起点
                    memset(point.get_jewel, false, sizeof(point.get_jewel));
                    point.x = i; point.y = j;  // 保存起点位置
                    point.tot = 0; // 起点步数为0
                    point.enchantment = true; // 具有结界
                }
                if(maze[i][j]=='$'){ // 传送门
                    door_coord[sdoor_coord][0]=i; // 存入位置
                    door_coord[sdoor_coord++][1]=j;
                }
            }
        }
        /*广度优先搜索*/
        que.push(point); //存入起点
        while(!que.empty()){ //队列不为空
            for(int i = 0; i < 4; i++){ //4个方向
                point = que.front(); //取出队首元素
                point.tot++;  // 步数+1
                point.x += F[i][0]; 
                point.y += F[i][1]; //改坐标
                if(point.x < 0 || point.x >= r || point.y < 0 || point.y >= c 
                    || maze[point.x][point.y]=='#') //超界或为墙
                    continue;
                if('0' <= maze[point.x][point.y] && maze[point.x][point.y]<='4') 
                    //如果为宝石
                    point.get_jewel[maze[point.x][point.y]-'0']=true; 
                    //改变point中该宝石的值为 “找到 ”
                int sget_jewel = 0, ss = 0; //找到的宝石个数
                for(int i = 0; i < 5; i++)
                    if(point.get_jewel[i])  //遍历宝石获得数
                        sget_jewel += pow(2, i), ss++;  // pow(2, i) 得到2的i次方值
                        //eg:获得0,3 --> 2进制：01001=9
                if(walked[point.x][point.y][sget_jewel]) // 走到相同位置
                    continue;
                //如果之前到达过该位置且未找到更多的宝石
                walked[point.x][point.y][sget_jewel]=true; //改变该位置的到达记录
                if(ss >= needkind)  //如果找到了足够的宝石
                    point.enchantment = false; //结界消失
                if(maze[point.x][point.y] == '$'){ //如果是传送门
                    door = point; //保存位置
                    for(int i = 0; i < sdoor_coord; i++) //遍历所有传送门
                        if(door_coord[i][0] != point.x || door_coord[i][1] != point.y){ 
                            //不是当前的位置
                            door.x=door_coord[i][0];
                            door.y=door_coord[i][1]; //存入传送门
                            que.push(door);
                        }
                }
                if(maze[point.x][point.y]=='E' && !point.enchantment){
                //如果是找到终点并且没有结界
                    printf("%d\n", point.tot);  // 输出步数
                    finish=true; //找到
                }
                if(finish) break; //找到退出
                que.push(point); //存入当前位置
            }
            if(finish) break; //找到退出
            que.pop(); //出队
        }
        if(!finish) printf("oop!\n"); //没有找到
    }
    return 0;
}