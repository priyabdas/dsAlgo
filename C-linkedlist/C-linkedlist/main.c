//
//  main.c
//  linkedlist-c
//
//  Created by priyabrata Das on 17/02/22.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t ;

void appendNode(node_t **head ,int data){
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return ;
    }

    node_t *last = *head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;

}


/*Print linked list */
void displayList(node_t *head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/*
 Assumption linked list position starts at 0 (similar array indexing)
 position example for n node linked list 0,1,2,3,4,5,...,n
 Note if position is greater than the linked list size it will add at the end
 */
void appendAtPos(node_t **head , int pos , int val){
    printf("Adding a new node at position %d value %d \n",pos ,val);

    node_t *current = *head;

    if (*head == NULL){
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    //Add at 0th position
    if (pos == 0){
        new_node->data = val;
        new_node->next = current;
        *head = new_node;
        return;
        //Add at 0th position
    }

    for(int i = 0 ; i < pos-1 && current != NULL; i++){
        if(current->next == NULL){
            break;
        }
        current = current->next;
    }

    node_t *current_next = current->next;
    new_node->data = val;
    current->next = new_node;
    new_node->next = current_next;
}

/*
 Delete a node at a given position .
 if the input is 0 , delete the first node and so on .
 position example for n node linked list 0,1,2,3,4,5,...,n
 */
void deleteAtPos(node_t **head, int pos){
    printf("Deleting node at position %d\n",pos);
    //Sanity for inputs to the function
    if (pos < 0 || *head == NULL ){
        return;
    }

    node_t *current = *head;

    if (pos == 0){
        *head = current->next;
        free(current);
        return;
    }

    for(int i = 0 ; i < pos-1 && current!= NULL; i++){
        if (current->next == NULL || current->next->next == NULL){
            break;
        }
        current = current->next;
    }

    node_t *next = current->next->next;
    free(current->next);
    current->next = next;
}

/*
    Reverse a linked list given its head
*/
void reverseLinkedlist(node_t **head){
    printf("Reverseing linkedlist \n");

    node_t *prev= NULL, *next = NULL;
    node_t *current = *head;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev ;
}

void printMiddleLinkedlist(node_t **head){

    node_t *fast = *head;
    node_t *slow = *head;

    if (fast == NULL){
        return;
    }

    while(slow != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle of linked list is %d\n",slow->data);



}


int main (){
    node_t *head = NULL;

    appendNode(&head, 10);

    appendNode(&head, 20);

    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 50);
    displayList(head);
    appendAtPos(&head, 0, 100);
    displayList(head);
    appendAtPos(&head, 2, 80);
    displayList(head);
    appendAtPos(&head, 5, 90);
    displayList(head);
    appendAtPos(&head, 10, 60);
    displayList(head);
    deleteAtPos(&head, 0);
    displayList(head);
    deleteAtPos(&head, 2);
    displayList(head);
    deleteAtPos(&head, 5);
    displayList(head);
    deleteAtPos(&head, 10);
    displayList(head);
    appendAtPos(&head, 0, 100);
    displayList(head);
    appendAtPos(&head, 2, 80);
    displayList(head);
    appendAtPos(&head, 5, 90);
    displayList(head);
    appendAtPos(&head, 10, 60);
    displayList(head);
    reverseLinkedlist(&head);
    displayList(head);
    printMiddleLinkedlist(&head);



    return (0);

}
