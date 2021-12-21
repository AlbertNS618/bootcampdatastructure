#include <stdio.h>
#include <malloc.h>
struct Node{
    int value;
    Node *next;
    Node *prev;
} *head = NULL, *tail = NULL;

// create new node
Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// push to head
void pushHead(int value){
    Node *newNode = createNode(value);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// pop from head
void popHead(){
    if(head == NULL){
        return;
    }
    else if(head == tail){
        head->next = NULL;
        head->prev = NULL;
        free(head);
        head = tail = NULL;
    }
    else{
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
}

// print all element in linked list
void printAll(){
    Node *curr = head;
    while(curr != NULL){
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("null\n");
}

int main(){
    pushHead(12);
    pushHead(13);
    pushHead(14);
    popHead();
    printAll();
    return 0;
}