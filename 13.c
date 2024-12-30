#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define MAX 20
float stack[MAX];
int top = -1;
void push(float num) { if (top == MAX - 1) { printf("Stack overflow\n"); exit(0); } stack[++top] = num; }
float pop() { if (top == -1) { printf("Stack underflow\n"); exit(0); } return stack[top--]; }
float eval_postfix(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) push(ch - '0');
        else {
            float op2 = pop(), op1 = pop();
            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': push(pow(op1, op2)); break;
                default: printf("Illegal operator\n"); exit(0);
            }
        }
    }
    return pop();
}
int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    float result = eval_postfix(postfix);
    printf(top == -1 ? "Result: %f\n" : "Not a valid expression\n", result);
    return 0;
}
