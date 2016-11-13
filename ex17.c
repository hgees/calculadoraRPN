#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
#define debug 1

typedef struct st_pilha
{
    float car;
    struct st_pilha *prox;
} pilha;

void calcular(char vet[], pilha *cabeca, pilha **cabec);
void push(pilha **cabeca, char c); /* inseri o elemento no comeco da lista */
void show(pilha *cabeca); /* exibe os elementos da lista */
float pop(pilha **cabeca); /* retira o primeiro elemento da lista retornando o valor que contem */
int size(pilha *cabeca); /* retorna quantidade de elementos na pilha */
void inverstr(char *str); /* inverte uma string dada */

int main(void)
{
    /* algoritmo de repeticao do programa */
    char vet[MAX];
    pilha *cabeca=NULL;

    printf("\nCalculadora em notacao polonesa inversa\nOperacoes disponiveis:\n+ - soma\n- - subtracacao\n* - multiplicacao\n/ - divisao\n= - resultado da operacao\n");

    do
    {
        fgets(vet, MAX, stdin);
        calcular(vet, cabeca, &cabeca);
    }while((strcmp(vet, "=")));
    /*
       inverstr(vet);

       if(debug)
       {
       putchar('\n');
       printf("%s", vet);
       putchar('\n');
       }
       */
    return EXIT_SUCCESS;
}

void calcular(char vet[], pilha *cabeca, pilha **cabec)
{
    int qtd;
    char *p;
    float x, y, result;

    if((p=strchr(vet, '\n'))) *p='\0';

    if((!strcmp(vet, "+")))
    {
        qtd = size(cabeca);
        if(qtd==1)
        {
            printf("Nao e' possivel realizar a soma\n");
            return;
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
        x=pop(&cabeca);
        y=pop(&cabeca);
        result=y-x;
        push(&cabeca, result);
    }
    else if((!strcmp(vet, "*")))
    {
        qtd = size(cabeca);
        if(qtd==1)
        {
            printf("Nao e' possivel realizar essa multiplicacao\n");
            return;
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
            return;
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
    }
    else
        push(&cabeca, atof(vet));

    *cabec = cabeca;

    return;
}


void inverstr(char *str)
{
    int i;
    pilha *cabeca=NULL;
    for(i=0; i < strlen(str)-1;i++)
        push(&cabeca, str[i]);
    for(i=0; i < strlen(str)-1;i++)
        str[i]=pop(&cabeca);
    return;
}

void push(pilha **cabeca, char c)
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

    printf("\nResultado da operacao: ");
    while(ms!=NULL)
    {
        printf("%.2f\n", ms->car);
        ms=ms->prox;
    }

    return;
}

float pop(pilha **cabeca)
{ 
    float valor=0;
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

