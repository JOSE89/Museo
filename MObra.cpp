#include "MObra.h"

namespace MObra 
{ 
    
    void LeerObra(TObra &o)
    {
         cout << "Referencia:";
         getline(cin,o.ref,ENTER);
         cout << "Titulo:";
         getline(cin,o.titulo,ENTER);
         cout << "Autor:";
         getline(cin,o.autor,ENTER);
         cout << "Anyo:";
         cin >> o.anyo;
         cout << "Valoracion:";
         cin >> o.valoracion;
         cin.ignore();
    }
    
    void EscribirObra(TObra o)
    {
         cout << "Referencia: " << o.ref << endl;
         cout << "Titulo: " << o.titulo << endl;
         cout << "Autor: " << o.autor << endl;
         cout << "Anyo: " << o.anyo << endl;
         cout << "Valoracion: " << o.valoracion << endl;
    }

    void LeerObraFicheroTXT(ifstream &fich, TObra &o)
    {
        //Ref#Titulo
        //Autor#Año Valoracion
                
         getline(fich,o.ref,SEP);
         getline(fich,o.titulo,ENTER);
         getline(fich,o.autor,SEP);
         fich >> o.anyo;
         fich >> o.valoracion;
         fich.ignore();
    }


    void EscribirObraFicheroTXT(ofstream &fich, TObra o)
    {
        fich << o.ref << SP << o.titulo << endl;
        fich << o.autor << SEP << o.anyo << SP << o.valoracion << endl;
    }

}
