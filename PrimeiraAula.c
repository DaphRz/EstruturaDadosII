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

    void tangente(circ *c, circ *z){
        
        double d = sqrt(pow((c->x-z->x),2) + pow((c->y-z->y),2));
        
        int dif = c->raio - z-> raio;
        
        if(dif<0) dif = -dif;
        
        if(d <= (c->raio + z->raio) && d >= dif){
            
            printf("\n\nAs duas circunferências se interceptam");
        }
        else{
            printf("\nNão se interceptam");
        }
        
        // se a distancia entre os pontos for igual a soma dos raio
        
        // Se d < |r1 - r2|: uma circunferência fica totalmente dentro da outra, sem tocar → não tem interseção.
        // Se d > r1 + r2: elas estão separadas, longe demais → também não tem interseção.
        // Só quando d está entre esses dois valores (inclusive) é que elas se interceptam (2 pontos) ou são tangentes (1 ponto).
    }

Programa Completo:

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    
    typedef struct {
        int x, y;
        int raio;
    } circ;
    
    circ* criar_c(int x, int y, int raio){
        
            circ *c = malloc(sizeof(circ));
            
            if(c==NULL){
                return NULL;  // erro de alocação
            }
            
            (*c).x = x;
            c->y = y;
            c->raio = raio;
            
            return c;
        }
        
    int destruir(circ *c){
        
        if(c != NULL){
            free(c);
        }
    }
    
    void dentro(circ *c, int a, int b){
        
        if(sqrt(pow((c->x-a),2) + pow((c->y-b),2)) <= c->raio){
            printf("\n\nEstá dentro");
        }
        else{
            printf("\nEstá fora");
        }
    }
    
    void tangente(circ *c, circ *z){
        
        double d = sqrt(pow((c->x-z->x),2) + pow((c->y-z->y),2));
        
        int dif = c->raio - z-> raio;
        
        if(dif<0) dif = -dif;
        
        if(d <= (c->raio + z->raio) && d >= dif){
            
            printf("\n\nAs duas circunferências se interceptam");
        }
        else{
            printf("\nNão se interceptam");
        }
        
        // se a distancia entre os pontos for igual a soma dos raio
        
        // Se d < |r1 - r2|: uma circunferência fica totalmente dentro da outra, sem tocar → não tem interseção.
        // Se d > r1 + r2: elas estão separadas, longe demais → também não tem interseção.
        // Só quando d está entre esses dois valores (inclusive) é que elas se interceptam (2 pontos) ou são tangentes (1 ponto).
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
        
        circ* c1 = criar_c(-2,0,2);
        circ* c2 = criar_c(-6,0,2);
        
        tangente(c,c1);
        tangente(c,c2);
        
        return 0;
    }
