/* Escrever umm programa que leia um arquivo e conte quantos caracteres, espacos,  tabs, e newlines estao presentes
espaco = 32
tabs = tabulacao
newlines = "\n"
*/

#include <stdio.h>
int main(){
    FILE *fp;
    char ch;
    int caracteres=0, espacos=0, tabs=0, newlines = 0;
    fp = fopen("exercicio.c", "r");
    while(1){
        ch = fgetc(fp); // devolve um caractere e descola um byte (atualiza o ponteiro fp)
        if(ch == EOF){
            break;
        } else if (ch == 32){
            espacos++;
        } else if (ch == 9){
            tabs++;
        } else if (ch == 10){
            newlines++;
        } else if (ch >= 33 && ch <= 126){
            caracteres++;
        }
    }
    fclose(fp);
    printf("Caracteres: %d\nEspacos: %d\nTabs: %d\nNewlines: %d\n\t", caracteres, espacos, tabs, newlines);
    return 0;
}