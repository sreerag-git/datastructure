#include <stdio.h>

#define MAX_SIZE 100

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Current number of elements in the array
    int choice, value, i;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. View\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                if (size < MAX_SIZE) {
                    printf("Enter the value to insert: ");
                    scanf("%d", &value);
                    arr[size] = value; // Insert at the end
                    size++;
                    printf("Value inserted.\n");
                } else {
                    printf("Array is full. Cannot insert.\n");
                }
                break;

            case 2: // Delete
                if (size > 0) {
                    printf("Enter the index to delete (0 to %d): ", size - 1);
                    scanf("%d", &i);
                    if (i >= 0 && i < size) {
                        for (int j = i; j < size - 1; j++) {
                            arr[j] = arr[j + 1]; // Shift elements left
                        }
                        size--;
                        printf("Value deleted.\n");
                    } else {
                        printf("Invalid index.\n");
                    }
                } else {
                    printf("Array is empty. Cannot delete.\n");
                }
                break;

            case 3: // View
                display(arr, size);
                break;

            case 4: // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

