#include <stdio.h>

int partition(int data[], int low, int high)
{
    int i, j, pivot;
    pivot = data[low]; // 选择第一个元素作为基准值
    i = low;
    j = high;

    while (i < j)
    {
        // 从数组的两端交替地向中间扫描 从左边找到一个不符合的元素，再从右边找到一个不符合的元素，彼此之间相互交换位置
        while (i < j && data[j] >= pivot)
            j--;
        data[i] = data[j]; // 将小于基准值的元素移到左侧
        while (i < j && data[i] <= pivot)
            i++;
        data[j] = data[i]; // 将大于基准值的元素移到右侧
    }
    data[i] = pivot; // 放置基准值到正确位置
    return i;        // 返回基准值的位置
}

void quickSort(int data[], int low, int high)
{
    if (low < high)
    {
        int loc = partition(data, low, high); // 获取基准值位置
        quickSort(data, low, loc - 1);        // 对左侧子数组递归排序
        quickSort(data, loc + 1, high);       // 对右侧子数组递归排序
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

    quickSort(data, 0, n - 1);

    printf("\n排序后数组：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
}
