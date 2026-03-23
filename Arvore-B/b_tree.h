#ifndef B_TREE_H
#define B_TREE_H

#include <stdio.h>

#define M 3

typedef struct dado {
    int posicao;
    int matricula;
    char nome[50];
    int telefone;
} dado;

typedef struct chave {
    int matricula;
    int posicao;
} chave;

typedef struct NO {
    int qtd;
    chave chaves[M-1];
    struct NO *filhos[M];
    int eh_folha;
} NO;

// Declaração das funções
NO *criarArv(FILE *dados);
NO *criarNO();

int cadastrar(NO *no, chave *chave);
int cadastrarNovoRegistro(NO *btree, FILE *dados);
int buscarRegistro(NO *btree, FILE *dados);
int pesquisar(FILE *arquivo, NO *arvore, int matricula);
int gravar(NO *no, FILE *arvore);
int sair(NO *no);

// FILE *dados = fonte.txt
// FILE *indice = indice.txt

#endif