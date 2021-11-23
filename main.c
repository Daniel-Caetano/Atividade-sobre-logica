// Autor: Daniel Caetano de Souza Ferreira
// Data: 23/11/2021
// Atividade feita como base para primeira prova do protocolo bicicleta de
// rodinhas
#include "menu.c"
#include "menu.h"
#include <Windows.h>
#include <math.h>
#include <stdio.h>

extern int _INDICE = 2;

void calcularIdade() {
  int dia;
  int mes;
  int ano;
  int idade;

  system("cls||clear");
  printf("\n|[1] - Q1: calcular a idade de uma pessoa!|");
  printf("\nDigite a data de nascimento!\n");
  printf("Dia:/");
  scanf("%d/", &dia);
  printf("Mes: /");
  scanf("%d", &mes);
  printf("Ano: /");
  scanf("%d", &ano);

  if ((dia < 1 || dia > 31) || (mes < 1) || (mes > 12) || (ano > 2021)) {
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

  idade = 2021 - ano;
  if ((dia <= 23 && mes <= 11) || mes < 11) {
    printf("Idade =|%d|ano(s)", idade);
  } else if (ano == 2021) {
    printf("Ainda nao nasceu!", idade);
  } else {

    printf("Idade =|%d| ano(s)", idade - 1);
  }

  submenu(&calcularIdade);
}

int main() {

  // abertura();
  do {

    // menu();

    switch (_INDICE) {
    case 1:
      calcularIdade();
      break;
    case 2:
      // calcular juros;
      break;
    case 3:
      // calcular coroa circular;
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
