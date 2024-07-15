#include <stdio.h>
#include <time.h>

int a[10], n;

void Qsort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main()
{
    int i;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of elements \n");
    scanf("%d", &n);
    printf("Enter array elements \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();
    Qsort(a, 0, n - 1);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Sorted elements \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

    return 0;
}

void Qsort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = partition(a, low, high);
        Qsort(a, low, mid - 1);
        Qsort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int i, j, temp, pivot;
    pivot = a[low];
    i = low + 1;
    j = high;
    while (i <= j)
    {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
