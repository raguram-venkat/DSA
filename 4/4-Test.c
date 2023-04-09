#include <stdio.h>
#include <stdlib.h>

int *mergeArray(int *a, int *b, int p, int q)
{
    int *c;
    int m = 0;
    int i = 0;
    int j = 0;
    int l = 0;
    printf("A");
    while (m <= p + q - 1)
    {
        printf("Hi");
        if (i == p - 1)
        {
            for (int k = 0; k < q - j; k++)
            {
                c[l + k] = b[j + k];
                printf("b");
            }
            break;
        }

        if (j == q - 1)
        {
            for (int k = 0; k < p - i; k++)
            {
                c[l + k] = a[i + k];
                printf("c");
            }
            break;
        }
        if (a[i] > b[j])
        {
            c[l] = a[i];
            l++;
            i++;
            printf("d");
        }

        else if (b[j] > a[i])
        {
            c[l] = b[j];
            l++;
            j++;
            printf("e");
        }

        else
        {
            c[l] = a[i];
            l++;
            i++;
            printf("f");
        }

        m++;
    }

    return c;
}
int main()
{
    int a[4] = {1, 2, 3, 4};
    int b[6] = {2, 5, 7, 9, 10, 11};
    int *c;
    c = mergeArray(a, b, 4, 6);
    printf("%d", &c[0]);
}