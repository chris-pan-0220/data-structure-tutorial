# queue
* (空間會使用完的) queue
* circular queue 

### (空間會使用完的) queue
假設現在queue的空間是固定的，每`push`一次，`rear`就會加一；每`pop`一次，`front`也會加一，可以思考一下，一直重複的`push`, `pop`，queue總有一天會沒有空間使用。

```c
// ch1_queue_use_array.c
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10
#define TEST_DATA_SIZE 11

// pop (from front)
// push (from rear)
// empty (check front, rear)
// full (check rear, QUEUE_SIZE)
typedef struct Queue{
    int front;
    int rear;
    char items[QUEUE_SIZE];
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
    if(!empty(queue))
        return queue->items[queue->front++];
    else  
        printf("Queue is empty.\n");
}

void push(Queue *queue, char item){
    if(!full(queue))
        queue->items[queue->rear++] = item;
    else  
        printf("Queue is full.\n");
}

int empty(Queue *queue){
    return queue->front == queue->rear;
}

int full(Queue *queue){
    return queue->rear == QUEUE_SIZE;
}
```

### circular queue 
circular queue的創造是為了解決一般的queue空間用完的問題，
circular queue的實作大概會有以下的要點
* mod 取值
* 
* 

```c
// ch1_queue_circular.c
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10 // capacity = QUEUE_SIZE - 1 
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
```