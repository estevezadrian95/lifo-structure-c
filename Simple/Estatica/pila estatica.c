//PILA ESTATICA
#include <stdio.h>
#include <stdlib.h>
#define TAM 10 //tamaño que sea necesario

typedef struct
{

}t_info;

typedef struct
{
    t_info pila[TAM];
    int tope;
}t_pila;

void crearPila(t_pila *p)
{
    p -> tope=0;
}

int pilaLlena(const t_pila *p)
{
    return p -> tope==TAM;
}

int apilar(t_pila *p, const t_info *d)
{
    if(p -> tope==TAM)
        return 0;
    p -> pila[p->tope]=*d;
    p -> tope++;
    return 1;
}

int pilaVacia(const t_pila *p)
{
    return p -> tope == 0;
}

int verTope(const t_pila *p, t_info *d)
{
    if(p -> tope==0)
        return 0;
    *d= p -> pila[p->tope-1];
    return 1;
}

int desapilar(t_pila *p, t_info *d)
{
    if(p -> tope==0)
        return 0;
    p -> tope--;
    *d= p ->pila[p->tope];
    return 1;
}

void vaciarPila(t_pila *p)
{
    p -> tope=0;
}
