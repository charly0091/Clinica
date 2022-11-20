#ifndef QUEJAS_H_INCLUDED
#define QUEJAS_H_INCLUDED
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Persona.h"
#include "turnos.h"

class Queja{
private:
  char quejas[200];
  char usuario[30];
  char password[30];

public:

   char *getQuejas()
    {
        return quejas;
    }
     char *getUsuario()
    {
        return usuario;
    }
     char *getPassword()
    {
        return password;
    }

    void setQuejas(const char *q)
    {
        strcpy(quejas,q);
    }

     void setUsuarios(const char *u)
    {
        strcpy(usuario,u);
    }

     void setPassword(const char *p)
    {
        strcpy(password,p);
    }



  bool GrabarEnDisco();
  bool LeerEnDisco(int nroRegistro);
  int ModificarEnDisco(int pos);
  void cargarQueja();
  void CrearUsuario();
  int BuscarUser(const char *u, const char *c);
  int BuscarNombre(const char *u);
  void mostrarQuejas();
  void VerificarUser();







};


#endif // QUEJAS_H_INCLUDED
