#include "filaEstatica.h"

/*============================================================
Procedimento print_pessoa: Recebe uma pessoa p para impressao
Entradas: Uma pessoa p
Saida: O valores impressos na tela
*/
void print_pessoa(Pessoa p){
  if(p.comorbidades)
    printf("Nome: %s, idade: %d, fase: %d, possui comibidades: Sim, ", p.nome, p.idade, p.fase);
  else
    printf("Nome: %s, idade: %d, fase: %d, possui comibidades: Nao, ", p.nome, p.idade, p.fase);
  if(p.profSaude)
    printf("eh trabalhador na saude: Sim, ");
  else
    printf("eh trabalhador na saude: Nao, ");
  if(p.prof4fase)
    printf("eh profissional da quarta fase: Sim\n");
  else
    printf("eh profissional da quarta fase: Nao\n");
  printf("\n");
}

/*============================================================
Procedimento new_fila: Prepara os valores de uma nova fila
Entradas: Uma fila f
Saida: O valores preenchidos em f
*/
void new_fila(struct Fila *f){
  f->inicio = 0;
  f->fim = 0;
  f->tam = 0;
}

/*============================================================
Procedimento enqueue_pri: Insere uma pessoa na fila
Entradas: Uma fila f e uma pessoa dado
Saida: A pessoa dado na fila f
*/
void enqueue_pri(struct Fila *f, Pessoa dado){
    
  if(dado.fase<=4){
    int pos= f->fim;

    while(pos > f->inicio && dado.fase < f->vetor[pos-1].fase){
      pos--;
    }
     
    for(int i=f->fim; i>pos; i--){
      f->vetor[i]=f->vetor[i-1]; 
    }
     
    f->vetor[pos]=dado;

    f->tam++;
    f->fim = (f->fim + 1) % 100;
  }else{
    if(((f->fim + 1) % 100) == f->inicio)
      exit(1);
    f->vetor[f->fim] = dado;
    f->fim = (f->fim + 1) % 100;
    f->tam++;
  }
  
}

/*============================================================
Procedimento print_fila: Imprime toda a fila
Entradas: Uma fila f
Saida: Chamada do procedimento print_pessoa para cada pessoa
*/
void print_fila(struct Fila *f){
  int cont=0;
  printf("---------------------Fila---------------------\n");
  
  for(int i=f->inicio;i<f->fim;i++){
    print_pessoa(f->vetor[i]);
    cont++;
  }
  if(cont==0)
    printf("Nenhum registro encontrado\n");
}

/*============================================================
Procedimento print_fila_fase: Imprime a fila de uma fase
Entradas: Uma fila f e uma fase inteira
Saida: Chamada do procedimento print_pessoa para cada pessoa de 
uma fila
*/
void print_fila_fase(struct Fila *f, int fase){
  int cont=0;
  printf("---------------------Fila---------------------\n");
  
  for(int i=f->inicio;i<f->fim;i++){
    if(f->vetor[i].fase==fase){
      print_pessoa(f->vetor[i]);
      cont++;
    }
  }
  if(cont==0)
    printf("Nenhum registro encontrado\n\n");
}

/*============================================================
Função size_fila: Retorna o tamanho da fila
Entradas: Uma fila f
Saida: O tamanho da fila
*/
int size_fila(struct Fila *f){
  return f->tam;
}

/*============================================================
Função dequeue: Remove a primeira pessoa da fila
Entradas: Uma fila f
Saida: A pessoa removida
*/
Pessoa dequeue(struct Fila *f){
  if(f->tam==0){
    Pessoa p = {"Invalido", -1};
    return p;
  }
  Pessoa resp = f->vetor[f->inicio];
  f->inicio = (f->inicio + 1) % 101;
  f->tam--;
  return resp;
}