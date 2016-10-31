#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_pilha
{
    float car;
    struct st_pilha *prox;
} pilha;

void push(pilha **cabeca, float c); /* inseri o elemento no comeco da lista */

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

