#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_pilha
{
    float car;
    struct st_pilha *prox;
} pilha;

void push(pilha **cabeca, float c); /* inseri o elemento no comeco da lista */
void show(pilha *cabeca); /* exibe os elementos da lista */
float pop(pilha **cabeca); /* retira o primeiro elemento da lista retornando o valor que contem */

int main(void)
{
    /* algoritmo de repeticao do programa */

    return EXIT_SUCCESS;
}

void push(pilha **cabeca, float c)
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

