#include <stdio.h>
#include <stdlib.h>
#include "FILA.h"
// Created by Beatriz Bistaffa on 03/09/25.
//

int main() {
    Fila *f;
    Pilha *p1,*p2;
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
    p1=CriaPilha();
    p2=CriaPilha();
    numeros20(f,p1,p2);
    imprime(p1);
    printf("\n\n");
    imprime(p2);
    return 0;
}