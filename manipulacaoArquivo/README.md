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
A função fopen recebe dois parâmetros:
* o arquivo que será aberto com a extensão
* o método de abertura
Busca no disco pelo arquivo. O arquivo é carregado do disco em um espaço em memória chamado buffer
É muito mais rápido manipular o arquivo em memória que em disco

| Mode | Description |
| ------ | ------ |
| "r" | Opens a file for reading. The file must exist. |
| "w" | Creates an empty file for writing. If a file with the same name already exists, its content is erased and the file is considered as a new empty file. |
| "a" | Appends to a file. Writing operations, append data at the end of the file. The file is created if it does not exist. |
| "r+" | Opens a file to update both reading and writing. The file must exist. |
| "w+" | Creates an empty file for both reading and writing. |
| "a+" | Opens a file for reading and appending |
```c
FILE *fp;
fp = fopen("arquivo","r");
```
caso a abertura falha, a função fopen() retorna um valor NULL

### Leitura de um arquivo
O fgetc retorna o primeiro byte e aponta o ponteiro para o próximo byte
```c
char ch = fgetc(fp);
```
### Fechamento de umm arquivo
Realiza três operações:
* Os caracteres no buffer serão escritos no arquivo no disco
* No final do arquivo um caractere ASCII 26 será escrito (EOF)
* buffer será eliminado da memória
```c
fclose(fp)
```
