//Doubly Linked list Implementation
#include<stdio.h>
#include<stdlib.h>


struct node
{
    struct node *prv;
    int ele;
    struct node *nxt;
};

void insertHead(struct node ** head) {
    int ele;
    printf("\nEnter element: ");
    scanf("%d",&ele);
    if(*head == NULL) {
        *head = (struct node *) malloc(sizeof(struct node));
        (*head)->prv = NULL;
        (*head)->nxt = NULL; 
        (*head)->ele = ele;
    }else{
        struct node *nN = (struct node *) malloc(sizeof(struct node));
        nN->ele = ele;
        nN->prv = NULL;
        nN->nxt = *head;
        (*head)->prv = nN;
        *head = nN;
    }
}

void insertTail(struct node **head) {
    int ele;
    printf("\nEnter element: ");
    scanf("%d",&ele);
    if(*head == NULL) {
        *head = (struct node *) malloc(sizeof(struct node));
        (*head)->prv = NULL;
        (*head)->nxt = NULL;
        (*head)->ele = ele;
    }else {
        struct node *tmp = *head;
        while(tmp->nxt!= NULL) {
            tmp = tmp->nxt;
        }
        struct node *nN = (struct node *) malloc(sizeof(struct node));
        tmp->nxt = nN;
        nN->prv = tmp;
        nN->nxt = NULL;
        nN->ele = ele;
    }
}

void displayList(struct node ** head) {
    if(*head == NULL) {
        printf("\n[ ]\n");
    }else {
        struct node *tmp = *head;
        printf("\n[");
        while(tmp->nxt != NULL) {
            printf("%d, ",tmp->ele);
            tmp = tmp->nxt;
        }
        printf("%d]\n",tmp->ele);
    }
}

void removeHead(struct node **head) {
    if(*head == NULL) {
        printf("\nOops nothing to remove, List is empty.\n");
    }else {
        (*head)->nxt->prv = NULL;
        *head = (*head)->nxt; 
    }
}

void removeTail(struct node **head) {
    if(*head == NULL) {
        printf("\nOops nothing to remove, List is empty.\n");
    }else {
        struct node *tmp = *head;
        while(tmp->nxt != NULL) {
            tmp = tmp->nxt;
        }
        if(tmp->nxt != (*head)->nxt) {
            tmp->prv->nxt = NULL;
            tmp->prv = NULL;
            free(tmp);
        }else {
            *head = (*head)->nxt;
        }
    }
}

int length(struct node **head) {
    int l=0;
    if(*head != NULL) {
        struct node *tmp= *head;
        while(tmp->nxt != NULL) {
            tmp= tmp->nxt;
            l++;
        }
        l++;
        return l;
    }else{
        return l;
    }
}

void insertAtPosition(struct node **head) {
    if(*head == NULL) {
        printf("Oops unable to insert, List is empty\n");
    }else {
        int po,ele;
        printf("Enter position and element: ");
        scanf("%d%d",&po,&ele);
        struct node *tmp = *head;
        int f=0;
        while(po > 1) {
            tmp=tmp->nxt;
            po--;
            if(tmp->nxt == NULL) {
                if(po >= 1) {
                    f=1;
                }
            }
        }
        if(f ==1) {
            printf("Position is out of range, can't insert\n");
        }else{
            struct node *nN = (struct node *) malloc(sizeof(struct node));
            nN->ele = ele;
            nN->prv = tmp;
            nN->nxt = tmp->nxt;
            tmp->nxt->prv = nN;
            tmp->nxt = nN;
        }
        

    }
}

void removeAtPosition(struct node **head) {
    if(*head == NULL) {
        printf("Oops unable to remove, List is empty\n");
    }else {
        int po;
        printf("Enter position: ");
        scanf("%d",&po);
        struct node *tmp = *head;
        int f=0;
        if(po == 1 ){
            (*head)->nxt->prv = NULL;
            *head = (*head)->nxt;
            return;
        }
        while(po > 1) {
            if(tmp->nxt != NULL) {
                tmp=tmp->nxt;
            }
            po--;
            if(tmp->nxt == NULL) {
                if(po >= 1) {
                    f=1;
                }
            }
        }
        if(f ==1) {
            if(po == 1 ) {
                printf("Cant remove at tail. Usee remove at tail function\n");
            }else {
                printf("Position is out of range, can't Remove\n");
            }
        }else{
            tmp->prv->nxt = tmp->nxt;
            tmp->nxt->prv = tmp->prv;
            free(tmp);
        }
        

    }

}

void searchEle(struct node **head) {
    if(*head == NULL) {
        printf("OOPS, List is empty");
    }else{
        int ele;
        printf("Enter element to search for: ");
        scanf("%d",&ele);
        if((*head)->ele == ele) {
            printf("%d, found at first position",ele);
            return;
        }else{
            struct node *tmp = *head;
            int po= 1, f=0;
            while(tmp->nxt!= NULL) {
                if(tmp->ele == ele){
                    f = 1;
                    break;
                }
                tmp= tmp->nxt;
                po++;
            }
            if(f==1) {
                printf("%d, is found at %d position.",ele,po);
            }else{
                printf("%d, is NOT FOUND\n",ele);
            }
        }
    }
}

void removeElement(struct node **head) {
    if(*head == NULL) {
        printf("OOPS, List is empty");
    }else{
        int ele;
        printf("Enter element to remove: ");
        scanf("%d",&ele);
        if((*head)->ele == ele) {
            *head = (*head)->nxt;
        }else{
            struct node *tmp = *head;
            int po= 1, f=0;
            while(tmp->nxt!= NULL) {
                if(tmp->ele == ele){
                    f = 1;
                    break;
                }
                tmp= tmp->nxt;
                po++;
            }
            if(f==1) {
                printf("%d, is found at %d position. and Removed successfully",ele,po);
                tmp->prv->nxt = tmp->nxt;
                tmp->nxt->prv = tmp->prv;
                free(tmp);
            }else{
                printf("%d, is NOT FOUND\n",ele);
            }
        }
    }
}


int main() {
    struct node *head= NULL;
    int op;
    do{
        printf("\n\nSelect an option to perform:\n\t1. Insert ele at Head\n\t2. Insert ele at Tail\n\t3. Remove ele at Head\n\t4. Remove ele at Tail\n\t5. Insert ele at position\n\t6. Remove ele at Position\n\t7. Remove given ele\n\t8. Search for an ele\n\t9. Length of list\n\t10. Exit\n\t11. Display List \n\t");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            insertHead(&head);
            break;
        case 2:
            insertTail(&head);
            break;
        case 3:
            removeHead(&head);
            break;
        case 4:
            removeTail(&head);
            break;
        case 5:
            insertAtPosition(&head);
            break;
        case 6:
            removeAtPosition(&head);
            break;
        case 7:
            removeElement(&head);
            break;
        case 8:
            searchEle(&head);
            break;
        case 9:
            printf("Length = %d\n",length(&head));
            break;
        case 11:
            displayList(&head);
            break;
        default:
            break;
        }

    } while (op!=10);
    


}

//Vivek Tej

