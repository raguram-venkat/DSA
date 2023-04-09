#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a[] = {1, 2, 3, 9, 8, 4, 3};
    mergeSort(0, 6, a);
    for (int i = 0; i < 7; i++)
        printf("%d", a[i]);
    int c = binarySearch(0, 6, a, 2);
    printf("%d", c);
}

void mergeSort(int p, int r, int *a)
{
    if (p >= r)
        return;
    int q = (p + r) / 2;
    mergeSort(p, q, a);
    mergeSort(q + 1, r, a);
    merge(a, p, q, r);
}

void merge(int arr[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

int binarySearch(int p, int r, int a[], int x)
{
    if (p >= r)
        return 0;
    int q = (p + r) / 2;
    if (x == a[q])
        return q + 1;
    if (x > a[q])
    {
        binarySearch(q, r, a, x);
        printf("a");
    }
    if (x < a[q])
    {
        binarySearch(p, q, a, x);
        printf("b");
    }
}