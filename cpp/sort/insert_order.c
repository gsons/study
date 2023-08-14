#include <stdlib.h> // 包含标准库以使用 malloc 和 free 函数
#include <stdio.h>

void insert_sort(int *arr, int len)
{
    int i, j;

    // 从第二个元素开始遍历，将其插入已排序的部分
    for (i = 1; i < len; i++)
    {
        // 如果当前元素小于前一个元素，需要将其插入到正确的位置
        if (arr[i] < arr[i - 1])
        {
            int temp = arr[i]; // 暂存当前元素

            // 在已排序的部分中查找插入位置
            for (j = i - 1; j >= 0; j--)
            {
                // 如果当前元素大于暂存元素，将当前元素后移一位
                if (arr[j] > temp)
                {
                    arr[j + 1] = arr[j];
                }
                else
                {
                    break; // 找到插入位置，跳出循环
                }
            }

            arr[j + 1] = temp; // 将暂存元素插入到正确位置
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

    insert_sort(data, n);

    printf("\n排序后数组：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
}
