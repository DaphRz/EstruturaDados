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

// Selection Sort 
// do Final ao Início ordenando pelo Maior

  void selectionSortInvertido (int *v, int tam) {
      
      int maior, aux;
      
      // Loop principal: percorre o array de trás para frente
      for (int i = tam - 1; i > 0; i--) {
          
          // Assume que o último elemento não ordenado é o maior
          maior = i;
          
          // Loop aninhado: procura o maior elemento na sub-lista
          // movendo-se do final para o início da sub-lista.
          for (int j = i - 1; j >= 0; j--){
              
              // Se encontrar um elemento maior que o atual, atualiza o índice do maior
              if (v[j] > v[maior]){
                  maior = j;
              }
          }
          
          // Se o maior elemento não estiver na posição i, realiza a troca
          if (i != maior){
              
              aux = v[i];
              v[i] = v[maior];
              v[maior] = aux;
          }
      }
  }
  
   void imprimir (int *v, int n){
        
      printf("\nVetor: ");
        
      for (int i = 0; i<n; i++){
            
          printf(" %d ", v[i]);
      }
  }
    
  int main(){
        
      int vet [] = {-8,90,23,23,54,7,45};
  
      imprimir(vet,7);
    
      selectionSortInvertido(vet,7);
        
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

  /* O Insertion Sort funciona como se estivesse organizando cartas em uma mão:

  1. Ele considera o primeiro elemento como a parte "ordenada".

  2. A cada passo, ele pega o próximo elemento (v[i]) e o compara com os elementos da parte "ordenada" à sua esquerda.

  3. Se um elemento à esquerda for maior, ele é movido para a direita, liberando espaço.

  4. O processo de mover para a direita continua até que a posição correta seja encontrada.

  5. O elemento é inserido nessa posição. */


  void insertionSort (int *v, int tam) {
    
    int aux, j; // j: variável de controle para o loop interno, usada para percorrer a parte já ordenada do array
  
    for (int i = 1; i < tam; i++){  // A cada iteração, ele pega o elemento na posição i 
                                   // e o insere na sua posição correta na sub-lista ordenada à sua esquerda.
        aux = v[i];
            
        for (j = i; (j>0) && (aux < v[j-1]); j--){  // Este é o segundo loop (interno), responsável por 
                                                   // encontrar a posição correta para o valor em aux
                                                  // condição principal - O loop continua enquanto o valor em aux 
                                                 // for menor que o elemento à sua esquerda (v[j-1]).
                                                 
            v[j] = v[j-1];  // Se a condição do loop interno for verdadeira, 
                           // esta linha move o elemento da esquerda (v[j-1]) para a direita (v[j]). 
                          // Isso abre espaço para que o valor em aux seja inserido posteriormente. 
        }
        
        v[j] = aux;  // Quando o loop interno termina, o índice j estará na posição correta para a inserção. 
                    // Esta linha insere o valor armazenado em aux na posição j.
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
