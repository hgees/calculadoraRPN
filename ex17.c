#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 256
#define debug 1

typedef struct st_pilha
{
    float car;
    struct st_pilha *prox;
} pilha;

int calcular(char vet[], pilha *cabeca, pilha **cabec);
void push(pilha **cabeca, double c); /* inseri o elemento no comeco da lista */
void show(pilha *cabeca); /* exibe os elementos da lista */
double pop(pilha **cabeca); /* retira o primeiro elemento da lista retornando o valor que contem */
int size(pilha *cabeca); /* retorna quantidade de elementos na pilha */

int main(void)
{
    /* algoritmo de repeticao do programa */
    char vet[MAX];
    int success;
    pilha *cabeca=NULL;

    printf("\nCalculadora em notacao polonesa inversa\nOperacoes disponiveis:\n+ - soma\n- - subtracacao\n* - multiplicacao\n/ - divisao\n= - resultado da operacao\n");

    do
    {
        printf("\nDigite um valor!!\n");
        fgets(vet, MAX, stdin);
        if((!strcmp(vet, "+")) && (!strcmp(vet, "-")) && (!strcmp(vet, "*")) && (!strcmp(vet, "/")) && (!strcmp(vet, "=")))
        {
            if(isalpha(vet))
            {
                printf("\n\nERROR\n\n");
                exit(0);
            }
            push(&cabeca, strtod(vet,NULL));            
        }   
        else
            success = calcular(vet, cabeca, &cabeca);
        if(success == -1)
            break;

    }while((strcmp(vet, "=")));
    return EXIT_SUCCESS;
}

int calcular(char vet[], pilha *cabeca, pilha **cabec)
{
    int qtd = 0;
    char *p;
    float x, y, result;

    if((p=strchr(vet, '\n'))) *p='\0';

    if((!strcmp(vet, "+")))
    {
        qtd = size(cabeca);
        if(qtd==1)
        {
            printf("Nao e' possivel realizar a soma\n");
            qtd = -1;
        }
        else
        {   
            x=pop(&cabeca);
            y=pop(&cabeca);
            result=x+y;
            push(&cabeca, result);
        }
    }
    else if((!strcmp(vet, "-")))
    {
        qtd = size(cabeca);
        /* se qtd de elementos=1, resultado e' o oposto */
        if(qtd==1)
        {
            x=pop(&cabeca);
            x*=-1;
            push(&cabeca, x);
        }
        else
        {
            x=pop(&cabeca);
            y=pop(&cabeca);
            result=y-x;
            push(&cabeca, result);
        }
    }
    else if((!strcmp(vet, "*")))
    {
        qtd = size(cabeca);
        if(qtd==1)
        {
            printf("Nao e' possivel realizar essa multiplicacao\n");
            qtd = -1;
        }
        else
        {   
            x=pop(&cabeca);
            y=pop(&cabeca);
            result=x*y;
            push(&cabeca, result);
        }
    }
    else if((!strcmp(vet, "/")))
    {
        qtd = size(cabeca);
        if(qtd==1)
        {
            printf("Nao e' possivel realizar a divisao\n");
            qtd = -1;
        }
        else
        {   
            x=pop(&cabeca);
            y=pop(&cabeca);
            result=y/x;
            push(&cabeca, result);
        }
    }
    else if((!strcmp(vet, "=")))
    {
        if(cabeca!=NULL)
            show(cabeca); /* mostra os elementos da lista */
        exit(1);
    }
    else
        push(&cabeca, atof(vet));


    *cabec = cabeca;

    show(cabeca); /* mostra os elementos da lista */
    return qtd;
}

void push(pilha **cabeca, double c)
{
    pilha *pp=*cabeca;
    pp=malloc(sizeof(pilha));
    pp->car=c;
    pp->prox=NULL;
    if(cabeca == NULL)
    {
        pp->prox=NULL;
        *cabeca=pp;
    }
    else
    {        
        pp->prox=*cabeca;
        *cabeca=pp;
    }
    return;
}

void show(pilha *cabeca)
{
    pilha *ms=cabeca;

    printf("\nResultado da operacao:\n");
    while(ms!=NULL)
    {
        printf("%.2f\n", ms->car);
        ms=ms->prox;
    }

    return;
}

double pop(pilha **cabeca)
{ 
    double valor=0;
    pilha *primeiro=*cabeca;

    *cabeca=primeiro->prox;
    valor=primeiro->car;
    free(primeiro);
    return valor;
} 

int size(pilha *cabeca)
{
    pilha *pp=cabeca;
    int count=0;
    while(pp!=NULL)
    {
        count++;
        pp=pp->prox;
    }
    return count;
}

