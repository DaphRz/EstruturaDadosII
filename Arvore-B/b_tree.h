#ifndef B_TREE_H
#define B_TREE_H

#include <stdio.h>

#define M 3

typedef struct _pagina {
    int chave[M -1];
    struct _pagina *filho[M];
    int posicao[M-1];
    int folha;
} Pagina;

typedef Pagina *ArvoreB;

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

typedef struct NO *arvB;

arvB *criarArv();

NO *criarNO();

int cadastrar(FILE *arvore, dado *elementos, NO *no);
int pesquisar(FILE *arvore, int matricula);
int gravar(FILE *arvore);
int sair(FILE *arvore);

// FILE *data = fonte.tx
// FILE *arvore = indice.txt

#endif