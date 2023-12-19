# include <stdio.h>
# include <stdlib.h>

typedef struct pilha
{
    char caracter;
    struct pilha *prox;
} pilha;

pilha *empilhar(pilha *p, char valor)
{
    pilha *novo;
    novo = (pilha *)malloc(sizeof(pilha));
    novo->caracter = valor;
    novo->prox = p;
    p = novo;
    return p;
}
pilha *desempilhar(pilha *p)
{
    pilha *aux;
    aux = p;
    if (p->prox == NULL)
        p = NULL;
    else
        p = p->prox;
    free(aux);
    return p;
}

// Função identifica_formacao

// Retorno:
//. 0 - Caso f não seja o fechamento de d
//. 1 - Caso f seja o fechamento de d
int forma_par(char f, char d)
{
    switch (f)
    {
    case ')':
        if (d == '(')
            return 1;
        else
            return 0;
        break;
    case ']':
        if (d == '[')
            return 1;
        else
            return 0;
        break;
    case '}':
        if (d == '{')
            return 1;
        else
            return 0;
        break;
    }
}

// Função identifica_formacao
// Retorno:
//. 0 - Caso a expressão de entrada está bem formada
//. 1 - Caso a expressão de entrada não esteja bem formada
void identifica_formacao(char x[])
{
    pilha *p;
    p = (pilha *) malloc(sizeof(pilha));
    p->prox = NULL;
    for (int i=0; x[i] != '\0'; i++){
        // printf("%c", x[i]);
        if (x[i] == '(' || x[i] == '{'){
            p = empilhar(p, x[i]);
            printf("%c\n", x[i]);
        }
        else if (x[i] == ')' || x[i] == '}'){
            if (forma_par(x[i], p->caracter) == 1){
                printf("certo\n");
                p = desempilhar(p);
                printf("%c\n", x[i]);

            } else {
                printf("erro\n");

            }
        }
    }

}

int main()
{
    char exp[50];

    printf("\tDigite um expressao: ");
    scanf("%49[^\n]", exp);
    identifica_formacao(exp);
    // printf("\nExpressao: %s\nRetorno: %d\n", exp, identifica_formacao(exp));
}