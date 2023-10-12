# include <stdio.h>
# include <stdlib.h>

// Escreva uma função recursiva que retorne a soma dos elementos de um vetor: long int somavet(int *a, int qtde);
long int somavet(int *a, int qtde){
    if(qtde == 0){
        return 0;
    }
    else{
        return a[qtde-1] + somavet(a, qtde-1);
    }
}
// função recursiva que verifica se duas strings são iguais (retorne 1) ou não (retorne 0)
int stringsIguais(char *stra, char *strb){
    if (stra[0] == '\0' && strb[0] == '\0'){
        return 1;
    }
    if (stra[0] == strb[0]){
        return stringsIguais(&stra[1], &strb[1]); // ou stra+1, strb+1
    }
    if (stra[0] != strb[0]){
        return 0;
    }
}
// função recursiva para calcular o n-ésimo termo de Fibonacci
int fibonacii(int n){
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    } else if ( n > 1)    {
        return fibonacii(n-1) + fibonacii(n-2);
    }
    
}
int main(){
    //int vetor[6] = {2,5,3,5,7,4};
    //int tam = 6;
    //printf("%ld", somavet(vetor, tam));
    char stra[] = "Ola mundo";
    char strb[] = "Ola mundo";
    printf("%d\n", stringsIguais(stra, strb));
    
}