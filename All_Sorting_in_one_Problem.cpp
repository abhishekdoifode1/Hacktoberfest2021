#include<iostream>
using namespace std;

// functions prototype
void Display(int arr[], int n)
{
    // code of traversal
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}
//Insertion of elements of an array
int Insertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

//Deletion of elements of an array
void Deletion(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

//Searching
int LinearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}
//sorting
void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
//insertion_sorting
void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
//bubble_short
void BubbleSort(int arr[], int size)
{
    int counter = 1;
    while (counter < size)
    {
        for (int i = 0; i < size - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
}
//binary_search
int BinarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    cout << "Since Binary search is used in sorting array so first we have to sort array if array is not sorted.\n";
    InsertionSort(arr, size);
    cout << "Sorted Array : ";
    Display(arr, size);
    cout << endl;
    // Keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    int arr[100] = {12, 54, 16, 47, 25};
    int size = 5;
    int choice, element, index;
    do{
    cout << "\nEnter 1 -> For Traversal \n";
    cout << "Enter 2 -> For Insertion \n";
    cout << "Enter 3 -> For Deletion \n";
    cout << "Enter 4 -> For Linear searching \n";
    cout << "Enter 5 -> For Selection Sorting \n";
    cout << "Enter 6 -> For Bubble Sorting\n";
    cout << "Enter 7 -> For Insertion Sorting \n";
    cout << "Enter 8 -> For Binary searching \n";
    cout << "Enter 9 -> For Display\n";
    cout << "Enter 10 -> For Quit\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Traversal : \n";
        Display(arr, size);
        break;
    case 2:
        cout << "Enter the index of the element less than " << size << " : ";
        cin >> index;
        cout << "Enter the element of array  : ";
        cin >> element;
        Insertion(arr, size, element, 100, index);
        size += 1;
        break;
    case 3:
        cout << "Enter the index of the element less than " << size << " : ";
        cin >> index;
         Deletion(arr, size, index);
         size -= 1;
         Display(arr,size);
        break;
    case 4:
        cout << "Enter the element of array : ";
        cin >> element;
        cout << element << " is found at index " << LinearSearch(arr, size, element);
        break;
    case 5:
        cout << "\nBefore sorting of elements of an array\n";
        Display(arr, size);
        SelectionSort(arr, size);
        cout << "\nAfter sorting of elements of an array\n";
        Display(arr, size);
        break;
    case 6:
        cout << "\nBefore sorting of elements of an array\n";
        Display(arr, size);
        BubbleSort(arr, size);
        cout << "\nAfter sorting of elements of an array\n";
        Display(arr, size);
        break;
    case 7:
        cout << "\nBefore sorting of elements of an array\n";
        Display(arr, size);
        InsertionSort(arr, size);
        cout << "\nAfter sorting of elements of an array\n";
        Display(arr, size);
        break;
    case 8:
        cout << "Enter the element of array : ";
        cin >> element;
        cout << element << " is found at index " << BinarySearch(arr, size, element);
        break;
    case 9:
        Display(arr,size);
        break;
    default:
        break;
    }
    }
    while(choice!=10);
    return 0;
}
