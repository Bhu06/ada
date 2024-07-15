#include <stdio.h>
#include <time.h>

void mergesort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main() {
    int i, n, a[100];
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();
    mergesort(a, 0, n - 1);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Sorted array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Time taken to sort the array: %f seconds\n", cpu_time_used);

    return 0;
}

void mergesort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int c[100];  // Temporary array for merging
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j <= high) {
        c[k] = a[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}
