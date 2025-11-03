#include <stdlib.h>  // rand, srand
#include <time.h>    // time
#define TAM 50
#include <stdio.h>
#include <time.h>

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
    int i, j;
    for (i = 1; i < n; i++) {
        for (j=i;j>0;j--){
            if (v[j - 1].chave < v[j].chave) {
                // ordem decrescente
                troca(&v[j - 1], &v[j]);
            }
        }
    }
}


int particao(item *v, int LI, int LS)
{
    int aux, pivo, e=LI, d=LS;
    pivo=v[e].chave;
    while(e < d)
    {
        while((v[e].chave>=pivo)&& (e<LS)) { e++;}
        while((v[d].chave<pivo)&&(d>LI)) {d--;}
        if(e<d)
        {
            aux = v[e].chave; v[e].chave=v[d].chave; v[d].chave=aux;
        }
    }
    aux = v[LI].chave; v[LI].chave=v[d].chave; v[d].chave=aux;
    return d;
}

void quicksort(item *v, int LI, int LS)
{
    if(LI<LS)
    {
        int p,i;
        p = particao(v,LI,LS);
        quicksort(v,LI,p-1);
        quicksort(v,p+1,LS);
    }
}


int main()
{
    int i;
    item vetor[TAM];
    clock_t inicio, fim;
    double tempo_insercao, tempo_quick;

    geraVetorAleatorio(vetor, TAM, 500);
    printf("Exemplo de vetor aleatorio:\n");
    for (i = 0; i < 50; i++) {
        printf("Chave: %d\n", vetor[i].chave);
    }
    printf("\n\n\n\n");
    /*insercao(vetor, 50);
    for (i = 0; i < 50; i++) {
        printf("Chave: %d\n", vetor[i].chave);
    }*/
    inicio = clock();
    quicksort(vetor, 0, 49);
    fim = clock();
    tempo_quick = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\n\n\n\n");
    for (i = 0; i < 50; i++) {
        printf("Chave: %d\n", vetor[i].chave);
    }

    printf("Tempo QuickSort: %.20f segundos\n", tempo_quick);

}



