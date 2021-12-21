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

// push from tail
void pushTail(int value){
    Node *newNode = createNode(value);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
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

// push according to priority scale
void pushMid(int value){
    if(head == NULL){
        Node *newNode = createNode(value);
        head = tail = newNode;
    }
    else if(head->value < value){
        pushHead(value);
    }
    else if(tail->value >= value){
        pushTail(value);
    }
    else{
        Node *newNode = createNode(value);
        Node *curr = head;
        while(curr->value >= value){
            curr = curr->next;
        }
        newNode->prev = curr->prev;
        newNode->next = curr;
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
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
    pushMid(12);

    return 0;
}