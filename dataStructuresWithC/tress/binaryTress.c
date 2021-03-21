//Implementation of binary tree data structure.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *lNode;
    int ele;
    struct node *rNode;
};

struct Queue
{
    struct node *a[50];
    int top;
    int max;
};

void enQueue(struct Queue *q,struct node *tmp) {
    if(q->max-1 == q->top) {
        printf("\nQueue is full.\n");
    }else {
        q->top++;
        q->a[q->top] = tmp;
    }
}

struct node* deQueue(struct Queue *q){
    if(q->top == -1) {
        printf("\nQueue is empty\n");
        return NULL;
    }else {
        return q->a[q->top--];
    }
}

void insert(struct node **rootNode) {
    int ele;
    printf("\nEnter the element to insert: ");
    scanf("%d",&ele);
    if(*rootNode == NULL) {
        *rootNode = (struct node *) malloc(sizeof(struct node));
        (*rootNode)->ele = ele;
        (*rootNode)->lNode = NULL;
        (*rootNode)->rNode = NULL;
    }else {
        struct node *tmp = *rootNode;
        struct Queue q;
        q.max = 20;
        q.top = -1;
        enQueue(&q,tmp);
        while(1){
            tmp = deQueue(&q);
            if(tmp!= NULL) {
                if(tmp->lNode != NULL)  {
                enQueue(&q,tmp->lNode);
                }else{
                    break;
                }if(tmp->rNode != NULL) {
                    enQueue(&q,tmp->rNode);
                }else {
                    break;
                }
            }else{
                break;
            }
        }
        if(tmp != NULL) {
            struct node *nN = (struct node *) malloc(sizeof(struct node));
            nN->ele = ele;
            nN->lNode = NULL;
            nN->rNode = NULL;
            if(tmp->lNode == NULL) {
                tmp->lNode = nN;
            }else{
                tmp->rNode = nN;
            }
        }else{
            return;
        }
    }
}



int main() {
    int opt;
    struct node *rootNode= NULL;
    do
    {
        printf("\nSelect an option to perform on a tree: \n\t1. Insertion. \n\t0. Exit \n  __");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            insert(&rootNode);
            break;
        default:
            break;
        }
    } while (opt!=0);
    
}