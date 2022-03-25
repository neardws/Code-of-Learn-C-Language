// 矩形数量
// 给出平面上一些点（少于50个），坐标都是整数（｜x_i｜,|y_i|<=10^9）, 有可能重复。
// 问存在多少个以这些点为顶点的平行于坐标轴的不同矩形。
// （两个矩形如果四个顶点坐标都相同，就算相同的矩形。）

// 输入
// 第一行一个整数T(T<=100)表示测试数据的组数，
// 对于每组数据，第一行一个整数n, 表示点的数量，
// 下面n行每行两个整数x_i， y_i 表示点的坐标。

// 输出
// T 行，每行一个整数表示以这些点为顶点的平行于坐标轴的矩形个数。

// 样例输入
// 1
// 7
// 0 0
// 0 1
// 0 2
// 1 0
// 1 1 
// 1 2
// 0 0

// 样例输出
// 3


#include<bits/stdc++.h>
using namespace std;

struct node{
	int x, y;
}node_list[51];

struct two_node{
    int x1, y1, x2, y2;
}two_node_list[2501];

bool is_nodes_in_two_nodes_list(int x1, int y1, int x2, int y2){
    for(int i = 0; i < (int)(sizeof(two_node_list) / sizeof(two_node_list[0])); i++){
        if(two_node_list[i].x1 == x1 && two_node_list[i].y1 == y1 
            && two_node_list[i].x2 == x2 && two_node_list[i].y2 == y2){
            return true;
        }
        if(two_node_list[i].x1 == x2 && two_node_list[i].y1 == y2 
            && two_node_list[i].x2 == x1 && two_node_list[i].y2 == y1){
            return true;
        }
    }
    return false;
}



int main(){
	int t, n;
    cin>>t;
    for(int i = 1; i <= t; i++){
        memset(node_list, 0, sizeof(node_list));
        memset(two_node_list, 0, sizeof(two_node_list));
        int ans=0;
        cin>>n;
        for(int j = 1; j <= n; j++){
            int x, y;
            cin>>x>>y;
            node_list[j].x = x;
            node_list[j].y = y;
        }
        for(int i = 1; i <= n; i++){
            int x1 = node_list[i].x;     // 左上角的点
            int y1 = node_list[i].y;
            for(int j = 1; j <= n; j++){
                int x2 = node_list[j].x;    // 右上角的点
                int y2 = node_list[j].y;
                if(x1 != x2 && y1 == y2){
                    for(int k = 1; k <= n; k++){
                        int x3 = node_list[k].x;    // 左下角的点
                        int y3 = node_list[k].y;
                        if(x3 == x1 && y3 != y1){
                            for(int l = 1; l <= n; l++){
                                int x4 = node_list[l].x;    // 右下角的点
                                int y4 = node_list[l].y;
                                if(x4 == x2 && y4 == y3){
                                    if(is_nodes_in_two_nodes_list(x1, y1, x2, y2)) {
                                        continue;
                                    }
                                    else{
                                        two_node_list[ans].x1=x1;
                                        two_node_list[ans].y1=y1;
                                        two_node_list[ans].x2=x2;
                                        two_node_list[ans].y2=y2;
                                        ans++;
                                    }
                                }     
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}