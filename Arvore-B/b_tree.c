#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

void main()
{
    printf("[DEBUG] Iniciando programa...\n");

    FILE *dados = fopen("fonte.txt", "a+");
    FILE *indice = fopen("indice.txt", "a+");

    char texto_linha[100];

    if (dados == NULL){
        printf("[ERRO] O arquivo 'fonte.txt' não foi aberto.\n");
    }

    if (indice == NULL){
        printf("[ERRO] O arquivo 'indice.txt' não foi aberto.\n");
    }

    printf("[DEBUG] Criando arvore B...\n");
    arvB* btree = criarArv(dados);

    if (btree == NULL) {
        printf("[ERRO] Falha ao criar arvore B.\n");
    }

    fclose(dados);
    fclose(indice);

    printf("[DEBUG] Programa finalizado.\n");
}

arvB *criarArv(FILE *dados) {


    if (dados == NULL) {
        printf("[ERRO] arquivo de dados é NULL em criarArv\n");
        return NULL;
    }

    /* garantir que a leitura comece do início do arquivo */
    rewind(dados);

    arvB* raiz = (arvB*) malloc(sizeof(arvB));

    if(raiz == NULL){
        printf("[ERRO] Falha ao alocar memória para raiz\n");
        return NULL;
    }

    *raiz = criarNO();

    if (*raiz == NULL) {
        printf("[ERRO] Falha ao criar nó raiz\n");
        return NULL;
    }

    char texto_linha[200];

    while(fgets(texto_linha, sizeof texto_linha, dados) != NULL) {
        printf("[DEBUG] Lendo linha para inserir na árvore: %s", texto_linha);

        int posicao = 0;
        int matricula = 0;

        /* espera linhas no formato: posicao,matricula  (ex: 111,88888) */
        if (sscanf(texto_linha, " %d , %d", &posicao, &matricula) == 2) {
            chave chave_lida = { matricula, posicao };
            printf("[DEBUG] Inserindo chave: matricula=%d, posicao=%d\n", matricula, posicao);
            cadastrar(*raiz, &chave_lida);
        } else {
            printf("[WARN] Linha com formato inesperado: %s", texto_linha);
        }
    }

    printf("Criou criarArv\n");

    return raiz;
}

NO *criarNO() {
    
    printf("[DEBUG] Criando novo nó...\n");

    NO *no = (NO*) malloc(sizeof(NO));

    if(no == NULL){
        printf("[ERRO] Falha ao alocar memória para nó\n");
        return NULL;
    }

    no->qtd = 0;
    no->eh_folha = 1;

    for(int i = 0; i < M; i++){
        no->filhos[i] = NULL;
    }

    printf("[DEBUG] Nó criado com sucesso (folha=%d, qtd=%d)\n", no->eh_folha, no->qtd);

    return no;
}

int cadastrar(NO *no, chave *chave) {
    
    printf("[DEBUG] Entrou em cadastrar\n");

    if (no == NULL) {
        printf("[ERRO] Nó NULL em cadastrar\n");
        return -1;
    }

    printf("[DEBUG] Nó qtd=%d | eh_folha=%d\n", no->qtd, no->eh_folha);

    if (no->eh_folha) {
        printf("[DEBUG] Inserção em nó folha\n");

        // Aqui ainda falta implementar inserção real
        if (no->qtd == M - 1) {
            // NÓ CHEIO = SPLIT()
        }
        else {
            // Procurando a posição correta para inserir a chave
            int i = no->qtd -1;

            while (i >= 0 && no->chaves[i].matricula > chave->matricula) {
                no->chaves[i + 1] = no->chaves[i];
                i--;
            }
            
            no->chaves[i + 1] = chave;
            no->qtd++;
        }
    } else {  // entender else
       int i = no->qtd -1;

            while (i >= 0 && no->chaves[i].matricula > chave->matricula) {
                no->chaves[i + 1] = no->chaves[i];
                i--;
            }

        cadastrar(no->filhos[i+1], chave);
    }

    return 0;
}

int pesquisar(FILE *arvore, int matricula);
int gravar(FILE *arvore);
int sair(FILE *arvore);