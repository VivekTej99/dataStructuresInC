// Implementation of infix to postfix conversion using stacks

#include <stdio.h>
#include <stdlib.h>


struct stack
{
    char *a;
    int max;
    int top;
};

void push(struct stack *s,char ele) {
    if(s->top == s->max -1){
        printf("Your stack got full cant push..\n");
    }else {
        s->top++;
        s->a[s->top] = ele;
    }
}

char pop(struct stack *s) {
    if(s->top == -1) {
        printf("Your stack is empty");
        return '.';
    } else {
        return   s->a[s->top--];
    }
}

char top(struct stack *s) {
    return s->a[s->top];
}

int isEmpty(struct stack *s) {
    if(s->top == -1) {
        return 1;
    }else if (s->top != -1) {
        return 0;
    }
}

int prior(char prop) {
    if(prop == '(') {
        return 0;
    }else if(prop == '+' || prop == '-') {
        return 1;
    }else if(prop == '*' || prop == '/') {
        return 2;
    }else{
        return 3;
    }
}

int main() {
    int sz;
    struct stack *s;
    s = (struct stack *) malloc(sizeof(struct stack));
    printf("Enter the size of expression: ");
    scanf("%d",&sz);
    s->a = (char *)malloc(sz*sizeof(int));
    s->max = sz;
    s->top = -1;
    char exp[sz+2];
    printf("\nEnter the expression: ");
    scanf("%s",exp);
    char *e;
    e = exp;
    while (*e != '\0') {
        if(*e == '+' || *e == '-' || *e == '*' || *e == '/') {
            if(isEmpty(s)) {
                push(s,*e);
            } else if(prior(top(s)) < prior(*e)) {
                push(s,*e);
            } else if(prior(top(s)) >= prior(*e)) {
                while (prior(top(s)) >= prior(*e))
                {
                    printf("%c",pop(s));
                    if(isEmpty(s)) {
                        break;
                    }
                }
                push(s,*e);
            }
        }else if(*e == '(') {
            push(s,*e);
        }else if(*e == ')') {
            while(top(s) != '('  ) {
                printf("%c",pop(s));
            }
            pop(s);
        }
        else {
            printf("%c",*e);
        }
        e++;
    }
    while (!isEmpty(s))
    {
        printf("%c",pop(s));
    }
    
}

//Vivek Tej  B172299
