#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
typedef struct stack {
    int top; // range [-1..SIZE-1]
    char items[SIZE];
} STACK;

int empty(const STACK * const ptr){
    if (ptr->top == -1)
        return(1);
    return(0);
}

int overflow(const STACK * const ptr){
    if (ptr->top == SIZE-1)
        return(1);
    return(0);
}

void push(STACK *ptr, char input){
    if(!overflow(ptr))
        ptr->items[++(ptr->top)] = input;
}

char pop(STACK *ptr){
    if(!empty(ptr))
        return (ptr->items[(ptr->top)--]);
}

int main(){
    STACK stack;
    stack.top = -1;

    // test
    const int TEST_DATA_SIZE = 10;
    for(int i = 0;i < TEST_DATA_SIZE;i++){
        push(&stack, (char)('a'+i)); 
        printf("Push %c\n", (char)('a'+i));
        printf("\n");
    }

    printf("Push z when stack is overflow\n\n");
    push(&stack, 'z');
        
    for(int i = 0;i < TEST_DATA_SIZE;i++){
        char item = pop(&stack);
        printf("Pop %c\n", item);
        printf("\n");
    }

    printf("Pop when stack is empty\n\n");
    pop(&stack);
}
