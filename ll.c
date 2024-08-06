#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_llist(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("end\n");
}

void add_first(struct node **head, int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

void add_last(struct node **head, int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->next = NULL;
    new_node->data = val;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void remove_first(struct node **head) {
    if (*head == NULL) {
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void remove_last(struct node **head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

int main() {
    
    struct node *head = NULL;

    add_last(&head, 1);
    add_last(&head, 2);
    add_last(&head, 3);

    print_llist(head);

    remove_first(&head);
    print_llist(head);

    remove_last(&head);
    print_llist(head);

    // Free the remaining list
    remove_first(&head);

    print_llist(head);

    return 0;
}
