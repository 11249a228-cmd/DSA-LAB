#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char arr[MAX];
    int top;
} Stack;
void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX - 1; }
void push(Stack *s, char c) { if(!isFull(s)) s->arr[++(s->top)] = c; }
char pop(Stack *s) { if(!isEmpty(s)) return s->arr[(s->top)--]; return 0; }
int isMatchingPair(char open, char close) {
    return (open=='(' && close==')') || (open=='{' && close=='}') || (open=='[' && close==']');
}
int areParenthesesBalanced(char expr[]) {
    Stack s; initStack(&s);
    for(int i=0; expr[i]; i++) {
        char ch = expr[i];
        if(ch=='('||ch=='{'||ch=='[') push(&s, ch);
        else if(ch==')'||ch=='}'||ch==']') {
            if(isEmpty(&s) || !isMatchingPair(pop(&s), ch))
                return 0;
        }
    }
    return isEmpty(&s);
}
int main() {
    char expr[MAX];
    printf("Enter expression: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = 0;
    if(areParenthesesBalanced(expr))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are NOT balanced.\n");
    return 0;
}
