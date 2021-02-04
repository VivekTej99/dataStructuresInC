
//Implenetation of Stack with arrays switch case and Functions

#include <stdio.h>

int push(int top,int stack[],int stackSize){
    if(top == stackSize -1){
        printf("Stack is full can't push\n");
    }else if (top != stackSize -1 ) {
        int ele;
        printf("Enter element: ");
        scanf("%d",&ele);
        stack[++top] = ele;
    }
    return top;
}

int pop(int top,int stack[]) {
    if(top == -1){
        printf("Stack is empty can't pop\n");
    }else if (top !=  -1 ) {
        printf("Poped out element is : %d\n",stack[top]);
        top--;
    }
    return top;
}

int main() {
    int stackSize;
    printf("Please input the size of stack : ");
    scanf("%d",&stackSize);
    int stack[stackSize];
    int top = -1;
    int option;
    do{
        printf("Choose an Option\n 1. Push \n 2. Pop \n 3. Exit\n __");
        scanf("%d",&option);
        switch (option) {
            case 1:
                top = push(top,stack,stackSize);
                break;
                
            case 2:
                top = pop(top,stack);
                break;
            default:
                break;
        }
        
    }while(option != 3);
    
}

//VivekTej


