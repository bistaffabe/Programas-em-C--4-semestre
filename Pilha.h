#ifndef DOWNLOADS_PILHAA_H
#define DOWNLOADS_PILHAA_H

/* FUN��ES DE MANIPULA��O DE PILHA

Pilha* CriaPilha ()     CRIA A PILHA
No* ins_ini (No* t, int a)  AUXILIAR DA INSER��O
void push (Pilha* p, int v) INSER��O
No* ret_ini (No* l)         AUXILIAR DA REMO��O
int pop (Pilha* p)          REMOVE RETORNANDO O VALOR QUE FOI REMOVIDO
Pilha* liberaPilha (Pilha* p)      LIBERA A PILHA
void imprime (Pilha* p)     IMPRIMA A PILHA
int vaziaPilha(Pilha *p)	    VERIFICA SE A PILHA EST� VAZIA, RETORNA 1

*/

typedef struct no
{
    int info;
    struct no *prox;
}No;

typedef struct pilha
{
    No *Topo;
}Pilha;

int vaziaPilha( Pilha *p)
{
    if(p->Topo== NULL)
    {
        return 1;
    }
    return 0;
}

Pilha* CriaPilha (void)
{
    Pilha *p;
    p=(Pilha*)malloc(sizeof(Pilha));
    p->Topo = NULL;
    return p;
}

No* ins_ini (No* t, int a)
{
    No* aux = (No*) malloc(sizeof(No));
    aux->info = a;
    aux->prox = t;
    return aux;
}

void push (Pilha* p, int v)
{
    p->Topo = ins_ini(p->Topo,v);
}

No* ret_ini (No* aux)
{
    No* p = aux->prox;
    free(aux);
    return p;
}

int pop (Pilha *p)
{
    int v;
    if (vaziaPilha(p))
    {
        printf("\n\n\t==> Pilha VAZIA, IMPOSSIVEL CONTINUAR.\b\n");
        exit(1); /* aborta programa */
    }
    v = p->Topo->info;
    p->Topo = ret_ini(p->Topo);
    return v;
}

void imprime(Pilha *p)
{
    No *aux= p->Topo;

    if (vaziaPilha(p))
    {
        printf("Pilha vazia");
    }
    else
    {
        while(aux!= NULL)
        {
            printf("%d", aux-> info);
            aux= aux-> prox;
        }
    }
}

Pilha* liberaPilha (Pilha *p) {
    No* aux;
    while(p->Topo != NULL) {
        aux = p->Topo-> prox;
        free(p->Topo);
        p->Topo = aux;
    }
    free(p);
    return NULL;
}

float mediaPilha (Pilha* p) {
    No *aux;
    aux=p -> Topo;
    int soma=0, qtd=0;
    if (!vaziaPilha(p)) {// not significa que se for 0, ou seja a pilha nao estiver vazia vai executar
        while(aux != NULL) {
            soma= soma + aux-> info;
            qtd++;
            aux= aux-> prox;
        }
    return (float)soma/qtd;
    }
    return 0;
}

int quantidadePilha (Pilha* p) {
    No *aux;
    int qtd=0;
    if (!vaziaPilha(p)) {
        aux = p->Topo;
        while(aux != NULL) {
            qtd++;
            aux= aux->prox;
        }
        return qtd;
    }
    return 0;
}



int comparaPilha(Pilha *p1, Pilha *p2) {
    int cont1,cont2;
    cont1= quantidadePilha(p1);
    cont2= quantidadePilha(p2);
    if (cont1>cont2) {
        return 1;
    }
    if (cont1<cont2) {
        return 2;
    }
    return 0;
}

Pilha* inverter(Pilha *p) {
    Pilha *p2;
    //No *aux;
    float valor=0;
    p2=CriaPilha();

    while(p->Topo != NULL) {
        valor=pop(p);
        push(p2,valor);
    }
    return p2;
}

Pilha* guarda(int num,Pilha* p) {

    int num1;
    if (num==0) {
        push(p,num);
        return p;
    }
    while (num != 0) {
        num1 = num % 10;
        num=num/10;
        push(p,num1);
    }
    return p;
}



#endif 
