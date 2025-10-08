// Lista Encadeada

    #include <stdio.h>
    
    typedef struct celula{
        int conteudo;
        struct celula *seguinte;
    } celula;
    
    // typedef struct celula celula // cria apelido
    
    typedef struct celula* lista;  // ponteiro de célula
    
    lista* criar_lista(){
        lista *li = (lista*) malloc (sizeof(lista));
        
        if(li != NULL){     // se conseguiu alocar memória
            *li = NULL;
        }
        return li;        // li = NULL
    }
    
    int add_fim(Lista *lista, int x){
        
        if(lista == NULL) {return 0;}
        
        celula* aux = (celula*) malloc(sizeof(celula));
        
        if(aux == NULL) {return 0;}
        
        aux -> conteudo = x;
        aux -> seguinte = NULL;
        
        if((*lista)) == NULL) {  // estou inserindo o primeiro elemento
            *lista = aux;       // se for o primeiro elemento da lista
        } else {
            cel *temp;
            temp = *lista;  // o primeiro elemento da lista
            
            while(temp->seguinte != NULL){
                temp = temp->seguinte;
            }
            
            temp->seguinte = aux;
        }
        
        return 1;
    }
    
      int main(){
        
        Lista = *lst;
        lst = criar_lista();
        
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
    
        return 0;
      }
