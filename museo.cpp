/*----------------------------------------------------------------
|	Autor:                                                        |
|	Fecha:                            Versión: 1.0	              |
|-----------------------------------------------------------------|
|	Descripción del Programa:                                     |
|  								                                  |
| ----------------------------------------------------------------*/

// Incluir E/S y Librerías Standard
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "MError.h"
#include "MObra.h"
#include "MMuseo.h"

using namespace std;
using namespace MError;
using namespace MObra;
using namespace MMuseo;

// Zona de Declaración de Constantes

// Zona de Declaración de Tipos

// Zona de Cabeceras de Procedimientos y Funciones
char menu();
bool Confirmar();

// Programa Principal
int main()
{
  // Zona de Declaración de Variables del Programa principal
  char op;
  bool salir;
  TMuseo museo;
  TError err;
  TObra o;
  TTipoObra t;
  string nombre,ref,autor;
  float prom;
  
  salir = false;
  CrearMuseo(museo);
  
  while(!salir)
  {
    err = NoError;           
    op = menu();
    cout << endl;
    
    switch(op)
    {
       case 'A': LeerTipoObra(t,err);
                 if (err==NoError)
                 {
                    LeerObra(o);
                    InsertarObraMuseo(museo,t,o,err);
                 }
                 break;
       case 'B': cout << "Nombre del Fichero: ";
                 getline(cin,nombre,ENTER);
                 CargarMuseoFichero(museo,nombre,err);
                 break;
       case 'C': MostrarMuseo(museo,err);
                 break;
       case 'D': cout << "Referencia obra: ";
                 cin >> ref;
                 cin.ignore();
                 EliminarObraMuseo(museo,ref,err);
                 break;
       case 'E': cout << "Nombre del Fichero: ";
                 getline(cin,nombre,ENTER);
                 SalvarMuseoFichero(museo,nombre,err);
                 break;
       case 'F': cout << "Nombre del Autor: ";
                 getline(cin,autor,ENTER);
                 MostrarObrasAutor(museo,autor,err);
                 break;
       case 'G': prom=CalcularPromedioValoracion(museo,err);
                 if (err == NoError) {
                    cout << "Promedio valoracion obras: " << prom << endl;
                 }
                 break;
       case 'H': MostrarMuseoOrdenadoPorAnyo(museo);
                 break;
       case 'X': salir = Confirmar();
                 cout << endl << endl;
                 break; 
       default:  cout << "  Opcion Incorrecta ..." << endl;
                 cout << endl; 
                 break;
    }
    
    MostrarError(err);
    system("Pause"); // Hacer una pausa
    system("cls");   // Borrar Pantalla
  }
  DestruirMuseo(museo);
  return 0;	   // Valor de retorno al S.O.
}

// Implementación de Procedimientos y Funciones
char menu()
{
  char op;
  
  cout << "Nombre: (Apellidos, Nombre)    Curso: 1º" << endl;
  cout << "Especialidad: Sistemas         Grupo: A/B/C" << endl;
  cout << "Puesto: número de ordenador    Fecha: 02/09/2010" << endl;
  cout << endl;
  cout << "          Gestion Museo" << endl;
  cout << "          =============" << endl;
  cout << "  A. Insertar Obra." << endl;
  cout << "  B. Cargar Obras desde Fichero de Texto." << endl;
  cout << "  C. Mostrar Catalogo Museo." << endl;
  cout << "  D. Eliminar Obra." << endl;
  cout << "  E. Salvar Obras a Fichero de Texto." << endl;
  cout << "  F. Mostrar Obras de un mismo Autor." << endl;
  cout << "  G. Mostrar Promedio Valoracion Obras" << endl;
  cout << "  H. Mostrar Museo Ordenado Por Año." << endl;
  
  cout << "  X. Salir del Programa" << endl;
  cout << endl;
  cout << "  Introduzca su opcion: " ;
  
  cin >> op;
  cin.ignore();
  op = toupper(op);
  
  return op;

}

bool Confirmar()
{ 
  char car;

  cout << "?Esta seguro(S/N)?";
  cin >> car;
  cin.ignore();
  car = toupper(car);
  
  return (car=='S');
}


