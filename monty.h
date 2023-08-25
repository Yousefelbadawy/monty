#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define the stack structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function to initialize an empty stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = value;
}

// Function to print all values on the stack
void pall(Stack *stack) {
    if (isEmpty(stack)) {
        return; // Stack is empty, nothing to print
    }
    
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

int main() {
    Stack myStack;
    initialize(&myStack);
    
    char line[100]; // Assuming each line of input is at most 100 characters
    
    while (fgets(line, sizeof(line), stdin) != NULL) {
        char opcode[10];
        int value;
        
        if (sscanf(line, "%s %d", opcode, &value) == 2) {
            if (strcmp(opcode, "push") == 0) {
                push(&myStack, value);
            } else {
                printf("Invalid opcode: %s\n", opcode);
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&myStack);
        } else {
            printf("Invalid input format: %s", line);
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}
