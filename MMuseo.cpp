#include "MMuseo.h"

namespace MMuseo
{ 
    // CABECERAS PROCEDIMIENTOS Y FUNCIONES AUXILIARES      
    TTipoObra SUC(TTipoObra t);
    string Mayusculas(string s);
    string TipoObra_a_Cadena(TTipoObra t);
    void Cadena_a_TipoObra(string s, TTipoObra &t, TError &err);
    
  
    // IMPLEMENTACION DE LA FUNCIONALIDAD DEL MÓDULO
    void LeerTipoObra(TTipoObra &t, TError &err)
    {
         string s;
         
         cout << "Tipo obra: ";
         getline(cin,s,ENTER);
         Cadena_a_TipoObra(s,t,err);
    }
    
    void EscribirTipoObra(TTipoObra t)
    {
         cout << TipoObra_a_Cadena(t);
    }
    
    void CrearMuseo(TMuseo &m)
    {
         TTipoObra t;
         
         for(t=Pintura;t<=Otros;t=SUC(t))
         {
             CrearLista(m[t]);
         }         
    }
    
    void InsertarObraMuseo(TMuseo &m, TTipoObra t, TObra o, TError &err)
    {
         InsertarLista(m[t],o,err);
    }
    
    
    void MostrarMuseo(TMuseo &m, TError &err)
    {
         TTipoObra t;
         int pos;
         TObra o;
         
         for(t=Pintura;t<=Otros;t=SUC(t))
         {
             cout << "Tipo obra: "; 
             EscribirTipoObra(t);
             cout << endl;
             for(pos=0;pos<LongitudLista(m[t]);++pos)
             {
                  ObtenerObraLista(m[t],pos,o,err);
                  EscribirObra(o);
                  cout << endl;
             }
             cout << endl;
         }         
    }

    
    
    void EliminarObraMuseo(TMuseo &m, string ref, TError &err)
    {
         TTipoObra t;
         
         err = ErrorObraNoEncontrada;
         t=Pintura;
         while ( (t <= Otros) && (err != NoError) )
         {
            EliminarObraLista(m[t],ref,err);
            t = SUC(t);
         }         
    }

   
    
    
    void CargarMuseoFichero(TMuseo &m, string nomFich, TError &err)
    {
         ifstream fich;
         TObra o;
         TTipoObra t;
         string s;
         int i,num;
         
         fich.open(nomFich.c_str());
         if ( fich.bad() || fich.fail() )
         {
             err = ErrorFichero; 
         }
         else
         {
             DestruirMuseo(m);

             getline(fich,s,SEP);
             while (!fich.eof())
             {
                   Cadena_a_TipoObra(s,t,err);
                   fich >> num;
                   fich.ignore();
                   for(i=0;i<num;++i)                   
                   {
                       LeerObraFicheroTXT(fich,o);
                       InsertarObraMuseo(m,t,o,err);
                   }
                   getline(fich,s,SEP);
             }
             fich.close();
             err = NoError;             
         }
    }
    
    
    
    void SalvarMuseoFichero(TMuseo &m, string nomFich, TError &err)
    {
         ofstream fich;
         TObra o;
         TTipoObra t;
         int pos,num;
         
         fich.open(nomFich.c_str());
         if ( fich.bad() || fich.fail() )
         {
             err = ErrorFichero; 
         }
         else
         {
             for(t=Pintura;t<=Otros;t=SUC(t))
             {
                  num = LongitudLista(m[t]);                        
                  fich << TipoObra_a_Cadena(t) << SEP << num << endl;
                  for(pos=0;pos<num;++pos)
                  {
                      ObtenerObraLista(m[t],pos,o,err);
                      EscribirObraFicheroTXT(fich,o);
                  }
             }  
             fich.close();
             err = NoError;             
         }
    }



    void MostrarObrasAutor(TMuseo &m, string autor, TError &err) 
    {
         TObra o;
         TTipoObra t;
         int pos,num;
         
         cout << "Obras autor: " << autor << endl;
         for(t=Pintura;t<=Otros;t=SUC(t))
         {
            num = LongitudLista(m[t]);                        
            for(pos=0;pos<num;++pos)
            {
                ObtenerObraLista(m[t],pos,o,err);
                if (o.autor==autor) {
                    EscribirObra(o);
                    cout << endl;
                }
            }
         }  
    }



    float CalcularPromedioValoracion(TMuseo &m,TError &err)
    {
         TObra o;
         TTipoObra t;
         int pos,num;
         int num_total;
         float resul;

         num_total=0;
         resul=0.0;         
         
         for(t=Pintura;t<=Otros;t=SUC(t))
         {
            num = LongitudLista(m[t]);                        
            num_total+=num;
            
            for(pos=0;pos<num;++pos)
            {
                ObtenerObraLista(m[t],pos,o,err);
                resul+=o.valoracion;
            }
         }  
         
         if (num_total==0) {
            err = ErrorListaVacia;
         }
         else {          
            err = NoError;
            resul = resul/num_total;
        }
        
        return resul;
    }    




    void MostrarMuseoOrdenadoPorAnyo(TMuseo &m)
    {
         TListaObras lista_todos;
         TTipoObra t;
         int pos;
         TObra o;
         TError err;

         CrearLista(lista_todos);
         for(t=Pintura;t<=Otros;t=SUC(t))
         {
             for(pos=0;pos<LongitudLista(m[t]);++pos)
             {
                  ObtenerObraLista(m[t],pos,o,err);
                  InsertarLista(lista_todos,o,err);
             }
         }        
         
         for (pos=0;pos<LongitudLista(lista_todos);++pos)
         {
                  ObtenerObraLista(lista_todos,pos,o,err);
                  EscribirObra(o);
                  cout << endl;
         }

        DestruirLista(lista_todos);
    }
    

        
    void DestruirMuseo(TMuseo &m)
    {
         TTipoObra t;
         
         for(t=Pintura;t<=Otros;t=SUC(t))
         {
             DestruirLista(m[t]);
         }         
    }
    
    
    
    //PROCEDIMIENTOS Y FUNCIONES AUXILIARES      
    TTipoObra SUC(TTipoObra t)
    {
        int ord;
        ord = int(t)+1;
        return TTipoObra(ord);     
    }
    
    string Mayusculas(string s)
    {
           string res;
           unsigned i;
           
           res="";
           for(i=0;i<s.length();++i)
           {
                res+=toupper(s[i]);
           }
           return res;
    }
    
    string TipoObra_a_Cadena(TTipoObra t)
    {
           string res;
           
           switch (t)
           {
                  case Pintura:     res = "Pintura"; break;
                  case Escultura:   res = "Escultura"; break;
                  case Arqueologia: res = "Arqueologia"; break;
                  case Otros:       res = "Otros"; break;
           }
           
           return res;
    }
    
    void Cadena_a_TipoObra(string s, TTipoObra &t, TError &err)
    {
         err = ErrorTipoObraDesconocida;
         t = Pintura;
         
         while ( (t<=Otros) && (err!=NoError) )
         {
               if (Mayusculas(s)==Mayusculas(TipoObra_a_Cadena(t)))
               {
                  err = NoError;                                                         
               }
               else
               {
                   t = SUC(t);
               }               
         }
    }
    
}
