#include <iostream>  // std::cout
#include <algorithm> // std::swap

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; ++i)
        for (j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}
int main()
{
    int arr[] = {5, 7, 2, 4, 9, 3, 1, 8, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    return 0;
}
