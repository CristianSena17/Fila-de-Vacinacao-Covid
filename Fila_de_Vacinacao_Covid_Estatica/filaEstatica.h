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