#include "filaDinamica.h"

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
Funcao *new_celula: Cria uma celula
Entradas: Não possui
Saida: A celula tmp alocada
*/
Celula *new_celula(){
  Celula *tmp = (Celula*) malloc(sizeof(Celula));
  tmp->prox = NULL;
  return tmp;
}

/*============================================================
Procedimento new_fila: Prepara os valores de uma nova fila
Entradas: Uma fila f
Saida: O valores preenchidos em f
*/
void new_fila(Fila *f){

  Celula *nova = new_celula();

  f->inicio = nova;
  f->fim = nova;
  f->tam = 0;
}

/*============================================================
Procedimento enqueue_pri: Insere uma pessoa na fila
Entradas: Uma fila f e uma pessoa dado
Saida: A pessoa dado na fila f
*/
void enqueue_pri(Fila *f, Pessoa dado){

  Celula *nova = new_celula();
  nova->dado = dado;

  if(dado.fase <= 4){ //Verifica se faz parte das fases prioritarias

    Celula *ant = f->inicio;
    Celula *tmp = f->inicio->prox;


    while(tmp!=NULL && tmp->dado.fase <= dado.fase){ //Verificacao de fase
      ant = ant->prox;
      tmp = tmp->prox;
    }

    nova->prox = tmp;
    ant->prox = nova;
    f->tam++;

    if(tmp == NULL){
      f->fim = nova;
    }

  }else{

    f->fim->prox = nova;
    f->fim = nova;
    f->tam++;
  }
}

/*============================================================
Procedimento print_fila: Imprime toda a fila
Entradas: Uma fila f
Saida: Chamada do procedimento que imprime para cada pessoa
*/
void print_fila(Fila *f){
  printf("---------------------Fila---------------------\n");

  Celula *tmp = f->inicio->prox;
  int cont=0;
  
  while(tmp != NULL){
    print_pessoa(tmp->dado);
    cont++;
    tmp = tmp->prox;
  }
  if(cont==0)
    printf("Nenhum registro encontrado\n");
}

/*============================================================
Procedimento print_fila_fase: Imprime a fila de uma fase
Entradas: Uma fila f e uma fase inteira
Saida: Chamada do procedimento que imprime para cada pessoa de 
uma fila
*/
void print_fila_fase(Fila *f, int fase){
  printf("\n---------------------Fila---------------------\n");
  Celula *tmp = f->inicio->prox;
  int cont=0;

  while(tmp != NULL){
    if(tmp->dado.fase==fase){
      print_pessoa(tmp->dado);
      cont++;
    }
    tmp = tmp->prox;
  }
  if(cont==0)
    printf("Nenhum registro encontrado\n\n");
}

/*============================================================
Função size_fila: Retorna o tamanho da fila
Entradas: Uma fila f
Saida: O tamanho da fila
*/
int size_fila(Fila *f){
  return f->tam;
}

/*============================================================
Função dequeue: Remove a primeira pessoa da fila
Entradas: Uma fila f
Saida: A pessoa removida
*/
Pessoa dequeue(Fila *f){
  if(f->tam == 0){
    Pessoa p = {"Invalido", -1};
    return p;
  }

  Celula *tmp = f->inicio;
  f->inicio = f->inicio->prox;  
  free(tmp);
  f->tam--;

  return f->inicio->dado;
}