#include <stdlib.h> // 包含标准库以使用 malloc 和 free 函数
#include <stdio.h>

void bubble_sort(int *arr, int len)
{
    int i, j;

    // 外层循环控制每次冒泡的次数，最多 len - 1 次
    for (i = 0; i < len - 1; i++) {
        // 内层循环进行相邻元素的比较和交换
        // 在每次冒泡中，最大的元素会“冒泡”到末尾
        for (j = 0; j < len - 1 - i; j++) {
            // 如果当前元素比后一个元素大，交换它们的位置
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main()
{
    int data[] = {12, 34, 5, 23, 67, 87, 45, 1, 8, 22};
    int n = sizeof(data) / sizeof(data[0]);

    printf("原始数组：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    bubble_sort(data, n);

    printf("\n排序后数组：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
}
