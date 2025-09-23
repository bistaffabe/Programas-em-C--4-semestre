#ifndef lib_h_include
#define lib_h_included

#include <ctype.h>
#include <string.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct dados
{
    char nome[50];
    int idade;
    int id;
    char especie[30];
    int prior;
    Data aniv;
} Dados;

typedef struct no
{
    struct no *prox;
    Dados info;
} No;

typedef struct lista
{
    No* ini;
    No* fim;
} Fila;

Fila* CriaFila(void)
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int vaziaFila(Fila* f)
{
    if (f->ini == NULL) return 1;
    else return 0;
}

No* ins_fim(No *fim, char nome[50], char idade, char especie[30], int prior, int dia, int mes, int ano)
{
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->info.nome, nome);
    novo->info.idade = idade;
    strcpy(novo->info.especie, especie);
    novo->info.prior = prior;
    novo->info.aniv.dia = dia;
    novo->info.aniv.mes = mes;
    novo->info.aniv.ano = ano;
    if (fim != NULL)
    {
        fim->prox = novo;
    }
    return novo;
}

void insere_pet(Fila *f, char nome[50], int idade, char especie[30], int prior, int dia, int mes, int ano)
{
    f->fim = ins_fim(f->fim, nome, idade, especie, prior, dia, mes, ano);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}


void transferencia(Fila *atendidos, Fila *f) {
    No *aux = f->ini;
    f->ini = aux->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    aux->prox = NULL;
    if (atendidos->ini == NULL) {
        atendidos->ini = aux;
        atendidos->fim = atendidos->ini;
    }
    else {
        atendidos->fim->prox = aux;
        atendidos->fim = aux;
    }
}

No* remove_pet(No* ini)
{
    No *p = ini->prox;
    free(ini);   // libera o primeiro n�
    return p;    // retorna o novo in�cio
}

void atende(Fila *f, Fila *atendidos)
{
    No* aux = f->ini;
    transferencia(atendidos,f);
}

void imprime_prox(Fila *f)
{
    No* aux = f->ini;
    if(vaziaFila(f)==1)
    {
        printf("\nNao ha nenhum pet na fila de atendimento.");
    }
    else
    {
    printf("\n%s | ", aux->info.nome);
    printf("%s | ", aux->info.especie);
    printf("%d | ", aux->info.prior);
    }
}

int busca(Fila *f, char nome[50])
{
    No* aux = f->ini;
    while (aux != NULL)
        {
        if (strcmp(aux->info.nome, nome)==0)
        {
            printf("\nO animal buscado esta cadastrado!");
            printf("\n%s | ", aux->info.nome);
            printf("%s | ", aux->info.especie);
            printf("%d | ", aux->info.prior);
            return 1;
        }
        else
        {
            aux = aux->prox;
        }
    }
    return 0;
}

void imprime(Fila *f)
{
    No* aux = f->ini;
    while (aux != NULL)
    {
        printf("\n%s | ", aux->info.nome);
        printf("%s | ", aux->info.especie);
        printf("%d | ", aux->info.idade);
        printf("%d/%d/%d | ", aux->info.aniv.dia, aux->info.aniv.mes, aux->info.aniv.ano);
        printf("%d ", aux->info.prior);
        aux = aux->prox;
    }
}

#endif // fila_h_include
