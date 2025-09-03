// Selection Sort

  void selectionSort (int *v, int tam) {
    
    int menor, aux;
    
    for(int i=0; i<tam-1; i++) {      // percorre o vetor inteiro
        menor = i;
        
        for(int j = i+1; j<tam; j++){ // percorre do i até o final 
            
            if(v[j]<v[menor]){    // verifica se achou um menor q o atual
                menor = j;       // atualiza o menor
            }
        }
    if (i!=menor){        // se achou um n° menor q o lugar q estou (v[i]), eu troco
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
          }
      }
  }

  void imprimir(int *v, int n){
      
      printf("\nVetor: ");
      
      for(int i = 0; i<n; i++){
          printf(" %d ", v[i]);
      }
  }
  
  int main(){
      
      int vet [] = {-8,90,23,23,54,7,45};

      imprimir(vet,7);
  
      selectionSort(vet,7);
      
      imprimir(vet,7);
  
      return 0;
  }

// Bubble Sort

  void bubbleSort (int *v, int tam) {
    
  int troca, aux;
  
  do {
      
      troca = 0;
      
      for(int i = 0; i < tam-1; i++){
          
          if(v[i]>v[i+1]){
              
            aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
            
            troca = 1;
          }
      }
      
    } while(troca);  // troca == 1  == true 
                  // if (troca == false) sai do loop
  }

  void imprimir(int *v, int n){
    
    printf("\nVetor: ");
    
    for(int i = 0; i<n; i++){
        printf(" %d ", v[i]);
      }
  }

  int main(){
    
    int vet [] = {-8,90,23,23,54,7,45};

    imprimir(vet,7);
    printf("\n");

    bubbleSort(vet,7);
    
    imprimir(vet,7);

    return 0;
  }

// Insertion Sort

  void insertionSort (int *v, int tam) {
    
    int aux,aux1;
    aux1 = 1;
  
    for(int i = 0; i < tam; i++){
    
        if(v[i+1]<v[i]){
          
            aux = v[i+1];
            v[i] = v[i+1];
            v[i] = aux;
        }
        
    aux1++;
    
                            //for(int n = tam; n = 0; n--){
                                
                            //}
    }
  }

  void imprimir(int *v, int n){
    
    printf("\nVetor: ");
    
    for(int i = 0; i<n; i++){
        printf(" %d ", v[i]);
    }
  }

  int main(){
    
    int vet [] = {-8,90,23,23,54,7,45};

    imprimir(vet,7);
    printf("\n");

    insertionSort(vet,7);
    
    imprimir(vet,7);

    return 0;
  }
