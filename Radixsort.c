#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int getMax(int list[], int n) {
    int mx = list[0];
    int i;
    for (i = 1; i < n; i++)
        if (list[i] > mx)
            mx = list[i];
    return mx;
}

void countSort(int list[], int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(list[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(list[i] / exp) % 10] - 1] = list[i];
        count[(list[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        list[i] = output[i];
}

void radixsort(int list[], int n) {
    int m = getMax(list, n);

    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(list, n, exp);
}

void print(int list[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t", list[i]);
}

int main()
{
    int list[] = { 82, 901, 100, 12, 150, 77, 55, 23 };
    int i, n = sizeof(list) / sizeof(list[0]);

    printf("List of numbers before sort: \n");
    for(i = 0; i<8; i++)
        printf("%d\t", list[i] );

    radixsort(list, n);

    printf("\n\nList of numbers after sort: \n");
    print(list, n);
    printf("\n\n");
    return 0;
}