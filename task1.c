#include "task1.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Node* fisier(const char* filename, int* N) {
    FILE* fin = fopen(filename, "r");
    if (!fin) return NULL;

    if (fscanf(fin, "%d", N) != 1 || *N <= 1) {
        fclose(fin);
        return NULL;
    }

    Node *head = NULL, *tail = NULL;
    double pret_anterior = 0;

    for (int i = 0; i < *N; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            fclose(fin);
            return head;
        }
        if (fscanf(fin, "%lf", &newNode->valoare) != 1) {
            free(newNode);
            break;
        }
        newNode->next = NULL;
        if (i == 0) {
            newNode->randament = 0.0;
            head = tail = newNode;
        } else {
            newNode->randament = (newNode->valoare - pret_anterior) / pret_anterior;
            tail->next = newNode;
            tail = newNode;
        }
        pret_anterior = newNode->valoare;
    }
    fclose(fin);
    return head;
}

void calcul(Node* head, int N, double* miu, double* x, double* y) {
    if (!head || !head->next || N <= 1) return;

    double suma_randamente = 0;
    Node* curent = head->next;
    while (curent != NULL) {
        suma_randamente += curent->randament;
        curent = curent->next;
    }
    *miu = suma_randamente / (N - 1);

    double suma_patrate = 0;
    curent = head->next;
    while (curent != NULL) {
        suma_patrate += pow(curent->randament - (*miu), 2);
        curent = curent->next;
    }
    *x = sqrt(suma_patrate / (N - 1));
    *y = (*miu) / (*x);
}

double trunchiere(double val) {
    return (long)(val * 1000) / 1000.0;
}

void free_list(Node* head) {
    Node* curent = head;
    while (curent != NULL) {
        Node* temp = curent;
        curent = curent->next;
        free(temp);
    }
}