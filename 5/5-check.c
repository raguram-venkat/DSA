#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int maxDynamite(int *a, int n, int q)
{
    int *b = (int *)calloc(n, sizeof(int));
    // int *c = (int *)calloc(n, sizeof(int));

    int x = 0;
    int y = 0;
    int k = 1;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            x += 1;
            y = 0;
        }
        if (a[i] == 1)
        {
            y += 1;
            x = 0;
        }
        if ((a[i] == 0) && (a[i + 1] == 1))
        {
            b[k] = x;
            k++;
        }
        if ((a[i] == 1) && (a[i + 1] == 0))
        {
            b[k] = y;
            k++;
        }
    }

    // for (int i = 1; i <= k; i++)
    // {
    //     printf("%d", b[i]);
    // }

    // printf("\n");

    f = a[0];
    int r = 0;
    if (f == 1)
    {
        for (int i = 1; i <= k; i = i + 2)
        {
            x = front(b, i, q);
            y = back(b, i, q);
            if (r < x)
                r = x;
            if (r < y)
                r = y;
        }
    }

    if (f == 0)
    {
        for (int i = 2; i <= k; i = i + 2)
        {
            x = front(b, i, q);
            // printf("%d\n", x);
            y = back(b, i, q);
            if (r < x)
                r = x;
            if (r < y)
                r = y;
        }
    }

    return r;
}

int front(int *a, int i, int c)
{

    if (a[i + 1] == 0)
        return a[i] + c;

    if (a[i + 1] > c)
    {
        // printf("%d\n", a[i]);
        return a[i] + c;
    }
    if (a[i + 1] <= c)
    {

        int h = a[i] + a[i + 1] + front(a, i + 2, c - a[i + 1]);
        // printf("%d\n", h);
        return h;
    }
}

int back(int *a, int i, int c)
{
    if (a[i + 1] == 0)
        return a[i] + c;
    if (a[i + 1] > c)
    {
        return a[i] + c;
    }
    if (a[i + 1] < c)
    {
        int h = a[i] + a[i - 1] + front(a, i - 2, c - a[i - 1]);
        return h;
    }
}

int main()
{
    int a[100] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int z = maxDynamite(a, 11, 2);
    printf("%d", z);
}