#include <stdio.h>
int n;
float menor = 0;
int main() {
    printf("Vamos ver os menores de 0 números\n");
    for (int i = 0; i <= 10; ++i) {
        printf("Digite um número INTEIRO: ");
        scanf("%d", &n);
        if ( i == 0 || n < menor ) {
            menor = n;
        };
    };
    printf("Dos 10 números inseridos, o menor é %d", menor);
}
