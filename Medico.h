#ifndef MEDICO_H_INCLUDED
#define MEDICO_H_INCLUDED
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Persona.h"
#include "turnos.h"


class Medico:public Persona{
private:
  int id;
  int especialidad;

public:
  int getId(){return id;}
  void setId(int i){id=i;}

  int getEspecialidad(){return especialidad;}
  void setEspecialidad(int esp){especialidad = esp;}

  void cargarMedico();
  bool GrabarEnDiscoMedico();
  bool LeerEnDiscoMedico(int nroRegistro);
  void mostrarMedicoRegistrados();
  int ModificarEnDiscoMedico(int pos);
  void ModificarDatosMedico();
  void BuscarMedicoId();
  void mostrarMedico();
  bool leerTodos(Medico* resumen, int cantidad);
  int getCantidad();
  void BuscarMedicoNum2(int num);







};

#endif // MEDICO_H_INCLUDED
