#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header3.h"

int main(int argc,char** argv) {
    if (argc<3){
        return 1;
    }
    FILE *f1=fopen(argv[1],"r");
    FILE *f2 = fopen(argv[2],"w");
    if (!f1||!f2){
        return 1;
    }
    char n[NUM][MAX_SYM], buf[2048];
    double p[NUM][100];
    int d=0,x,y,flag=1;

    if (fgets(buf, sizeof(buf), f1)){
        char* t=strtok(buf,", \t\r\n");
        x=0;
        while (t&&x<NUM){ 
            strncpy(n[x++], t,MAX_SYM); 
            t=strtok(NULL,", \t\r\n"); 
        }
    }
    while (fgets(buf,sizeof(buf), f1)){
        char* t=strtok(buf,", \t\r\n");
        y=0;
        while (t&&y<NUM){ 
            p[y++][d]=atof(t); 
            t=strtok(NULL,", \t\r\n"); 
        }
        d++;
    }

    TreeNode* root=newT(0);
    for (x=0;x<NUM;x++) ins(root,n[x],p[x],d);
    for (x=0;x<NUM;x++) {
        TreeNode* m=find(root,p[x],d);
        if (m&&m->stocks){
            StockList* y_curr=m->stocks;
            while (y_curr){
                int k=-1;
                for(int i=0;i<NUM;i++){
                    if(!strcmp(n[i],y_curr->symbol)){ 
                        k=i; 
                        break; 
                    }
                }
                if (k>x){
                    if (!flag) fprintf(f2,"\n");
                    fprintf(f2,"%s-%s",n[x],y_curr->symbol);
                    flag=0;
                }
                y_curr=y_curr->next;
            }
        }
    }
    clear(root); 
    fclose(f1); 
    fclose(f2);
    return 0;
}
