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
    int head;
    int tail;
};

void enQueue(struct Queue *q,struct node *tmp) {
    if(q->tail > 49) {
        printf("\nQueue is full.\n");
    }else {
        q->tail++;
        q->a[q->tail] = tmp;
    }
}

struct node* deQueue(struct Queue *q){
    if(q->head >= q->tail) {
        printf("\nQueue is empty\n");
        return NULL;
    }else {
        return q->a[++q->head];
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
        q.head = -1;
        q.tail = -1;
        enQueue(&q,tmp);
        while(1){
            tmp = deQueue(&q);
            if(tmp!= NULL) {
                if(tmp->lNode != NULL)  {
                    enQueue(&q,tmp->lNode);
                }else{
                    break;
                }
                if(tmp->rNode != NULL) {
                    enQueue(&q,tmp->rNode);
                }else{
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

void display(struct node **rootNode) {
    if(*rootNode == NULL) {
        printf("\n[ ]\n");
    }else {
        struct node *tmp = *rootNode;
        struct Queue q;
        q.head = -1;
        q.tail = -1;
        enQueue(&q,tmp);
        printf("\n[");
        while(q.head != q.tail){
            tmp = deQueue(&q);
            printf("%d, ",tmp->ele);
            if(tmp!= NULL) {
                if(tmp->lNode != NULL)  {
                    enQueue(&q,tmp->lNode);
                }
                if(tmp->rNode != NULL) {
                    enQueue(&q,tmp->rNode);
                }
            }else{
                break;
            }
        }
        printf("]\n");
    }
}

struct node* searchElement(struct node **rootNode,int ele) {
    if(*rootNode !=NULL) {
        if((*rootNode)->ele == ele) {
            return *rootNode;
        }
        struct Queue q;
        q.head = -1;
        q.tail = -1;
        struct node *tmp = *rootNode;
        enQueue(&q,tmp);
        while(q.head != q.tail) {
            tmp = deQueue(&q);
            if(tmp->lNode!= NULL) {
                if(tmp->lNode->ele == ele) {
                    return tmp->lNode;
                }
                enQueue(&q,tmp->lNode);
            }if(tmp->rNode != NULL) {
                if(tmp->rNode->ele == ele) {
                    return tmp->rNode;
                }
                enQueue(&q,tmp->rNode);
            }
        }
        return NULL;
    }else {
        printf("\nTree is empty.\n");
        return NULL;
    }
}

struct node * findLastNode(struct node **rootNode) {
    if(*rootNode!=NULL) {
        struct node *tmp = *rootNode;
        struct Queue q;
        q.head=-1;
        q.tail =-1;
        enQueue(&q,tmp);
        while(q.head != q.tail) {
            tmp = deQueue(&q);
            if(tmp->lNode != NULL) {
                enQueue(&q,tmp->lNode);
            }
            if(tmp->rNode != NULL) {
                enQueue(&q,tmp->rNode);
            }
        }
        return q.a[q.head];
    }else {
        return NULL;
    }
}

struct node * findParentNode(struct node **rootNode,struct node* lastNode) {
    if(*rootNode!=NULL) {
        if((*rootNode)->lNode!= NULL && (*rootNode)->lNode == lastNode) {
            return *rootNode;
        }if((*rootNode)->rNode!= NULL && (*rootNode)->rNode == lastNode) {
            return *rootNode;
        }
        struct node *tmp = *rootNode;
        struct Queue q;
        q.head=-1;
        q.tail =-1;
        enQueue(&q,tmp);
        while(q.head != q.tail) {
            tmp = deQueue(&q);
            if(tmp->lNode != NULL) {
                if(tmp->lNode == lastNode) {
                    return tmp;
                }
                enQueue(&q,tmp->lNode);
            }
            if(tmp->rNode != NULL) {
                if(tmp->rNode == lastNode) {
                    return tmp;
                }
                enQueue(&q,tmp->rNode);
            }
        }
        return NULL;
    }else {
        return NULL;
    }
}

void delete(struct node **rootNode) {
    int dEle;
    printf("\nEnter element to be deleted: ");
    scanf("%d",&dEle);
    struct node* foundNode;
    foundNode = searchElement(rootNode,dEle);
    if(foundNode != NULL) {
        printf("\n Element found at: %u",foundNode);
        struct node* lastNode;
        lastNode = findLastNode(rootNode);
        if(lastNode) {
            printf("\n LastNode is: %d",lastNode->ele);
            struct node* parentNode;
            parentNode = findParentNode(rootNode,lastNode);
            if(parentNode!=NULL) {
                printf("\n parentNode is: %d",parentNode->ele);
                foundNode->ele = lastNode->ele;
                if(parentNode->lNode == lastNode) {
                    parentNode->lNode = NULL;
                }else if(parentNode->rNode == lastNode) {
                    parentNode->rNode = NULL;
                }
                printf("\nDeleted successfully :)");
            }else {
                printf("\nCan't find the parentNode SORRY :( \n");
            }
        }else {
                printf("\nCan't find the lastNode SORRY :( \n");
        }
    }else {
        printf("\nThe requested is element is NOT FOUND or may be Tree is EMPTY\n");
    }
}



int main() {
    int opt;
    struct node *rootNode= NULL;
    do
    {
        printf("\n\n\nSelect an option to perform on a tree: \n\t1. Insertion.\n\t2. Display\n\t3. Delete a node \n\t0. Exit \n  __");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            insert(&rootNode);
            break;
        case 2:
            display(&rootNode);
            break;
        case 3:
            display(&rootNode);
            delete(&rootNode);
        default:
            break;
        }
    } while (opt!=0);
    
}