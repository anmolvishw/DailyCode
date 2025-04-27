#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} CL;

CL* makenode() {
    CL *p = (CL*)malloc(sizeof(CL));
    if (!p) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("\nEnter Data: ");
    scanf("%d", &p->data);
    p->next = NULL;
    return p;
}

void addfirst(CL **h) {
    CL *p = makenode();
    if (*h == NULL) {
        p->next = p;
        *h = p;
    } else {
        CL *t = *h;
        while (t->next != *h)
            t = t->next;
        t->next = p;
        p->next = *h;
        *h = p;
    }
}

void addlast(CL **h) {
    CL *p = makenode();
    if (*h == NULL) {
        p->next = p;
        *h = p;
    } else {
        CL *t = *h;
        while (t->next != *h)
            t = t->next;
        t->next = p;
        p->next = *h;
    }
}

void addpos(CL **h) {
    int pos, i, count = 1;
    if (*h == NULL) {
        printf("\nList is empty. Adding at first position.\n");
        addfirst(h);
        return;
    }

    CL *t = *h;
    do {
        count++;
        t = t->next;
    } while (t != *h);

    printf("\nWe have %d nodes. Enter position (1 to %d): ", count - 1, count);
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("\nInvalid Position!\n");
        return;
    }
    if (pos == 1) {
        addfirst(h);
        return;
    }
    if (pos == count) {
        addlast(h);
        return;
    }

    CL *p = makenode();
    t = *h;
    for (i = 1; i < pos - 1; i++)
        t = t->next;
    
    p->next = t->next;
    t->next = p;
}

void delfirst(CL **h) {
    if (*h == NULL) {
        printf("\nList is already empty.\n");
        return;
    }
    if ((*h)->next == *h) {
        printf("\nDeleting: %d\n", (*h)->data);
        free(*h);
        *h = NULL;
        return;
    }

    CL *t = *h;
    while (t->next != *h)
        t = t->next;

    CL *temp = *h;
    t->next = (*h)->next;
    *h = (*h)->next;
    printf("\nDeleting: %d\n", temp->data);
    free(temp);
}

void dellast(CL **h) {
    if (*h == NULL) {
        printf("\nList is already empty.\n");
        return;
    }
    if ((*h)->next == *h) {
        printf("\nDeleting: %d\n", (*h)->data);
        free(*h);
        *h = NULL;
        return;
    }

    CL *t = *h;
    while (t->next->next != *h)
        t = t->next;

    CL *temp = t->next;
    t->next = *h;
    printf("\nDeleting: %d\n", temp->data);
    free(temp);
}

void delpos(CL **h) {
    if (*h == NULL) {
        printf("\nList is already empty.\n");
        return;
    }

    int pos, count = 1, i;
    CL *t = *h;
    do {
        count++;
        t = t->next;
    } while (t != *h);

    printf("\nWe have %d nodes. Enter position to delete (1 to %d): ", count - 1, count - 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > count - 1) {
        printf("\nInvalid Position!\n");
        return;
    }
    if (pos == 1) {
        delfirst(h);
        return;
    }
    if (pos == count - 1) {
        dellast(h);
        return;
    }

    t = *h;
    for (i = 1; i < pos - 1; i++)
        t = t->next;

    CL *temp = t->next;
    t->next = temp->next;
    printf("\nDeleting: %d\n", temp->data);
    free(temp);
}

void display(CL *h) {
    if (h == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    CL *t = h;
    printf("\nList Elements:\n");
    do {
        printf("Data = %d\n", t->data);
        t = t->next;
    } while (t != h);
}

int main() {
    CL *head = NULL;
    int ch;
    while (1) {
        printf("\n========== Circular Linked List Menu ==========");
        printf("\n1. Add First");
        printf("\n2. Add Last");
        printf("\n3. Add at Position");
        printf("\n4. Delete First");
        printf("\n5. Delete Last");
        printf("\n6. Delete at Position");
        printf("\n7. Display");
        printf("\n8. Exit");
        printf("\n\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                addfirst(&head);
                break;
            case 2:
                addlast(&head);
                break;
            case 3:
                addpos(&head);
                break;
            case 4:
                delfirst(&head);
                break;
            case 5:
                dellast(&head);
                break;
            case 6:
                delpos(&head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("\nThanks a Million!!!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
