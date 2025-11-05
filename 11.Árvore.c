/******************************************************

Árvore 

* feita de ponteiro de ponteiro (**)
* (*p).info = p -> info

*******************************************************/

#include <stdio.h>
#include <stdlib.h>
    
typedef struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
} NO;
    
typedef struct NO *ArvBin;  // arvore é um end de um nó = **NO

ArvBin* cria_ArvBin(){     // retornar ponteiro de arvore binario

    ArvBin *raiz = (ArvBin*) malloc (sizeof(ArvBin));   // raiz = variável do tipo ponteiro
    
    if(raiz != NULL){   // consegui alocar
        *raiz = NULL;   // conteudo da raiz
    }
    
    return raiz;
}

void preOrdem(ArvBin *raiz){  // RED
    
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){                // conteúdo da raiz / árvore
        printf("%d ", *raiz -> info);
        preOrdem(&(*raiz -> esq));    // passei o end dql ponteiro
        preOrdem(&(*raiz -> dir));
    }
}

void ordem(ArvBin *raiz){   // ERD
    
    if(raiz ==  NULL){
        return;
    }
    if(*raiz != NULL){
        ordem(&(*raiz -> esq));    // passei o end dql ponteiro
        printf("%d ", *raiz -> info);
        ordem(&(*raiz -> dir));
    }
}

void posOrdem(ArvBin *raiz){   // EDR
    
    if(raiz ==  NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem(&(*raiz -> esq));    // passei o end dql ponteiro
        posOrdem(&(*raiz -> dir));
        printf("%d ", *raiz -> info);
    }
}

int peso(ArvBin *raiz){
    
    if(raiz ==  NULL){
        return;
    }
    if(*raiz != NULL){
        quant = 0;
        peso(&(*raiz -> esq));
        quant++;
    }
}
    
int main(){
    
    ArvBin *raiz = cria_ArvBin();
    
    NO a,b,c,d,e,f,g,h,i;
    NO *converte = &a;  
    raiz = &converte;     // raiz = ponteiro de ponteiro pra a
    
    return 0;
}
