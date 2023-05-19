// 实现堆结构
// 定义一个数组，初始化为空。在数组上执行两种
// 操作：
// 1、增添1个元素，把1个新的元素放入数组。
// 2、输出并删除数组中最小的数。
// 使用堆结构实现上述功能的高效算法。
// 时间限制：3000
// 内存限制：65535
// 输入
// 第一行输入一个整数t，代表测试数据的组数。对
// 手每组测试数据，第一行输入一个整数n，代表操作的次数。每次採作首先输入一个整数type。当
// type=1，增添操作，接着输入一个整数u，代表要插入的元素。当type=2，输出删除操作，输出并删除数组中最小的元素。 1<=n<=100000。
// 输出
// 每次删除操作输出被删除的数字。

// 堆结构是一种常用的数据结构，可用于高效地实现插入和删除操作，其中插入操作和删除最小元素操作的时间复杂度为O(log n)。
// 使用一个数组heap来表示堆。通过heapify_up和heapify_down函数来维护堆的性质。heapify_up函数用于将新插入的元素上浮到合适的位置，保持堆的性质。heapify_down函数用于将堆顶元素下沉到合适的位置，保持堆的性质。

// 在主函数中，首先读取测试数据的组数t。然后，对于每组测试数据，读取操作的次数n。接下来，根据操作类型执行增添和输出删除最小元素的操作。对于增添操作，将新元素插入堆中，并调用heapify_up函数。对于输出删除操作，如果堆不为空，输出堆顶元素并删除，然后将最后一个元素移动到堆顶，并调用heapify_down函数。

// 每次输出删除操作会输出被删除的数字。

// 这样，使用堆结构实现的算法可以高效地执行增添和输出删除最小元素的操作。

#include <iostream>
#include <vector>
using namespace std;

// 将新插入的元素上浮到合适的位置，维护堆的性质
void heapify_up(vector<int>& heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[idx] < heap[parent]) {  // 如果当前节点比父节点小，交换它们的值
            swap(heap[idx], heap[parent]);
            idx = parent;  // 更新当前节点的索引为父节点的索引，继续向上比较
        } else {
            break;
        }
    }
}

// 将堆顶元素下沉到合适的位置，维护堆的性质
void heapify_down(vector<int>& heap, int idx, int size) {
    while (idx < size) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < size && heap[left] < heap[smallest]) {  // 如果左子节点存在且比当前节点小
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest]) {  // 如果右子节点存在且比当前节点小
            smallest = right;
        }

        if (smallest != idx) {  // 如果最小节点不是当前节点，交换它们的值
            swap(heap[idx], heap[smallest]);
            idx = smallest;  // 更新当前节点的索引为最小节点的索引，继续向下比较
        } else {
            break;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> heap;
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;

            if (type == 1) {
                int u;
                cin >> u;
                heap.push_back(u);  // 将新元素插入堆中
                heapify_up(heap, heap.size() - 1);  // 上浮新插入的元素
            } else if (type == 2) {
                if (!heap.empty()) {
                    cout << heap[0] << endl;  // 输出堆顶元素
                    swap(heap[0], heap[heap.size() - 1]);  // 将最后一个元素移动到堆顶
                    heap.pop_back();  // 删除堆顶元素
                    heapify_down(heap, 0, heap.size());  // 下沉堆顶元素
                }
            }
        }
    }

    return 0;
}
