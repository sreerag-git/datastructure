#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
node *head = NULL;

void insert_end() {
    int data;
    node *temp, *pre;
    
    printf("\nEnter value: ");
    scanf("%d", &data);
    
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        pre = head;
        while (pre->next != NULL) {
            pre = pre->next;
        }
        pre->next = temp;
    }
}

void insert_first() {
    int data;
    node *temp;

    printf("\nEnter value to insert: ");
    scanf("%d", &data);
    
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insert_pos() {
    int data, pos;
    node *temp, *new_node;
    printf("\nEnter value to insert: ");
    scanf("%d", &data);
    printf("\nEnter Position to insert: ");
    scanf("%d", &pos);

    new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    if (head == NULL && pos == 1) {
        new_node->next = NULL;
        head = new_node;
    } else if (pos == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        temp = head;
        int count = 1;

        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            printf("Position exceeds the length of the list. Node not inserted.\n");
            free(new_node);
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

void display() {
    node *temp = head;
    int count = 1;

    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    }

    while (temp != NULL) {
        printf("List [%d]: %d\n", count, temp->data);
        temp = temp->next;
        count++;
    }
}

void search() {
    node *temp = head;
    int data, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &data);
    
    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    }

    while (temp != NULL) {
        if (data == temp->data) {
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        printf("\nFound\n");
    } else {
        printf("\nNot found\n");
    }
}

void delete_e() {
    int value;
    node *temp = head, *prev = NULL;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    }

    if (temp != NULL && temp->data == value) {
        head = temp->next; // Change head
        free(temp); // Free the old head
        printf("Deleted: %d\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp); // Free the memory of the node
    printf("Deleted: %d\n", value);
}

int main() {
    int opt;
    do {
        printf("\n1) Insert in FIRST");
        printf("\n2) Insert in END");
        printf("\n3) Insert @ a Position");
        printf("\n4) Display");
        printf("\n5) Search");
        printf("\n6) Delete");
        printf("\n0) Quit\n");
        printf("\nChoose option: ");
        scanf("%d", &opt);
        
        switch (opt) {
            case 1:
                insert_first();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_pos();
                break;
            case 4:
                display();
                break;
            case 5:
                search();
                break;
            case 6:
                delete_e();
                break;
            default:
                if (opt != 0) {
                    printf("Invalid option! Try Again..\n");
                }
        }
    } while (opt != 0);

    return 0;
}

