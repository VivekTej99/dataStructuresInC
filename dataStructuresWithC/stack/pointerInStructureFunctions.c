//Implementation of stack with pointer array inside structure with functions..


#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *a;
    int max;
    int top;
};

void push(struct stack *s) {
    if(s->top == s->max -1){
        printf("Stack is full can't push\n");
    }else if (s->top != s->max -1 ) {
        int ele;
        printf("Enter element: ");
        scanf("%d",&ele);
        s->top++;
        *(s->a+s->top) = ele;
    }
}

void pop(struct stack *s) {
    if(s->top == -1){
        printf("Stack is empty can't pop\n");
    }else if (s->top !=  -1 ) {
        printf("Poped out element is : %d\n",*(s->a+s->top--));
    }

}

int main() {
    struct stack *s;
    s = (struct stack *) malloc(sizeof(struct stack));
    printf("Please input the size of stack less than '20' : ");
    scanf("%d",&s->max);
    s-> a = (int *) malloc(s->max*sizeof(int));
    s->top = -1;
    int option;
    do{
        printf("Choose an Option\n 1. Push \n 2. Pop \n 3. Exit\n __");
        scanf("%d",&option);
        switch (option) {
            case 1:
                push(s);
                break;
                
            case 2:
                pop(s);
                break;
            default:
                break;
        }
        
    }while(option != 3);
}

//VivekTej
