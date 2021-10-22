#include <stdio.h>

int idade, count;
float somaIdade;
int main() {
  while ( idade != -2 ) {
    printf("digite um número: ");
    scanf("%d", &idade);
    if ( idade != -2 ) {
      count++;
      somaIdade += idade;
    }
  };
  printf("A media de idades é %f", somaIdade/count);
}