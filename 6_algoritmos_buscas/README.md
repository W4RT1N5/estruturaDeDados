[Voltar à página inicial](../README.md#sumário)
# Buscas

## Conceitos Iniciais

- Busca é recuperar um dado que está armazenada em um conjunto de dados, por exemplo, um banco de dados, arquivo, ou vetor. A apresentação ordenada ou desordenada deste conjunto de dados impacta no tipo de busca.
- Tipos de buscas
  - Dados desordenados: busca sequencial
  - Dados ordenados: busca binária
- Para a busca em memória, os dados são armezenados em um vetor, que pode ser ordenado ou desordenado
- Algoritmos
  - Busca linear em vetor desordenado
  - Busca linear em vetor ordenado
  - Busca binária em vetor ordenado

## Busca Sequencial

### Vetor Desordenado

A busca sequencial é feita em um vetor desordenado, ou seja, não há uma ordem lógica para os dados. Neste caso, a busca é feita de forma linear, ou seja, elemento por elemento, até que o elemento seja encontrado ou que o vetor acabe.

```c
// Busca chave no vetor desordenado V[0..n-1]
int buscaSequencialDesordenada(int *V, int n, int chave){
    int p, posic = -1;
    for(p=0;p<n;p++){
        if(chave == V[p]){
            posic = p;
        }
    }
    return posic;
}
```

O algoritmo acima tem complexidade O(n), pois o pior caso é quando o elemento não está no vetor, ou seja, é necessário percorrer todo o vetor. O melhor caso também é O(n), pois o algoritmo continua percorrendo o vetor até o final, mesmo que o elemento seja encontrado no início.

```c
// Busca chave no vetor desordenado V[0..n-1]
int buscaSequencialDesordenada(int *V, int n, int chave){
    int p, posic = -1;
    for(p=0;p<n;p++){
        if(chave == V[p]){
            posic = p;
            break;
        }
    }
    return posic;
}
```

Já nesse algoritmo, o melhor caso é O(1), pois o elemento é encontrado no início do vetor. O pior caso continua sendo O(n), pois o elemento não está no vetor, ou seja, é necessário percorrer todo o vetor.

### Vetor Ordenado

```c
// Busca chave no vetor ordenado V[0..n-1]
int buscaSequencialOrdenada(int *V, int n, int chave) {
    int p=0, posic = -1;
    while (p < n && chave <= V[p]){
        if(V[p]==chave){
            posic = p;
            break;
        }
        p++;
    }
    return posic;
}
```

Esse algoritmo tem complexidade O(n), pois o pior caso é quando o elemento não está no vetor, ou seja, é necessário percorrer todo o vetor. Já o melhor caso é O(1).

Além disso, esse algoritmo é mais eficiente que o anterior, pois o vetor está ordenado, então, quando o elemento for maior que o elemento do vetor, não é necessário continuar a busca.

Para ter uma solução que retorna a posição da última ocorrência de chave, basta começar a busca pelo final do vetor e mudar a condição da chave.

## Busca Binária

```c
// Busca chave no vetor ordenado V[0..n-1]
int buscaBinaria(int *V, int n, int chave){
    int inicio, final, meio;
    inicio = 0;
    final = n - 1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if (chave == V[meio])
            return meio;
        if (chave < V[meio])
            final = meio - 1; // busca nos valores menores
        else
            inicio = meio + 1; // busca nos valores maiores
    }
    return -1; // chave não encontrada
}
```

A busca binária tem complexidade O(log n), pois a cada iteração, o tamanho do vetor é reduzido pela metade. O pior caso é O(log n), pois o elemento não está no vetor, ou seja, é necessário percorrer todo o vetor. O melhor caso é O(1), pois o elemento é encontrado no meio do vetor.

# Aplicação

- Enunciado: O arquivo de dados do censo 2010 do IBGE está
  ordenado pelo código de município (campo IBGE). Faça um programa com as seguintes opções: 
    - Faça a carga de um vetor contendo IBGE e Linha onde Linha refere-se ao número da linha do arquivo 
    - Leia um código de município e mostre na tela as seguintes informações deste município: Município, UF. Região, Populaçãoem 2010 e Porte. Mostre ainda o tempo de execução desta busca com Busca Binária e Busca Sequencial 
    - Sair. Não deixe lixo na memória.
- Dados: [Base de dados](http://blog.mds.gov.br/redesuas/lista-de-municipios-brasileiros/)

- Dica: pré-processar o arquivo para garantir que todas as linhas tenham o mesmo tamanho
