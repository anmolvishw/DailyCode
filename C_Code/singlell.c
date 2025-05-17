#include<stdio.h>
#include<stdlib.h>

typedef struct  list
{
    int data;
    struct list *next;
}ll;

ll *node(){
    ll *n = (ll*)malloc(sizeof(ll*));
    printf("\n Enter data : ");
    scanf("%d",&n->data);

    n->next = NULL;
    return n;
}

ll *addfirst(ll *h){
    ll *p = node();
    p->next = h;
    return p;
}

ll *delfirst(ll *h){
    if(h == NULL){
        printf("\n List is empty \n ");
        return h;
    }

    ll *t = h;
    h = h->next;
    free(t);
    return h;
}

ll *addlast(ll *h){
    ll *n = node();

    if(h == NULL){
        return n;
    }

    ll *t = h;

    while(t->next != NULL){
        t=t->next;
    }
    t->next = n;
    return h;
}

ll *dellast(ll *h){
    if(h == NULL){
        printf("\n Empty List");
        return h;
    }

    if(h->next == NULL){
        free(h);
        return NULL;
    }

    ll *t=h,*p;

    while (t->next->next != NULL)
    {
       t=t->next;
    }
    p = t->next;
    free(p);
    t->next = NULL;
    return h;
}

void display(ll *h){
    if(h == NULL){
        printf("\n Empty list \n");
        return;
    }

    while(h!=NULL){
        printf("\n data = %d ",h->data);
        h = h->next;
    }
}

ll *addpos(ll *h){

ll *t=h,*p;
int n =0, i , pos;

    while(t!=NULL){
        t=t->next;
        n++;
    }

    printf("Total nodes %d and enter pos ",n);
    scanf("%d",&pos);

     t = h;
    if(pos < 1 || pos > n+1){
        printf("\n Insertion not possible\n");
        return h;
    }

    if(pos == 1){
        h = addfirst(h);
        return h;
    }
    if(pos == n+1){
        h = addlast(h);
        return h;
    }

    for(i = 2; i< pos; i++){
        t=t->next;
    }
    p = node();
    p->next = t->next;
    t->next = p;
    return h;
}

ll *delpos(ll *h){
    int n = 0, pos, i;
    ll *p , *t = h;

    while(t!=NULL){
        n++;
        t=t->next;
    }
    printf("\n ENter pos ");
    scanf("%d",&pos);

    t = h;
    if(pos < 1 || pos > n){
        printf("\n Invalid inpu");
        return h;
    }

    if(pos == 1) {
        h = delfirst(h);
        return h;
    }
    if(pos == n){
        h = dellast(h);
        return h;

    }

    for(i =2; i< pos; i++){
        t=t->next;
    }
     p = t->next;
     t->next = p->next;
     free(p);
     return h;
}



int main(){
    ll *head = NULL;
   
    head = addpos(head);
    head = addpos(head);
    head = addpos(head);
    head = delpos(head);
    display(head);

    return 0;
}


