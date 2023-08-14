#include <stdlib.h> // 包含标准库以使用 malloc 和 free 函数
#include <stdio.h>


void merge_arr(int *arr, int start, int middle, int end)
{
    // 初始化左右子数组的起始索引和临时数组的索引
    int i = start, j = middle + 1, k = 0;

    // 为临时数组分配内存
    int *temp;
    temp = (int *)malloc((end - start + 1) * sizeof(int));

    // 比较左右子数组的元素，并将较小的元素放入临时数组中
    while (i <= middle && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // 将剩余的左子数组元素放入临时数组
    while (i <= middle)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // 将剩余的右子数组元素放入临时数组
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // 将临时数组中的元素复制回原始数组的正确位置
    for (i = 0; i < k; i++)
    {
        arr[start + i] = temp[i]; // 注意这里的索引修正
    }

    // 释放临时数组的内存
    free(temp);
}

void merge_sort(int *arr, int start, int end)
{
    // 当子数组长度大于1时，继续划分子数组并合并
    if (start < end)
    {
        // 计算中间索引，划分为左右子数组
        int middle = (start + end) / 2;

        // 递归调用 merge_sort 处理左子数组
        merge_sort(arr, start, middle);

        // 递归调用 merge_sort 处理右子数组
        merge_sort(arr, middle + 1, end);

        // 合并左右子数组
        merge_arr(arr, start, middle, end);
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

    merge_sort(data,0, n-1);

    printf("\n排序后数组：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
}