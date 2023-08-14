#include <stdio.h>

// 调整堆，使其满足大顶堆定义
void HeapAdjust(int data[], int s, int m) {
    int tmp = data[s]; // 备份元素 data[s]，为其找到适当位置后再插入
    int j;

    for (j = 2 * s + 1; j <= m; j = j * 2 + 1) {
        // 选择值较大的孩子结点向下筛选
        if (j < m && data[j] < data[j + 1]) {
            j++; // 右孩子比左孩子大，j指向右孩子
        }
        if (tmp >= data[j]) {
            break; // 如果父节点大于等于子节点，不需要调整
        }
        data[s] = data[j]; // 用 s 记录待插入元素的位置（下标）
        s = j;
    }
    data[s] = tmp; // 将备份元素插入到由 s 所指出的位置
}

// 堆排序函数
void HeapSort(int data[], int n) {
    int i, tmp;

    // 建立初始堆，从最后一个非叶子节点开始
    for (i = n / 2 - 1; i >= 0; --i) {
        HeapAdjust(data, i, n - 1);
    }

    // 进行堆排序
    for (i = n - 1; i > 0; --i) {
        tmp = data[0]; // 将堆顶元素（最大值）与堆底元素交换
        data[0] = data[i];
        data[i] = tmp;
        HeapAdjust(data, 0, i - 1); // 对剩余元素进行堆调整
    }
}

int main() {
    int data[] = {6, 2, 8, 3, 5, 1, 7, 4};
    int len = sizeof(data) / sizeof(data[0]);

    printf("原始数组: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    HeapSort(data, len); // 调用堆排序函数

    printf("排序后数组: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
