#include <stdio.h>

int main()
{
    int a[5] = {1, 3, 5, 7, 9};
    int b[4] = {2, 4, 6, 8};

    int n1 = 5, n2 = 4;
    int c[9];

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    // copy remaining elements
    while (i < n1)
        c[k++] = a[i++];

    while (j < n2)
        c[k++] = b[j++];

    printf("Merged Array:\n");
    for (i = 0; i < k; i++)
        printf("%d ", c[i]);

    return 0;
}
