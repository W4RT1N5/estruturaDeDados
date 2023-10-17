# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Escreva uma função recursiva que calcule a soma dos dígitos de um número inteiro.
int somaDigitos(int num){
    if (num == 0){
        return 0;
    }
    else {
        if (num < 0){
            num = num * (-1);
        }
        return num % 10 + somaDigitos(num / 10);
    }
}
// Escreva uma função recursiva que calcule o produto de dois números inteiros positivos a e b, usando apenas somas e subtrações
int produto(int a, int b){
    if (a == 0 || b == 0){
        return 0;
    } 
    if (b > 0) {
        return a + produto(a,b-1); 
    }
    if (b < 0) {
        return -a + produto(a,b+1); 
    }
}
// Escreva uma função recursiva que calcule o valor de x elevado à potência n, onde x e n são números inteiros positivos.
int potencia(int x, int n){
    if (n == 0){
        return 1;
    }
    else if (x == 0){
        return 0;
    } else {
        return x * potencia(x, n-1);
    }
}
//Escreva uma função recursiva que determine se uma string é um palíndromo (ou seja, se pode ser lida igualmente de trás para frente).
// tem como implementar essa função apenas com a variavél tamanho e deslocando o ponteiro da string?
int stringPalindromo(char *str, int inicio, int fim){
    if (inicio >= fim){
        return 1;
    }
    if (str[inicio] != str[fim]){
        return 0;
    }
    printf("%c e %c\n", str[inicio], str[fim]);
    return stringPalindromo(str, inicio + 1, fim - 1);
}
// Escreva uma função recursiva que calcule o máximo divisor comum (MDC) de dois números inteiros
int mdc(int a, int b){
    if(a < 0){
        a = -a;
    }
    if (b < 0){
        b = -b;
    }
    if(a == 0){
        return b;
    }
    if (b == 0){
        return a;
    }
    int r;
    r = a % b;
    return mdc(b,r);
}
// Escreva uma função recursiva que calcule o maior elemento em uma vetor de inteiros.
int maiorElemento(int *vetor, int tamanho){
    if (tamanho == 1){
        return vetor[0];
    }
    int maior = maiorElemento(vetor, tamanho - 1);
    return vetor[tamanho - 1] > maior ? vetor[tamanho - 1] : maior;
}

// Escreva uma função recursiva que encontre a posição de um elemento v em um vetor V.
int posicaoElemento(int *v, int tamanho, int elemento){
    if(v[tamanho-1] == elemento){
        return tamanho-1;
    }
    return posicaoElemento(v, tamanho-1, elemento);
}

int main(){
    //printf("%d", somaDigitos(123));

    //printf("%d\n", produto(3,5));
    //printf("%d\n", produto(-3,5));
    //printf("%d\n", produto(3,-5));
    //printf("%d\n", produto(-3,-5));

    //printf("%d\n", potencia(2,0));
    //printf("%d\n", potencia(2,1));
    //printf("%d\n", potencia(2,2));
    //printf("%d\n", potencia(2,3));
    
    //printf("%d", stringPalindromo("abba", 0, 3));

    //printf("%d", mdc(75,20));

    int vetor[4] = {2,5,7,4};
    printf("%d", maiorElemento(vetor,4));

    //int vetor[4]= {7,5,9,1};
    //printf("%d", posicaoElemento(vetor, 4, 5));

    return 0;
}