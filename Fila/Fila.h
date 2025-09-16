#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

/* FUN��ES DE MANIPULA��O DE PFILA

Fila* CriaFila()  CRIA A FILA

int VaziaFila (Fila* f) VERIFICA SE A FILA EST� VAZIA RETORNA 1 QUANDO EST� VAZIA

void InsereFila (Fila* f, int v) INSER��O

int RetiraFila (Fila* f) REMO��O

Fila* liberaFila (Fila* f) LIBERA A FILA

void imprimeFila (Fila* f)IMPRIME A FILA
*/
typedef struct nos
{
    int info;
    struct nos *prox;
}Nos;

typedef struct fila
{
    Nos * ini;
    Nos * fim;
}Fila;

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

int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;

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


Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

Nos* ins_fim (Nos *fim, int A)
{
    Nos *p = (Nos*)malloc(sizeof(Nos));
    p->info = A;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista n�o estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int v)
{
    f->fim = ins_fim(f->fim,v);
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}

Nos* retira_ini (Nos* ini)
{
    Nos* p = ini->prox;
    free(ini);
    return p;
}

int RetiraFila (Fila* f)
{
    int v;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    v = f->ini->info;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;
    return v;
}

void imprimeFila (Fila* f)
{
    Nos* q;
    printf("\n\t\t");
    for (q=f->ini; q!=NULL; q=q->prox)
    {
        printf("%d - ",q->info);
    }
    printf("\n");
}


Fila* liberaFila (Fila* f)
{
    Nos* q = f->ini;
    while (q!=NULL)
    {
        Nos* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

//RETORNA A QUANTIDADE DE PARES EM UMA FILA 
int pares(Fila* f)
{
    Nos* aux= f->ini;
    int pares = 0;
    if (VaziaFila(f)==1) {
        printf("Fila vazia.\n");
        return 0;
    }
    while(aux!=NULL)
    {
        if(aux->info %2==0){
            pares++;
        }
        aux=aux->prox;
    }
    return pares;
}

//RECEBE UMA FILA, TRANSFORMA EM UMA FILA PAR E OUTRA IMPAR. A FILA ORIGINAL DEIXA DE EXISTIR 

void duasFilas(Fila *f1, Fila* fPares, Fila* fImpares) {
    while (f1->ini != NULL) {
        int valor = RetiraFila(f1);
        if (valor % 2 == 0) {
            InsereFila(fPares, valor);
        } else {
            InsereFila(fImpares, valor);
        }
    }
    liberaFila(f1);
}

//INVERTE UMA FILA 

void inverter(Fila *f) {
    Pilha *aux;
    int valor=0;
    aux=CriaPilha();
    if (VaziaFila(f)==1) {
        printf("Fila vazia.\n");
       exit(0);
   }
    while (f->ini != NULL) {
        valor= RetiraFila(f);
        push(aux,valor);
    }
    while (!vaziaPilha(aux))// enquanto a pilha nao estiver vazia, vazia ==1
    {
        valor=pop(aux);
        InsereFila(f,valor);
    }
    free(aux);
}

//RECEBE UM FILA E RETORNA DUAS PILHAS, SEPARANDO EM NUMEROS MAIORES E MENORES QUE 20 

void numeros20(Fila *f,Pilha *p1, Pilha *p2) {
    Nos *aux;                                    
    aux=f->ini;                                    
    while (aux!= NULL) {
        if (aux->info > 20) {
            push(p1,aux->info);
        }
        if (aux->info < 20) {
            push(p2,aux->info);
        }
        aux= aux->prox;
    }
}

#endif // FILA_H_INCLUDED

