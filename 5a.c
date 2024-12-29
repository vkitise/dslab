#include <stdio.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int num) {
    stack[++top] = num;
}
int pop() {
    return stack[top--];
}
int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (isdigit(ch)) {
            push(ch - '0'); 
        } 
        else {
            int b = pop();
            int a = pop();

            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': push(pow(a, b));break;
            }
        }
    }
    return pop();
}
int main() {
    char exp[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);
    return 0;
}
