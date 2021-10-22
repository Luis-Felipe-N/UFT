#include <stdio.h>
#include <stdlib.h>

float numHorasTrabalhadas, salarioMinimo, numHorasExtras, valorHorasTrabalhadas, valorHorasExtras, valorSalarioBruto, valorBrutoHorasExtras, salario;


int main(void){
    printf("Qual as horas trabalhadas?");
    scanf("%f", &numHorasTrabalhadas);
    printf("Qual seu salário minímo?");
    scanf("%f", &salarioMinimo);
    printf("Números de horas extras?");
    scanf("%f", &numHorasExtras);

    valorHorasTrabalhadas = salarioMinimo/8;
    valorHorasExtras = salarioMinimo/4;
    valorSalarioBruto = numHorasTrabalhadas * valorHorasTrabalhadas;
    valorBrutoHorasExtras = numHorasExtras * valorHorasExtras;

    salario = valorSalarioBruto + valorBrutoHorasExtras;

    printf("Salario a receber é %f", salario);
    return 0;
}