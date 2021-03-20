#include<stdio.h>
#include<stdlib.h>

struct node
{
    int ele;
    struct node *nxt;
};

void enQueue(struct node **head) {
    int ele;
    printf("\nEnter the ele: ");
    scanf("%d",&ele);
    if(*head == NULL) {
        *head = (struct node*) malloc(sizeof(struct node));
        (*head)->ele = ele;
        (*head)->nxt = NULL;
    }else{
        struct node *tmp = *head;
        while(tmp->nxt != NULL) {
            tmp= tmp->nxt;
        }
        struct node *nn = (struct node *)malloc(sizeof(struct node));
        nn->ele = ele;
        nn->nxt = NULL;
        tmp->nxt = nn;
    }
}

void deQueue(struct node **head) {
    if(*head == NULL){
        printf("Queue is Empty");
    }else{
        *head = (*head)->nxt;
    }
}

void display(struct node **head) {
    if(*head == NULL) {
        printf("\n[ ]\n");
    }else{
        struct node *tmp = *head;
        printf("\n[");
        while(tmp->nxt!= NULL) {
            printf("%d, ",tmp->ele);
            tmp=tmp->nxt;
        }
        printf("%d ]\n",tmp->ele);
    }
}


int main() {
    int op;
    struct node *head = NULL;
    do
    {
        printf("Select an Option to perform:\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n  ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            enQueue(&head);
            break;
        case 2:
            deQueue(&head);
            break;
        case 3:
            display(&head);
            break;
        default:
            break;
        }
        
    }while (op!=0);
    
}