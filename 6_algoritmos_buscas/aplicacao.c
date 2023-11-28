#include <stdio.h>
#include <stdlib.h>
/*
Enunciado:O arquivo de dados do censo 2010 do IBGE está ordenado pelo código de município(campo IBGE).
Faça um programa com as seguintes opções:
    -Faça a carga de um vetor contendo IBGE e Linha onde Linha refere-se ao número da linha do arquivo
    - Leia um código de município e mostre na tela as seguintes informações deste município:Município, UF.Região, Populaçãoem 2010 e Porte.
    - Mostre ainda o tempo de execução desta busca com Busca Binária e Busca Sequencial
- Sair.Não deixe lixo na memória.

- O arquivo foi padronizado de forma que cada linha tem 196 caracteres
*/

typedef struct {
    int Linha;
    int IBGE;
} municipio;

int linhasDoArquivo(FILE *arquivo){
    int qtdLinhas = 0;
    while (1)
    {
        char c = fgetc(arquivo);
        if (c == '\n')
            qtdLinhas++;
        if (c == EOF)
            break;
    }
    return qtdLinhas + 1;
}

int buscaBinaria(int chave, municipio *vetor, int tam){
    int inicio, final, meio;
    inicio = 0;
    final = tam - 1;
    while (inicio <= final)
    {
        meio = (inicio + final) / 2;
        if (chave == vetor[meio].IBGE)
            return meio;
        if (chave < vetor[meio].IBGE){
            final = meio - 1; // busca nos valores menores
        }
        else {
            inicio = meio + 1; // busca nos valores maiores
        } 
    }
    return -1; // chave não encontrada
}

void printarLinha(FILE *fp, int linha){
    char str[197];
    fseek(fp, 197 * linha, SEEK_SET);
    fgets(str, 197, fp);
    for (int i = 0; i < 197; i++){
        if (str[i] != ' '){
            printf("%c", str[i]);
        }
    }
}

void lerCSV(FILE *fp, municipio *vetor, int tam){
    char strIBGE[8];
    int i = 0;
    while (i < tam){
        fseek(fp, 197 * i, SEEK_SET);
        fgets(strIBGE, 8, fp);
        vetor[i].Linha = i;
        vetor[i].IBGE = atoi(strIBGE);
        i++;
    }
}

int main(){
    char *nomeArquivo = "listaPadronizada.csv";
    FILE *fp;
    fp = fopen(nomeArquivo, "r");
    int tam = linhasDoArquivo(fp);
    // fseek(fp, 0, SEEK_SET);
    rewind(fp);
    municipio *vetor = (municipio *)malloc(sizeof(municipio) * tam);
    lerCSV(fp, vetor, tam);

    int chave;
    scanf("%d", &chave);

    int linha = buscaBinaria(chave, vetor, tam);

    printarLinha(fp,linha);

    free(vetor);

    return 0;
}