
#include <stdio.h>
#include <stdlib.h>

int changedBinarySearch(int *a, int low, int high, int x, int n)
{
    int mid = (low + high) / 2;
    if (a[mid] == x)
    {
        return mid;
    }
    else if (low == high)
    {
        if (a[mid] == x)
        {
            return mid;
        }
        else
        {
            return mid + 1;
        }
    }
    else if (low + 1 == high)
    {
        if (a[low] == x)
            return low;

        else
        {
            if (a[n - 1] < x)
            {
                return -1;
            }
            else
                return high;
        }
    }
    else if (a[mid] > x)
    {
        changedBinarySearch(a, low, mid, x, n);
    }
    else if (a[mid] < x)
    {
        changedBinarySearch(a, mid, high, x, n);
    }
}

int fun(int *a, int low, int high, int t, int n)
{
    int c = 0;
    int k = 0;
    int q = t;
    while (k != -1)
    {

        k = changedBinarySearch(a, low, high, q, n);

        q += t;
        if (k == -1)
        {
            break;
        }
        c += (n - k);
    }

    return c;
}
int planks(int *a, int n, int k)
{
    int l = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                l = a[j + 1];
                a[j + 1] = a[j];
                a[j] = l;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        l = a[n - i];
        int o = fun(a, 0, n - 1, l, n);

        if (o >= k)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return -1;
    if (flag == 1)
        return l;
}

int main()
{
    int a[20] = {1, 3, 3, 2};
    int v = planks(a, 4, 10);
    printf("%d", v);
}