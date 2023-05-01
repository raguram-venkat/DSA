#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, ra, ca;
    scanf("%d %d", &ra, &ca);

    arr = (int *)malloc(ra * ca * sizeof(int));
    int count = 0;
    for (int i = 0; i < ra; i++)
        for (int j = 0; j < ca; j++)
            *(arr + i * ca + j) = ++count; // OR *(*(arr+i)+j) = ++count

    for (int i = 0; i < ra; i++)
        for (int j = 0; j < ca; j++)
            printf(" value at i j is : %d \n", arr[i * ca + j]);

    /* Code for further processing and free the
    dynamically allocated memory */

    // for (int i = 0; i < r; i++)
    //     free(arr[i]);

    free(arr);

    return 0;
}
