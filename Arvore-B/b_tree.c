#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

void main()
{    
    FILE *dados = fopen("fonte.txt", "a+");
    FILE *indice = fopen("indice.txt", "a+");
    
    char texto_linha[100];

    arvB btree = criarArv();

    if (dados == NULL){
        printf("ERRO! O arquivo não foi aberto.\n");
    }
    else {
        printf("O arquivo foi aberto com sucesso!\n");
    }
 
    while(fgets(texto_linha,100,dados) != NULL) {
        printf("%s",texto_linha);
    }
    criarArv(dados, indice);

    fclose(dados);
    false(indice);

    return 0;
}

arvB *criarArv() {

    arvB *raiz = (arvB*) malloc(sizeof(arvB));

    if(raiz == NULL)
        return NULL;

    *raiz = (NO*) malloc(sizeof(NO));

    if(*raiz == NULL)
        return NULL;

    (*raiz)->qtd = 0;
    (*raiz)->eh_folha = 1;

    for(int i = 0; i < M; i++)
        (*raiz)->filhos[i] = NULL;

    printf("Árvore B criada.\n");

    return raiz;
}

int cadastrar(FILE *arvore, dado *elementos, NO *no);
int pesquisar(FILE *arvore, int matricula);
int gravar(FILE *arvore);
int sair(FILE *arvore);