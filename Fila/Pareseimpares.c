//
// Created by Beatriz Bistaffa on 03/09/25.
//

#include <stdio.h>
#include <stdlib.h>

#include "FILA.h"



int main() {
    int num,num1;
    Fila *f,*pares,*impares;
    f=CriaFila();
    pares=CriaFila();
    impares=CriaFila();
    printf("Quantos elementos voce deseja inserir na fila? ");
    scanf("%d",&num);
    while(num>0) {
        printf("\nValor: ");
        scanf("%d",&num1);
        InsereFila(f,num1);
        num--;
    }
    printf("\n");
    printf("Fila Pares: ");
    duasFilas(f,pares,impares);
    imprimeFila(pares);
    printf("\n");
    printf("Fila Impares: ");
    imprimeFila(impares);

    return 0;


}