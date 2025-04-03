#include <stdio.h>
#include <stdlib.h>

int memorySizes() {

    int myVal = 13;
    
    printf("Value of integer 'myVal': %d\n", myVal);
    printf("Size of integer 'myVal': %lu bytes\n", sizeof(myVal)); // 4 bytes
    printf("Address to 'myVal': %p\n", &myVal);
    printf("Size of the address to 'myVal': %lu bytes\n", sizeof(&myVal)); // 8 bytes

    return 0;
}

// --------------------LINKED LIST IMPLEMENTATION--------------------

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void printList(Node *node) {
    while (node) {
        printf("%d ", node -> data);
        node = node -> next;
    }
}

int nodeImplement() {
    Node* node1 = createNode(3);
    Node* node2 = createNode(5);
    Node* node3 = createNode(13);
    Node* node4 = createNode(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printList(node1);

    // Free the memory
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}

int main() {
    nodeImplement();
    return 0;
}