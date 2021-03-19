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

void displayList(struct node *head) {
    struct node* tmp= head;
    printf("\n[");
    while(tmp->nxt != NULL) {
        printf("%d, ",tmp->ele);
        tmp = tmp->nxt;
    }
    printf("]\n");
}


int main() {
    struct node *head= NULL;
    int op;
    do
    {
        printf("Select an option to perform:\n\t1. Insert ele at Head\n\t2. Insert ele at Tail\n\t3. Remove ele at Head\n\t4. Remove ele at Tail\n\t5. Insert ele at position\n\t6. Remove ele at Position\n\t7. Remove given\n\t8. Search for an ele\n\t9. Length of list\n\t10. Exit\n\t11. Display List ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            head = insertHead(head);
            break;
        case 11:
            displayList(head);
            break;
        default:
            break;
        }

    } while (op!=10);
    


}