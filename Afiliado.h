#ifndef AFILIADO_H_INCLUDED
#define AFILIADO_H_INCLUDED
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Persona.h"
#include "Turnos.h"
#include "Medico.h"
#include "Fecha.h"


class Afiliado: public Persona{
    private:
    int NumAfiliado;

    public:

    int getNumAfiliado(){return NumAfiliado;}
    void setNumAfiliado(int n){NumAfiliado=n;}

    void cargarAfiliado();
    bool GrabarEnDisco();
    bool LeerEnDisco(int nroRegistro);
    void mostrarAfiliadoRegistrados();
    int ModificarEnDisco(int pos);
    void ModificarDatos();
    void BuscarAfiliadoNum();
    void BuscarAfiliadoNum2(int num);
    bool BuscarAfiliadoActivo(int num);
    void mostrarAfiliado();
    void borrarRegistroAfiliado();
    void recuperarRegistrosAfiliado();


};
#endif // AFILIADO_H_INCLUDED
