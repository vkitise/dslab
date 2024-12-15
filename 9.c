#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Node {
    int coef, exp;
    struct Node* next;
} Node;
Node* insert(Node* head, int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    if (!head) { newNode->next = newNode; return newNode; }
    Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode; newNode->next = head;
    return head;
}
void display(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        if (temp->exp == 0) printf("%d", temp->coef);
        else printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != head) printf("+");
    } while (temp != head);
    printf("\n");
}
Node* add(Node* p1, Node* p2) {
    Node *result = NULL, *t1 = p1;
    do {
        result = insert(result, t1->coef, t1->exp);
        t1 = t1->next;
    } while (t1 != p1);

    Node* t2 = p2;
    do {
        Node* temp = result;
        int found = 0;
        do {
            if (temp->exp == t2->exp) {
                temp->coef += t2->coef; found = 1; break;
            }
            temp = temp->next;
        } while (temp != result);
        if (!found) result = insert(result, t2->coef, t2->exp);
        t2 = t2->next;
    } while (t2 != p2);
    return result;
}
int evaluate(Node* head, int x) {
    int sum = 0;
    if (!head) return sum;
    Node* temp = head;
    do {
        sum += temp->coef * pow(x, temp->exp);
        temp = temp->next;
    } while (temp != head);
    return sum;
}
int main() {
    Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int choice, terms, coef, exp, x;
    do {
        printf("1. Input Poly1 2. Input Poly2 3. Add and Eval 4. Exit: ");
        scanf("%d", &choice);
        if (choice == 1 || choice == 2) {
            printf("Enter terms: ");
            scanf("%d", &terms);
            for (int i = 0; i < terms; i++) {
                printf("Coef Exp: ");
                scanf("%d%d", &coef, &exp);
                if (choice == 1) poly1 = insert(poly1, coef, exp);
                else poly2 = insert(poly2, coef, exp);
            }
        } else if (choice == 3) {
            sum = add(poly1, poly2); 
            printf("Sum: ");
            display(sum); 
            printf("Enter x: ");
            scanf("%d", &x);
            printf("Value of the sum at x = %d: %d\n", x, evaluate(sum, x)); 
        }
    } while (choice != 4);
    return 0;
}
