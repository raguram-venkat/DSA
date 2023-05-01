#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, fp, fpi, ln, lni, flag;
    printf("Enter no. of elements\n");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    flag = 0;
    fp = -10;
    fpi = 0;
    ln = 0;
    lni = 0;

    for (int i = 0; i < n; i++)
    {
        if (flag == 0)
        {
            if (a[i] > 0)
            {
                fp = a[i];
                fpi = i;
                flag = 1;
            }
        }

        if (a[i] < 0)
        {
            ln = a[i];
            lni = i;
        }
        if (lni > fpi)
        {
            a[fpi] = ln;
            fpi += 1;
            for (int j = lni; j >= fpi; j--)
            {
                a[j] = a[j - 1];
            }
            a[fpi] = fp;
            lni = fpi - 1;
        }
    }

    printf("Finally it is\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
}
