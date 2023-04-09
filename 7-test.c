#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int x, sum, ind, i;
    sum = 0;
    ind = 1;
    int a[100];
    memset(a, 0, sizeof(a));
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &a[i]);
    }
    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = 0;
    }

    fun(ind, a, sum, arr, i);
    i = 0;

    printf("HI");
    // while (arr[i] > 0)
    // {
    //     printf("%d", &arr[i]);
    //     i++;
    // }
}

void fun(int ind, int *a, int sum, int *arr, int i)
{
    int m = ind;

    if ((a[2 * m] == 0))
    {
        sum += a[m - 1];
        arr[i] = sum;
        printf("%d\n", arr[i]);
        i++;
        return;
    }
    sum += a[m - 1];
    m = 2 * m;
    // printf("%d", m);
    fun(m, a, sum, arr, i);
    sum -= a[m - 1];
    m = m / 2;
    m = 2 * m + 1;
    fun(m, a, sum, arr, i);
}