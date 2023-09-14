# Manipulação de arquivos
## Operações com arquivos
* criação de um novo arquivo
* abertura de um arquivo existente
* leitura e escrita de um arquivo
* mover a um local específico no arquivo (seeking)
* fechamento de arquivo

```c
#include <stdio.h>
int  main(){
    FILE *fp;
}
```
### Abertura de arquivo
A função `fopen(arquivo, metodo)` recebe dois parâmetros:
* o arquivo que será aberto com a extensão
* o método de abertura

Busca no disco pelo arquivo. O arquivo é carregado do disco em um espaço em memória chamado *buffer*<br>
É muito mais rápido manipular o arquivo em memória que em disco

| Modo de abertura | Descrição |
| --------- | --------- |
| "r" | Abre um arquivo para leitura. O arquivo deve existir. |
| "w" | Cria um arquivo vazio para gravação. Se já existir um arquivo com o mesmo nome, seu conteúdo será apagado e o arquivo será considerado como um novo arquivo vazio. |
| "a" | Acrescenta a um arquivo. Operações de gravação, anexa dados no final do arquivo. O arquivo é criado se não existir. |
| "r+" | Abre um arquivo para atualizar a leitura e a escrita. O arquivo deve existir. |
| "w+" | Cria um arquivo vazio para leitura e gravação. |
| "a+" | Abre um arquivo para leitura e acréscimo |

```c
FILE *fp;
fp = fopen("arquivo","r");
```
caso a abertura falha, a função fopen() retorna um valor NULL

### Leitura de um arquivo
O `fgetc(ponteiro)` retorna o primeiro byte e aponta o ponteiro para o próximo byte
```c
char ch = fgetc(fp);
```
### Fechamento de um arquivo
Realiza três operações:
* Os caracteres no buffer serão escritos no arquivo no disco
* No final do arquivo um caractere ASCII 26 será escrito (EOF)
* buffer será eliminado da memória
```c
fclose(fp);
```

### Escrita de um arquivo
A função `fputc(caractere, ponteiro)` é usada para escrever um caractere em um arquivo e recebe dois parâmetros:
* variável caractere
* ponteiro que aponta para o arquivo

```c
fputc(ch, fp);
```
Nesse caso, o modo de abertura do arquivo não pode ser o "r"

A função `fputs(string, ponteiro)` escreve uma string e recebe dois parâmetros:
* a string
* o ponteiro que aponta para o arquivo
```c
FILE *fp;
char s[80];
fp = fopen ("arquivo.txt", "w");
printf("Digite uma string\n");
while(strlen(gets(s))>0){
    fputs(s, fp);
    fputs("\n", fp);
}
```

### Lendo uma string
A função `fgets(string, tamanho, ponteiro)` recebe três parâmetros:
* A variável string
* O tamanho da string
* O ponteiro que aponta para o arquivo

```c
FILE *fp;
char s[80];
fopen("arquivo.txt", "r");
fgets(s, 79, fp)
```

### Outras funções
A função `fprint()` usada para printar no arquivo e a função `fscanf()` usada para escanear o arquivo
```c
fprintf(fp, "%s %d %f", s, num, num2);
fscanf(fp, "%s %d %f", s, &num, &num2);
```

A função `fflush(stdin)` limpa o buffer da entrada padrão