# include <stdio.h>

int AckermannRecursivo(int m, int n){
    if (m == 0){
        return n + 1;
    }
    if (m > 0 && n == 0){
        return AckermannRecursivo(m-1,1);
    }
    if (m > 0 && n > 0){
        return AckermannRecursivo(m - 1, AckermannRecursivo(m, n - 1));
    }
}
int main(){
    int m, n;
    do{
        printf("\nDigite o valor de m: ");
        scanf("%d", &m);
        if (m < 0){
            printf("Numero invalido. Digite um inteiro positivo\n");
        }
    } while (m < 0);
    do{
        printf("\nDigite o valor de n: ");
        scanf("%d", &n);
        if (n < 0){
            printf("Numero invalido. Digite um inteiro positivo\n");
        }
    } while (n < 0);
    printf("%d\n", AckermannRecursivo(m,n));
    return 0;
}