#include <stdio.h>
#include <ctype.h>
#define SIZE 50 
char stack[SIZE];
int top = -1;
void push(char elem) {
    stack[++top] = elem;
}
char pop() {
    return stack[top--];
}
int precedence(char elem) {
    switch (elem) {
        case '#': return 0;
        case '(': return 1;
        case '+': case '-': return 2;
        case '*': case '/': case '%': return 3;
        case '^': return 4;
        default: return -1;
    }
}
int main() {
    char infix[SIZE], postfix[SIZE];
    int i = 0, k = 0;
    char ch;
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    push('#'); 
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch; 
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(') 
                postfix[k++] = pop();
            pop(); // Remove '(' from stack
        } else {
            while (precedence(stack[top]) >= precedence(ch)) 
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (stack[top] != '#') 
        postfix[k++] = pop();
    postfix[k] = '\0'; 
    printf("\nInfix expression: %s\nPostfix expression: %s\n", infix, postfix);
    return 0;
}
