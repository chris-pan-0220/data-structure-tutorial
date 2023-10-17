#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 11 // capacity = QUEUE_SIZE - 1 
#define TEST_DATA_SIZE 11

typedef struct Queue{
    unsigned int front;
    unsigned int rear;
    char items[QUEUE_SIZE+1];
} Queue;

void init_queue(Queue *queue);
char pop(Queue *queue);
void push(Queue *queue, char item);
int empty(Queue *queue);
int full(Queue *queue);

int main(){
    Queue queue;
    init_queue(&queue);

    printf("Push items to queue.\n\n");
    for(int i = 0;i < TEST_DATA_SIZE;i++){
        push(&queue, (char)('a'+i));
        printf("Push %c\n", (char)('a'+i));
        printf("front is %d. rear is %d\n\n", queue.front, queue.rear);
    }

    printf("------------------------------\n");
        
    printf("Pop items from queue.\n\n");
    for(int i = 0;i < TEST_DATA_SIZE;i++){
        char item = pop(&queue);
        printf("Pop %c\n", item);
        printf("front is %d. rear is %d\n\n", queue.front, queue.rear);
    }

    printf("------------------------------\n");

    printf("Can we push item to queue now ?\n\n");
    push(&queue, 'z');
    printf("Push %c\n", 'z');
    printf("front is %d. rear is %d\n\n", queue.front, queue.rear);
}

void init_queue(Queue *queue){
    queue->front = 0;
    queue->rear = 0;
}

char pop(Queue *queue){
    if(!empty(queue)){
        queue->front = (queue->front+1) % QUEUE_SIZE;
        return queue->items[queue->front];
    }else{
        printf("Queue is empty.\n");
    }
}

void push(Queue *queue, char item){
    if(!full(queue)){
        queue->rear = (queue->rear+1) % QUEUE_SIZE;
        queue->items[queue->rear] = item;
    }else
        printf("Queue is full.\n");
}

int empty(Queue *queue){
    return queue->front == queue->rear;
}

int full(Queue *queue){
    return (queue->rear + 1) % QUEUE_SIZE == queue->front;
}
