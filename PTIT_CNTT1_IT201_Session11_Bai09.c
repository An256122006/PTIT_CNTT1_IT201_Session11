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
   node *temp=(node *)malloc(sizeof(node));
   temp->data = data;
   temp->next = NULL;
   temp->prev = NULL;
   return temp;
}
void print_list(node *head) {
   node *temp = head;
   int i=1;
   while(temp!=NULL) {
      printf("Node%d:%d\n",i,temp->data);
      temp=temp->next;
      i++;
   }
}
node *resevere_node(node *head) {
   node *temp = NULL;
   node *current = head;

   while (current != NULL) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
   }
   if (temp != NULL) {
      head = temp->prev;
   }
   return head;
}
int main(){
   node *head = create_node(1);
   node *node1=create_node(2);
   node *node2=create_node(3);
   node *node3=create_node(4);
   node *node4=create_node(5);
   head->next = node1;
   node1->prev = head;
   node1->next = node2;
   node2->prev = node1;
   node2->next = node3;
   node3->prev = node2;
   node3->next = node4;
   node4->prev = node3;
   head = resevere_node(head);
   print_list(head);
   return 0;
}