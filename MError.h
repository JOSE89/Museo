#ifndef _MError_h_
#define _MError_h_

#include <iostream>
#include <cstdlib>

using namespace std;

namespace MError
{ 
    typedef enum TError
    { 
        ErrorListaLlena, ErrorListaVacia, ErrorTipoObraDesconocida, 
        ErrorFichero, ErrorObraNoEncontrada,NoError
    };
  
    void MostrarError(TError err);

}

#endif
