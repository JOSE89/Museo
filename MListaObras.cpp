#include "MListaObras.h"

namespace MListaObras
{ 
    
    void CrearLista(TListaObras &l)
    {
        l = NULL;
    }
    
    bool ListaVacia(TListaObras l)
    {
        return (l==NULL);
    }
    
    bool ListaLlena(TListaObras l)
    {
        TListaObras aux;
        bool llena;
        
        aux = new TNodo;
        llena = (aux==NULL);
        if (!llena)
        {
           delete aux; //Se borra porque se ha creado para ver si se podía
        }
        
        return llena;
    }
     
    void InsertarLista(TListaObras &l, TObra o, TError &err)
    {
        TListaObras nuevoNodo;
        
        if ( (ListaVacia(l)) || o.anyo < l->obra.anyo )
        {
           // Inserto por la cabeza
           if (ListaLlena(l))
           {
               err = ErrorListaLlena;
           }  
           else
           {
               err = NoError;
               nuevoNodo = new TNodo;
               nuevoNodo->obra = o;
               nuevoNodo->sig = l;
               l = nuevoNodo;
           }
        }
        else
        {
             InsertarLista(l->sig,o,err);
        }
    }
    
    
    void ObtenerObraLista(TListaObras l, int posicion, TObra &o, TError &err)
    {
        TListaObras ptr;
        int i;
        
        if (posicion < LongitudLista(l))
        {
            err = NoError;
            ptr = l;
            
            for(i=0; i < posicion; ++i)
            {
                   ptr = ptr->sig;
            }
            
            o = ptr->obra;
        }
        else
        {
             err = ErrorObraNoEncontrada;
        }
    }



    void EliminarObraLista(TListaObras &l, string ref, TError &err)
    {
        TListaObras ptr,ant;
        
        err = NoError;
        ptr=l;
        ant=NULL;

        while ((ptr != NULL) && (ptr->obra.ref != ref))
        {
            ant=ptr;
            ptr = ptr->sig;
        }
        
        if (ptr != NULL) {    
            if (ant==NULL) {
                l=l->sig;
                }
            else {
                ant->sig=ptr->sig;
            }
            delete ptr;
        }
        else
        {
             err = ErrorObraNoEncontrada;
        }
    }



    
    
	int LongitudLista(TListaObras l)
	{
        int i;
        TListaObras ptr;
        
        ptr = l;
        i=0;
        
        while (ptr!=NULL)
        {
              ++i;
              ptr = ptr->sig;
        }
        
        return i;
    }
    
    
    void DestruirLista(TListaObras &l)
    {
        TListaObras ptr;
        
        while (l!=NULL)
        {
              ptr=l;
              l=l->sig;
              delete ptr;
        }
    }
}

