#include <stdlib.h> // 包含标准库以使用 malloc 和 free 函数
#include <stdio.h>

void select_sort(int *arr, int len)
{
    int i, j;

    // 外层循环遍历整个数组，从第一个元素到倒数第二个元素
    for (i = 0; i < len - 1; i++)
    {
        int min = i; // 假设当前位置的元素为最小值

        // 内层循环遍历未排序部分，找到最小值的索引
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min]) // 如果当前元素比最小值小
            {
                min = j; // 更新最小值索引
            }
        }

        // 将最小值与当前位置的元素交换位置
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    select_sort(data, n);

    printf("\n排序后数组：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
}