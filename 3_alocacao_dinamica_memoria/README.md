# Introdução a Ponteiros
É uma variável que armazena o endereço de memória de outra variável. Um ponteiro ocupa 8 bytes na memória.
Os ponteiros são declarados usando a seguinte sintaxe:
```c
tipo *nome;
```
```c
#include <stdio.h>
int main()
{
    int numero, *ptr;
    numero = 5654;
    ptr = &numero; // ptr recebe o endereço de memória de numero
    // ptr também pode receber NULL
    // agora é possível acessar o valor de numero de duas formas: numero ou *ptr
    *ptr = 10; // altera o valor de numero
    return 0;
}
```
Possui dois componentes: o endereço (&) e o conteúdo (*). O endereço é o local onde a variável está armazenada na memória e o conteúdo é o valor armazenado na variável.

## Exemplo prático: Swap
Função que troca os valores de duas variáveis. Parâmetros passados por referência.
```c
#include <stdio.h>
void trocarValores(float *ptra, float *ptrb)
{
    float temp = *ptra;
    *ptra = *ptrb;
    *ptrb = temp;
}
int main()
{
    float a = 3.14, b = 2.71;
    printf("valores originais a = %.2f, b = %.2f\n", a, b);
    trocarValores(&a, &b);
    printf("valores trocados a = %.2f, b = %.2f\n", a, b);
    return 0;
}
```
# Alocação Dinâmica de Memória
Necessário sempre que a quantidade de memória requerida só é sabida em tempo de execução (carregamento dos dados de um arquivo ou operações com vetores/matrizes cujas dimensões dependem do contexto do problema, por exemplo).  
Obs: ao alocar memória, também é necessário liberá-la antes de encerrar o programa   

#### Vantagem: 
Controle do uso de memória: uso sob demanda
#### Cuidado: 
Gerenciar lixo de memória
## malloc
```c
# include <stdlib.h>
void *malloc(size_t tamanho);
// tamanho é o número de bytes a serem alocados
```
```c
# include <stdlib.h>
int *numero = (int *) malloc(sizeof(int)* tamanho);
// esse (int *) é um cast, pois malloc retorna um ponteiro void
```
## calloc
```c
# include <stdlib.h>
void *calloc(size_t qtd, size_t tamanho);
// qtd é a quantidade de elementos a serem alocados
// tamanho é o tamanho de cada elemento
```
```c
# include <stdlib.h>
int *numero = (int *) calloc(qtd, sizeof(int));
// preenche com 0
```
## free
Para desalocação de memória	
```c
# include <stdlib.h>
void free(void *ptr);
```