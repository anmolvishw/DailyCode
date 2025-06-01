#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST *left,*right;
    
}bst;

bst* insert(bst *root,int val){
    if(root == NULL){
        root = (bst*)malloc(sizeof(bst));

        root->data = val;
        root->left = root->right = NULL;
        return root;
    }

    if(root->data > val){
       root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }

    return root;
}


void inOrder(bst* root){
    if(root !=NULL){
        inOrder(root->left);
        printf(" %d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(bst* root){
    if(root !=NULL){
        printf(" %d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(bst* root){
    if(root !=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ",root->data);
    }

}

int main(){
    int arr[] = {15,7,6,8,9,10,6,11};
    bst *root = NULL;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<n; i++){
        root = insert(root,arr[i]);
    }

    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    return 0;
}