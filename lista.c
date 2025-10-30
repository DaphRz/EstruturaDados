#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
  int conteudo;
  struct cel *seg;
} cel;

typedef struct cel* Lista;

Lista* cria_lista(){
  Lista *li = (Lista*) malloc(sizeof(Lista));
  if(li != NULL){
    *li=NULL;
  }
  return li;
}

int insere_lista_fim(Lista* lista, int x){
  
  if(lista==NULL) {return 0;}
  
  cel* aux = (cel*) malloc(sizeof(cel));
  
  if(aux==NULL){return 0;}
  
  aux->conteudo = x;
  aux->seg = NULL;
  
  if(*lista == NULL){*lista = aux;}
  else{
    cel *temp;
    temp = *lista;
    
    while(temp->seg!= NULL){   //caminha até o utlimo elemento
      temp= temp->seg;
    }
    temp->seg = aux;
  }
  return 1;
}

int imprime_lista(Lista* lista){
  
    if(lista==NULL) {
      printf("Lista Não Existe");
    }
  
    cel *temp = *lista;
  
    printf("\n Minha lista:");
  
    while(temp != NULL){ 
        printf("\t%d", temp->conteudo);
        temp= temp->seg;
    }
 
    return 0;
}

int busca_lista(Lista* lista, int x){
  
    if(lista==NULL) {
      printf("Lista Não Existe");
      return 0;
    }
    cel *temp = *lista;
    
    while(temp != NULL){ 
        if(temp->conteudo == x){
            return 1;
        }
        temp= temp->seg;
    }
 
    return 0;
}

void libera_lista(Lista *lista)  // liberar toda a lista da memória — nó por nó, e depois o próprio ponteiro da lista.
{
    if(lista != NULL)
    {
        cel *aux;
        
        while(*lista != NULL)  // (?)  
        {
            aux = *lista;
            
            *lista = (*lista) -> seg;
            free(aux);
        }
      
        free(lista);
    }    
}

int remove_lista(Lista *lista,int x)   // Remover apenas um elemento específico (x) da lista. 
{
    if(lista == NULL) {return 0;}   // lista existe?
    if(*lista == NULL) {return 0;}  // lista esta vazia?

    cel* anterior, // cel* é um ponteiro de celula - um ponteiro q aponta pra estrutura cel 
    *aux = *lista;
    
    while(aux != NULL && aux->conteudo != x)
    {
        anterior = aux;
        aux = aux->seg;
    }
    
    if(aux == NULL){return 0 ;}   // se nao tiver elemento na lista
    
    if(aux == *lista)     // se for o primeiro elemento da lista
    {
        *lista = aux->seg;
    }
    else
    {
        anterior->seg = aux->seg;
    }
    free(aux);
    return 1;
}

int main(void) 
{
  Lista *lst;
  lst = cria_lista();
  insere_lista_fim(lst, 1);
  insere_lista_fim(lst, 2);
  insere_lista_fim(lst, 3);
  insere_lista_fim(lst, 4);
  insere_lista_fim(lst, 5);
  imprime_lista(lst);
  
  //printf("\n %d",busca_lista(lst, 3));

remove_lista(lst,3);

imprime_lista(lst);

  return 0;
}
