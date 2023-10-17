# stack 

## stack基本功能
* push
* pop
* overflow
* empty

## stack實作範例
```c
// ch1_stack_use_pointer.c
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
```

## 實作stack要注意的地方
如果stack要儲存的變數，Data type佔據記憶體空間很大，`push`function就需要pass by address
```c
// 如果儲存的是一個字串，並且字串最大儲存空間為256
#define STACK_SIZE 10
#define ITEM_SIZE 256
typedef struct Stack{
    int top;
    char items[STACK_SIZE][ITEM_SIZE];
} Stack;

// ...

// 這時pass by value會比較方便，不過要注意複製字串的時候destination空間是否足夠(要將\0算進去)
void push(Stack *stack, char *item){
    if(!(overflow(stack)))
        strcpy(&stack->items[++(stack->top)], item);
}
```
延續上面的情況，那`pop`function是不是也要return item的pointer？要注意的是：
* 如果你呼叫了`pop`，return的item的address儲存在一個pointer，並且你的stack是使用`malloc`動態分配記憶體，釋放stack之後要注意不可以再使用剛剛的pointer存取變數，不然會存取到不該存取的東西。
* 一樣的，如果你呼叫了`pop`，stack再存放新的item的時候，誤用原先的pointer會改到不該改的變數。
* 當然，有些人的`pop`function並不會回傳`top`item，就沒有這個問題。
