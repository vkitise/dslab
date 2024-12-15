#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char ssn[20], name[20], dept[20], desg[20], phno[15];
    float sal;
    struct Node *prev, *next;
};
struct Node *head = NULL, *tail = NULL;
int count = 0;
struct Node* createNode() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter SSN, Name, Dept, Designation, Salary, Phone Number: ");
    scanf("%s %s %s %s %f %s", newNode->ssn, newNode->name, newNode->dept, newNode->desg, &newNode->sal, newNode->phno);
    newNode->prev = newNode->next = NULL;
    count++;
    return newNode;
}
void insertEnd() {
    struct Node *newNode = createNode();
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertFront() {
    struct Node *newNode = createNode();
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void deleteFront() {
    if (!head) {
        printf("\nList is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    printf("\nDeleted: %s %s %s %s %.2f %s\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
    free(temp);
    count--;
}
void deleteEnd() {
    if (!head) {
        printf("\nList is empty.\n");
        return;
    }
    struct Node *temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("\nDeleted: %s %s %s %s %.2f %s\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
    free(temp);
    count--;
}
void display() {
    if (!head) {
        printf("\nList is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("\nEmployee List:\n");
    while (temp) {
        printf("%s %s %s %s %.2f %s\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
        temp = temp->next;
    }
    printf("Total Employees: %d\n", count);
}
int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n1. Insert at End\n2. Insert at Front\n3. Delete from Front\n4. Delete from End\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertEnd(); break;
            case 2: insertFront(); break;
            case 3: deleteFront(); break;
            case 4: deleteEnd(); break;
            case 5: display(); break;
            case 6: printf("\nExiting.\n"); return 0;
            default: printf("\nInvalid choice.\n");
        }
    }
}
