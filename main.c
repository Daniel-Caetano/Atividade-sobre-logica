// Autor: Daniel Caetano de Souza Ferreira
// Data: 23/11/2021
// Atividade feita como base para primeira prova do protocolo bicicleta de
// rodinhas

#include "menu.c"
#include "menu.h"
#include <Windows.h>
#include <math.h>
#include <stdio.h>

extern int _INDICE = 1;
void dataAtual(int *dia, int *mes, int *ano) {
  time_t mytime;
  mytime = time(NULL);
  struct tm data = *localtime(&mytime);

  (*dia) = data.tm_mday;
  (*mes) = data.tm_mon + 1;
  (*ano) = data.tm_year + 1900;
  // printf("Data: %d/%d/%d/\n", (*dia), (*mes), (*ano));
}

void calcularIdade() {
  int diaAtual, mesAtual, anoAtual;
  int dia;
  int mes;
  int ano;
  int idade;
  dataAtual(&diaAtual, &mesAtual, &anoAtual);
  system("cls||clear");
  printf("\n|[1] - Q1: calcular a idade de uma pessoa!|");
  printf("\nDigite a data de nascimento!\n");
  printf("Dia:/");
  scanf("%d/", &dia);
  printf("Mes: /");
  scanf("%d", &mes);
  printf("Ano: /");
  scanf("%d", &ano);

  //---condições para validação da idade digitada
  if ((dia < 1 || dia > 31) || (mes < 1) || (mes > 12) || (ano > anoAtual)) {
    printf("\n Data invalida digite novamente");
    Sleep(1000);
    calcularIdade();
  } else if (dia == 31 &&
             (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
    printf("\n Data invalida digite novamente");
    Sleep(1000);
    calcularIdade();
  } else if (dia > 29 && mes == 02) {
    printf("\n Data invalida digite novamente");
    Sleep(1000);
    calcularIdade();
  }
  //---FIM : condições para validação da idade digitada

  idade = anoAtual - ano;
  if ((dia <= diaAtual && mes <= mesAtual) || mes < mesAtual) {
    printf("Idade =|%d|ano(s)", idade);
  } else if (ano == anoAtual) {
    printf("Ainda nao nasceu!", idade);
  } else {
    printf("Idade =|%d| ano(s)", idade - 1);
  }

  submenu(&calcularIdade);
}

void calculaJuros() {
  float valorEmprestimo;
  float juros;
  float qtdDiasJuros;
  float emprestimoFloat;
  int qtdMes;
  int qtdDias;
  char atrasado;
  system("cls||clear");
  printf("|[2] - Q2: Calcular juros emprestimo!     |\n");
  printf("\nQuantidade de dias para pagamento?");
  scanf("%d", &qtdDias);

  if (qtdDias < 1) {
    system("cls || clear");
    printf("\nDias precisa ser maior que zero '0', digite novamente");
    Sleep(2000);
    calculaJuros();
  }
  printf("\nValor emprestimo de 800 , pagamento para %d dias", qtdDias);

  if (qtdDias <= 30) {
    emprestimoFloat = 800 + (800 * 0.06);
  } else if (qtdDias <= 60) {
    emprestimoFloat = 800 + (800 * 0.10);
  } else if (qtdDias <= 90) {
    emprestimoFloat = 800 + (800 * 0.13);
  } else {
    qtdMes = qtdDias / 30;
    if (qtdDias % 30 != 0) {
      qtdMes++;
    }
    juros = pow(1.04, qtdMes);
    // printf("\nJUROS: %f", juros);

    emprestimoFloat = 800 * juros;
  }
  printf("\nValor emprestimo acrescido dos juros:|%.2f|", emprestimoFloat);

  submenu(&calculaJuros);
}

calcularCoroa() {
  float coroaMaior;
  float coroaMenor;
  float coroaCircular;

  system("cls || clear");
  printf("|[3] - Q3: Calcular a coroa circular      |\n");
  printf("\nDigite o Raio da coroa maior(R1)!\n");
  scanf(" %f", &coroaMaior);
  printf("\nDigite o Raio da coroa menor (R2)!\n");
  scanf(" %f", &coroaMenor);

  coroaCircular =
      (float)(3.1415926 * (pow(coroaMaior, 2) - pow(coroaMenor, 2)));
  printf("\nRaio da Coroa:|%f|", coroaCircular);

  submenu(&calcularCoroa);
}

int main() {

  abertura();
  do {

    menu();

    switch (_INDICE) {
    case 1:
      calcularIdade();
      break;
    case 2:
      calculaJuros();
      break;
    case 3:
      calcularCoroa();
      break;
    case 4:
      printf("\nObrigado por utilizar nosso sistema!\n");
      _INDICE = 0;
      break;
    default:
      printf("Comando invalido!");
      Sleep(2000);
    }
  } while (_INDICE);
  system("pause");
}
