Relação de ordem

# Listas Encadeadas
- Uma lista é uma representação de um conjunto de objetos na memória do computador. Cada elemento da lista é armazenado em um nó ou célula: o primeiro elemento na primeira célula, o segundo na segunda e assim por diante. 
- Utilizar Estruturas de Dados que cresçam e diminuam na medida da necessidade: alocação dinâmica de memória conforme demanda
- O tamanho máximo de uma lista é limitado apenas pela quantidade de memória disponível, ou seja,  não precisa ser definido previamente
- Flexibilidade permitindo que os itens sejam rearranjados eficientemente
- O acesso a um nó é feito de forma sequencial: O(n), difrente de um vetor que é O(1)
- Uma lista encadeada é uma sequência de nós não contíguos
- Cada célula contém um campo que armazena o valor do elemento e um campo que armazena o endereço da célula seguinte. O endereço da primeira célula é armazenado em uma variável chamada de ponteiro para o início da lista.

```c
struct TNo {
    int dado;
    struct TNo *Prox;
};
```

## Verificar se a lista está vazia
```c
bool Vazia(TNo *pLista){
    if(pLista == NULL)
        return true;
    else
        return false;
}
```

## Inclusão na cabeça

```c
TNo *IncluiCabeca(TNo *pLista, int pValor){
    TNo *pNovoNo;
    pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->dado = pValor;
    pNovoNo->Prox = pLista; // aponta pNovoNo para o antigo primeiro elemento da lista
    pLista = pNovoNo; // aponta pLista para o novo primeiro elemento da lista
    return pLista;
} // O(1)
```

## Inclusão na cauda

```c
TNo *IncluiCalda(TNo *pLista, int pValor){
    TNo *pNovoNo, *pAux;
    pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->dado = pValor;
    pNovoNo->Prox = NULL;
    pAux = pLista;
    while (pAux->Prox != NULL)
        pAux = pAux->Prox;
    pAux->Prox = pNovoNo;
    return pLista;
} // O(n)
```

## Inclusão antes de uma chave
```c
TNo *IncluiAntes(TNo *pLista, int pChave, int pValor){
    TNo *pNovoNo, *pAux;
    pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->dado = pValor;
    pAux = pLista;
    while (pAux->Prox->dado != pChave)
        pAux = pAux->Prox;
    pNovoNo->Prox = pAux->Prox;
    pAux->Prox = pNovoNo;
    return pLista;
}
```

## Exclusão na cabeça
```c
TNo *ExcluiCabeca(TNo *pLista){
    TNo *pAux;
    pAux = pLista;
    pLista = pLista->Prox;
    free(pAux);
    return pLista;
}
```

## Exclusão na calda
```c
TNo *ExcluiCalda(TNo *pLista){
    TNo *pAux;
    pAux = pLista;
    while (pAux->Prox->Prox != NULL)
        pAux = pAux->Prox;
    free(pAux->Prox);
    pAux->Prox = NULL;
    return pLista;
}
```

## Exclusão de uma chave
```c
TNo *ExcluiChave(TNo *pLista, int pChave){
    TNo *pAnt, *pPost;
    pAnt = pLista;
    while (pAnt->Prox->dado != pChave)
        pAnt = pAnt->Prox;
    pPost = pAnt->Prox->Prox;
    free(pAnt->Prox);
    pAnt->Prox = pPost ;
    return pLista;
}
```

## Descritor
- O descritor é um struct que contém o tamanho da lista e dois ponteiros: um para o primeiro elemento e outro para o último elemento da lista.
```c
struct TLista{
    TNo *Primeiro;
    int Qtde;
    TNo *Ultimo;
};
```
Dessa forma, é possível reduzir a complexidade da remoção de um elemento do final da lista de O(n) para O(1).

# Lista Duplamente Encadeada
- Uma lista duplamente encadeada é uma estrutura composta por nós, onde cada nó tem uma informação e dois ponteiros: um para o próximo nó e outro para o nó anterior.
- Conhecido o primeiro elemento da lista (cabeça) e o último elemento da lista (cauda), é possível percorrer a lista em qualquer direção.
- Diferente das listas encadeadas, as listas duplamente encadeadas reduzem a complexidade da remoção de um elemento do final da lista de O(n) para O(1);

