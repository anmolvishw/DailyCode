#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *prev, *next;
} DL;

DL* makenode() {
    DL *p = (DL*)malloc(sizeof(DL));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter Data: ");
    scanf("%d", &p->data);
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void addfirst(DL **h) {
    DL *p = makenode();
    if (*h == NULL) {
        *h = p;
    } else {
        (*h)->prev = p;
        p->next = *h;
        *h = p;
    }
}

void delfirst(DL **h) {
    if (*h == NULL) {
        printf("\nList is already empty...\n");
        return;
    }
    DL *p = *h;
    if ((*h)->next == NULL) {
        printf("\nDeleting... %d\n", p->data);
        free(p);
        *h = NULL;
    } else {
        *h = (*h)->next;
        (*h)->prev = NULL;
        printf("\nDeleting... %d\n", p->data);
        free(p);
    }
}

void displayForward(DL *h) {
    if (h == NULL) {
        printf("\nList is already empty...\n");
        return;
    }
    printf("\nForward List:\n");
    while (h) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

void displayBackward(DL *h) {
    if (h == NULL) {
        printf("\nList is empty...\n");
        return;
    }
    while (h->next != NULL)
        h = h->next;

    printf("\nBackward List:\n");
    while (h) {
        printf("%d ", h->data);
        h = h->prev;
    }
    printf("\n");
}

void addlast(DL **h) {
    DL *p = makenode();
    if (*h == NULL) {
        *h = p;
    } else {
        DL *t = *h;
        while (t->next != NULL)
            t = t->next;
        t->next = p;
        p->prev = t;
    }
}

void dellast(DL **h) {
    if (*h == NULL) {
        printf("\nList is already empty...\n");
        return;
    }
    DL *t = *h;
    if (t->next == NULL) {
        printf("\nDeleting... %d\n", t->data);
        free(t);
        *h = NULL;
    } else {
        while (t->next != NULL)
            t = t->next;
        t->prev->next = NULL;
        printf("\nDeleting... %d\n", t->data);
        free(t);
    }
}

void addpos(DL **h) {
    int pos, n = 0, i;
    DL *t = *h;
    if (t) n = 1;
    while (t && t->next != NULL) {
        t = t->next;
        n++;
    }
    printf("\nWe have %d nodes. Enter the position to add: ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1) {
        printf("\nInvalid Position!\n");
        return;
    }
    if (pos == 1) {
        addfirst(h);
    } else if (pos == n + 1) {
        addlast(h);
    } else {
        t = *h;
        for (i = 2; i < pos; i++)
            t = t->next;
        DL *p = makenode();
        p->next = t->next;
        p->prev = t;
        if (t->next)
            t->next->prev = p;
        t->next = p;
    }
}

void delpos(DL **h) {
    int pos, n = 0, i;
    DL *t = *h;
    if (t) n = 1;
    while (t && t->next != NULL) {
        t = t->next;
        n++;
    }
    printf("\nWe have %d nodes. Enter the position to delete: ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n) {
        printf("\nInvalid Position!\n");
        return;
    }
    if (pos == 1) {
        delfirst(h);
    } else if (pos == n) {
        dellast(h);
    } else {
        t = *h;
        for (i = 2; i < pos; i++)
            t = t->next;
        DL *p = t->next;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        printf("\nDeleting... %d\n", p->data);
        free(p);
    }
}

int main() {
    DL *head = NULL;
    int ch;
    while (1) {
        printf("\n===== Doubly Linked List Menu =====");
        printf("\n1. Add First");
        printf("\n2. Delete First");
        printf("\n3. Add Last");
        printf("\n4. Delete Last");
        printf("\n5. Add at Position");
        printf("\n6. Delete from Position");
        printf("\n7. Display Forward");
        printf("\n8. Display Backward");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: addfirst(&head); break;
            case 2: delfirst(&head); break;
            case 3: addlast(&head); break;
            case 4: dellast(&head); break;
            case 5: addpos(&head); break;
            case 6: delpos(&head); break;
            case 7: displayForward(head); break;
            case 8: displayBackward(head); break;
            case 9: printf("\nThank you!\n"); exit(0);
            default: printf("\nInvalid choice, try again.\n");
        }
    }
    return 0;
}
