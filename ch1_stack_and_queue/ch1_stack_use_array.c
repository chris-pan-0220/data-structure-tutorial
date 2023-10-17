#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define TEST_DATA_SIZE 11

typedef struct Stack{
    int top; // min = -1, max = STACK_SIZE
    char items[STACK_SIZE];
} Stack;

void init_stack(Stack *stack);
void push(Stack *stack, char item);
char pop(Stack *stack);
int empty(Stack *stack);
int overflow(Stack *stack);

int main(){
    Stack stack;
    init_stack(&stack);

    for(int i = 0;i < TEST_DATA_SIZE;i++){
        push(&stack, (char)('a'+i)); 
        printf("top is %d\n", stack.top);
        printf("Push %c\n", (char)('a'+i));
    }
        
    for(int i = 0;i < TEST_DATA_SIZE;i++){
        char item = pop(&stack);
        printf("top is %d\n", stack.top);
        printf("Pop %c\n", item);
    }
        
}

void init_stack(Stack *stack){
    stack->top = -1;
    for(int i = 0;i < STACK_SIZE;i++)
        stack->items[i] = '0';
}

void push(Stack *stack, char item){
    if(!overflow(stack))
        stack->items[++(stack->top)] = item;
}

char pop(Stack *stack){
    if(!empty(stack))
        return stack->items[(stack->top)--];
}

int empty(Stack *stack){
    return stack->top == -1;
}

int overflow(Stack *stack){
    return stack->top == STACK_SIZE -1;
}