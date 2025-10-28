#include <stdlib.h>  // rand, srand
#include <time.h>    // time
#define TAM 500000
#include <stdio.h>

typedef struct {
    int chave;
    double valor;
}item;



void geraVetorAleatorio(item vetor[], int tamanho,int sem) {
    srand(sem);
    for (int i = 0; i < tamanho; i++) {
        vetor[i].chave = 100000 + rand() % 200001;  // entre 100000 e 300000
        vetor[i].valor = 100000.0 + ((double)rand() / RAND_MAX) * 100000.0; // real > 100000
    }
}

void troca(item *a, item *b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}


void insercao(item *v, int n) {
    int i,j;
   // srand(time(NULL));
    for (i = 1; i < n; i++) {
        for (j = i; j > 0; j++)
        {
            if (v[j-1].chave < v[j].chave) {
                troca(&v[j-1], &v[j]);
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("Chave %d: ", v[i].chave);
    }
}

int main()
{
    item vetor[TAM];
    geraVetorAleatorio(vetor, TAM, 134);
    printf("Exemplo de vetor aleatorio:\n");
    /*for (int i = 0; i < TAM; i++)
    {
        printf("chave = %d | valor = %.2lf\n", vetor[i].chave, vetor[i].valor);
    }*/
   insercao(vetor,500000);



}



