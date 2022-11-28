#include <stdio.h>
#include <stdlib.h>
#include"F_Pila_Circular.h"

void crear_pila_circular (t_pila_c *p){
*p=NULL;
}

int pila_llena (t_pila_c *p){

    t_nodo *aux = (t_nodo*)malloc(sizeof(t_nodo));
    free(aux);
return aux==NULL;
}

int pila_vacia (t_pila_c *p){

    return *p==NULL;
}

int poner_en_pila_circular(t_pila_c *p, t_info *d){

    t_nodo *nuevo=(t_nodo*)malloc(sizeof(t_nodo));
    if(nuevo==NULL)
        return 0;

    nuevo->info = *d;

    if(*p==NULL)
    {
        nuevo->sig = nuevo;
        *p         = nuevo;
    }
    else
    {
        nuevo->sig = (*p)->sig;
        (*p)->sig  = nuevo;
    }
return 1;
}

int sacar_de_pila_circular (t_pila_c *p, t_info *d){

    t_nodo *aux;

    if(*p==NULL)
        return 0;///NADA EN LISTA

    aux  =  (*p)->sig;
    *d   =  aux->info;

    if(aux == aux->sig)///PREGUNTA SI ES EL ULTIMO NODO DE LA PILA
    {
        *p=NULL;
    }
    else
    {
        (*p)->sig=aux->sig;
        free(aux);
    }
return 1;
}

void vaciar_pila_circular (t_pila_c *p){

    t_nodo *aux;

    while(*p!=NULL)
    {
        aux=(*p)->sig;
        (*p)->sig=aux->sig;
        if(aux == *p)
        {
            *p=NULL;
        }
        free(aux);
    }
}

int ver_tope_pila (t_pila_c *p, t_info *d){

    if(*p==NULL)
        return 0;///NADA EN PILA

    *d  = (*p)->info;
return 1;
}
