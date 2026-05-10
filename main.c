#include "task1.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        return 1;
    }

    int N = 0;
    Node* portofoliu=fisier(argv[1], &N);
    if (portofoliu==NULL) {
        return 0; 
    }
    double miu=0,x=0,y=0;
    printf("%.3f\n%.3f\n%.3f\n",trunchiere(miu),trunchiere(x),trunchiere(y));
    free_list(portofoliu);
    return 0;
}