// Ponteiros 
    
    int *p, *p1, x = 10;
    float y = 20.0;
    
    p = &x;
    
    printf("Conteúdo apontado por p: %d\n", &x);
    printf("Conteúdo apontado por p: %d\n", p);  // Conteúdo de p (endereço de x)
    printf("Conteúdo apontado por p: %d\n", *p);  // Conteúdo ao qual p aponta

    p1 = p;
    
    printf("\nConteúdo apontado por p1: %d\n", *p1);
    
    p = &y;
    
    printf("\nConteúdo apontado por p: %d\n", *p);
    printf("Conteúdo apontado por p: %f\n", *p);
    printf("Conteúdo apontado por p: %f\n", *((float*)p));
    printf("Conteúdo apontado por p: %d\n", p);

// Vetor
    
    int vet[5] = {1,2,3,4,5};
    int *p;
    
    p = vet;
    
    printf("Terceiro elemento: %d ou %d", p[2], *(p+2));
    
    return 0;  

// Struct
    
    struct ponto {
        int x, y;
    }
    
    struct ponto q;
    struct ponto *p;
    
    q.x = 10;
    (*p).x = 10;
    p -> x = 10;
    
    // ^^ Mesma coisa ^^

// Recursão

        // Decrescente

        void recursao (int i){
        if(i>=0){
            printf("Oi, %d\n",i);
            recursao (i-1);
            }
        }
    
        int main(){
        
        int n;
    
        printf("Digite um número: ");
        scanf("%d",&n);
        printf("\n");
        
        recursao(n);
        
        return 0;
        }

        // Crescente

        void recursao (int i){
        if(i>=0){
            recursao(i-1);
            printf("Oi, %d\n",i);
            }
        }
        
        int main(){
            
        int n;
        
        printf("Digite um número: ");
        scanf("%d",&n);
        printf("\n");
        
        recursao(n);
        
        return 0;
        }

        // Fatorial

        int fatorial (int i){
            if (i == 0) {
                return 1;
            }
            else {   //if(i>1)
                return i * fatorial(i-1);
            }
            
        }
        
        int main(){
            
        int n;
        
        printf("Digite um número: ");
        scanf("%d",&n);
        printf("\n");
        
        printf("%d",fatorial(n));
        
        return 0;
        
        }
