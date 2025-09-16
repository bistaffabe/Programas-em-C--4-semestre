#include <stdio.h>
#include <stdlib.h>



typedef struct no
{
    int info;
    struct no *prox;
}no;
typedef no lista;

// ------- Insere um valor a lista --------

lista* insere(lista *recebida, int valor)
{
    lista *novo;
    novo=(lista*)malloc(sizeof(lista));
    if (novo!= NULL)
    {
        novo -> info=valor;
        novo -> prox=recebida ;
        return novo;
    }
    return recebida;
}

// --------Inicializa a lista--------

lista* inicializa()
{
    return NULL;
}

//-------Imprime a lista--------

void imprime(lista *aux)
{
    if (aux==NULL)
    {
        printf("Lista Vazia");
    }
    else{
    printf("Lista -> ");
    while (aux!= NULL)
        {
            printf("%d", aux -> info);
            aux= aux -> prox;
        }

    }
}

//--------Apago um valor do inicio da lista ------

lista* apagavalor(lista *comeca)
{
    lista *aux2;
    //aux2=(lista*)malloc(sizeof(lista));
    if(comeca!= NULL)
    {
        aux2= comeca-> prox;
        free(comeca);
        return aux2;
    }
    return comeca;
}


//---------Apaga a lista inteira------

lista* apagalista(lista *aux3)
{
    lista *aux4;
    while (aux3 != NULL)
    {
        aux4=aux3;
        aux3= aux3 -> prox;
        free(aux4);

    }
    return aux3;
}


//---------Busca um valor na lista---------

int busca( lista *aux5, int valor)
{
    while(aux5 != NULL)
    {
        if(aux5 -> info == valor)
        {
            return 1;
        }
        aux5= aux5 -> prox;
    }
    return 0;
}


//----------Verifica se a lista está vazia----

int vaziaLista(lista *aux) {
    if (aux== NULL){
        return 1;
    }
    return 0;
}

//---------Retorna a quantidade de elementos de uma lista--------

int quantidade(lista *aux) {
    int qtd;
    while(aux!=NULL) {
        qtd++;
        aux= aux -> prox;
    }
    return qtd;
}

//-------Soma os elementos de uma lista-------

int soma(lista *aux) {
    int soma;
    while(aux!=NULL) {
        soma+= aux-> info;
        aux=aux -> prox;
    }
    return soma;
}

//---------Insere um valor ao fim da lista ---------

lista *inserefim (lista *aux, int valor) {
    lista *aux2, *novo;
    aux2=aux;
    novo=(lista*)malloc(sizeof(lista));
    if (novo!= NULL)
    {
        novo -> info=valor;
        novo -> prox=NULL;
    }
    while(aux2-> prox!=NULL) {
        aux2= aux2 -> prox;
    }
    aux2-> prox = novo;
    return aux;
}

//---------Apaga um valor ao fim da lista ---------

lista *apagafim(lista *aux) {
    lista *aux2, *aux3;
    aux2=aux;
    aux3=NULL;
    while(aux2->prox!=NULL) {
        aux3= aux2;
        aux2= aux2 -> prox;
    }
    aux3->prox=NULL;
    free(aux2);
    return aux;
}

//---------Retorna a quantidade de numeros impares de uma lista  ---------

int numerosimpares(lista *aux) {
    int qtd=0;
    while(aux!=NULL) {
        if (aux -> info %2 !=0) {
            qtd++;
        }
        aux= aux -> prox;
    }
    return qtd;
}



int main()
{
    int num=0,num1=0,teste=0,i=0,num7=0;
    lista *inicio;
    inicio= inicializa();
    printf("Digite quantos numeros deseja inserir: ");
    scanf("%d",&num);
    while (num>0) {
        printf("Valor= ");
        scanf("%d",&num1);
        inicio= insere(inicio,num1);
        num--;
    }
    imprime(inicio);
    printf("\n");
    inicio=apagavalor(inicio);
    printf("\n");
    imprime(inicio);
    printf("\n Qual valor voce deseja buscar?");
    scanf("%d",&i);
    teste = busca(inicio,i);
    if(teste==1)
    {
        printf("\nEste numero PERTENCE na lista");
    }
    else{
        printf("\nEste numero NÃO PERTENCE na lista");
    }
    inicio=inserefim(inicio,4);
    printf("\n\n");
    imprime(inicio);
    inicio=apagafim(inicio);
    printf("\n\n");
    imprime(inicio);
    printf("\n\n");
    num7=numerosimpares(inicio);
    printf("A quantidade de numeros impares é: %d", num7);
    inicio=apagalista(inicio);


    return 0;
}
