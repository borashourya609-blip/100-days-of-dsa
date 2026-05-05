#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Peek
char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int k = 0;

    scanf("%s", infix);

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // Left parenthesis
        else if (ch == '(') {
            push(ch);
        }
        // Right parenthesis
        else if (ch == ')') {
            while (peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s\n", postfix);

    return 0;
}