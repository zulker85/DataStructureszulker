#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define STR_SIZE 100

typedef struct {
    char items[MAX][STR_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, const char *item) {
    if (!isFull(s)) {
        strcpy(s->items[++(s->top)], item);
        printf("Pushed: %s\n", item);
    } else {
        printf("Stack is full!\n");
    }
}

// Function to pop an element from the stack
void pop(Stack *s) {
    if (!isEmpty(s)) {
        printf("Popped: %s\n", s->items[(s->top)--]);
    } else {
        printf("Stack is empty!\n");
    }
}

// Function to display the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%s\n", s->items[i]);
    }
}

int main() {
    Stack s;
    initStack(&s);

    int choice;
    char item[STR_SIZE];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Terminate\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter a string to push: ");
                fgets(item, STR_SIZE, stdin);
                item[strcspn(item, "\n")] = '\0'; // Remove trailing newline
                push(&s, item);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Terminating program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

