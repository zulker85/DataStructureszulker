#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define STR_SIZE 100

typedef struct {
    char items[MAX][STR_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to enqueue an element
void enqueue(Queue *q, const char *item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        strcpy(q->items[q->rear], item);
        printf("Enqueued: %s\n", item);
    }
}

// Function to dequeue an element
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued: %s\n", q->items[q->front]);
        if (q->front == q->rear) {
            // Queue has become empty
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
    }
}

// Function to display the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents:\n");
    int i = q->front;
    while (1) {
        printf("%s\n", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int choice;
    char item[STR_SIZE];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Terminate\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter a string to enqueue: ");
                fgets(item, STR_SIZE, stdin);
                item[strcspn(item, "\n")] = '\0'; // Remove trailing newline
                enqueue(&q, item);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
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

