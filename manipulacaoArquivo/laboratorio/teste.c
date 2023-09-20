#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int existeNoArquivoSaida(FILE *arq, char *palavra){
    while(fgetc(arq) != EOF){
        char string[60];
        fscanf(arq, "%s", string);
        int compara = strcmp(string, palavra);
        if (compara == 0)
            return 0;
    }
    return 1;
}

int main(){
    FILE *arqent;
    // abrir arquivo
    arqent = fopen("texto_Vocabulo.txt", "r+");
    if (arqent == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    printf("%d", existeNoArquivoSaida(arqent, "perceber"));
    fclose(arqent);

}