#include "MError.h"


namespace MError
{ 
void MostrarError(TError err)
{
     cout << endl;
     switch(err)
     {
        case ErrorListaLlena: 
                   cout << "ERROR: La lista está Llena." 
                        << endl; 
                   break;
        case ErrorListaVacia: 
                   cout << "ERROR: La Lista está Vacia." 
                        << endl; 
                   break;
        case ErrorFichero:
                   cout << "ERROR: No se puede abrir el fichero." 
                        << endl; 
                   break;
        case ErrorObraNoEncontrada:
                   cout << "ERROR: La obra NO se encuentra." 
                        << endl; 
                   break;
        case ErrorTipoObraDesconocida:
                   cout << "ERROR: El tipo de obra no es correcto." 
                        << endl; 
                   break;
        case NoError:
                   cout << "Operacion Realizada Correctamente." 
                        << endl; 
                   break;
     }
     
}}

