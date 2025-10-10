// Lista Encadeada

    #include <stdio.h>
    #include <stdlib.h>
    
    typedef struct celula{
        int conteudo;
        struct celula *seguinte;
    } celula;
    
    // typedef struct celula celula  // cria apelido
    
    typedef struct celula* lista;  // apelido para ponteiro de célula
    
    lista* criar_lista(){
        lista *li = (lista*) malloc (sizeof(lista));
        
        if(li != NULL){     // se conseguiu alocar memória
            *li = NULL;    // inicializa a lista como vazia
        }
        return li;       // li = NULL // retorna o ponteiro para o ponteiro da lista
    }
    
    int add_fim(lista *lista, int x){   // ajustado para lista (celula*)
        
        if(lista == NULL) {return 0;}
        
        celula* aux = (celula*) malloc(sizeof(celula));
        
        if(aux == NULL) {return 0;}
        
        aux -> conteudo = x;
        aux -> seguinte = NULL;
        
        if((*lista) == NULL) {   // estou inserindo o primeiro elemento
            *lista = aux;       // se for o primeiro elemento da lista
        } else {
            celula *temp;
            temp = *lista;   // o primeiro elemento da lista
            
            while(temp->seguinte != NULL){
                temp = temp->seguinte;
            }
            
            temp->seguinte = aux;
        }
        
        return 1;
    }
    
    int imprimir(lista *lista){  
        
        if(lista == NULL) {
            printf("Lista não Existe!")
        }
        
        celula *temp;
        temp = *lista;  // temporário vai percorrer de 1 em 1
        
        printf("Minha Lista: ")
        
        while(temp != NULL){
            
            printf("\t%d", temp -> conteudo);
            temp = temp -> seguinte;
        }
    }
    
    int buscar(lista *lista, int x){  
        
        if(lista == NULL) {
            printf("Lista não Existe!")
            return 0;
        }
        
        celula *temp = *lista;
    
        while(temp != NULL){
            
            if(temp -> conteudo == x){
                return 1;
            }
            
            temp = temp -> seguinte;
        }
        
        return 0;
    }
    
    int main(){
        
        lista = *lst;          // declara lista
        lst = criar_lista();  // inicializa a lista
        
        celula c1, c2, c3;
        
        c1.conteudo = 1;  // variável concreta = . (p.conteudo)
        c2.conteudo = 2;
        c3.conteudo = 3;
        
        c1.seguinte = &c2;
        c2.seguinte = &c3;
        c3.seguinte = NULL;
        
        *lst = &c1;
        // apontam pro msm lugar (início da lista)
        celula* temp = *lst;
        
        while(temp != NULL){
            printf("\t%d", temp -> conteudo);  // ponteiro = -> ((*p).conteudo OU p -> conteudo)
            temp = temp -> seguinte;
        }
        
        imprimir(lst);
        
        printf("\n %d", buscar(lst, 3));
    
        return 0;
      }
