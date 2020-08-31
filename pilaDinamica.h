#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#define TAM_PILA 500

typedef struct SNodo
{
    void* dato;
    unsigned tamElem; //Tamanio del dato
    struct SNodo* sig; //Puntero nodo

} Nodo;

typedef Nodo* Pila; //

#endif // PILADINAMICA_H_INCLUDED
