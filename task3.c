#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header3.h"

StockList* newL(const char *n) {
    StockList* x=malloc(sizeof(StockList));
    if(x){ 
        strncpy(x->symbol,n,MAX_SYM); 
        x->next=NULL; 
    }
    return x;
}

TreeNode* newT(int d) {
    TreeNode* x=malloc(sizeof(TreeNode));
    if(x){ 
        x->stocks=NULL; 
        x->left=x->right=NULL; 
        x->depth=d; 
    }
    return x;
}

void add(TreeNode *node,const char *n) {
    StockList* x=newL(n);
    if (!node->stocks){
        node->stocks=x;
    } else { 
        StockList* y=node->stocks; 
        while(y->next) y=y->next; 
        y->next=x; 
    }
}

void ins(TreeNode *root,const char *n,double p[],int d){
    TreeNode* x=root;
    int i=0;
    for (i=0;i<d-1;i++){
        if (p[i+1]>=p[i]) {
            if (!x->right){
                x->right=newT(i+1);
            }
            x=x->right;
        } else{
            if(!x->left){ 
            x->left=newT(i+1);
            }
            x=x->left;
        }
    }
    add(x, n);
}

TreeNode* find(TreeNode *root,double p[],int d){
    TreeNode* x=root;
    int i=0;
    for (i=0;i<d-1;i++){
        if (p[i+1]>=p[i]){
            if (!x->left){ 
                return NULL;
            }
            x=x->left;
        } else {
            if (!x->right){
            return NULL;
            }
          
            x=x->right;
        }
    }
    return x;
}

void clear(TreeNode *root){
    if (!root){
    return;
    }
    clear(root->left); 
    clear(root->right);
    StockList* x=root->stocks;
    while(x){ 
        StockList*y=x; 
        x=x->next; 
        free(y); 
    }
    free(root);
}
