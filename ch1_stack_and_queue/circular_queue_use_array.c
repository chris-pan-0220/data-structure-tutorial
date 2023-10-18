#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
typedef struct queue {
    unsigned int front; // range [0..SIZE-1]
    unsigned int rear; // range [0..SIZE-1]
    char items[SIZE];
} QUEUE;

int empty(const QUEUE * const ptr){
    if (ptr->rear == ptr->front)
        return(1);
    return(0);
}

int overflow(const QUEUE * const ptr){
    if ((ptr->rear + 1) % SIZE == ptr->front)
        return(1);
    return(0);
}

void insert(QUEUE *ptr, char input){
    if(!overflow(ptr)){
        ptr->items[ptr->rear] = input;
        ptr->rear = (ptr->rear + 1) % SIZE;
    }
}

char pop(QUEUE *ptr){
    if(!empty(ptr)){
        char output = ptr->items[ptr->front];
        ptr->front = (ptr->front + 1) % SIZE;
        return output;
    }
}

int main(){
    QUEUE queue;
    queue.front = 0;
    queue.rear = 0;
    // write test
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
}