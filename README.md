# Fila de Vacinação - Covid
Trabalho desenvolvido na disciplina de **AED2 2021/2**
**Engenharia de Computação** - PUC Minas COREU
<br>**Aluno:** Cristian Fernandes Sena
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

A remoção sempre acontece no primeiro da fila, como em uma fila comum.

# Desenvolvimento
Durante o desenvolvimento foram elaborados dois projetos, um com **Fila Dinâmica Encadeada** e outro com **Fila Estática por vetor**. Ambos os projetos estão disponíveis em suas respectivas pastas neste repositório.
<br>Para o desenvolvimento da 
<br>Para o desenvolvimento da **Fila Dinâmica Encadeada** foi utilizado o seguinte modelo:
```c
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
```
Já para o desenvolvimento da **Fila Estática por vetor** foi utilizado o seguinte modelo:
```c
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
```
Observe que os dois códigos apresentam poucas diferenças, o que demonstra que a **Fila Dinâmica Encadeada** e a **Fila Estática por vetor** possuem comportamentos parecidos, sendo que a maior diferença esta na maneira de implementação.
<br>A **Fila Dinâmica Encadeada** necessita de uma struct Celula, o que não é obrigatório na **Fila Estática por vetor**, mas a **Fila Estática por vetor** necessita realizar movimentações no elementos do vetor sempre que um elementos é retirado ou adicionado, ao menos que ele seja adicionado no final. Já na **Fila Dinâmica Encadeada** uma simples alteração em ponteiros resolve o problema para adição ou remoção de qualquer elemento.
# Interação com o usuário 
Abaixo seguem os menus de interação com o usuário, se pode observar que eles possuem um funcionamento simples e objetivo, evitando que usuários leigos fiquem perdidos em meio a muitas opções.
<br>**Menu Principal**
```
-------> SISTEMA DE FILA DE VACINACAO <------
--------------Escolha uma opcao--------------
1 - Inserir uma pessoa na fila
2 - Retirar uma pessoa da fila
3 - Exibir a fila
4 - Exibir a fila de uma fase especifica
5 - Verificar o tamanho da fila
0 - Sair
Digite a opcao desejada:
```
**Menu de Opções de Filtragem**
```
------Informe a fase que deseja imprimir:-----
1: Trabalhadores de Saúde, pessoas acima de 75 anos.
2: Pessoas de 60 a 74 anos.
3: Pessoas com comorbidades.
4: Professores, forças de segurança, etc..
5: Pessoas nao prioritarias.
```
# Conclusão
Este projeto simplificou o desenvolvimento e entendimento de filas encadeadas e filas estáticas, o que abre portas para novos projetos com diferentes tipos de TADs e futuras melhorias e implementações no projeto em questão.
