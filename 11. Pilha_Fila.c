/******************************************************

PILHA 

* só pode ver o topo dela
* pilha é um ponteiro para os nós que estão linkados

*******************************************************/

#include <stdio.h>
#include <stdlib.h>
    
typedef struct elemento{
int conteudo;
struct elemento *prox;
} elem;
    
typedef struct elemento* pilha;  // apelido para ponteiro de elemento
    
pilha* criar_pilha(){
    
    pilha* pi = (pilha*) malloc (sizeof(pilha));   // Aloca memória para o ponteiro da pilha
        
    if(pi != NULL){     // se conseguiu alocar memória
        *pi = NULL;    // inicializa a lista como vazia
    }
    
    return pi;       // pi = NULL // retorna o ponteiro para o ponteiro da pilha (!?)
}
    
int push(pilha* pi, int x){   // recebe pilha* p (elemento**)
        
    if(pi == NULL) {return -1;}
        
    elem *no = (elem*) malloc(sizeof(elem));
        
    if(no == NULL) {return -1;}  // conferir se espaço foi alocado
        
    no -> conteudo = x;
    no -> prox = (*pi);  // no->prox vai pegar o conteúdo de pilha
    
     // colocou x no topo da pilha
    // x tá apontando para o topo
    
    *pi = no;  // conteúdo de pilha está recebendo o nó
    
    return 1;
}

int pop(pilha* pi){
    
    if(pi == NULL || (*pi) == NULL) {return -1;}  // se a pilha existe e se o conteúdo da pilha não é vazio
    
    elem *no = *pi;    
    *pi = no -> prox;  // *pi -> prox;
    
    int valor_retorno = no -> conteudo;   // nó auxiliar para retornar o valor q eu tirei
    
    free(no);
    
    return valor_retorno;
}

void excluir(pilha* pi){  // receber a pilha
    
    if(pi != NULL){
        elem *no;    // referencia pra ir caminhando na pilha
        
        while((*pi) != NULL){
            
            no = *pi;  // pega o topo
            *pi = (*pi) -> prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo(pilha* pi){
    
    if(pi == NULL || (*pi) == NULL) {return -1;}   // *pi = conteúdo da pilha é um nó
    
    return (*pi) -> conteudo;                     // tô indo no nó e mostrando o conteúdo (int)
}

// não se faz essa função pq usa o conceito de Lista Encadeada
int imprimir(pilha* pi){   // recebe pilha* l (elemento**) <- (!?) 
        
    if(pi == NULL) {
        printf("Lista não Existe!");
    }
    else {
        elem* no = *pi;  // primeiro elemento da pilha
        
        printf("\nTOPO PILHA");
        
        while(no != NULL){
            printf("\nConteúdo: %d", no -> conteudo);  // nó é ponteiro (com uma struct)
            no = no -> prox;
        }
        printf("\nBASE PILHA");
    }
}
    
int main(){
        
    pilha *pi;            // declara pilha  // pilha *pi = criar_pilha();
    pi = criar_pilha();  // inicializa a lista

    push(pi,0);
    push(pi,1);
    push(pi,2);
    
    imprimir(pi);
    pop(pi);
    imprimir(pi);
    
    return 0;
}
