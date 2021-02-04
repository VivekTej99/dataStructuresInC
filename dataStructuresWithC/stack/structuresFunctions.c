//Implement stacks with structueres and functions

#include <stdio.h>

struct stack
{
    int max;
    int a[20];
    int top;
};

struct stack push(struct stack s) {
    if(s.top == s.max -1){
        printf("Stack is full can't push\n");
    }else if (s.top != s.max -1 ) {
        int ele;
        printf("Enter element: ");
        scanf("%d",&ele);
        s.top++;
        s.a[s.top] = ele;
    }
    return s;
}

struct stack pop(struct stack s) {
    if(s.top == -1){
        printf("Stack is empty can't pop\n");
    }else if (s.top !=  -1 ) {
        printf("Poped out element is : %d\n",s.a[s.top--]);
    }
    return s;
}


int main() {
    struct stack s;
    printf("Please input the size of stack less than '20' : ");
    scanf("%d",&s.max);
    s.top = -1;
    int option;
    do{
        printf("Choose an Option\n 1. Push \n 2. Pop \n 3. Exit\n __");
        scanf("%d",&option);
        switch (option) {
            case 1:
                s = push(s);
                break;
                
            case 2:
                s = pop(s);
                break;
            default:
                break;
        }
        
    }while(option != 3);
}


//vivek