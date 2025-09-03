//REMOVA UM DETERMINADO ELEMENTO DA PILHA SE EXISTIR
//IMPRIMIR UM INTEIRO QUE ESTA EM UMA PILHA (APENAS INVERTER E IMPRIMIR?)

int main()
{

    Pilha *pilha, *pilha2;
    int valor,valor1,qtd1;
    float media;
    printf("Bem vindo!");
    pilha2 = CriaPilha();
    push(pilha2, 1);
    push(pilha2, 2);
    push(pilha2, 3);
    do {

        printf("\n1.Para criar uma pilha");//certo
        printf("\n2.Inserção no topo da pilha");//certo
        printf("\n3.Remoção no topo da pilha");//certo
        printf("\n4.Imprimir pilha");//certo
        printf("\n5.Media dos elementos da pilha");//certo
        printf("\n6.Quantidade de elementos na pilha");//certo
        printf("\n7.Comparação entre duas pilhas");//certo, porem declaro a pilha2 antes
        printf("\n8.Inverter pilha");//certo
        printf("\n9.Para guardar um inteiro em uma pilha e imprimir");//certo
        printf("\n10.Liberar a pilha");
        printf("\n11.Sair");
        printf("\n>>>>>>>>>RESPOSTA:");
        scanf("%d",&valor);

        switch (valor) {
            case 1:
                pilha=CriaPilha();
                break;
            case 2:
                printf("Digite o valor que deseja inserir: ");
                scanf("%d",&valor1);
                push(pilha,valor1);
                break;
            case 3:
                valor1=pop(pilha);
                printf("O valor removido foi %d",valor1);
                break;
            case 4:
                imprime(pilha);
                break;
            case 5:
                media = mediaPilha(pilha);
                printf("Media dos elementos da pilha: %f",media);
                break;
            case 6:
                qtd1 = quantidadePilha(pilha);
                printf("Quantidade de elementos da pilha: %d",qtd1);
                break;
            case 7:
                qtd1 = comparaPilha(pilha,pilha2);
                printf("\n 0 para mesma quantidade \n 1 se a pilha 1 tiver mais elementos \n 2 se a pilha 2 tiver mais elementos");
                printf("\nResposta: %d \n",qtd1);

            case 8:
                pilha=inverter(pilha);
                break;
            case 9:
                printf("\nDigite um inteiro: ");
                scanf("%d",&valor1);
                guarda(valor1,pilha);
                printf("\n");
                imprime(pilha);
                break;
            case 10:
                liberaPilha(pilha);
                break;
        }

    }while(valor!=11);


  return 0;
}







