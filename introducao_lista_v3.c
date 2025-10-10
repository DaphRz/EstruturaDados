#include <stdio.h>
#include<stdlib.h>

typedef struct cel{
  int conteudo;
  struct cel *seg;
}cel;

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
  if((*lista)==NULL){ *lista = aux;}
  else{
    cel *temp;
    temp = *lista;
    while(temp->seg!= NULL){ //caminha até o utlimo elemento
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


int main(void) {
  Lista *lst;
  lst = cria_lista();
  insere_lista_fim(lst, 1);
  insere_lista_fim(lst, 2);
  insere_lista_fim(lst, 3);
  insere_lista_fim(lst, 4);
  insere_lista_fim(lst, 5);
  imprime_lista(lst);
  printf("\n %d",busca_lista(lst, 3));



  return 0;
}
