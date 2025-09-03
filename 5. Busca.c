// Busca Sequencial ou Linear

  int busca (int v[], int tam, int n){
      
      for(int i = 0; i <= tam; i++){
          
          if (n == v[i]){
              printf("\nA posição de %d é %d",n,(i+1));
              return 0;
          }
      }
      
      printf("\nNúmero não encontrado");
      return 0;
  }
      
  int main(){
      
      int vet [] = {23,4,67,-8,54,90,21};
      int num;
      
      printf("\nQual número você quer buscar? ");
      scanf("%d",&num);
      
      busca(vet,7,num);
  
      return 0;
  }

// Busca Sequencial Ordenado

    int busca (int v[], int tam, int n){
        
        for(int i = 0; i <= tam; i++){
            
            if (n == v[i]){
                printf("\nA posição de %d é %d",n,(i+1));
                return 0;
            }
            else if (n < v[i]){
                printf("\nNúmero não encontrado");
                return 0;
            }
        }
        
        printf("\nNúmero não encontrado");
        return 0;
    }
        
    int main(){
        
        int vet [] = {-8,4,21,23,54,67,90};
        int num;
        
        printf("\nQual número você quer buscar? ");
        scanf("%d",&num);
        
        busca(vet,7,num);
    
        return 0;
  }

// Busca Binária

  int busca (int v[], int tam, int n) {
    
    int inicio,meio,fim;
    
    inicio = 0;
    fim = tam-1;
    
    
    while(inicio<=fim){
        
        meio=(inicio+fim)/2;
        
        if(v[meio] == n){
            return meio;
        }
        else{
            if(v[meio]<n){
                inicio = meio+1;
            }
            else{
                fim = meio-1;
            }
        }
    }
    
    printf("\nNúmero não Encontrado\n");
    return -1;
    }
    
    void imprimir(int *v, int n){
        
        printf("Vetor: ");
        
        for(int i = 0; i<n; i++){
            printf(" %d ", v[i]);
        }
    }
    
    int main(){
        
        int vet [] = {-8,4,21,23,54,67,90};
        int num;
        
        imprimir(vet,7);
        
        printf("\n\nQual número você quer buscar? ");
        scanf("%d",&num);
        
        printf("\nPosição: %d",busca(vet,7,num));
    
        return 0;
    }

// Busca Binária Recursiva

  int busca (int *v, int inicio, int fim, int n) {
      
      if(inicio<=fim){
          
          int meio=(inicio+fim)/2;
          
          if(v[meio] == n){
              return meio;
          }
          else{
              if(v[meio]>n){
                  return busca(v,inicio,meio-1,n);
              }
              else{
                  return busca(v,meio+1,fim,n);
              }
          }
      }
      
      printf("\nNúmero não Encontrado\n");
      return -1;
  }
  
  void imprimir(int *v, int n){
      
      printf("Vetor: ");
      
      for(int i = 0; i<n; i++){
          printf(" %d ", v[i]);
      }
  }
  
  int main(){
      
      int vet [] = {-8,4,21,23,54,67,90};
      int num;
      
      imprimir(vet,7);
      
      printf("\n\nQual número você quer buscar? ");
      scanf("%d",&num);
      
      printf("\nPosição: %d",busca(vet,0,7,num));
  
      return 0;
  }
