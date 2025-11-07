/******************************************************

Árvore Binária

* feita de ponteiro de ponteiro (**)
* (*p).info = p -> info
* pd ter valor repetido

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
        printf("%d ", (*raiz) -> info);
        preOrdem(&((*raiz) -> esq));    // passei o end dql ponteiro
        preOrdem(&((*raiz) -> dir));
    }
}

void ordem(ArvBin *raiz){   // ERD
    
    if(raiz ==  NULL){
        return;
    }
    if(*raiz != NULL){
        ordem(&((*raiz) -> esq));    // passei o end dql ponteiro
        printf("%d ", (*raiz) -> info);
        ordem(&((*raiz) -> dir));
    }
}

void posOrdem(ArvBin *raiz){   // EDR
    
    if(raiz ==  NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem(&((*raiz) -> esq));    // passei o end dql ponteiro
        posOrdem(&((*raiz) -> dir));
        printf("%d ", (*raiz) -> info);
    }
}

int peso(ArvBin *raiz){
    
    if(raiz ==  NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    
    int total_esq = peso(&((*raiz)->esq));
    int total_dir = peso(&((*raiz)->dir));
    
    return total_esq + total_dir +1;    // +1 = raiz 
}

int altura(ArvBin *raiz){
    
    if( raiz == NULL){
        return -1;
    }
    if(*raiz == NULL){
        return -1;
    }
    
    int alt_esq = altura(&((*raiz)->esq));
    int alt_dir = altura(&((*raiz)->dir));
    
    if(alt_esq>alt_dir){
        return alt_esq+1;
    } else{
        return alt_dir+1;
    }
}
    
int main(){
    
    ArvBin *raiz = cria_ArvBin();
    
    NO a,b,c,d,e,f,g,h,i;
    NO *converte = &a;  
    raiz = &converte;     // raiz = ponteiro de ponteiro pra a
    
    a.info = 80;
	a.esq = &b;
	a.dir = &c;
	b.info = 60;
	b.esq = &d;
	b.dir = &e;
	c.info = 90;
	c.esq = &f;
	c.dir = &g;
	d.info = 50;
	d.esq = NULL;
	d.dir = NULL;
	e.info = 70;
	e.esq = &h;
	e.dir = NULL;
	h.info = 65;
	h.esq = NULL;
	h.dir = NULL;
	f.info = 85;
	f.esq = NULL;
	f.dir = NULL;
	g.info = 110;
	g.esq = &i;
	g.dir = NULL;
	i.info = 100;
	i.esq = NULL;
	i.dir = NULL;

	printf("Pre-Ordem:\n");
	preOrdem_ArvBin(raiz);

	printf("\nEm-Ordem:\n");
	emOrdem_ArvBin(raiz);

	printf("\nPos-Ordem:\n");
	posOrdem_ArvBin(raiz);

	printf("\nTOTAL DE NOS:\n");
	//printf("%d", totalNosArvBin(raiz));
	printf("\nALTURA:\n");
	//printf("%d", altura_arvBin(raiz));
    
    return 0;
}

/******************************************************

Árvore Binária De Busca

* ñ pode ter valor repetido

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

int consulta(ArvBin *raiz, int valor){
    
    if (raiz == NULL){
        return 0;
    }
    
    NO *atual = *raiz;  // ponteiro de n´o chamado atual
    
    while(atual != NULL){
        
        if(valor == atual -> info){
            return 1;
        }
        if(valor>atual->info){
            atual = atual->dir;
        } else{
            atual= atual->esq;
        }
    } return 0;
}
    
int main(){
    
    ArvBin *raiz = cria_ArvBin();
    
    NO a,b,c,d,e,f,g,h,i;
    NO *converte = &a;  
    raiz = &converte;     // raiz = ponteiro de ponteiro pra a
    
    a.info = 80;
	a.esq = &b;
	a.dir = &c;
	b.info = 60;
	b.esq = &d;
	b.dir = &e;
	c.info = 90;
	c.esq = &f;
	c.dir = &g;
	d.info = 50;
	d.esq = NULL;
	d.dir = NULL;
	e.info = 70;
	e.esq = &h;
	e.dir = NULL;
	h.info = 65;
	h.esq = NULL;
	h.dir = NULL;
	f.info = 85;
	f.esq = NULL;
	f.dir = NULL;
	g.info = 110;
	g.esq = &i;
	g.dir = NULL;
	i.info = 100;
	i.esq = NULL;
	i.dir = NULL;
    
    return 0;
}
