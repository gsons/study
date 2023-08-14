#include <stdlib.h> // 包含标准库以使用 malloc 和 free 函数
#include <stdio.h>

// 希尔排序算法
void ShellSort(int data[], int n)
{
    int *delta;         // 存储增量序列的数组指针
    int k, i, t, dk, j; // 循环计数器、临时变量和间隔大小

    // 初始化变量 k 为数组长度 n
    k = n;

    // 计算增量序列 delta，用于确定子序列的间隔
    delta = (int *)malloc(sizeof(int) * (n / 2)); // 分配内存存储增量序列
    i = 0;                                        // 初始化循环计数器 i 为 0
    do
    {
        k = k / 2;      // 计算新的增量值
        delta[i++] = k; // 将增量值存入增量序列数组
    } while (k > 1);    // 当增量值大于 1 时继续循环

    // 使用增量序列进行希尔排序
    i = 0; // 重置循环计数器 i 为 0
    while ((dk = delta[i++]) > 0)
    { // 遍历增量序列
        for (k = dk; k < n; ++k)
        {                // 遍历数组，从第 dk 个元素开始
            t = data[k]; // 将当前元素保存到临时变量 t 中
            for (j = k - dk; j >= 0 && t < data[j]; j -= dk)
            {
                // 在已排序的子序列中找到适当位置插入当前元素
                data[j + dk] = data[j]; // 移动元素以便腾出插入位置
            }
            data[j + dk] = t; // 插入当前元素到正确位置
        }
    }

    // 释放增量序列的内存
    free(delta);
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

    ShellSort(data, n);

    printf("\n排序后数组：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
}
