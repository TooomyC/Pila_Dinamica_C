#include <stdlib.h>
#include <memory.h>
#include <pilaDinamica.h>
#include <defines.h>

void crearPila(Pila* ppila) //ppila para no confundir con pila de la estatica
{
    *ppila = NULL;
}

int apilar(Pila* ppila, const void* d, unsigned tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo)); //Se castea porque Malloc devuelve void, sino devuelve warning.

    if(!nue) //Por si Malloc no encuentra memoria
        return FALSO;

    nue->dato = malloc(tamElem);

    if(!nue->dato)
    {
        free(nue->dato);
        return FALSO;
    }

    nue->tamElem = tamElem;

    memcpy(nue->dato, d, tamElem); //Se hace memcpy porque no se sabe a que apunta

    nue->sig = *ppila /// (1)
    *ppila = nue; /// (2)

    return VERDADERO;

}

int desapilar(Pila* ppila, void* d, unsigned tamElem)
{
    if(!*ppila)
        return FALSO;

    Nodo* nae = *ppila; /// (1)
    *ppila = nae->sig; /// (2)
    memcpy(d, nae->dato, minimo(nae->tamElem, tamElem));

    free(nae->dato);
    free(nae);

    return VERDADERO;
}

int topePila(const Pila* ppila, void* d, unsigned tamElem)
{
    if(!*ppila)
        return FALSO;

    Nodo* ntope = *ppila;
    memcpy(d, ntope->dato, minimo(ntope->tamElem, tamElem));

    return VERDADERO;
}

void vaciarPila(Pila* ppila)
{
    if(!*ppila)
        return VERDADERO;
}

int pilaVacia(const Pila* ppila)
{
    return !*ppila; //*ppila == NULL
}

int pilaLlena(const Pila* ppila, unsigned tamElem)
{
    Nodo* nae;
    while(*ppila)
    {
        nae = *ppila; /// (1)
        *ppila = nae->sig; /// (2)
        free(nae->dato);
        free(nae);
    }

    return !p; //p == NULL
}
