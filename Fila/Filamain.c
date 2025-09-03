#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FILA.h"
//
// Created by Beatriz Bistaffa on 02/09/25.
//


int main()
{
    Fila *f;
    int num,num1;

    f=CriaFila();
    printf("Quantos elementos voce deseja inserir na fila? ");
    scanf("%d",&num);
    while(num>0) {
        printf("\nValor: ");
        scanf("%d",&num1);
        InsereFila(f,num1);
        num--;
    }
    printf("\nFila: ");
    imprimeFila(f);
    num=pares(f);
    printf("\nQuantidade de numeros pares: %d\n",num);
    inverter(f);
    printf("\nFila invertida: ");
    imprimeFila(f);
    return 0;
}