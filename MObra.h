#ifndef _MObra_h_
#define _MObra_h_

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

namespace MObra 
{ 
    const char SEP = '#';
    const char SP  = ' ';
    const char ENTER  = '\n';
        
    struct TObra
    {
        string ref;
        string titulo;
        string autor;
        int anyo;
        float valoracion;
    };
    
    void LeerObra(TObra &a);
    void EscribirObra(TObra a);
    void LeerObraFicheroTXT(ifstream &fich, TObra &a);
    void EscribirObraFicheroTXT(ofstream &fich, TObra a);

}

#endif
