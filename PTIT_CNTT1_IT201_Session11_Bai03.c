#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *create_node(int data) {
    node *temp = (node *) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

node* search_node(node *head, int data) {
    while (head != NULL) {
        if (head->data == data) return head;
        head = head->next;
    }
    return NULL;
}

int main() {
    node *head = create_node(1);
    node *node1 = create_node(2);
    node *node2 = create_node(3);
    node *node3 = create_node(4);
    node *node4 = create_node(5);
    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    int search;
    scanf("%d", &search);
    if (search_node(head, search)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    return 0;
}
