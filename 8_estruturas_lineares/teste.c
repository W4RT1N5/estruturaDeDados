# include <stdio.h>
# include <stdlib.h>

typedef struct TNo
{
    int dado;
    struct TNo *Prox;
} TNo;

typedef struct pilha
{
    char caracter;
    struct pilha *prox;
} pilha;

TNo *IncluiCabeca(TNo *pLista, int pValor)
{
    TNo *pNovoNo;
    pNovoNo = (TNo *)malloc(sizeof(TNo));
    pNovoNo->dado = pValor;
    pNovoNo->Prox = pLista;
    pLista = pNovoNo;
    // pNovoNo->Prox = pLista->Prox;
    // pLista->Prox = pNovoNo;
    // return pLista;
}

TNo *IncluiCalda(TNo *pLista, int pValor)
{
    TNo *pNovoNo, *pAux;
    pNovoNo = (TNo *)malloc(sizeof(TNo));
    pNovoNo->dado = pValor;
    pNovoNo->Prox = NULL;
    pAux = pLista;
    while (pAux->Prox != NULL)
        pAux = pAux->Prox;
    pAux->Prox = pNovoNo;
    return pLista;
}

TNo *IncluiAntes(TNo *pLista, int pChave, int pValor)
{
    TNo *pNovoNo, *pAux;
    pNovoNo = (TNo *)malloc(sizeof(TNo));
    pNovoNo->dado = pValor;
    pAux = pLista;
    while (pAux->Prox->dado != pChave)
        pAux = pAux->Prox;
    pNovoNo->Prox = pAux->Prox;
    pAux->Prox = pNovoNo;
    return pLista;
}

int func(char x[]){
    pilha *p;
    p = NULL;
    int i = 0;
    while (x[i] != '\0')
    {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            p = empilhar(p, x[i]);
        }
        else if (x[i] == ')' || x[i] == ']' || x[i] == '}')
        {
            if (p == NULL)
            {
                return 1;
            }
            else if (forma_par(x[i], p->caracter))
            {
                p = desempilhar(p);
            }
            else
            {
                return 1;
            }
        }
        i++;
    }
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(){
    TNo *pLista;
    pLista = (TNo *)malloc(sizeof(TNo));
    pLista->Prox = NULL;
    pLista->dado = 0;
    pLista = IncluiCabeca(pLista, 10);
    pLista = IncluiCabeca(pLista, 20);
    pLista = IncluiCabeca(pLista, 30);
    // pLista = IncluiCalda(pLista, 40);
    // pLista = IncluiCalda(pLista, 50);
    pLista = IncluiAntes(pLista, 20, 40);
    // printar lista
    TNo *pAux;
    pAux = pLista;
    while (pAux != NULL)
    {
        printf("%d\n", pAux->dado);
        pAux = pAux->Prox;
    }
}