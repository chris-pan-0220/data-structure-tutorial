#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define TEST_DATA_SIZE 11

typedef struct Stack{
    int top; // min = -1, max = SIZE-1
    char items[SIZE];
} Stack;

void init_stack(Stack *stack);
void push(Stack *stack, char item);
char pop(Stack *stack);
int empty(const Stack *const stack);
int overflow(const Stack *const stack);

int main(){
    Stack stack;
    init_stack(&stack);

    for(int i = 0;i < TEST_DATA_SIZE;i++){
        push(&stack, (char)('a'+i)); 
        printf("Push %c\n", (char)('a'+i));
        printf("top is %d\n", stack.top);
        printf("\n");
    }
        
    for(int i = 0;i < TEST_DATA_SIZE;i++){
        char item = pop(&stack);
        printf("Pop %c\n", item);
        printf("top is %d\n", stack.top);
        printf("\n");
    }
        
}

void init_stack(Stack *stack){
    stack->top = -1;
}

void push(Stack *stack, char item){
    if(!overflow(stack))
        stack->items[++(stack->top)] = item;
}

char pop(Stack *stack){
    if(!empty(stack))
        return stack->items[(stack->top)--];
}

int empty(const Stack *const stack){
    return stack->top == -1;
}

int overflow(const Stack *const stack){
    return stack->top == SIZE-1;
}