#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
void insertAtBeginning(Node **head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; newNode->prev = NULL; newNode->next = *head;
    if(*head != NULL) (*head)->prev = newNode;
    *head = newNode;
}
void insertAtEnd(Node **head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; newNode->next = NULL;
    if(*head == NULL) { newNode->prev = NULL; *head = newNode; return; }
    Node* temp = *head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode; newNode->prev = temp;
}
void displayForward(Node *head) {
    printf("List forward: ");
    Node* temp = head;
    while(temp != NULL) { printf("%d - ", temp->data); temp = temp->next; }
    printf("NULL\n");
}
void displayBackward(Node *head) {
    if(head == NULL) { printf("List is empty.\n"); return; }
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    printf("List backward: ");
    while(temp != NULL) { printf("%d - ", temp->data); temp = temp->prev; }
    printf("NULL\n");
}
void deleteNode(Node **head, int value) {
    Node *temp = *head;
    while(temp && temp->data != value) temp = temp->next;
    if(temp == NULL) { printf("Value %d not found in the list.\n", value); return; }
    if(*head == temp) *head = temp->next;
    if(temp->prev) temp->prev->next = temp->next;
    if(temp->next) temp->next->prev = temp->prev;
    free(temp); printf("Deleted %d from the list.\n", value);
}
int main() {
    Node* head = NULL;
    insertAtEnd(&head, 10); insertAtBeginning(&head, 5);
    insertAtEnd(&head, 15); insertAtEnd(&head, 20);
    displayForward(head); displayBackward(head);
    deleteNode(&head, 15); displayForward(head); displayBackward(head);
    deleteNode(&head, 100); // Try deleting absent value
    return 0;
}
