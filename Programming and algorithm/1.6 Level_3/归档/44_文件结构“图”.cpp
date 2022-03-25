// 1777:文件结构“图”
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 在计算机上看到文件系统的结构通常很有用。
// Microsoft Windows上面的"explorer"程序就是这样的一个例子。
// 但是在有图形界面之前，没有图形化的表示方法的，
// 那时候最好的方式是把目录和文件的结构显示成一个"图"的样子，
// 而且使用缩排的形式来表示目录的结构。比如：

// ROOT
// |     dir1
// |     file1
// |     file2
// |     file3
// |     dir2
// |     dir3
// |     file1
// file1
// file2
// 这个图说明：ROOT目录包括三个子目录和两个文件。
// 第一个子目录包含3个文件，第二个子目录是空的，第三个子目录包含一个文件。

// 输入
// 你的任务是写一个程序读取一些测试数据。
// 每组测试数据表示一个计算机的文件结构。
// 每组测试数据以'*'结尾，而所有合理的输入数据以'#'结尾。
// 一组测试数据包括一些文件和目录的名字
// （虽然在输入中我们没有给出，但是我们总假设ROOT目录是最外层的目录）。
// 在输入中,以']'表示一个目录的内容的结束。目录名字的第一个字母是'd'，
// 文件名字的第一个字母是'f'。
// 文件名可能有扩展名也可能没有（比如fmyfile.dat和fmyfile）。
// 文件和目录的名字中都不包括空格,长度都不超过30。
// 一个目录下的子目录个数和文件个数之和不超过30。
// 输出
// 在显示一个目录中内容的时候，先显示其中的子目录（如果有的话），
// 然后再显示文件（如果有的话）。
// 文件要求按照名字的字母表的顺序显示
// （目录不用按照名字的字母表顺序显示，只需要按照目录出现的先后显示）。
// 对每一组测试数据，我们要先输出"DATA SET x:"，
// 这里x是测试数据的编号（从1开始）。在两组测试数据之间要输出一个空行来隔开。

// 你需要注意的是，我们使用一个'|'和5个空格来表示出缩排的层次。
// 样例输入
// file1
// file2
// dir3
// dir2
// file1
// file2
// ]
// ]
// file4
// dir1
// ]
// file3
// *
// file2
// file1
// *
// #
// 样例输出
// DATA SET 1:
// ROOT
// |     dir3
// |     |     dir2
// |     |     file1
// |     |     file2
// |     dir1
// file1
// file2
// file3
// file4

// DATA SET 2:
// ROOT
// file1
// file2
// 提示
// 一个目录和它的子目录处于不同的层次
// 一个目录和它的里面的文件处于同一层次
// 来源
// 翻译自 Pacific Northwest 1998 的试题
// http://noi.openjudge.cn/ch0202/1777/

#include<bits/stdc++.h>
using namespace std;
string s;
int deep = 0, have = 1, flag = 0;   //分别为深度，文件表数，标志是否为首位
void wj() {
    string str[50];         // 定义一个字符串数组，用来存储文件名
    int num = 0;
    while (cin >> s) {
        if (flag == 0 && s[0] != '#') {         //一开始
            cout << "DATA SET " << have << ":\nROOT" << endl;
            flag = 1;
        }
        if (s[0] == '#')        //#
            return;
        if (s[0] == '*') {      //*
            deep = 0;
            sort(str, str + num);
            for (int i = 0; i < num; i++) {
                cout << str[i] << endl;
            }
            cout << endl;
            have ++;
            flag = 0;
            num = 0;
        } else {
            if (s[0] == 'f') {     //读入的是文件名，入栈
                str[num] = s;
                num++;
                continue;
            } else if (s[0] == 'd') {   //读入的是目录名，深度加1，并且输出
                deep++;
                for (int i = 0; i < deep; i++) {    // 深度表示要输出的层次
                    cout << "|     ";
                }
                cout << s << endl;
                wj();
            } else if (s[0] == ']') {   //读入的是]，输出栈内的文件，并且深度减1
                sort(str, str + num);   //按照字母表顺序排序
                for (int i = 0; i < num; i++) {
                    for (int j = 0; j < deep; j++) {
                        cout << "|     ";
                    }
                    cout << str[i] << endl;
                }
                deep--;  //深度减1
                return;
            }
        }
    }
}

int main(){ 
    wj(); 
    return 0;    
}

