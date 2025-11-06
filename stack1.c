#include <stdio.h>
#define MAX 100
typedef struct {
    int arr[MAX];
    int top;
} Stack;
void initStack(Stack *s) { s->top = -1; }
int isEmptyStack(Stack *s) { return s->top == -1; }
int isFullStack(Stack *s) { return s->top == MAX - 1; }
void push(Stack *s, int value) {
    if(isFullStack(s)) { printf("Stack Overflow! Cannot push %d\n", value); return; }
    s->arr[++(s->top)] = value; printf("Pushed %d\n", value);
}
int pop(Stack *s) {
    if(isEmptyStack(s)) { printf("Stack Underflow! Cannot pop\n"); return -1; }
    return s->arr[(s->top)--];
}
int peek(Stack *s) {
    if(isEmptyStack(s)) { printf("Stack is empty\n"); return -1; }
    return s->arr[s->top];
}
int main() {
    Stack s; initStack(&s);
    push(&s, 10); push(&s, 20); push(&s, 30);
    printf("Top element is %d\n", peek(&s));
    printf("Popped element is %d\n", pop(&s));
    printf("Popped element is %d\n", pop(&s));
    if(isEmptyStack(&s))
        printf("Stack is empty now\n");
    else
        printf("Stack is not empty\n");
    return 0;
}
