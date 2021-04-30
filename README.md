# Fila de Vacinação - Covid
Trabalho desenvolvido na disciplina de **AED2 2021/2**
**Engenharia de Computação** - PUC Minas COREU
**Aluno:** Cristian Fernandes Sena
# Introdução
O projeto consiste em um sistema de fila para vacinação conta covid-19. Através de um menu, o sistema possibilita a inserção de pessoas na fila, impressão de dados, impressão filtrada e remoção de pessoas da fila.
<br>O sistema lê os dados do usuário e o ordena automaticamente na fila de acordo com sua fase. Cada fase corresponde a um grupo prioritário. 
<br>Abaixo segue a tabela com a especificação de cada grupo prioritário:
|   Fase  |                   Especificação                   |
|:-------:|:-------------------------------------------------:|
| 1ª fase | Trabalhadores de Saúde, pessoas acima de 75 anos. |
| 2ª fase | Pessoas de 60 a 74 anos.                          |
| 3ª fase | Pessoas com comorbidades.                         |
| 4ª fase | Professores, forças de segurança, etc..           |
<br>A remoção sempre acontece no primeiro da fila, como uma fila comum.

# Desenvolvimento
Durante o desenvolvimento foram elaborados dois projetos, um com **Fila Dinâmica Encadeada** e outro com **Fila Estática por vetor**. Ambos os projetos estão disponíveis em suas respectivas pastas neste repositório.
<br>Para o desenvolvimento da 
<br>Para o desenvolvimento da **Fila Dinâmica Encadeada** foi utilizado o seguinte modelo:
'''
#ifndef  FILADINAMICA_H
#define  FILADINAMICA_H
//========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//========================================
typedef struct Pessoa{
  char nome[100];
  int idade;
  int fase;
  bool comorbidades;
  bool profSaude;
  bool prof4fase;
}Pessoa;
//========================================
typedef struct Celula{
  Pessoa dado;
  struct Celula *prox;
}Celula;
//========================================
typedef struct Fila{
  Celula *inicio;
  Celula *fim;
  int tam;
}Fila;
//========================================
void print_pessoa(Pessoa p);
//========================================
Celula *new_celula();
//========================================
void new_fila(Fila *f);
//========================================
void enqueue_pri(Fila *f, Pessoa dado);
//========================================
void print_fila(Fila *f);
//========================================
void print_fila_fase(Fila *f, int fase);
//========================================
int size_fila(Fila *f);
//========================================
Pessoa dequeue(Fila *f);
//========================================
#endif 
'''
<br>Já para o desenvolvimento da **Fila Estática por vetor** foi utilizado o seguinte modelo:
'''
#ifndef  FILAESTATICA_H
#define  FILAESTATICA_H
//========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//========================================
typedef struct Pessoa{
  char nome[100];
  int idade;
  int fase;
  bool comorbidades;
  bool profSaude;
  bool prof4fase;
}Pessoa;
//========================================
typedef struct Fila{
  Pessoa vetor[101];
  int inicio;
  int fim;
  int tam;
}Fila;
//========================================
void print_pessoa(Pessoa p);
//========================================
void new_fila(Fila *f);
//========================================
void enqueue_pri(Fila *f, Pessoa dado);
//========================================
void print_fila(Fila *f);
//========================================
void print_fila_fase(Fila *f, int fase);
//========================================
int size_fila(Fila *f);
//========================================
Pessoa dequeue(Fila *f);
//========================================
#endif
'''
Observe que os dois códigos apresentam poucas diferenças, o que demonstra que a **Fila Dinâmica Encadeada** e a **Fila Estática por vetor** possuem comportamentos parecidos.
# Conclusão
