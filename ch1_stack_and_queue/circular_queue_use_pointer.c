#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct queue {
    char *front; 
    char *rear; 
    char items[SIZE];
} QUEUE;

// #define SIZE 10
// #define TEST_DATA_SIZE 11

// // pop (from front)
// // push (from rear)
// // empty (check front, rear)
// // full (check rear, SIZE)
// typedef struct Queue{
//     int front;
//     int rear;
//     char items[SIZE];
// } Queue;

// void init_queue(Queue *queue);
// char pop(Queue *queue);
// void push(Queue *queue, char item);
// int empty(const Queue *const queue);
// int full(const Queue *const queue);

// int main(){
//     Queue queue;
//     init_queue(&queue);

//     printf("Push items to queue.\n\n");
//     for(int i = 0;i < TEST_DATA_SIZE;i++){
//         push(&queue, (char)('a'+i));
//         printf("Push %c\n", (char)('a'+i));
//         printf("front is %d. rear is %d\n\n", queue.front, queue.rear);
//     }

//     printf("------------------------------\n");
        
//     printf("Pop items from queue.\n\n");
//     for(int i = 0;i < TEST_DATA_SIZE;i++){
//         char item = pop(&queue);
//         printf("Pop %c\n", item);
//         printf("front is %d. rear is %d\n\n", queue.front, queue.rear);
//     }

//     printf("------------------------------\n");

//     printf("Can we push item to queue now ?\n\n");
//     push(&queue, 'z');
//     printf("Push %c\n", 'z');
//     printf("front is %d. rear is %d\n\n", queue.front, queue.rear);
// }

// void init_queue(Queue *queue){
//     queue->front = 0;
//     queue->rear = 0;
// }

// char pop(Queue *queue){
//     if(!empty(queue))
//         return queue->items[queue->front++];
//     else  
//         printf("Queue is empty.\n");
// }

// void push(Queue *queue, char item){
//     if(!full(queue))
//         queue->items[queue->rear++] = item;
//     else  
//         printf("Queue is full.\n");
// }

// int empty(const Queue *const queue){
//     return queue->front == queue->rear;
// }

// int full(const Queue *const queue){
//     return queue->rear == SIZE;
// }

int empty(const QUEUE * const ptr){
    if (ptr->rear == ptr->front)
        return(1);
    return(0);
}

int overflow(const QUEUE * const ptr){
    if ((ptr->rear - ptr->items + 1) % SIZE == ptr->front - ptr->items)
        return(1);
    return(0);
}

void insert(QUEUE *ptr, char input){
    if(!overflow(ptr)){
        *ptr->rear = input;
        ptr->rear = ptr->items + (ptr->rear - ptr->items + 1) % SIZE;
    }
}

char pop(QUEUE *ptr){
    if(!empty(ptr)){
        char output = *(ptr->front);
        ptr->front = ptr->items + (ptr->front - ptr->items + 1) % SIZE;
        return output;
    }
}

int main(){
    QUEUE queue;
    queue.front = queue.items;
    queue.rear = queue.items;

    // test
    const int TEST_DATA_SIZE = 9;
    for(int i = 0;i < TEST_DATA_SIZE;i++){
        insert(&queue, (char)('a'+i));
        printf("Insert %c\n\n", (char)('a'+i));
    }

    for(int i = 0;i < TEST_DATA_SIZE;i++){
        char item = pop(&queue);
        printf("Pop %c\n\n", item);
    }


    printf("Can we insert item to queue now ?\n\n");
    insert(&queue, 'z');
    printf("Insert %c\n", 'z');
    printf("front is %c\n\n", *queue.front);
}

