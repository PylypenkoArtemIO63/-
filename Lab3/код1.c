#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int count;
} CircularQueue;

void init_queue(CircularQueue *q) {
    memset(q->data, 0, sizeof(q->data));
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int is_empty(const CircularQueue *q) {
    return q->count == 0;
}

int is_full(const CircularQueue *q) {
    return q->count == MAX;
}

void enqueue(CircularQueue *q, int value) {
    if (is_full(q)) {
        printf("Array is full. Cannot add an element %d.\n", value, MAX);
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->count++;
}

int dequeue(CircularQueue *q) {
    if (is_empty(q)) {
        printf("The queue is empty The dequeue operation is not possible.\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return value;
}

int peek_front(const CircularQueue *q) {
    if (is_empty(q)) {
        printf("Queue is empty! Operation peek_front is not possible.\n");
        return -1;
    }
    return q->data[q->front];
}

int main() {
    CircularQueue q;
    init_queue(&q);

    printf("Array testing  (MAX = %d) \n", MAX);
    for (int i = 1; i <= MAX; i++) {
        enqueue(&q, i * 10);
    }
    printf("The queue is completely full %d elements.\n", q.count);

    init_queue(&q);

    int n;
    printf("Enter n: ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid value for n. The array holds a maximum of %d people.\n", MAX);
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        enqueue(&q, i);
    }

    if (is_full(&q)) {
        printf("\nAll %d seats are taken. (%d):\n", MAX, n + 1);
        enqueue(&q, n + 1);
    }

    int elimination = 0;
    int first_person_turn = 0;

    while (q.count > 1) {
        enqueue(&q, dequeue(&q));

        int eliminated = dequeue(&q);
        elimination++;

        if (eliminated == 1) {
            first_person_turn = elimination;
        }
    }

    int last_person = peek_front(&q);

    printf("1. Last person : %d\n", last_person);
    if (last_person == 1) {
        printf("2. Person No. 1, who started the counting, was not eliminated and remained the last one. %d.\n", n);
    } else {
        printf("2. Person No. 1, who started the counting, was the %d-th to be eliminated.\n", first_person_turn);
    }

    return 0;
}