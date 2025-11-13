#include <stdio.h>
#include <stdlib.h>


int naodirecionada(int M[][4],int n) {
    int flag=0;
    int i,j;
    for (int i=0;i<n;i++) {
        if (flag==0) {
            for (int j=0;j<n;j++) {
                if (M[i][j]!=M[j][i]) {
                    flag=1;
                    break;
                }
            }
        }
    }
    if (flag==0) {
        printf("\nA matriz nao eh direcionada\n");
        return 1;
    }
    else {
        printf("\nMatriz eh direcionada\n");
        return 0;
    }
}

void tipodografo(int M[][4],int n) {
    int flag=0;
    int i,j;
    for (int i=0;i<n;i++) {
        if (flag==0) {
            for (int j=0;j<n;j++) {
                if ( (M[i][j])!=0 && (M[i][j]!=1))
                {
                    flag=1;
                    break;
                }
            }
        }
    }
    if (flag==0) {
        printf("\nA matriz eh simples\n");
    }
    else {
        printf("\nMatriz eh um multigrafo\n");
    }
}

int regular(int M[][4], int n) {
    int grau[n];
    int i, j;

    for (i = 0; i < n; i++) {
        grau[i] = 0;
        for (j = 0; j < n; j++) {
            if (M[i][j] == 1)
                grau[i]++;
        }
    }


    for (i = 1; i < n; i++) {
        if (grau[i] != grau[0])
            return 0;
    }

    return 1;
}


int fonte(int M[][4],int n) {
    int num;
    int vertice=0;
    int i=0,j;
    int num2=n-1;
    num=naodirecionada(M,4);
    if (num==0){
        for (j=0;j<n;j++) {
            i=0;
            while ((M[i][j]==0) && (j<n)){
                i++;
                if ((i==num2) && (M[i][j]==0)){
                    vertice++;
                }
            }
        }
    }
    return vertice;
}

int semidouro(int M[][4],int n) {
    int num;
    int vertice1=0;
    int i=0,j;
    int num2=n-1;
    num=naodirecionada(M,4);
    if (num==0){
        for (i=0;i<n;i++) {
            j=0;
            while ((M[i][j]==0) && (j<n)) {
                j++;
                if ((j==num2) && (M[i][j]==0)){
                    vertice1++;
                }
            }
        }
    }
    return vertice1;
}



int main(void) {
    int matriz[4][4];
    int num,num2;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("MATRIZ[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    naodirecionada(matriz, 4);
    tipodografo(matriz, 4);
    num = fonte(matriz, 4);
    printf("\nVertice fonte:%d", num);
    num2 = semidouro(matriz, 4);
    printf("\nVertice semidouro:%d", num2);
    return 0;
}
