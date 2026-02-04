Programa em C que imprime "Olá, mundo." sem o uso de ; no código.

    #include <stdio.h>
    
    int main()
    {
        if(printf("Hello World")){}
    
        return 0;
    }

Escreva um TAD (Tipo Abstrato de Dados - um tipo definido pelo usuário - conjunto de elementos q contém propriedades iguais e conjunto de operações) que represente uma circunferência com as seguintes operações (funções):

1. Criar uma Circunferência.

    typedef struct {
        int x, y;
        float raio;
    } circ;
    
    circ* criar_c(int x, int y, float raio){
            circ *c = malloc((sizeof(circ)));
            
            (*c).x = x;
            c->y = y;
            c->raio = raio;
            
            return c;
        }

2. Destruir.
