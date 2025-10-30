// Lista Encadeada

    #include <stdio.h>
    #include <stdlib.h>
    
    typedef struct celula{
    int conteudo;
    struct celula *seguinte;  // criando um Ponteiro para outra Struct do mesmo tipo  
    } celula;
    
    // typedef struct celula {} celula  // cria apelido
    
    typedef struct celula* lista;  // apelido para Ponteiro de Célula (celula*)
    
    lista* criar_lista(){
        lista *li = (lista*) malloc (sizeof(lista));   // aloca memória para o Ponteiro da Lista (celula**)
        
        if(li != NULL){     // se conseguiu alocar memória
            *li = NULL;    // inicializa a lista como vazia
        }
        return li;       // li = NULL // retorna o ponteiro para o ponteiro da lista
    }
    
    int add_fim(lista* l, int x){   // ajustado para lista (celula*) // recebe lista* l (celula**)
        
        if(l == NULL) {return 0;}
        
        celula* aux = (celula*) malloc(sizeof(celula));
        
        if(aux == NULL) {return 0;}
        
        aux -> conteudo = x;
        aux -> seguinte = NULL;
        
        if(*l == NULL) {      // estou inserindo o primeiro elemento
            *l = aux;        // se for o primeiro elemento da lista, atualiza o ponteiro que aponta para o inicio da lista
        } 
        else {
            celula *temp;
            temp = *l;    // o primeiro elemento da lista
            
            while(temp -> seguinte != NULL){  //caminha até o último elemento
                temp = temp -> seguinte;
            }
            
            temp -> seguinte = aux;
        }
        
        return 1;
    }
    
    int imprimir(lista* l){   // recebe lista* l (celula**)
        
        if(l == NULL) {
            printf("Lista não Existe!");
        }
        
        celula *temp;
        temp = *l;  // temporário vai percorrer de 1 em 1
        
        printf("Minha Lista: ");
        
        while(temp != NULL){
            
            printf("\t%d", temp -> conteudo);
            temp = temp -> seguinte;
        }
    }
    
    int buscar(lista* l, int x){  // recebe lista* l (celula**)
        
        if(l == NULL) {
            printf("Lista não Existe!");
            return 0;
        }
        
        celula *temp = *l;
    
        while(temp != NULL){
            
            if(temp -> conteudo == x){
                return 1;
            }
            
            temp = temp -> seguinte;
        }
        
        return 0;
    }
    
    int main(){
        
        lista *lst;          // declara lista
        lst = criar_lista();  // inicializa a lista

        // As linhas a seguir criam e encadeiam células na stack (memória local)
        // O correto seria usar add_fim para gerenciar a lista alocada dinamicamente.
        
        celula c1, c2, c3;
        
        c1.conteudo = 1;  // variável concreta = . (p.conteudo)
        c2.conteudo = 2;
        c3.conteudo = 3;
        
        c1.seguinte = &c2;
        c2.seguinte = &c3;
        c3.seguinte = NULL;
        
        *lst = &c1;
        // apontam pro msm lugar (início da lista) // Faz o ponteiro dinâmico 'lst' apontar para a célula estática 'c1'
        celula* temp = *lst;
        // Bloco de impressão 1 (Exibe 1, 2, 3)
        
        while(temp != NULL){
            printf("\t%d", temp -> conteudo);  // ponteiro = -> ((*p).conteudo OU p -> conteudo)
            temp = temp -> seguinte;
        }
        
        printf("\n\n");
        imprimir(lst);
        
        printf("\n\n%d\n\n", buscar(lst, 3));

        add_fim(lst, 4);
        imprimir(lst);
    
        return 0;
      }
