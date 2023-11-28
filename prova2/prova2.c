#include <stdio.h>

int q1(char *nome, int qtde){
    int i = 0;
    if (*nome == '\0'){
        return qtde;
    }
    printf("%c", '\n');
    while (nome[i] != '\0'){
        printf("%c", nome[i]);
        i++;
    }
    return q1(nome+1, qtde+1);
}

char letraCorrespondente(int P)
{
    P = P % 26;
    return 'a' + P;
}

int q2(char *nome, int matricula)
{
    int p = 0;
    int posic = -1;
    char chave = letraCorrespondente(matricula % 100);
    while (nome[p] != '\0')
    {
        if (chave == nome[p])
        {
            posic = p;
        }
        p++;
    }
    return posic;
}

int q3(char *nome, int matricula, int qtde)
{
    char pcont = 0;
    char chave = nome[matricula % 10];
    int inicio = 0, final = qtde - 1, meio;
    while (inicio <= final)
    {
        pcont++;
        meio = (inicio + final) / 2;
        if (chave == nome[meio])
            break;
        if (chave < nome[meio])
            final = meio - 1;
        else
            inicio = meio + 1;
    }
    return pcont;
}

int q4(char *vet, int tam)
{
    int i, j; 
    int pcont = 0;
    char aux;
    for (i = 0; i < tam; i++)
    {
        for (j = i+1; j < tam; j++)
        {
            if (vet[i] < vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                pcont++;
            }
        }
    }
    return pcont;
}

int q5(char vetor[], int tamanho)
{
    int trocas = 0;
    int j, i;
    char chave;
    for (i = 0; i < tamanho; i++)
    {
        chave = vetor[i];
        j = i-1;
        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j+1] = vetor[j];
            j--;
            trocas++;
        }
        vetor[j+1] = chave;
    }
    return trocas;
}

int main()
{
    printf("\nq1: %d\n", q1("lucas", 0));
    printf("q2: %d\n", q2("lucas martins gabriel", 221022088));
    printf("q3: %d\n", q3("  aaabcegiillmnrrsstu", 221022088, 21));
    char nome[] = "lucas";
    char ultimoSobrenome[] = "gabriel";
    printf("q4: %d\n", q4(nome, 5));
    printf("q5: %d\n", q5(ultimoSobrenome, 7));

    return 0;
}
