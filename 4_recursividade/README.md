# Recursividade
Uma função recursiva é um função que resolve parte de um problema, e para continuar chama ela mesma.  
## Exemplo: Fatorial
* se x = 1 ou x = 0, fatorial(x) = 1
* senão, fatorial(x) = x * fatorial(x-1)  
Sempre que a função recursiva é executada, um novo espaço é reservado na pilha (empilhamento de memória). Quando a função retorna, o espaço é liberado e ocorre a instanciação de valores (desempilhamento de memória).
## Observações
$\color{red}\text{Cuidado com as funções recursivas infinitas}$  
A recursividade nem sempre é a melhor solução para um problema.
## Outros exemplos
```c
int fatorial(int x){
    if (x == 0 || x == 1){
        return 1;
    }
    else {
        return x * fatorial(x-1);
    }
}
```
```c
int pot(int base, int exp){
    if (!exp){
        return 1;
    }
    else {
        return base * pot(base, exp-1);
    }
}
```
```c
# Imprimindo a string ao contrário
void contrario(char s[]){
    if (s[0] != '\0'){
        contrario(&s[1]);
        printf("%c", s[0]);
    }
}
int main(){
    char s[30], c;
    int t;
    printf("Imprime o reverso:\n");
    printf("Digite uma string: ");
    gets(s);
    contrario(s);
    getchar();
    return 0;
}
```
