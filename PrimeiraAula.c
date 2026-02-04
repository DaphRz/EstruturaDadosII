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

    int destruir(circ *c){
    free(c);
}

3. Se um Ponto está dentro ou fora da Circunferência.

    int dentro(circ *c, int a, int b){
        
        if(sqrt(pow((c->x-a),2) + pow((c->y-b),2)) < c->raio){
            printf("\n\nEstá dentro");
        }
        else{
            printf("\nEstá fora");
        }
    }

4. Se duas circunferências se interceptam.

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
    int raio;
} circ;

circ* criar_c(int x, int y, int raio){
        circ *c = malloc((sizeof(circ)));
        
        (*c).x = x;
        c->y = y;
        c->raio = raio;
        
        return c;
    }
    
int destruir(circ *c){
    free(c);
}

int dentro(circ *c, int a, int b){
    
    if(sqrt(pow((c->x-a),2) + pow((c->y-b),2)) < c->raio){
        printf("\n\nEstá dentro");
    }
    else{
        printf("\nEstá fora");
    }
}

int tangente(circ *c, circ *z){
    
    if(sqrt((c->x-)))
    
    // se a distancia entre os pontos for igual a soma dos raio
}

int main()
{
    circ* c;
    c = criar_c(0,0,2);
    
    printf("%d, %d, %d\n", c->x,c->y,c->raio);
    
    destruir(c);
    
    printf("\n%d, %d, %d", c->x,c->y,c->raio);
    
    c = criar_c(0,0,2);
    
    dentro(c,1,1);
    dentro(c,9,9);
    
    c1 = criar_c(-2,0,2);
    c2 = criar_c(-3,0,2);
}
