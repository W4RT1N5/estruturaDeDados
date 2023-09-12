/* Escrever umm programa que leia um arquivo e conte quantos caracteres, espaços,  tabs, e newlines estão presentes
espaco = " "
tabs = "    "
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
        }
    }
    fclose(fp);
    printf("Espacos: %d\nTabs: %d\nNewlines: %d\n", espacos, tabs, newlines);
    return 0;
}