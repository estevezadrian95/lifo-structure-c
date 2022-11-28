#include"Funciones_Pila.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
/**PILA ESTATICA**/
void crear_pila_estatica(t_pila_S *p){

    p->tope=0;
}

int pila_llena_estatica(t_pila_S *p){

return p->tope==TAM;

}

int pila_vacia_estatica(t_pila_S *p){

    return p->tope==0;
}

int poner_en_pila_estatica(t_pila_S *p,t_info *d){

    if(p->tope==TAM)
        return 0;///pila llena

    p->info[p->tope]=*d;
    p->tope++;

    return 1;///TODO_BIEN
}

int sacar_de_pila_estatica(t_pila_S *p,t_info *d){///revisar

    if(p->tope==0)
        return 0;///PILA_VACIA
    p->tope--;
    *d=p->info[p->tope];
    return 1;///TODO_BIEN
}

void vaciar_pila_estatica(t_pila_S *p){

    p->tope=0;

}

int ver_tope_pila_estatica(t_pila_S *p, t_info *d){

    if(p->tope==0)
        return 0;///PILA_VACIA
    *d=p->info[p->tope];
    return 1;
}


/**PILA DINAMICA**/
void crear_pila_dinamica(t_pila_D *p){

    *p=NULL;
}

int pila_llena_dinamica(t_pila_D *p){

    t_nodo_pila *nuevo=(t_nodo_pila*)malloc(sizeof(t_nodo_pila));
    free(nuevo);
return nuevo==NULL;
}

int pila_vacia_dinamica(t_pila_D *p){

return *p==NULL;
}

int poner_en_pila_dinamica(t_pila_D *p, t_info *d){

    t_nodo_pila *nuevo=(t_nodo_pila*)malloc(sizeof(t_nodo_pila));

    if(nuevo==NULL)
        return 0;///SIN_MEM

    nuevo->info = *d;
    nuevo->sig  = *p;
    *p          = nuevo;
    return 1;
}

int sacar_de_pila_dinamica(t_pila_D *p, t_info *d){

    t_nodo_pila *aux;

    if(*p==NULL)
        return 0;///NADA

    aux = *p;
    *d  = aux->info;
    *p  = aux->sig;
    free(aux);
return 1;///TODO_BIEN
}

void vaciar_pila_dinamica(t_pila_D *p){

    t_nodo_pila *aux;

    while(*p)
    {
        aux=*p;
        *p=aux->sig;
        free(aux);
    }
}

int ver_tope_pila_dinamica(t_pila_D *p,t_info *d){

    if(*p==NULL)
        return 0;///PILA_VACIA

    *d=(*p)->info;
return 1;
}


/**PILA CIRCULAR**/
void crear_pila_circular(t_pila_C *p){

    *p=NULL;
}

int pila_llena_circular(t_pila_C *p){

    t_nodo_pila *nuevo=(t_nodo_pila*)malloc(sizeof(t_nodo_pila));
    free(nuevo);
return nuevo==NULL;
}

int pila_vacia_circular(t_pila_C *p){

return *p==NULL;
}

int poner_en_pila_circular(t_pila_C *p, t_info *d){

    t_nodo_pila *nuevo=(t_nodo_pila*)malloc(sizeof(t_nodo_pila));

    if(nuevo==NULL)
        return 0;

    nuevo->info = *d;

    if(*p==NULL)
    {   ///caso del primer nodo
        nuevo->sig = nuevo;
        (*p)       =nuevo;
    }
    else
    {
        nuevo->sig = (*p)->sig;
        (*p)->sig  = nuevo;
    }
return 1;
}

int sacar_de_pila_circular(t_pila_C *p, t_info *d){

    t_nodo_pila *aux;

    if(*p==NULL)
        return 0;///PILA_VACIA

    aux=(*p)->sig;
    *d  = aux->info;

    if(aux != (*p)->sig)
    {
        (*p)= aux->sig;
        free(aux);
    }
    else
    {
        *p = NULL;
        free(aux);
    }
return 1;
}

void vaciar_pila_circular(t_pila_C *p){

    t_nodo_pila *aux;

    while(*p)
    {
        aux = (*p)->sig;
        *p  = aux ->sig;

        if(aux==*p)
            *p=NULL;

        free(aux);
    }
}

int ver_tope_pila_circular(t_pila_C *p,t_info *d){

    if(*p==NULL)
        return 0;///PILA_VACIA

    *d=(*p)->info;
return 1;///TODO_OK
}
