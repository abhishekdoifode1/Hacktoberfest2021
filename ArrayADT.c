

#include <stdio.h>

//This program contains Array ADT functions to perform display,insert ,delete,swap and LinearSearch


struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ,", arr.A[i]);
    }
}

void Insert(struct Array *pt, int index, int value)
{
    for (int i = pt->length; i > index; i--)
    {
        pt->A[i] = pt->A[i - 1];
    }
    pt->A[index] = value;
    pt->length++;
}
void Delete(struct Array *pt, int index)
{
    int i;
    if (index >= 0 && index < pt->length)
    {
        for (i = index; i < pt->length - 1; i++)
        {
            pt->A[i] = pt->A[i + 1];
        }
        pt->length--;
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int LinearSearch(struct Array *arr, int value)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (value == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}
int main()
{
    struct Array array = {{1, 4, 77, 7, 20}, 10, 5};
    printf("Initial array \n");
    Display(array);
    printf("\n");
    Insert(&array, 4, 5);
    printf("After inserting element 5 at index 4 \n");
    
    Display(array);

    Delete(&array, 0);
    printf("\n");
    printf("After deleting element  at index 0 \n");
   

    Display(array);
    printf("\n");
    printf("Performed linear search to find element 4 \n");
   
    printf("The element is found at index: %d\n", LinearSearch(&array, 4));

    return 0;
}
