/*Esse programa precisa ler um arquivo e identificar todas as palavras sem acentos com mais de 3 caracteres.
O programa deve armazenar essas palavras em outro arquivo */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int existeNoArquivoSaida(char* nomeArq, FILE *arq, char *palavra){
    /* abro o arquivo e modo de leitura */
    arq = fopen(nomeArq, "r+");
    while(fgetc(arq) != EOF){
        char string[60];
        fscanf(arq, "%s", string);
        /*strcmp retorna 0 se as strings forem iguais*/
        if (strcmp(string, palavra) == 0)
            return 1;
    }
    /* fecho o arquivo */
    fclose(arq);
    return 0;
}
/*Função verifica se uma string tem acento e retorna 1 se tiver*/
int temAcento(char* s){
    int acento = 0;
    for (int i=0; i < strlen(s); i++)
        if (!((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))){
            acento = 1;
        }
    return acento; 
}
/* Função que retorna uma string em lower case */
char* toLower(char* s) {
  for(char *p=s; *p; p++) *p=tolower(*p);
  return s;
}
/* Função que retorna a posição do ponto no nome do arquivo */
int namefilepointposition(char *fullname){
   int i;
   for(i=0;i<strlen(fullname);i++){
       if(fullname[i]=='.')
        break;
   } 
   if(i>=strlen(fullname))
        return -1;
    else
        return i;
}

int word2vec(char *pNomeTxtEntrada){
    FILE *arqent, *arqsaida;
    char nomarq[40];
    int pointidx = namefilepointposition(pNomeTxtEntrada);
    int pp;
    /*Gerar o nome do arquivo de saída*/   
    if(pointidx>=0){
        for(pp=0;pp<pointidx;pp++)
            nomarq[pp] = pNomeTxtEntrada[pp];
        /*Final da String*/
        nomarq[pp] = '\0';
    }
    else{
        strcpy(nomarq,  pNomeTxtEntrada);
    }
    strcat(nomarq,  "_Vocabulo");
    strcat(nomarq,  ".txt");
    printf("\nRecebi no nome do arquivo: %s\n", nomarq);

    /*Abrindo os arquivos:*/
    arqent = fopen(pNomeTxtEntrada, "r");
    arqsaida = fopen(nomarq, "w+");
    if(arqent == NULL || nomarq == NULL){
        puts("Nao foi possivel abrir o arquivo\n");
        return 0;
    }
    /* variaveis para a o laço onde será lidas as strings */
    int tamString = 0;
    int ponteiro = 0;
    int espaco;
    int inicioPalavra = 0;
    while(1){        
        char ch = fgetc(arqent);
        /*incrementa o ponteiro cada vez que lê um caractere*/
        ponteiro++;
        /*incrementa o tamanho da string se o caractere for válido*/
        if((ch != ' ' && ch != '\n' && ch != ',' && ch != '.' && ch != ';' && ch != ':' && ch != '?' && ch != '!') && ((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z'))){
            tamString++;
        }
        if(ch == ' ' || ch == '\n' || ch == EOF){
            /*define a posição do espaço*/
            espaco = ponteiro;
            /* aponta o ponteiro para o início da palavra */
            fseek(arqent, inicioPalavra, SEEK_SET);
            /* define uma string e le do arquivo de entrada */
            char string[tamString+1];
            fgets(string, tamString+1, arqent);
            /* Condições para adicionar a string ao arquivo de saída: 
            * tamanho maior ou igual a 4
            * não ter acentos
            * ainda não existir no arquivo */
            if (tamString >= 4){
                /* fecho o arquivo que foi aberto no modo w */
                fclose(arqsaida);
                if (temAcento(string) == 0 && existeNoArquivoSaida(nomarq, arqsaida, toLower(string)) == 0){
                    char *stringLower = toLower(string);
                    /* abro o arquivo agora no modo a (acrescentar) */
                    fopen(nomarq, "a+");
                    fputs(stringLower, arqsaida);
                    fputs("\n", arqsaida);
                } else{
                    /* se a string não válida, apenas abre o arquivo novamente*/
                    fopen(nomarq, "a+");
                }
                /* OUTRA SOLUÇÃO */
                /*if (temAcento(string) == 0){
                    char *stringLower = toLower(string);
                    /* fecho o arquivo que foi aberto no modo w
                    fclose(arqsaida);
                    /* a função existeNoArquivoSaida abre o arquivo no modo r e depois fecha
                    if (existeNoArquivoSaida(nomarq, arqsaida, stringLower) == 0){
                        /* abro o arquivo agora no modo a (acrescentar)
                        fopen(nomarq, "a+");
                        fputs(stringLower, arqsaida);
                        fputs("\n", arqsaida);
                    }
                    fopen(nomarq, "a+");
                }*/
            }
            /* Ponteiro reposicionado para a posição em que estava anteriormente */
            fseek(arqent, ponteiro, SEEK_SET);
            /* atualiza a posição do início da próxima palavra e o tamanho da string */
            inicioPalavra = ponteiro;
            tamString = 0;
        }
        /* se o caractere lido for o final do arquivo, o laço é finalizado*/
        if (ch == EOF){
            break;
        }
    }
    /* Fecha o arquivo e grava as informações */
    fclose(arqent);
    fclose(arqsaida);

    return 1;
}


int main(){
    char nomearq[30];
    printf("Entre com nome do arquivo:");
    scanf("%s",nomearq);
    if (!word2vec(nomearq))
        printf("\nErro na geracao do vocábulo!\n");
    else
        printf("\nGerei o vocabulo!\n");
    

    return 0;
}