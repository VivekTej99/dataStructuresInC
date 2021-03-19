//Stacks with linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int ele;
    struct node *nxt;
};

void push(struct node **head) {
    int ele;
    printf("Enter elemt: ");
    scanf("%d",&ele);
    if(*head == NULL) {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->nxt = NULL;
        (*head)->ele = ele;
    }else {
        struct node *temp = *head;
        while(temp->nxt != NULL) {
            temp = temp-> nxt;
        }
        struct node *nn= (struct node *) malloc(sizeof(struct node));
        nn->ele = ele;
        nn->nxt = NULL;
        temp->nxt = nn;
    }
}


void pop(struct node **head) {
    if(*head == NULL) {
        printf("Stack is empty");
    }else {
        struct node *temp = *head;
        struct node *pvTemp = *head;

        while(temp->nxt != NULL) {
            pvTemp = temp;
            temp = temp-> nxt;
        }
        pvTemp->nxt = NULL;
        free(temp);
    }
}

void display(struct node **head) {
    if(*head == NULL) {
        printf("[ ]");
    }else {
        printf("[");
        struct node *tmp = *head;
        while(tmp->nxt!=NULL) {
            printf("%d, ",tmp->ele);
            tmp = tmp->nxt;
        }
        printf("%d]",tmp->ele);

    }
}

int main() {
    struct node *head = NULL;
    int op;
    do
    {
        printf("Select an option:\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            push(&head);
            break;
        case 2:
            pop(&head);
            break;
        case 3:
            display(&head);
            break;
        
        default:
            break;
        }
    } while (op!=4);
    
}