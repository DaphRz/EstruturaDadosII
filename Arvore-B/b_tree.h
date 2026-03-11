#define M 4

typedef struct chave {
    int matricula;
    NO* posicao;
} chave;

typedef struct NO {
    NO* no;
    int qtd;
    chave chaves[M];
    NO* filhos[M+1];
} NO;

