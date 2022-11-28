//PILA DINAMICA
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char apyn[30];
}t_info;

typedef struct s_nodo
{
    t_info info;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo* t_pila; //Sirve para mantener el mismo main que el de pila estatica

void crearPila(t_pila *); //debo pasarrlo por *
int pilaLlena(const t_pila *); //me combiene pasarlo por *
int apilar(t_pila *, const t_info *);
int pilaVacia(const t_pila *);
int verTope(const t_pila *, t_info *);
int desapilar(t_pila *, t_info *);
void vaciarPila(t_pila *);
void mostrar(t_info *);
int mostrar1(t_pila *);
int cargarInfo(t_info *);

int main()
{
    t_info info;
    t_pila pila; //una direccion ocupa dos bytes. En este caso pila almacena la direccion de t_nodo
    crearPila(&pila);
    if(!pilaLlena(&pila))
        if(cargarInfo(&info))
            apilar(&pila, &info);

    if(!pilaVacia(&pila))
    {
        if(verTope(&pila, &info))
            mostrar(&info);
            printf("\n\n");
            mostrar1(&pila);
        desapilar(&pila, &info);
    }
    vaciarPila(&pila);
    return 0;
}

void crearPila(t_pila *p)
{
    *p=NULL;
}

int pilaVacia(const t_pila *p)
{
    return *p==NULL;
}

int pilaLlena(const t_pila *p)
{
    t_nodo *aux = (t_nodo *)malloc(sizeof(t_nodo));
    free(aux);
    return aux == NULL;
}


int apilar(t_pila *p, const t_info *d)
{
    t_nodo *nue=(t_nodo *)malloc(sizeof(t_nodo));
    if(nue==NULL)
        return 0;
    nue -> info = *d;
    nue -> sig = *p;
    *p = nue;
    return 1;
}

int verTope(const t_pila *p, t_info *d)
{
    if(*p==NULL)
        return 0;
    *d = (*p) -> info;
    return 1;
}

int desapilar(t_pila *p, t_info *d)
{
    t_nodo *aux;
    if(*p == NULL)
        return 0;
    aux = *p;
    *d = aux -> info;
    *p = aux -> sig;
    free(aux);
    return 1;
}

void vaciarPila(t_pila *p)
{
    t_nodo *aux;
    while(*p)
    {
        aux = *p;
        *p = aux -> sig;
        free(aux);
    }
}

int cargarInfo(t_info *d)
{
    printf("ingrse dni: ");
    scanf("%d",&d->dni);
    fflush(stdin);
    printf("\ningrese apellido y nombre: ");
    gets(d->apyn);
    return 1;
}

void mostrar(t_info *d)
{
    printf("\n\nDNI: %d\nApellido y Nombre: %s",d->dni,d->apyn);
}

int mostrar1(t_pila *p)
{
    t_pila *aux;
    aux = p;
    if((*aux)==NULL)
        return 0;
    while((*aux)->sig!=NULL)
    {
        printf("\n-> dni: %d  apyn: %s ",(*aux)->info.dni,(*aux)->info.apyn);
        *aux = (*aux)->sig;
    }
    printf("\n-> dni: %d  apyn: %s ",(*aux)->info.dni,(*aux)->info.apyn);
}

