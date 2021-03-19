//Implement all functionalities attached with linked lists.


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int ele;
    struct node* nxt;
};

struct node* insertHead(struct node* head) {
    int ele;
    printf("\nEnter the element: ");
    scanf("%d",&ele);
    if(head == NULL) {
        head = (struct node *) malloc(sizeof(struct node));
        head->ele = ele;
        head->nxt = NULL;
    }else {
        struct node* nn = (struct node *) malloc(sizeof(struct node));
        nn->ele = ele;
        nn->nxt = head;
        head = nn;
    }
    return head;
}

struct node* removeHead(struct node* head) {
    if(head == NULL) {
        printf("\nThere is no element at head, List is empty\n");
    }else {
        head = head-> nxt;
    }
    return head;
}

void removeTail(struct node* head) {
    if(head == NULL) {
        printf("\nThere is no element at Tail, List is empty\n");
    }else {
        struct node *tmp = head;
        struct node *pvtmp = head;

        while(tmp->nxt != NULL) {
            pvtmp = tmp;
            tmp = tmp -> nxt;
        }
        pvtmp->nxt = NULL;
    }
}

void insertTail(struct node *head) {
    int ele;
    printf("\nEnter the element: ");
    scanf("%d",&ele);
    if(head == NULL) {
        head = (struct node *) malloc(sizeof(struct node));
        head->ele = ele;
        head->nxt = NULL;
    }else{
        struct node *tmp = head;
        while(tmp->nxt != NULL) {
            tmp = tmp->nxt;
        }
        struct node * nn = (struct node *) malloc(sizeof(struct node));
        nn->ele = ele;
        nn->nxt = NULL;
        tmp->nxt = nn;
    }
}

void displayList(struct node *head) {
    if(head == NULL) {
        printf("Linked list is empty");
    }else {
        struct node* tmp= head;
        printf("\n[");
        while(tmp->nxt != NULL) {
            printf("%d, ",tmp->ele);
            tmp = tmp->nxt;
        }
        printf(" %d",tmp->ele);
        printf("]\n");
    }
}

void insertAtPosition(struct node * head) {
    int po,ele;
    printf("Enter Position and Element: ");
    scanf("%d%d",&po,&ele);
    if(head == NULL) {
        printf("Error: List is empty.");
    }else {
        struct node *tmp = head;
    int f = 0;
    while(po > 1) {
        tmp = tmp->nxt;
        if(tmp->nxt == NULL) {
            f=1;
            break;
        }
        po--;
    }
    if(f==1) {
        printf("Entered position out of range.");
    }else {
        struct node *nn = (struct node *) malloc(sizeof(struct node));
        nn->ele = ele;
        nn->nxt = tmp->nxt;
        tmp->nxt = nn;
    }
    
    }
}

void removeAtPosition(struct node * head) {
    int po;
    printf("Enter Position to remove: ");
    scanf("%d",&po);
    if(head == NULL) {
        printf("Error: List is empty.");
    }else {
        struct node *tmp = head;
        struct node *pvTmp = head;

    int f = 0;
    while(po > 1) {
        pvTmp = tmp;
        if(tmp->nxt == NULL) {
            f=1;
            break;
        }
        tmp = tmp->nxt;
        po--;
    }
    if(f==1) {
        printf("Entered position out of range.");
    }else {
        pvTmp->nxt = tmp->nxt;
        tmp->nxt = NULL;
    }
    
    }
}

void removeElement(struct node* head) {
    if(head == NULL) {
        printf("List is Empty\n.");
    }else {
        int ele;
        printf("Enter element to remove: ");
        scanf("%d",&ele);
         struct node *tmp = head;
        struct node *pvTmp = head;
        int f = 0;
        while (tmp->nxt != NULL) 
        {
            pvTmp = tmp;
            if(ele == tmp->ele) {
                f = 1;
                break;
            }
            tmp = tmp->nxt;
        }
        if(ele == tmp->ele) {
                f = 1;
        }
        if(f==0) {
            printf("Element not found in list\n");
        }else{
            pvTmp->nxt = tmp->nxt;
            tmp->nxt = NULL;
        }

        
        
    }
}

void searchEle(struct node *head) {
    if(head == NULL) {
        printf("\nList is Empty\n");
    }else {
        int po=1,sEle,f =0;
        printf("Enter element to search: ");
        scanf("%d",&sEle);
        struct node *tmp = head;
        while( tmp->nxt != NULL ) {
            if(tmp->ele == sEle) {
                f=1;
                break;
            }
            tmp=tmp->nxt;
            po++;
        }
        if(tmp->ele == sEle) {
                f=1;
        }
        if(f==0) {
            printf("Element not found in list\n");
        }else{
            printf("Element found at position: %d\n",po);

        }

    }

}

int length(struct node *head) {
    if(head == NULL) {
        return 0;
    }else {
        int l=0;
        struct node *tmp = head;
        while(head->nxt != NULL) {
            tmp = tmp->nxt;
            l++;
        }
        return l;
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
            head = insertHead(head);
            break;
        case 2:
            insertTail(head);
            break;
        case 3:
            head = removeHead(head);
            break;
        case 4:
            removeTail(head);
            break;
        case 5:
            insertAtPosition(head);
            break;
        case 6:
            removeAtPosition(head);
            break;
        case 7:
            removeElement(head);
            break;
        case 8:
            searchEle(head);
            break;
        case 9:
            printf("Length = %d\n",length(head));
            break;
        case 11:
            displayList(head);
            break;
        default:
            break;
        }

    } while (op!=10);
    


}

//Vivek Tej