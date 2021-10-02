#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

//Bubble sort
int *BubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            return arr;
    }
    return arr;
}

//Selection Sort
int *SelectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                swap(arr[i], arr[j]);
            }
        }
    }
    return arr;
}

//Insertion Sort
int *InsertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int num = arr[i];
        while (arr[i] < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num;
    }
    return arr;
}

//Merge Sort
void Merge(int *a, int l, int m, int r)
{
    int i = 0;
    int j = 0;
    int a1[m - l + 1];
    int a2[r - m];
    for (int i = 0; i < m - l + 1; i++)
    {
        a1[i] = a[l + i];
    }
    for (int i = 0; i < r - m; i++)
    {
        a2[i] = a[i + m + 1];
    }
    int k = l;
    while (i < m - l + 1 && j < r - m)
    {
        if (a1[i] > a2[j])
        {
            a[k] = a2[j];
            j++;
        }
        else
        {
            a[k] = a1[i];
            i++;
        }
        k++;
    }
    while (i < m - l + 1)
    {
        a[k] = a1[i];
        k++;
        i++;
    }
    while (j < r - m)
    {
        a[k] = a2[j];
        k++;
        j++;
    }
}

void MergeSortUtil(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    MergeSortUtil(arr, l, m);
    MergeSortUtil(arr, m + 1, r);
    Merge(arr, l, m, r);
}

void MergeSort(int *arr, int n)
{
    MergeSortUtil(arr, 0, n - 1);
}

//Quick Sort
int Partition(int *arr, int low, int high)
{
    int pivot = high;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr + j, arr + i);
        }
    }
    swap(arr + pivot, arr + i + 1);
    return i + 1;
}

void QuickSortUtil(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high);
        QuickSortUtil(arr, low, pi - 1);
        QuickSortUtil(arr, pi + 1, high);
    }
}

void QuickSort(int *arr, int n)
{
    QuickSortUtil(arr, 0, n - 1);
}

//Main Function
int main()
{
    int arr[] = {6, 23, 323, 32, 2, 532, 27};
    int n = sizeof(arr) / sizeof(int);
    int *a = BubbleSort(arr, n);
    cout << "Result of Bubble Sort : " << endl;
    print(a, n);
    int *b = SelectionSort(arr, n);
    cout << "Result of Selection Sort : " << endl;
    print(b, n);
    int *c = InsertionSort(arr, n);
    cout << "Result of Insertion Sort : " << endl;
    print(c, n);
    int arr2[] = {6, 23, 323, 32, 2, 532, 27};
    MergeSort(arr2, n);
    cout << "Result of Merge Sort : " << endl;
    print(arr2, n);
    int arr3[] = {6, 23, 323, 32, 2, 532, 27};
    QuickSort(arr3, n);
    cout << "Result of Quick Sort : " << endl;
    print(arr3, n);
}
