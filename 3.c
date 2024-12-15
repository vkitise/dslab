#include <stdio.h>
#include <stdlib.h>
int stack[6], rev[6]; 
int top = -1, k = 0;
int size;
void push();
void pop();
void display();
int isPalindrome();
int main() {
int choice, flag;
printf("Enter the size for stack: ");
scanf("%d", &size);
while (1) {
printf("1. Push\n2. Pop\n3. Display\n4. Check for Palindrome\n5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
flag = isPalindrome();
if (flag == 1)
printf("It's a Palindrome\n");
else
printf("It's not a Palindrome\n");
break;
case 5:
exit(0); 
default:
printf("Wrong choice...\n");
}
}
return 0;
}
void push() {
int num;
if (top == (size - 1)) {
printf("Stack Overflow\n");
} else {
printf("Enter the number to be pushed: ");
scanf("%d", &num);
top++;
stack[top] = num;
}
}
void pop() {
int num;
if (top == -1) {
printf("Stack Underflow\n");
} else {
num = stack[top];
printf("Popped element is %d\n", num);
top--;
}
}
void display() {
int i;
if (top == -1) {
printf("Stack Underflow\n");
} else {
printf("Stack Contents....\n");
for (i = top; i >= 0; i--) {
printf("%d\n", stack[i]);
rev[k++] = stack[i];
}
}
}
int isPalindrome() {
int i, flag = 1;
for (i = top; i >= 0; i--) {
if (stack[i] != rev[--k]) {
flag = 0;
}
}
return flag;
}
