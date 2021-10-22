#include <stdio.h>

int faltaDeAr, desacordado;
float temperaturaPaciente;
int main() {
  printf("Qual é a temperatura do paciente?");
  scanf("%f", &temperaturaPaciente);

  printf("O paciente está com falta de ar? [ 0-sim | 1-não ]: ");
  scanf("%d", &faltaDeAr);

  printf("O paciente está acordado? [ 0-sim | 1-não ]: ");
  scanf("%d", &desacordado);


  if ( temperaturaPaciente > 37.5 ) {
    printf("Paciente deve ser encaminhado ao exame de sangue e urina.\n");
  } else if ( temperaturaPaciente >= 35 ) {
    printf("Paciente deve ser encaminhado a consulta com clínico geral");
  } 
  
  if ( temperaturaPaciente < 35 || desacordado == 0 ) {
    printf("Paciente deve ser encaminhado à emergência");
  }

  if ( faltaDeAr == 0 ) {
    printf("Paciente deve ser encaminhado para tomografia do pulmão");
  }
}