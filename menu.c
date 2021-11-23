#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void abertura() {
  system("cls|| clear");
  printf("|*******************************************|\n");
  printf("|***************BEM VINDO!!*****************|\n");
  printf("|****Atividade base para primeira prova!****|\n");
  printf("|*Protocolo Bicicleta com rodinhas iniciado*|\n");
  printf("|*******************************************|\n");
  printf("|*******************************************|\n");
  Sleep(3000);
}
void menu() {
  system("cls || clear");
  printf("|_________________________________________|\n");
  printf("|Qual operacao deseja realizar?           |\n");
  printf("|Digite o numero de sua escolha :         |\n");
  printf("|-----------------------------------------|\n");
  printf("|[1] - Q1: calcular a idade de uma pessoa!|\n");
  printf("|[2] - Q2: Calcular juros emprestimo!     |\n");
  printf("|[3] - Q3: Calcular a coroa circular      |\n");
  printf("|[4] - Sair!                              |\n");
  printf("|-----------------------------------------|\n");

  scanf("%d", &_INDICE);
}
void submenu(void (*func)(void)) {
  printf("\n___________________________________________\n");
  printf("|Qual operacao deseja realizar?           |\n");
  printf("|Digite o numero de sua escolha :         |\n");
  printf("|-----------------------------------------|\n");
  printf("|[1] Para fazer a operacao novamente!     |\n");
  printf("|[2] Para voltar ao menu principal!       |\n");
  printf("|[3] Para sair do programa!               |\n");
  printf("|-----------------------------------------|\n");
  scanf(" %d", &_INDICE);

  switch (_INDICE) {
  case 1:
    func();
  case 2:
    _INDICE = 10;
    break;
  case 3:
    system("cls || clear");
    printf("\nObrigado por utilizar nosso sistema!");
    _INDICE = 0;
    break;
  default:
    printf("\nOpcao invalida, voltando ao menu iniciar!\n");
    Sleep(2000);
    _INDICE = 10;
    break;
  }
}
