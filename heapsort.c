#include <stdio.h>
#include <time.h>

void heap_sort(int a[], int n);
void heap_construct(int a[], int n);
void heap_adjust(int a[], int n);

int main()
{
    int n, i, a[10];
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();
    heap_sort(a, n);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Sorted array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

    return 0;
}

void heap_sort(int a[], int n)
{
    int i, temp;
    heap_construct(a, n);
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heap_adjust(a, i);
    }
}

void heap_construct(int a[], int n)
{
    int i, j, k, item;
    for (k = 1; k < n; k++)
    {
        item = a[k];
        i = k;
        j = (i - 1) / 2;
        while (i > 0 && item > a[j])
        {
            a[i] = a[j];
            i = j;
            j = (i - 1) / 2;
        }
        a[i] = item;
    }
}

void heap_adjust(int a[], int n)
{
    int i, j, item;
    j = 0;
    item = a[j];
    i = 2 * j + 1;
    while (i <= n - 1)
    {
        if (i + 1 <= n - 1 && a[i] < a[i + 1])
            i++;
        if (item < a[i])
        {
            a[j] = a[i];
            j = i;
            i = 2 * j + 1;
        }
        else
            break;
    }
    a[j] = item;
}
