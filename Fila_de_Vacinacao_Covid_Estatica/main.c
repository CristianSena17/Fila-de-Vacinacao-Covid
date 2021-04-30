#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filaEstatica.h"

/*
Sistema para gerenciar uma Fila de Pessoas para a vacinacao conta covid-19
com prioridades por fase.
Funcionalidades: Adicionar uma pessoa, remover uma pessoa, exibir toda a fila,
exibir a fila de uma fase e exibir o tamanho da fila.
*/

/*============================================================
Funcao menu: Recebe uma opcao do teclado e retorna a opcao
Entradas: Nao possui no cabecalho, mas recebe uma entrada int
do teclado
Saida: A opcao inteira
*/
int menu(){
  int opcao = 0;
  do{
    printf(" -------> SISTEMA DE FILA DE VACINACAO <------\n");
    printf(" --------------Escolha uma opcao--------------\n");
    printf(" 1 - Inserir uma pessoa na fila \n");
    printf(" 2 - Retirar uma pessoa da fila\n");
    printf(" 3 - Exibir a fila\n");
    printf(" 4 - Exibir a fila de uma fase especifica\n");
    printf(" 5 - Verificar o tamanho da fila\n");
    printf(" 0 - Sair\n");
    printf(" Digite a opcao desejada: ");
    scanf("%d", &opcao);
    if(opcao>=6 || opcao<0)
      printf("\n\n---------------Opcao Invalida----------------\n\n\n");
  }while(opcao>=6 || opcao<0);
  return opcao;
}

/*============================================================
Funcao cadastro: Recebe uma pessoa p e insere seus dados na struct
Entradas: Uma pessoa p e valores do teclado
Saida: Uma pessoa p preenchida
*/
Pessoa cadastro(Pessoa p){
  char resp;
  p.fase=5;
  p.comorbidades=false;
  p.profSaude=false;
  p.prof4fase=false;
  system("clear");

  printf("Informe o nome da pessoa\n");
  __fpurge(stdin);
  scanf ( "%[^\n]", p.nome);

  printf("Informe a idade da pessoa\n");
  scanf("%d", &p.idade);

  printf("Aa pessoa eh profissional da quarta fase (Professores, forças de segurança, etc.. )? |S para Sim|N para Nao|\n");
  scanf(" %c", &resp);
  if(resp=='S' || resp=='s'){
    p.fase=4;
    p.prof4fase=true;
  }

  printf("A pessoa possui comobidades? |S para Sim|N para Nao|\n");
  scanf(" %c", &resp);

  if(resp=='S' || resp=='s'){
    p.fase=3;
    p.comorbidades=true;
  }

  if(p.idade>=60 && p.idade<=74)
    p.fase=2;

  printf("A pessoa trabalha na area da saude? |S para Sim|N para Nao|\n");
  scanf(" %c", &resp);

  if(resp=='S' || resp=='s'){
    p.fase=1;
    p.profSaude=true;
  }
  if(p.idade>=75)
     p.fase=1;  

  printf("\n\n---------Cadastro efetuado com sucesso--------\n\n\n");
  return p;
}

/*============================================================
Funcao main: Recebe uma opcao do teclado para o menu
Entradas: Valores do teclado
Saida: Chamada das funcoes de acordo com a opcao desejada
*/
int main(void) {
  Fila fila;
  new_fila(&fila);
  int op = 0, QFase;
  system("clear");

  do{
    op = menu();
    switch(op){
      case 1:{
        Pessoa p;
        p = cadastro(p);    
        enqueue_pri(&fila, p);
      }
      break;

      case 2:{
        Pessoa p = dequeue(&fila);
        if(p.idade==-1)
          printf("\nFila vazia! Nenhuma pessoa foi removida\n\n");
        else{
          printf("\nPessoa removida: ");
          print_pessoa(p);
        }
      }     
      break;

      case 3:
        printf("\n\n");
        print_fila(&fila);
        printf("\n\n");
      break;

      case 4:{
        do{
          system("clear");
          printf("------Informe a fase que deseja imprimir:-----\n");
          printf("1: Trabalhadores de Saúde, pessoas acima de 75 anos.\n");
          printf("2: Pessoas de 60 a 74 anos.\n");
          printf("3: Pessoas com comorbidades.\n");
          printf("4: Professores, forças de segurança, etc..\n");
          printf("5: Pessoas nao prioritarias\n");
          scanf("%d", &QFase);
          if(QFase>=1 && QFase<=5)
            print_fila_fase(&fila, QFase);
        }while(QFase>=6 || QFase<=0);
      }
      break;

      case 5: 
        printf("\nTamanho da fila: %d\n\n", size_fila(&fila));
      break;
    }
  }while(op != 0);
  return 0;
}