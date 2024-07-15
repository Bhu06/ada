#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int searchArr(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(int n) {
    int perm[n];
    int dir[n]; 
    int num;
     printf("\nEnter number:");
    for (int i = 0; i < n; i++) {
        scanf("%d",&num);
        perm[i] = num;
        dir[i] = 0;
    }

    while (1) {
        printArray(perm, n);

        int mobile = 0, mobileIndex = -1;

        
        for (int i = 0; i < n; i++) {
            if ((dir[i] == 0 && i != 0 && perm[i] > perm[i - 1]) || (dir[i] == 1 && i != n - 1 && perm[i] > perm[i + 1])) {
                if (perm[i] > mobile) {
                    mobile = perm[i];
                    mobileIndex = i;
                }
            }
        }

        
        if (mobileIndex == -1) {
            break;
        }

        
        if (dir[mobileIndex] == 0) {
            swap(&perm[mobileIndex], &perm[mobileIndex - 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex - 1]);
            mobileIndex--;
        } else {
            swap(&perm[mobileIndex], &perm[mobileIndex + 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex + 1]);
            mobileIndex++;
        }

        
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile) {
                dir[i] = !dir[i];
            }
        }
    }
}


int main() {
    int n;
    printf("Enter the number of elements to permute: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of elements should be greater than 0.\n");
        return 1;
    }

    generatePermutations(n);

    return 0;
}