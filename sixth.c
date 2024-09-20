#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  // Maximum size of the stack

// Structure to represent a stack
struct Stack {
    int items[MAX];
    int top;
};

// Function to create a stack and initialize its top
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to add an item to the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }
    stack->items[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop\n");
        return -1; // Return -1 to indicate stack is empty
    }
    return stack->items[stack->top--];
}

// Function to return the top item of the stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return -1; // Return -1 to indicate stack is empty
    }
    return stack->items[stack->top];
}

// Main function to test the stack
int main() {
    struct Stack* stack = createStack();
    
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    
    printf("%d popped from stack\n", pop(stack));
    printf("Top item is %d\n", peek(stack));
    
    // Clean up
    free(stack);
    
    return 0;
}
