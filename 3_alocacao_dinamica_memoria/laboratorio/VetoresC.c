# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

// função CriaVetInt para alocação de vetores do tipo int que retorna o ponteiro para o vetor alocado
int *CriaVetInt(int n){
    int *vetor = (int *) malloc(sizeof(int) * n);
    return vetor;
}

// função CriaVetFloat para alocação de vetores do tipo float que retorna o ponteiro para o vetor alocado
float *CriaVetFloat(int n){
    float *vetor = (float *) malloc(sizeof(float) * n);
    return vetor;
}

// função para adicionar um char na primeira posição disponível de um vetor
void addChar(char caractere, char *pvetchar, int tamMax, int *qtd){
    if (*qtd < tamMax){
        pvetchar[*qtd] = caractere;
        *qtd += 1;
    }
    else {
        printf("erro");
    }
}
// função que receba um caracter e o exclua de um vetor
void removeChar(char caractere, char *pvetchar, int tamMax, int *qtd){
    for (int i=0; i < *qtd; i++){
        if (pvetchar[i] == caractere){
            pvetchar[i] = pvetchar[*qtd-1];
            *qtd -= 1;
        }
    }

}
// função que adiciona um valor em um vetor ordenado e retorna verdadeiro se conseguir
bool addFloat(float pv, float *pvalores, int pcapacidade, int *ptamanho){
    if (*ptamanho < pcapacidade){
        pvalores[*ptamanho] = pv;
        *ptamanho += 1;
        return true;
    }
    return false;
}
// função que remove um valor em um vetor ordenado e retorna verdadeiro se conseguir
bool removeFloat(float pv, float *pvalores, int pcapacidade, int *ptamanho){
    int indicePV;
    // encontrar a posição do elemento a ser excluido
    for (int i=0; i < *ptamanho; i++){
        if (pvalores[i] == pv){
            indicePV = i;
        }
    }
    *ptamanho -= 1;
    for (int i = indicePV; i < *ptamanho; i++){
        pvalores[i] = pvalores[i + 1];
    }
    return true;
}
bool EIgual(int *pveta, int ptama, int *pvetb, int ptamb){
    int cont = 0;
    if (ptama == ptamb){
        for (int i=0; i < ptama; i++){
            for (int j=0; j < ptama; j++){
                if (pveta[i] == pvetb[j]){
                    cont++;
                    continue;
                }
            }    
        }
        if (cont == ptama) return true;
    }
    return false;
}


int main(){
    /* Criar vetores do tipo int e do tipo float
    // criar um vetor de inteiros usando a função
    int *vetorInt = CriaVetInt(10);
    // preencher a posição 0 do vetor
    *vetorInt = 2;
    // deslocar o vetor para a proxima posição
    vetorInt = vetorInt + 1;
    // preencher a segunda posição do vetor
    *vetorInt = 3;
    printf("%d ", vetorInt[0]); // imprimirá 3
    // vetorInt[0] == *vetorInt
    */
   
   /* Vetores não ordenados
    char vetor[6];
    vetor[0] = 'a';
    vetor[1] = 'b';
    vetor[2] = 'c';
    vetor[3] = 'd';
    int tam = 6;
    int ocup = 4;
    addChar('f', vetor, tam, &ocup);
    printf("\nprintando o vetor\n");
    for (int i = 0; i < ocup; i++){
        printf("%c ", vetor[i]);
    }
    printf("\nocup atual: %d\n", ocup);
    removeChar('c', vetor, tam, &ocup);
    printf("\nprintando o vetor\n");
    for (int i = 0; i < ocup; i++){
        printf("%c ", vetor[i]);
    }
    printf("\nocup atual: %d\n", ocup);
    */

   /* Vetores ordenados float
    float vetor[5] = {1.5,3.7,4.6,7.2,9.1};
    int ocup = 5;
    printf("%d", addFloat(5.2, vetor, 5, &ocup));
    printf("\nprintando o vetor\n");
    for (int i = 0; i < ocup; i++){
        printf("%.2f ", vetor[i]);
    }
    printf("\nocup atual: %d\n", ocup);
    printf("%d", removeFloat(3.7, vetor, 5, &ocup));
    printf("\nprintando o vetor\n");
    for (int i = 0; i < ocup; i++){
        printf("%.2f ", vetor[i]);
    }
    printf("\nocup atual: %d\n", ocup);
    */
   int vetor[6] = {3,4,7};
   int tama = 3;
   int vet[9] = {7,3,4};
   int tamb = 3;
   printf("%d\n", EIgual(vetor, tama, vet, tamb));
    return 0;
}