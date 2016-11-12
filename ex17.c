#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
#define debug 1

typedef struct st_pilha
{
    char car;
    struct st_pilha *prox;
} pilha;

void calcular(char vet[]);
void push(pilha **cabeca, char c); /* inseri o elemento no comeco da lista */
void show(pilha *cabeca); /* exibe os elementos da lista */
char pop(pilha **cabeca); /* retira o primeiro elemento da lista retornando o valor que contem */
int size(pilha *cabeca); /* retorna quantidade de elementos na pilha */
void inverstr(char *str); /* inverte uma string dada */

int main(void)
{
    /* algoritmo de repeticao do programa */

    char vet[MAX];

    fgets(vet, MAX, stdin);
    inverstr(vet);

    if(debug)
    {
    putchar('\n');
    printf("%s", vet);
    putchar('\n');
    }
    
    return EXIT_SUCCESS;
}

void calcular(char vet[])
{
    char *p;
    float x, y, result;
    pilha *cabeca=NULL;

    if((p=strchr(caracteres, '\n'))) *p='\0';

    if((!strcmp(caracteres, "+")))
    {
        x=retira(&cabeca);
        y=retira(&cabeca);
        result=x+y;
        inserir(&cabeca, result);
    }
    else if((!strcmp(caracteres, "-")))
    {
        x=retira(&cabeca);
        y=retira(&cabeca);
        result=x-y;
        inserir(&cabeca, result);
    }
    else if((!strcmp(caracteres, "*")))
    {
        x=retira(&cabeca);
        y=retira(&cabeca);
        result=x*y;
        inserir(&cabeca, result);
    }

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
        printf("%c\n", ms->car);
        ms=ms->prox;
    }

    return;
}

char pop(pilha **cabeca)
{ 
    char valor='0';
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

