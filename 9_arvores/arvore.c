# include <stdio.h>
# include <stdlib.h>

// definir uma árvore binária de pesquisa
struct arvore {
    int info;
    struct arvore *esq;
    struct arvore *dir;
};

// função de inserção na árvore
void inserir(struct arvore *p, int n) {
    if (p == NULL) {
        p = (struct arvore *) malloc(sizeof(struct arvore));
        (p)->info = n;
        (p)->esq = NULL;
        (p)->dir = NULL;
    } else {
        if (n < (p)->info) {
            inserir(p->esq, n);
        } else {
            inserir(p->dir, n);
        }
    }
}

int main(){
    struct arvore *raiz;
    raiz = NULL;
    inserir(raiz, 10);
    inserir(raiz, 5);
    inserir(raiz, 15);
    inserir(raiz, 3);
    inserir(raiz, 12);

    
    return 0;
}