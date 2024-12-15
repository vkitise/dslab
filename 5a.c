#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define MAX 20
float stack[MAX];
int top = -1;
float eval_postfix(char[]);
void push(float);
float pop();
int main() {
char postfix[MAX];
float result;
printf("Enter postfix expression: ");
scanf("%s", postfix);
result = eval_postfix(postfix);
if (top == -1) {
printf("Result: %f\n", result);
} else {
printf("Not a valid expression\n");
}
return 0;
}
float eval_postfix(char postfix[]) {
int i = 0, k;
char ch;
float op1, op2, res;
while (postfix[i] != '\0') {
ch = postfix[i];
if (isdigit(ch)) {
k = ch - '0';
push(k);
} else {
op2 = pop();
op1 = pop();
switch (ch) {
case '+':
push(op1 + op2);
break;
case '-':
push(op1 - op2);
break;
case '*':
push(op1 * op2);
break;
case '/':
push(op1 / op2);
break;
case '^':
push(pow(op1, op2));
break;
default:
printf("Illegal operator\n");
exit(0);
}
}
i++;
}
res = pop();
return res;
}
void push(float num) {
if (top == MAX - 1) {
printf("Stack overflow\n");
exit(0);
} else {
top++;
stack[top] = num;
}
}
float pop() {
float num;
if (top == -1) {
printf("Stack underflow\n");
exit(0);
} else {
num = stack[top];
top--;
return num;
}
}
