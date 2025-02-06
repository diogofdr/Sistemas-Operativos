#ifndef PERSON_H
#define PERSON_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct pessoa Pessoa;

void adicionaPessoa(char* nome, int idade);
void listaPessoas(int n);
void atualizaIdade(char* referencia, char* tipo, int idade);
#endif