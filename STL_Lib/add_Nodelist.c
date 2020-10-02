#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** head_ref, int new_data) {
    Node* new_head =(struct Node *) malloc(sizeof(struct Node));
    new_head->data = new_data;
    new_head->next = *head_ref;
    *head_ref = new_head;
}

void print(Node* head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }

    puts("NULL");
}

void free_list(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->data = 1;
    printf("Before push:\n");
    print(head);
    push(&head, 2);
    printf("\nAfter push:\n");
    print(head);
    free_list(head);
    return 0;
}