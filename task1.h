#ifndef TASK1_H
#define TASK1_H
typedef struct Node {
    double valoare;
    double randament;
    struct Node* next;
} Node;
Node* fisier(const char* filename, int* N);
void calcul(Node* head, int N, double* miu, double* x, double* y);
double trunchiere(double val);
void free_list(Node* head);

#endif