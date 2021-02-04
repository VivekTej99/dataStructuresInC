
//Implenetation of Stack with arrays and switch case

#include <stdio.h>

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
                if(top == stackSize -1){
                    printf("Stack is full can't push\n");
                }else if (top != stackSize -1 ) {
                    int ele;
                    printf("Enter element: ");
                    scanf("%d",&ele);
                    stack[++top] = ele;
                }
                break;
                
            case 2:
                if(top == -1){
                    printf("Stack is empty can't pop\n");
                }else if (top !=  -1 ) {
                    printf("Poped out element is : %d\n",stack[top--]);
                }
                break;
            default:
                break;
        }
        
    }while(option != 3);
    
}

//VivekTej

