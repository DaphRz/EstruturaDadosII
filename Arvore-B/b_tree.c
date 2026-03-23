#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

int main()
{
    // 'a+' para dados (adiciona no fim) e 'w+' para índice (sobrescreve o estado)
    FILE *dados = fopen("fonte.txt", "a+");
    FILE *indice = fopen("indice.txt", "w+");

    if (dados == NULL){
        printf("Erro: O arquivo 'fonte.txt' não foi aberto.\n");
        return 1;
    }

    if (indice == NULL){
        printf("Erro: O arquivo 'indice.txt' não foi aberto.\n");
        fclose(dados); // Boa prática: fechar o que já foi aberto em caso de erro
        return 1;
    }

    NO *btree = criarArv(dados);

    if (btree == NULL) {
        printf("Falha ao criar arvore B.\n");
    } 
    else {
        int c = 1;
        while (c) {
            printf("\n============GERENCIADOR DA ARVORE B============\n");
            printf("Escolha uma opcao:\n");
            printf("1. Cadastrar Aluno\n");
            printf("2. Buscar Aluno\n");
            printf("3. Gravar Arvore\n");
            printf("4. Sair\n");
            printf("Opcao: ");
            
            int n;
            scanf("%d", &n);
            
            switch (n)
            {
            case 1:
                cadastrarNovoRegistro(btree, dados);
                break;
            case 2:
                buscarRegistro(btree, dados);
                break;
            case 3:
                gravar(btree, indice);
                printf("Arvore gravada com sucesso!\n");
                break;
            case 4:
                sair(btree);
                c = 0;
                break;
            default:
                printf("Opcao invalida. Tente Novamente.\n");
                break;
            }
            printf("\n==============================================");   
        }
    }

    fclose(dados);
    fclose(indice);

    return 0;
}

// ============================================================================
// 1. CRIAÇÃO DA ÁRVORE B
// ============================================================================

NO *criarArv(FILE *dados) {

    if (dados == NULL) {
        printf("[ERRO] arquivo de dados é NULL em criarArv\n");
        return NULL;
    }

    /* garantir que a leitura comece do início do arquivo */
    rewind(dados);

    NO *raiz = criarNO();

    if (raiz == NULL) {
        printf("[ERRO] Falha ao criar nó raiz\n");
        return NULL;
    }

    char texto_linha[200];

    while(fgets(texto_linha, sizeof(texto_linha), dados) != NULL) {
        printf("[DEBUG] Lendo linha para inserir na árvore: %s", texto_linha);

        int posicao = 0;
        int matricula = 0;

        /* espera linhas no formato: posicao,matricula  (ex: 111,88888) */
        if (sscanf(texto_linha, " %d , %d", &posicao, &matricula) == 2) {
            chave chave_lida = { matricula, posicao };
            printf("[DEBUG] Inserindo chave: matricula=%d, posicao=%d\n", matricula, posicao);
            cadastrar(raiz, &chave_lida);
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

// ============================================================================
// 2. INSERÇÃO E BALANCEAMENTO (SPLIT)
// ============================================================================

int cadastrar(NO *no, chave *chave) {
    
    printf("[DEBUG] Entrou em cadastrar\n");

    if (no == NULL) {
        printf("[ERRO] Nó NULL em cadastrar\n");
        return -1;
    }

    printf("[DEBUG] Nó qtd=%d | eh_folha=%d\n", no->qtd, no->eh_folha);

    if (no->eh_folha) {
        printf("[DEBUG] Inserção em nó folha\n");

        if (no->qtd == M - 1) {
            // NÓ CHEIO = SPLIT()
        }
        else {
            // Procurando a posição correta para inserir a chave
            int i = no->qtd - 1;

            while (i >= 0 && no->chaves[i].matricula > chave->matricula) {
                no->chaves[i + 1] = no->chaves[i];
                i--;
            }
            
            no->chaves[i + 1] = *chave;
            no->qtd++;
        }
    } else {  // se não é folha
       int i = no->qtd - 1;

        while (i >= 0 && no->chaves[i].matricula > chave->matricula) {
            i--;
        }

        cadastrar(no->filhos[i+1], chave);
    }

    return 0;
}

int cadastrarNovoRegistro(NO *btree, FILE *dados) {
    // Implementar a leitura dos dados do usuário e escrita em arquivo
    return 0;
}

// ============================================================================
// 3. BUSCA E RECUPERAÇÃO DE DADOS
// ============================================================================

int buscarRegistro(NO *btree, FILE *dados) {
    // Implementar a interface de requisição da matrícula para o usuário
    return 0;
}

int pesquisar(FILE *arquivo, NO *arvore, int matricula){
    
    if (arvore == NULL) {
        printf("[ERRO] Árvore NULL em pesquisar\n");
        return -1;
    }
    
    int i = arvore->qtd - 1; 
    
    // Procura a primeira chave maior ou igual a que queremos encontrar
    while (i >= 0 && arvore->chaves[i].matricula > matricula) {
        i--; 
    }

    // Se a chave for encontrada neste nó
    if(i >= 0 && arvore->chaves[i].matricula == matricula) {
        printf("[INFO] Registro encontrado para matrícula: %d\n", matricula);
        rewind(arquivo);
        fseek(arquivo, arvore->chaves[i].posicao, SEEK_SET);
        
        dado d;
        
        fscanf(arquivo, "%d,%d,%49[^,],%d",  // %[^,] -> lê string até a vírgula (nome)
                &d.posicao,
                &d.matricula,
                d.nome,
                &d.telefone);
                
        printf("Matrícula=%d, Nome=%s, Telefone=%d\n", d.matricula, d.nome, d.telefone);
        return 1;
    }

    // Se não achou e for folha, a chave não existe na árvore
    if (arvore->eh_folha) {
        return 0; 
    }

    // Se não é folha e não achou, desce pro filho correto
    return pesquisar(arquivo, arvore->filhos[i+1], matricula);
}

// ============================================================================
// 4. PERSISTÊNCIA (GRAVAÇÃO DO ÍNDICE)
// ============================================================================

int gravar(NO *no, FILE *arvore) {
    // Implementar gravação recursiva da árvore em disco
    return 0;
}

// ============================================================================
// 5. GERENCIAMENTO DE MEMÓRIA (DESTRUIÇÃO)
// ============================================================================

int sair(NO *no) {
    // Implementar liberação (free) de todos os nós alocados recursivamente
    return 0;
}