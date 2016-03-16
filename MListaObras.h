#ifndef _MListaObras_h_
#define _MListaObras_h_

#include "MError.h"
#include "MObra.h"

using namespace MObra;
using namespace MError;

namespace MListaObras
{ 

    
    typedef struct TNodo *TListaObras;
    
    struct TNodo
    {
        TObra obra;
        TListaObras sig;
    };
    
    void CrearLista(TListaObras &l);
    bool ListaVacia(TListaObras l);
    bool ListaLlena(TListaObras l);
    void InsertarLista(TListaObras &l, TObra o, TError &err);
    void ObtenerObraLista(TListaObras l, int posicion, TObra &o, TError &err);
    void EliminarObraLista(TListaObras &l, string ref, TError &err);

	int LongitudLista(TListaObras l);
    void DestruirLista(TListaObras &l);
}

#endif
