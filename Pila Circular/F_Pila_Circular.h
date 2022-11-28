#ifndef F_PILA_CIRCULAR_H_INCLUDED
#define F_PILA_CIRCULAR_H_INCLUDED

typedef struct{

    int  clave;
    char nombre[15];
}t_info;

typedef struct snodo{

    struct snodo *sig;
    t_info info;
}t_nodo, *t_pila_c;


void crear_pila_circular (t_pila_c *p);
int pila_llena (t_pila_c *p);
int pila_vacia (t_pila_c *p);
int poner_en_pila_circular(t_pila_c *p, t_info *d);
int sacar_de_pila_circular (t_pila_c *p, t_info *d);
void vaciar_pila_circular (t_pila_c *p);
int ver_tope_pila (t_pila_c *p, t_info *d);

#endif // F_PILA_CIRCULAR_H_INCLUDED