```c
struct TNo{
    TNo *Ant;
    int Numero;
    TNo *Prox;
};
```

## Verificar se a lista está vazia
```c
bool Vazia(TNo *pLista){
    if(pLista == NULL)
        return true;
    else
        return false;
}
```

## Inclusão na cabeça
```c
TNo *IncluiCabeca(TNo *pLista, int pValor){
    TNo *pNovoNo;
    pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    pNovoNo->Ant = NULL;
    pNovoNo->Prox = pLista;
    pLista->Ant = pNovoNo;
    pLista = pNovoNo;
    return pLista;
}
```

## Inclusão na cauda
```c
TNo *IncluiCalda(TNo *pLista, int pValor){
    TNo *pNovoNo, *pAux;
    pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    pNovoNo->Prox = NULL;
    pAux = pLista;
    while (pAux->Prox != NULL)
        pAux = pAux->Prox;
    pAux->Prox = pNovoNo;
    pNovoNo->Ant = pAux;
    return pLista;
}
```

## Inclusão depois de uma chave
```c
TNo *IncluiDepois(TNo *pLista, int pChave, int pValor){
    TNo *pNovoNo, *pAux;
    pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    pAux = pLista;
    while (pAux->Prox->Valor != pChave)
        pAux = pAux->Prox;
    pNovoNo->Prox = pAux->Prox;
    pNovoNo->Ant = pAux;
    pAux->Prox = pNovoNo;
    pNovoNo->Prox->Ant = pNovoNo;
    return pLista;
}
```

## Exclusão na cabeça
```c
TNo *ExcluiCabeca(TNo *pLista){
    pLista = pLista->Prox;
    free(pLista->Ant);
    pLista->Ant = NULL;
    return pLista;
}
```

## Exclusão na cauda
```c
TNo *ExcluiCalda(TNo *pLista){
    TNo *pAux;
    pAux = pLista;
    while (pAux->Prox->Prox != NULL)
        pAux = pAux->Prox;
    free(pAux->Prox);
    pAux->Prox = NULL;
    return pLista;
}
```

## Exclusão de uma chave
```c
TNo *ExcluiChave(TNo *pLista, int pChave){
    TNo *pAux;
    pAux = pLista;
    while (pAux->Numero != pChave)
        pAux = pAux->Prox;
    pAux->Ant->Prox = pAux->Prox;
    pAux->Prox->Ant = pAux->Ant;
    free(pAux);
    return pLista;
}
```

## Descritor
- O descritor é um struct que contém o tamanho da lista e dois ponteiros: um para o primeiro elemento e outro para o último elemento da lista.
```c
struct TLista{
    TNo *Primeiro;
    int Qtde;
    TNo *Ultimo;
};
```
Dessa forma, é possível reduzir a complexidade da remoção de um elemento do final da lista de O(n) para O(1).

# Pilha
- A Pilha é uma estrutura de dados com regras de acesso: O último elemento armazenado é o primeiro a ser removido
- LIFO (Last In First Out)
- Não permite acesso aleatório aos dados
    - A inclusão de um novo elemento é feito por meio de **Emiplhamento**
    - A exclusão do elemento é feito por meio de **Desemiplhamento**

- As operações elementares são:
    - Esvaziar a pilha
    - Verificar se a pilha está vazia
    - Incluir um elemento na pilha
    - Excluir um elemento da pilha
    - Acessar o elemento do topo da pilha

- A pilha pode ser implementada tanto com vetor como com lista encadeada (os métodos de empilhamento e desempilhamento são os de inclusão e exclusão na cabeça da lista)

# Fila
- A Fila é uma estrutura de dados com regras de acesso: O primeiro elemento armazenado é o primeiro a ser removido
- FIFO (First In First Out)
- A inclusão de um novo elemento é feita por meio de **Enfileiramento** (inclusão na calda)
- A exclusão de elemento é feita por meio de **Desenfileiramento** (exclusão da cabeça)

- As operações elementares são:
    - Esvaziar a fila
    - Verificar se a fila está vazia
    - Verificar se a fila está cheia
    - Enfileirar um elemento
    - Desenfileirar um elemento
    - Consultar o elemento do início da fila

- Pode ser implementada usando vetor circular, lista encadeada, lista encadeada com descritor, duplamente encadeada ou duplamente encadeada com descritor