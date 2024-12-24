#include <stdio.h>

void swap(int *a, int *b) {     // 交换两个整数的值
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {  // 分区函数
    int pivot = arr[high];      // 选择最后一个元素作为枢轴
    int i = (low - 1);          // 较小元素的索引
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {  // 如果当前元素小于或等于枢轴
            i++;                // 增加较小元素的索引
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {  // 快速排序函数
    if (low < high) {
        int pi = partition(arr, low, high);     // pi 是分区索引，arr[pi] 已经排好序
        quickSort(arr, low, pi - 1);            // 分别对分区的两部分进行排序   ·
        quickSort(arr, pi + 1, high);
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}