//Implement the queue ds with switchCase ,arrays and functions..

#include <stdio.h>

int enqueue(int tail, int max, int q[]) {
    int ele;
    if(tail == max - 1) {
        printf("Queue is full can't enqueue.\n");
    }else if(tail != max - 1) {
        printf("Enter the element to insert in Queue: ");
        scanf("%d",&ele);
        q[++tail] = ele;
    }
    return tail;
}

int dequeue(int head, int tail, int q[]) {
    if(head == tail) {
        printf("Queue is empty can't dequeue.\n");
    }else if(head != tail) {
        printf("The element got Dequeued is: %d\n",q[++head]);
    }
    return head;
}

int main() {
    int max;
    printf("Input the size of queue: ");
    scanf("%d",&max);
    int q[max];
    int head = -1;
    int tail = -1;
    int ele,opt;
    do{
        printf("Select an option to perform on queue\n1. Enqueue\n2. Dequeue\n 3. Exit\n __ ");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            tail = enqueue(tail, max, q);
            break;
        case 2:
            head = dequeue(head,tail,q);
            break;
        case 3:
            printf("Hey you have exited..");
        default:
            break;
        }

    }while(opt != 3);

}


//Vivek Tej B172299