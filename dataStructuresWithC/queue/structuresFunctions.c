// Implement the Queues with structures and functions

#include <stdio.h>

struct queue
{
    int q[20];
    int head;
    int tail;
    int max;
};

struct queue enqueue(struct queue q) {
    int ele;
    if(q.tail == q.max - 1) {
                printf("Queue is full can't enqueue.\n");
            }else if(q.tail != q.max - 1) {
                printf("Enter the element to insert in Queue: ");
                scanf("%d",&ele);
                q.q[++q.tail] = ele;
            }
    return q;
}

struct queue dequeue(struct queue q) {
    int ele;
    if(q.head == q.tail) {
        printf("Queue is empty can't dequeue.\n");
    }else if(q.head != q.tail) {
        printf("The element got Dequeued is: %d\n",q.q[++q.head]);
    }
    return q;
}

int main() {
    struct queue q;
    q.head = -1;
    q.tail = -1;
    printf("Input the size of queue: ");
    scanf("%d",&q.max);
    int ele,opt;
    do{
        printf("Select an option to perform on queue\n1. Enqueue\n2. Dequeue\n 3. Exit\n __ ");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            q = enqueue(q);
            break;
        case 2:
            q = dequeue(q);
            break;
        case 3:
            printf("Hey you have exited..");
        default:
            break;
        }

    }while(opt != 3);
}

//Vivek Tej B172299
