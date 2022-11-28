#ifndef FUNCIONES_PILA_H_INCLUDED
#define FUNCIONES_PILA_H_INCLUDED
#define TAM 10

typedef struct{

    int clave;
    char nombre[30];
}t_info;

typedef struct snodo{

    struct snodo *sig;
    t_info info;
}t_nodo_pila,*t_pila_D,*t_pila_C;

typedef struct{

    t_info info[TAM];
    int tope;
}t_pila_S;

/**PILA ESTATICA**/
void crear_pila_estatica(t_pila_S *p);
int pila_llena_estatica(t_pila_S *p);
int pila_vacia_estatica(t_pila_S *p);
int poner_en_pila_estatica(t_pila_S *p,t_info *d);
int sacar_de_pila_estatica(t_pila_S *p,t_info *d);///revisar
void vaciar_pila_estatica(t_pila_S *p);
int ver_tope_pila_estatica(t_pila_S *p, t_info *d);


/**PILA DINAMICA**/
void crear_pila_dinamica(t_pila_D *p);
int pila_llena_dinamica(t_pila_D *p);
int pila_vacia_dinamica(t_pila_D *p);
int sacar_de_pila_dinamica(t_pila_D *p, t_info *d);
void vaciar_pila_dinamica(t_pila_D *p);
int ver_tope_pila_dinamica(t_pila_D *p,t_info *d);

/**PILA CIRCULAR**/
void crear_pila_circular(t_pila_C *p);
int pila_llena_circular(t_pila_C *p);
int poner_en_pila_circular(t_pila_C *p, t_info *d);
int sacar_de_pila_circular(t_pila_C *p, t_info *d);
void vaciar_pila_circular(t_pila_C *p);
int ver_tope_pila_circular(t_pila_C *p,t_info *d);



#endif // FUNCIONES_PILA_H_INCLUDED
