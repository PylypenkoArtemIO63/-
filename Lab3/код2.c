#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
    int capacity;
} Queue;

void init_queue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    q->capacity = MAX;
}

int is_queue_empty(Queue* q) {
    return q->size == 0;
}

int is_queue_full(Queue* q) {
    return q->size >= q->capacity;
}

void enqueue(Queue* q, int value) {
    if (is_queue_full(q)) {
        printf("MAX limit reached (%d items). Cannot add %d.\n", q->capacity, value);
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Failed to allocate memory.\n");
        return;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (is_queue_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

int dequeue(Queue* q) {
    if (is_queue_empty(q)) {
        printf("The queue is empty. The dequeue operation is not possible.\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return value;
}

int peek_front(Queue* q) {
    if (is_queue_empty(q)) {
        printf("The queue is empty. The peek_front operation is not possible.\n");
        return -1;
    }
    return q->front->data;
}

typedef struct {
    Node* top;
    int size;
    int capacity;
} Stack;

void init_stack(Stack* s) {
    s->top = NULL;
    s->size = 0;
    s->capacity = MAX;
}

int is_stack_empty(Stack* s) {
    return s->size == 0;
}

int is_stack_full(Stack* s) {
    return s->size >= s->capacity;
}

void push(Stack* s, int value) {
    if (is_stack_full(s)) {
        printf("MAX limit reached. Cannot add %d.\n", s->capacity, value);
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Failed to allocate memory.\n");
        return;
    }

    new_node->data = value;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

int pop(Stack* s) {
    if (is_stack_empty(s)) {
        printf("The stack is empty. The pop operation is not possible.\n");
        return -1;
    }

    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;

    free(temp);
    s->size--;
    return value;
}

int peek(Stack* s) {
    if (is_stack_empty(s)) {
        printf("The stack is empty. The peek operation is not possible.\n");
        return -1;
    }
    return s->top->data;
}

int main() {
    int n;
    char prompt[100];
    strcpy(prompt, "Enter n: ");
    printf("%s", prompt);

    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Error.\n", MAX);
        return 1;
    }

    Queue circle;
    Stack eliminated_history;

    init_queue(&circle);
    init_stack(&eliminated_history);

    for (int i = 1; i <= n; i++) {
        enqueue(&circle, i);
    }

    int eliminated_count = 0;
    int first_person_elim_order = -1;

    while (circle.size > 1) {

        int safe_person = dequeue(&circle);
        enqueue(&circle, safe_person);

        int out_person = dequeue(&circle);
        eliminated_count++;

        push(&eliminated_history, out_person);
        if (out_person == 1) {
            first_person_elim_order = eliminated_count;
        }
    }

    int survivor = peek_front(&circle);

    printf("Last person: %d\n", survivor);

    if (survivor == 1) {
        printf("Person No. 1, who started the counting, was not eliminated and remained the last one..\n", n);
    } else {
        printf("Person No. 1, who started the counting, was the %d-th to be eliminated.\n", first_person_elim_order);
    }
    dequeue(&circle);
    while (!is_stack_empty(&eliminated_history)) {
        pop(&eliminated_history);
    }
    for (int i = 1; i <= MAX; i++) {
        enqueue(&circle, i);
        push(&eliminated_history, i);
    }
    printf("101 element:\n");
    enqueue(&circle, 101);
    push(&eliminated_history, 101);

    while (!is_queue_empty(&circle)) dequeue(&circle);
    while (!is_stack_empty(&eliminated_history)) pop(&eliminated_history);

    dequeue(&circle);
    peek_front(&circle);
    pop(&eliminated_history);
    peek(&eliminated_history);

    return 0;
}