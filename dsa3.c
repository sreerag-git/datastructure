#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[200], b[100], n1, n2, i, j, total, temp;

    printf("Enter the size of two arrays: ");
    scanf("%d %d", &n1, &n2);

    printf("Enter the first array: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the second array: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    // Merge the second array into the first arra
    total = n1 + n2;
    for (i = 0; i < n2; i++) {
        a[n1 + i] = b[i]; // Corrected index for merging
    }

    // Bubble sort the combined array
    for (i = 0; i < total; i++) {
        for (j = 0; j < total - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap if the current element is greater than the next
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Output the sorted array
    printf("After sorting:\n");
    for (i = 0; i < total; i++) {
        printf("%d ", a[i]);
    }
    printf("\n"); // Newline for better output format

    return 0;
}

 
  
 
  
