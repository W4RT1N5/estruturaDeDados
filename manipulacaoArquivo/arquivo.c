#include <stdio.h>
int main(){
    FILE *fp;
    char ch;
    fp = fopen("arquivo.c", "r");
    while(1){
        ch = fgetc(fp); // devolve um caractere e descola um byte (atualiza o ponteiro fp)
        if(ch == EOF){
            break;
        }
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}