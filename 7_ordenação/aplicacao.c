# include <stdio.h>
# include <stdlib.h>

void trocar(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int linhasDoArquivo(FILE *arquivo)
{
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

void lerCSV(FILE *fp, int *vetor, int tam)
{
    char populacao[14];
    int i = 0;
    while (i < tam)
    {
        fseek(fp, 197 * i + 64, SEEK_SET);
        fgets(populacao, 14, fp);
        vetor[i] = atoi(populacao);
        i++;
    }
}

int separa(int *v, int p, int r){
    int pivo = v[r];
     int swap = p; 
     int aux;
    for (int k=p; k < r; ++k){
        if (v[k] <= pivo){
            // trocar(&v[swap], &v[k]);
            aux = v[swap];
            v[swap] = v[k];
            v[k] = aux;
            ++swap;
        }
    }
    // trocar(&v[r], &v[swap]);
    aux = v[swap];
    v[swap] = v[r];
    v[r] = aux;
    return swap;
}

void quicksort(int *v, int p, int r)
{
    if (p < r){
        int j;
        j = separa(v, p, r);
        quicksort(v, p, j-1);
        quicksort(v, j+1, r);
    }
}

void intercala(int p, int q, int r, int v[])
{
    int *w;
    w = malloc((r - p) * sizeof(int));
    int i = p, j = q;
    int k = 0;

    while (i < q && j < r)
    {
        if (v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i < q)
        w[k++] = v[i++];
    while (j < r)
        w[k++] = v[j++];
    for (i = p; i < r; ++i)
        v[i] = w[i - p];
    free(w);
}

void mergesort(int p, int r, int v[])
{
    if (p < r - 1)
    {
        int q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

int main(){
    // int vetor[] = {5,3,4,7,2,1,9};
    // quicksort(vetor, 0, 6);
    // for (int i=0; i < 7; i++){
        // printf("%d ", vetor[i]);
    // }
    FILE *fp;
    fp = fopen("../6_algoritmos_buscas/ListaPadronizada.csv", "r");
    if (fp != NULL){
        printf("arquivo aberto com sucesso\n");
    }

    int tam = linhasDoArquivo(fp);
    rewind(fp);

    int *populacao = (int *) malloc(sizeof(int) * tam);

    lerCSV(fp, populacao, tam);

    // testes
    // printf("%d\n", populacao[0]);
    // printf("%d\n", populacao[1]);
    // printf("%d\n", populacao[2]);
    // printf("%d\n", populacao[3]);
    // printf("%d\n", populacao[5570]);

    // quicksort(populacao, 0, tam-1);
    mergesort(0, tam, populacao);

    for(int i=0; i < 20; i++){
        printf("%d ", populacao[i]);
    }
    // printf("%d\n", populacao[0]);
    // printf("%d\n", populacao[1]);
    // printf("%d\n", populacao[2]);
    // printf("%d\n", populacao[3]);

    free(populacao);
}