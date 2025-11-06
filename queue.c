#include <stdio.h>
#define MAX 100
typedef struct {
    int arr[MAX], front, rear;
} Queue;
void initQueue(Queue *q) { q->front = -1; q->rear = -1; }
int isEmptyQueue(Queue *q) { return q->front == -1; }
int isFullQueue(Queue *q) { return (q->rear + 1) % MAX == q->front; }
void enqueue(Queue *q, int value) {
    if(isFullQueue(q)) { printf("Queue Overflow! Cannot enqueue %d\n", value); return; }
    if(isEmptyQueue(q)) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("Enqueued %d\n", value);
}
int dequeue(Queue *q) {
    if(isEmptyQueue(q)) { printf("Queue Underflow! Cannot dequeue\n"); return -1; }
    int value = q->arr[q->front];
    if(q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % MAX;
    return value;
}
int peekQueue(Queue *q) {
    if(isEmptyQueue(q)) { printf("Queue is empty\n"); return -1; }
    return q->arr[q->front];
}
int main() {
    Queue q; initQueue(&q);
    enqueue(&q, 10); enqueue(&q, 20); enqueue(&q, 30);
    printf("Front element is %d\n", peekQueue(&q));
    printf("Dequeued element is %d\n", dequeue(&q));
    printf("Dequeued element is %d\n", dequeue(&q));
    if(isEmptyQueue(&q))
        printf("Queue is empty now\n");
    else
        printf("Queue is not empty\n");
    return 0;
}
