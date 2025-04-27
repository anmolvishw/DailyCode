#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} LL;

LL* makenode() {
    LL* p = (LL*)malloc(sizeof(LL));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->next = NULL;
    printf("Enter Data: ");
    scanf("%d", &p->data);
    return p;
}

void addfirst(LL **h) {
    LL *p = makenode();
    p->next = *h;
    *h = p;
}

void delfirst(LL **h) {
    LL *p;
    if (*h == NULL) {
        printf("\nList is already empty.\n");
        return;
    }
    p = *h;
    *h = (*h)->next;
    printf("\nDeleting... %d\n", p->data);
    free(p);
}

void display(LL *h) {
    if (h == NULL) {
        printf("\nEmpty List.\n");
        return;
    }
    printf("\nLinked List Contents:\n");
    while (h != NULL) {
        printf("Data = %d\n", h->data);
        h = h->next;
    }
}

void addlast(LL **h) {
    LL *p = makenode();
    LL *t;
    if (*h == NULL) {
        *h = p;
        return;
    }
    t = *h;
    while (t->next != NULL)
        t = t->next;
    t->next = p;
}

void dellast(LL **h) {
    LL *p, *t;
    if (*h == NULL) {
        printf("\nList is already empty.\n");
        return;
    }
    if ((*h)->next == NULL) {
        printf("\nDeleting... %d\n", (*h)->data);
        free(*h);
        *h = NULL;
        return;
    }
    t = *h;
    while (t->next->next != NULL)
        t = t->next;
    p = t->next;
    printf("\nDeleting... %d\n", p->data);
    free(p);
    t->next = NULL;
}

void addpos(LL **h) {
    LL *p, *t;
    int n = 0, pos, i;
    t = *h;
    while (t != NULL) {
        n++;
        t = t->next;
    }
    printf("\nWe have %d nodes. Enter the position to add new node: ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1) {
        printf("\nInvalid Position.\n");
        return;
    }
    if (pos == 1) {
        addfirst(h);
        return;
    }
    if (pos == n + 1) {
        addlast(h);
        return;
    }
    t = *h;
    for (i = 2; i < pos; i++)
        t = t->next;
    p = makenode();
    p->next = t->next;
    t->next = p;
}

void delpos(LL **h) {
    int n = 0, pos, i;
    LL *p, *t;
    t = *h;
    while (t != NULL) {
        n++;
        t = t->next;
    }
    printf("\nWe have %d nodes. Enter the position of node to delete: ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n) {
        printf("\nInvalid Position.\n");
        return;
    }
    if (pos == 1) {
        delfirst(h);
        return;
    }
    if (pos == n) {
        dellast(h);
        return;
    }
    t = *h;
    for (i = 2; i < pos; i++)
        t = t->next;
    p = t->next;
    printf("\nDeleting... %d\n", p->data);
    t->next = p->next;
    free(p);
}

int main() {
    LL *head = NULL;
    int ch;
    while (1) {
        printf("\n\n=== Linked List Menu ===\n");
        printf("1. Add First\n");
        printf("2. Delete First\n");
        printf("3. Add Last\n");
        printf("4. Delete Last\n");
        printf("5. Add at Position\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: addfirst(&head); break;
            case 2: delfirst(&head); break;
            case 3: addlast(&head); break;
            case 4: dellast(&head); break;
            case 5: addpos(&head); break;
            case 6: delpos(&head); break;
            case 7: display(head); break;
            case 8:
                printf("\nThanks a Million!!!\n");
                exit(0);
            default:
                printf("\nInvalid Choice. Try Again!\n");
        }
    }
    return 0;
}
