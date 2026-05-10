#ifndef H
#define H

#define MAX_SYM 10
#define NUM 10

typedef struct StockList {
    char symbol[MAX_SYM];
    struct StockList *next;
} StockList;

typedef struct TreeNode {
    StockList *stocks;
    struct TreeNode *left;
    struct TreeNode *right;
    int depth;
} TreeNode;

StockList* newL( char *n);
TreeNode* newT(int d);
void add(TreeNode *node,char *n);
void ins(TreeNode *root,char *n,double p[],int d);
TreeNode* find(TreeNode *root,double p[],int d);
void clear(TreeNode *root);

#endif