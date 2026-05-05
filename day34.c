#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node for stack
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Evaluate postfix
int evaluatePostfix(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {
        // If operand
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        } 
        else {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expr[100];

    // Read full line input
    fgets(expr, sizeof(expr), stdin);

    // Remove newline
    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluatePostfix(expr);
    printf("%d\n", result);

    return 0;
}