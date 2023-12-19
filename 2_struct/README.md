[Voltar à página inicial](../README.md#sumário)
# Struct
Struct é uma estrutura de dados composta que define fisicamente uma lista de variáveis agrupadas sob um único nome em um bloco de memória.  

```c
/* Estrutura geral */
struct tag_estrutura {
    tipo1 nome1;
    tipo2 nome2;
    ...
    tipoN nomeN;
}[umas ou mais variáveis da estrutura];
/* Exemplo prático */
struct ponto {
    int x;
    int y;
}p1, p2;
struct livro{
    char titulo[50];
    char autor[50];
    char assunto[100];
    int id_livro;
} livro1;
// criando outra variável do tipo struct livro
struct livro livro2;
// incializando a variável livro1
livro1 = {"C Programming", "Nuha Ali", "C Programming Tutorial", 6495407};
livro2.nome = "Titulo generico";
livro2.autor = "Autor generico";
livro2.assunto = "Assunto generico";
livro2.id_livro = 123456;
// outra forma (mais utilizada)
#include <string.h>
strcpy(livro2.titulo, "Titulo generico 2"); // para strings
```
O acesso aos membros da estrutura é feito de forma individual. Não é possível ler, por exemplo, um struct de uma vez (os campos são tratados de forma individual). Por exemplo, para escanear do usuário os dados do livro1, podemos fazer:
```c
scanf("%s", livro1.titulo);
scanf("%s", livro1.autor);
scanf("%s", livro1.assunto);
scanf("%d", &livro1.id_livro);
printf("Titulo: %s\n", livro1.titulo);
printf("Autor: %s\n", livro1.autor);
printf("Assunto: %s\n", livro1.assunto);
printf("ID: %d\n", livro1.id_livro);
```
## Typedef
Renomeia uma estrutura de dados para algo mais simples. Exemplo:
```c
typedef unsigned char byte;
byte b1, b2;
```
Podemos usar o typedef com o struct:
```c
typedef struct ponto {
    int x;
    int y;
} Ponto;
// criando variáveis do tipo struct ponto (Ponto)
Ponto p1, p2;
Ponto conjunto[10];
conjunto[4].x = 10;
p1 = conjunto[2]; // é possível fazer isso sem ser de forma individual
```
## Struct em funções
É possível passar uma struct como parâmetro ou como retorno de uma função. Exemplo:
```c
#include <stdio.h>
#include <string.h>

typedef struct pessoa{
    char nome[20];
    char sexo;
    int idade;
} Pessoa;

void imprimePessoa(Pessoa p){
    printf("Nome: %s\nSexo: %c\nIdade: %d", p.nome, p.sexo, p.idade);
}
Pessoa SetPessoa(const char *nome, char sexo, int idade){
    Pessoa p;
    // garante que o nome não exceda 19 caracteres
    strncpy(p.nome, nome, sizeof(p.nome) - 1);
    p.nome[sizeof(p.nome) - 1] = '\0'; // Garante que o nome esteja terminado com null byte.
    p.sexo = sexo;
    p.idade = idade;
    return p;
}
int main(){
    Pessoa lucas = SetPessoa("lucas", 'M', 19);
    imprimePessoa(lucas);
    return 0;
}

```