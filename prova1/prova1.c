# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int q1(int valor){
    int *ptr, *pnumeros, pn = valor % 10, pp, psoma=0;
    pnumeros = (int *) malloc(pn * sizeof(int));
    ptr = pnumeros;
    for (pp = 0; pp < pn; pp++){
        *ptr = valor % 10;
        valor = valor / 10;
        ptr++;
    }
    for (pp = 0; pp < pn; pp++){
        if ((pnumeros[pp] % 2) == 1){
            psoma = psoma + pnumeros[pp];
        }
    }
    return psoma;
}
void q2(char *str){
    int n = strlen(str);
    for (int i =0; i < n-1; i++){
        for (int j = i + 1; j < n; j++){
            if (str[i] > str[j]){
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
char * q3(int *M, char *NC){
    int n;
    char *code = (char *) malloc(9 * sizeof(char));
    for (int i =0; i < 9; i++){
        code[i] = NC[M[i]];
        if (code[i] == ' ') code[i] = '-';
    }
    return code;
}
int Verifica(char c){
    return (c >= 'a' && c <= 'z' && c!= 'a' && c!= 'e' && c!= 'i' && c!= 'o' && c!= 'u');
}
int q4(char *NC, char L, int pos){
    if (NC[0] == '\0'|| pos > 0 || pos <= strlen(NC) - 1){
        return -1;
    }
    if (NC[pos] == L && Verifica(NC[pos+1])){
        return pos;
    }
    return q4(NC, L, pos+1);
}
long q5(char *NC, int R){
    long r;
    FILE *A = fopen("Saida.txt", "w");
    for (int i =0; i < R; i++){
        fprintf(A, "%s", NC);
    }
    fclose(A);
    A = fopen("Saida.txt", "r;");
    fseek(A,0,SEEK_END);
    r = ftell(A);
    fclose(A);
    remove("Saida.txt");
    return r;
}
int main(){
    int matricula[] = {2,2,1,0,2,2,0,8,8};
    char nome[] = "LUCAS MARTINS GABRIEL";
    char *resposta = q3(matricula, nome);
    printf("%s", resposta);
    
    //char NC[] = "lucas martins gabriel";
    //char c = 'l';
    //int pos = 0;
    //printf("%d", q4(NC, c, pos));

    //char NC[] = "lucas martins gabriel";
    //printf("%ld", q5(NC, 11));
}