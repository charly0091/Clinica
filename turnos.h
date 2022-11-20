#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED
using namespace std;
#include "rlutil.h"
#include "Fecha.h"

class Turno
{
    private:
        int _numeroTurno;
        Fecha _fecha;
        int _numeroAfiliado;
        int _especialidad;
        int _idMedico;
        bool _estado;
    public:
        void setNumTurno(int num){_numeroTurno = num;};
        void setFecha(Fecha fecha){_fecha = fecha;};
        void setNumAfiliado(int num){_numeroAfiliado = num;};
        void setEspecialidad(int esp){_especialidad = esp;}
        void setEstado(bool estado){_estado = estado;};
        void setIdMedico(int id){_idMedico = id;}
        void mostrarTurnosRegistrados();
        int getNumTurno(){return _numeroTurno;}
        Fecha getFecha(){return _fecha;}
        int getNumAfiliado(){return _numeroAfiliado;}
        int getEspecialidad(){return _especialidad;}
        bool getEstado(){return _estado;}
        int getIdMedico(){return _idMedico;}

        bool GrabarEnDiscoTurno();
        bool LeerEnDiscoTurno(int nroRegistro);
        bool leerTodos(Turno* resumen, int cantidad);
        int getCantidad();
        void mostrarTurno(int cant);
        void cargarTurno();
        void BuscarTurno();
        int ModificarEnDiscoTurno(int Pos);
        void recuperarRegistros();
        void turnoPasadoFecha();



        void recuadroturnos(int x, int y, int ancho, int alto);
        void recuadroalu1(int x, int y, int ancho, int alto);

    protected:

};


#endif // TURNOS_H_INCLUDED

