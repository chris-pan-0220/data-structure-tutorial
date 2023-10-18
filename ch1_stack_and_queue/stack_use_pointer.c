#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
typedef struct stack {
    char *top; // top = NULL if empty ; min = items, max = items + SIZE - 1
    char items[SIZE];
} STACK;

int empty(const STACK * const ptr){
    if (ptr->top == NULL)
        return(1);
    return(0);
}
int overflow(const STACK * const ptr){
    if (ptr->top == &(ptr->items[SIZE-1]))
        return(1);
    return(0);
}

void push(STACK *ptr, char input){
    if(!overflow(ptr)){
        if(ptr->top == NULL)
            *(ptr->top = ptr->items) = input;
        else 
            *(++(ptr->top)) = input;
    } 
}

char pop(STACK *ptr){
    if(!empty(ptr)){
        char input = *ptr->top;
        if(ptr->top == ptr->items) 
            ptr->top = NULL;
        else 
            ptr->top--;
        return input;
    }
}

int main(){
    STACK stack;
    stack.top = NULL;

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