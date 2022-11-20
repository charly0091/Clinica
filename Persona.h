#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Fecha.h"

class Persona{
protected:
    char nombre[30];
    char apellido[30];
    int DNI;
    char email[30];
    Fecha fechaN;
    bool estado;
public:
    //sets()
    void setFecha(Fecha fn)
    {
        fechaN=fn;
    }
    void setNombre(const char *n)
    {
        strcpy(nombre,n);
    }
    void setApellido(const char *n)
    {
        strcpy(apellido,n);
    }
    void setDNI(int d)
    {
        DNI=d;
    }
    void setEmail(const char *e){
        strcpy(email,e);
    }
    void setFecha();
    void setEstado(int e){estado=e;}
    void cargarPersona();
    void mostrarPersona();


    //gets()
    char *getNombre()
    {
        return nombre;
    }
    char *getApellido()
    {
        return apellido;
    }
    int getDNI()
    {
        return DNI;
    }
    bool getEstado()
    {
        return estado;
    }
    Fecha getfecha()
    {
        return fechaN;
    }
};
#endif // PERSONA_H_INCLUDED
