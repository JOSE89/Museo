#ifndef _MMuseo_h_
#define _MMuseo_h_

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "MError.h"
#include "MObra.h"
#include "MListaObras.h"

using namespace std;
using namespace MError;
using namespace MObra;
using namespace MListaObras;

namespace MMuseo
{ 
    const int MAX_TIPOS = 4;
          
    typedef enum TTipoObra { Pintura, Escultura, Arqueologia, Otros };
    
    typedef TListaObras TMuseo[MAX_TIPOS];
    
    void LeerTipoObra(TTipoObra &t, TError &err);
    void EscribirTipoObra(TTipoObra t);
    
    void CrearMuseo(TMuseo &m);
    void DestruirMuseo(TMuseo &m);

    void InsertarObraMuseo(TMuseo &m, TTipoObra t, TObra o, TError &err);
    void MostrarMuseo(TMuseo &m, TError &err);

    void CargarMuseoFichero(TMuseo &m, string nomFich, TError &err);

    void EliminarObraMuseo(TMuseo &m, string ref, TError &err);

    // Opcion E
    void SalvarMuseoFichero(TMuseo &m, string nomFich, TError &err);

    // Opcion F
    void MostrarObrasAutor(TMuseo &m, string autor, TError &err);

    // Opcion G
    float CalcularPromedioValoracion(TMuseo &m,TError &err);    
    
    // Opcion H
    void MostrarMuseoOrdenadoPorAnyo(TMuseo &m);
}

#endif
