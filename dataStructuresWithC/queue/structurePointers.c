// Implement the Queues with structures pointers

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int q[20];
    int head;
    int tail;
    int max;
};

int main() {
    struct queue *q;
    q = (struct queue *) malloc(sizeof(struct queue));
    q->head = -1;
    q->tail = -1;
    printf("Input the size of queue: ");
    scanf("%d",&q->max);
    int ele,opt;
    do{
        printf("Select an option to perform on queue\n1. Enqueue\n2. Dequeue\n 3. Exit\n __ ");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            if(q->tail == q->max - 1) {
                printf("Queue is full can't enqueue.\n");
            }else if(q->tail != q->max - 1) {
                printf("Enter the element to insert in Queue: ");
                scanf("%d",&ele);
                q->q[++q->tail] = ele;
            }
            break;
        case 2:
            if(q->head == q->tail) {
                printf("Queue is empty can't dequeue.\n");
            }else if(q->head != q->tail) {
                printf("The element got Dequeued is: %d\n",q->q[++q->head]);
            }
            break;
        case 3:
            printf("Hey you have exited..");
        default:
            break;
        }

    }while(opt != 3);
}

//Vivek Tej B172299
