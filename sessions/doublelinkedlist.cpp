#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value; // store value of the Node
    Node *next; // points to the next Node
    Node *prev;
} *head, *tail; // first and last node in the LL

Node *createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node)); // allocate memory for new node
    newNode->value = value; // initialize the value of the Node to the parameter
    newNode->next = newNode->prev = NULL; // by default, newNode->next will be NULL
    return newNode; // return the newly created Node
}

void pushHead(int value) { // insert node at the beginning of the LL
    Node *temp = createNode(value); // create the new node

    if(!head) { // if head is NULL (LL is empty)
        head = tail = temp; // this node will be the first and last node in LL
    } else { // if LL has >= 1 node
        head->prev = temp; // set previous of head to temp (temp <- head)
        temp->next = head; // set next of temp to head (temp -><- head)
        head = temp; // temp will be the new head (first element in LL)
    }
}

void pushTail(int value) { // insert node at the end of the LL
    Node *temp = createNode(value); // create the new node

    if(!head) { // if head is NULL (LL is empty)
        head = tail = temp; // this node will be the first and last node in LL
    } else { // if LL has >= 1 node
        tail->next = temp; // set next of tail to temp (temp <- tail)
        temp->prev = tail; // set prev of temp to tail (temp -><- tail)
        tail = temp; // temp will be the new tail (last element in LL)
    }
}

void pushMid(int value){
    if( !head ){ // if head is NULL (LL is empty)
        Node *temp = createNode(value); // create the new node
        head = tail = temp; // this node will be the first and last node in LL
    }
    else if( value < head->value ){ // if value is the smalles
        pushHead(value); // add to the left
    }
    else if(value > tail->value){ // if value is the largest
        pushTail(value); // add to the right
    }
    else{
        Node *temp = createNode(value); // create the new node
        Node *curr = head; // we will set curr to become one node behind temp

        while(curr->value < value){
            curr = curr->next; // traverse until curr is found
        }

        temp->prev = curr->prev;
        temp->next = curr;
        curr->prev->next = temp;
        curr->prev = temp;
    }

}

void printLL() {
    puts("LINKED LIST: ");

    if(!head) {
        puts("EMPTY");
        return;
    }

    // Loop through all the nodes
    Node *temp = head;

    while(temp != tail->next) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }

    puts("NULL");
}

int main(){
    pushMid(5);
    printLL();
    pushMid(3);
    printLL();
    pushMid(10);
    printLL();
    pushMid(8);
    printLL();
    pushMid(4);
    printLL();
    pushMid(6);
    printLL();

}