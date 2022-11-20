#include <iostream>
using namespace std;
#include <cstdlib>
#include "turnos.h"
#include "Fecha.h"
#include <math.h>
#include "Medico.h"
#include <iomanip>
#include "Afiliado.h"

const string especialidades[10]= {"Cardiologia","Clinico","Dermatologia","Gastroenterologia","Ginecologia","Nutricion","Odontologia","Oftalmologia","Pediatria","Urologia" };

void recuadroalu2(int x, int y, int ancho, int alto)
{

    const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
    const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
    const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
    const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐

    const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─


    const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │




    /// Borramos el espacio del recuadro
    //COLOR DE FONDO
    int i, j;
    for(i=x; i<=x+ancho; i++)
    {
        for(j=y; j<=y+alto; j++)
        {
            rlutil::setBackgroundColor(rlutil::DARKGREY);
            rlutil::locate(i, j);
            cout << " ";

        }
    }
    //COLOR DE LINEAS Y LETRAS
    rlutil::setColor(rlutil::YELLOW);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++)
    {
        rlutil::locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;

    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++)
    {
        rlutil::locate(x, i);
        cout << UI_VERTICAL_LINE;
        rlutil::locate(x+ancho, i);
        cout << UI_VERTICAL_LINE;
    }
    //COLOR DE LETRAS
    /// Vértices
    rlutil::locate(x, y);
    cout << UI_TOP_LEFT;
    rlutil::locate(x, y+alto);
    cout << UI_BOTTOM_LEFT;
    rlutil::locate(x+ancho, y);
    cout << UI_TOP_RIGHT;
    rlutil::locate(x+ancho, y+alto);
    cout << UI_BOTTOM_RIGHT;
    rlutil::resetColor();
    rlutil::setBackgroundColor(rlutil::DARKGREY);
}
void recuadroalu3(int x, int y, int ancho, int alto)
{

    const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
    const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
    const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
    const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐

    const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─


    const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │




    /// Borramos el espacio del recuadro
    int i, j;
    for(i=x; i<=x+ancho; i++)
    {
        for(j=y; j<=y+alto; j++)
        {
            rlutil::setBackgroundColor(rlutil::DARKGREY);
            rlutil::locate(i, j);
            cout << " ";

        }
    }
    rlutil::setColor(rlutil::YELLOW);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++)
    {
        rlutil::locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i,4);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;

    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++)
    {
        rlutil::locate(x, i);
        cout << UI_VERTICAL_LINE;
        rlutil::locate(x+ancho, i);
        cout << UI_VERTICAL_LINE;
    }
    /// Vértices
    rlutil::locate(x, y);
    cout << UI_TOP_LEFT;
    rlutil::locate(x, y+alto);
    cout << UI_BOTTOM_LEFT;
    rlutil::locate(x+ancho, y);
    cout << UI_TOP_RIGHT;
    rlutil::locate(x+ancho, y+alto);
    cout << UI_BOTTOM_RIGHT;
}


int buscarNumAfiliado(int n){
    Afiliado Reg;
    int Pos=0;

    while(Reg.LeerEnDisco(Pos++)){
        if(Reg.getNumAfiliado()==n){
            return 0;
        }
    }
    return 1;

}


int Turno::ModificarEnDiscoTurno(int Pos){

    FILE *pAlu;
    int escribio;
    pAlu=fopen("Turnos.dat","rb+");
    if(pAlu==NULL){
        return -1;
    }
    fseek(pAlu, Pos*sizeof(Turno),0);
    escribio=fwrite(this,sizeof(Turno),1,pAlu);
	fclose(pAlu);
	return escribio;

}


void borrarRegistroTurno(){
    Turno alu;
    int pos=0;
    int id;
    rlutil::locate(2,6);
    cout<<"Ingrese el Numero del turno a dar de baja: ";
    cin>>id;
    while(alu.LeerEnDiscoTurno(pos)){
    if(alu.getNumTurno()==id){
        alu.setEstado(false);
        alu.ModificarEnDiscoTurno(pos);
        rlutil::locate(2,8);
        cout << "Se realizo la baja" << endl;
        rlutil::locate(10,20);
        system("pause");
        break;
    }
    pos++;
  }
          if(alu.getNumTurno()!=id){
          rlutil::locate(2,8);
          cout << "No se encontro un Turno con el Numero ingresado" << endl;
          rlutil::locate(10,20);
            system("pause");
        }
}


void Turno::BuscarTurno(){
    Turno Reg;

    int Pos=0;
    int id=0;
    int cantTurnos=0;
    bool encontroTurno = false;
    rlutil::locate(2,6);
    cout<< "Ingrese Num de afiliado: ";
    cin>> id;
    system("cls");

    cout << left;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t                            | BUSCAR TURNOS |"<< endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    while(Reg.LeerEnDiscoTurno(Pos++)==1){
        if(Reg.getNumAfiliado()==id){
            Reg.mostrarTurno(cantTurnos);
            cantTurnos++;
            encontroTurno = true;
        }
    }
    if(!encontroTurno){
            rlutil::locate(10,6);
        cout << "El afiliado no tiene cargado un proximo turno";
    }
    rlutil::locate(10,12+(cantTurnos*7));
    system("pause");
}
void Turno::recuperarRegistros(){
    Turno alu;
    int pos=0;
    int id;
    rlutil::locate(2,6);
    cout<<"Ingrese el ID del Turno a dar de alta: ";
    cin>>id;
    while(alu.LeerEnDiscoTurno(pos)==1){
        if(alu.getEstado()==false && alu.getNumTurno()==id){
            alu.setEstado(true);
            alu.ModificarEnDiscoTurno(pos);
            rlutil::locate(2,10);
            cout << "Se realizo el alta" << endl;
            rlutil::locate(10,20);
            system("pause");
            break;

        }
        pos++;
    }
          if(alu.getNumTurno()!=id){
          rlutil::locate(2,8);
          cout << "No se encontro el turno con el numero de turno ingresado" << endl;
          rlutil::locate(10,20);
            system("pause");
        }
}
void Turno::turnoPasadoFecha(){
    Turno turno;
    Fecha actual;
    actual.FechaActual();
    int pos = 0;
    while(turno.LeerEnDiscoTurno(pos++)){
        if(turno.getFecha().getAnio() < actual.getAnio() ||
           (turno.getFecha().getAnio() == actual.getAnio() && turno.getFecha().getMes() < actual.getMes()) ||
           turno.getFecha().getAnio() == actual.getAnio() && turno.getFecha().getMes() == actual.getMes() && turno.getFecha().getDia() < actual.getDia()){
                turno.setEstado(false);
                turno.ModificarEnDiscoTurno(pos);
           }
    }
}
int Turnos()
{

    int Opc;
    //int pos=0;
    Turno obj;

    while(true)
    {
        system("cls");
        recuadroalu2(1,1,60,20);
        recuadroalu3(1,1,60,20);
        rlutil::locate(23,3);
        cout<< "| MENU TURNOS |"<<endl;
        rlutil::locate(11,6);
        cout<< "F1 - Nuevo Turno"<<endl;
        rlutil::locate(11,8);
        cout<< "F2 - Turnos Registrados"<<endl;
        rlutil::locate(11,10);
        cout<< "F3 - Buscar por Numero de Afiliado"<<endl;
        rlutil::locate(11,12);
        cout<< "F4 - Dar de baja por ID"<<endl;
         rlutil::locate(11,14);
        cout<< "F5 - Dar de alta por ID"<<endl;
        rlutil::locate(11,16);
        cout<< "F6 - Salir"<<endl;

        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18: //F1
            system("cls");
            recuadroalu2(1,1,60,20);
            recuadroalu3(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| NUEVO TURNO |"<<endl;
            obj.cargarTurno();
            rlutil::locate(10,22);
            system("pause");
            system("cls");

            break;


        case 19: //F2
            system("cls");
            obj.mostrarTurnosRegistrados();

            break;


        case 20: //F3
            system("cls");
            recuadroalu2(1,1,60,20);
            recuadroalu3(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| BUSCAR TURNO |"<<endl;
            rlutil::locate(11,8);
            obj.BuscarTurno();
            rlutil::locate(10,20);
            system("cls");

            break;
        case 21: //F4
            system("cls");
            recuadroalu2(1,1,60,20);
            recuadroalu3(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| DAR DE BAJA TURNO |"<<endl;
            borrarRegistroTurno();

            break;
        case 22: //F5
            system("cls");
            recuadroalu2(1,1,60,20);
            recuadroalu3(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| DAR DE ALTA TURNO |"<<endl;
            obj.recuperarRegistros();

            break;

        case 23: //F6
            return 0;
            break;


        }
    }
    cout<< endl;
    system("pause");
    return 0;
}

bool Turno::GrabarEnDiscoTurno()
{
    FILE *p;
    p=fopen ("Turnos.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Turno),1,p);
    fclose(p);
    return escribio;
}
bool Turno::LeerEnDiscoTurno(int nroRegistro)
{
    FILE *p = fopen("Turnos.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Turno), SEEK_SET);
    bool leyo = fread(this, sizeof(Turno), 1, p);
    fclose(p);
    return leyo;
}
bool Turno::leerTodos(Turno* resumen, int cantidad)
{
    FILE* pFile;
    pFile = fopen("Turnos.dat", "rb");
    if (pFile == NULL)
    {
        return false;
    }

    fread(resumen, sizeof(Turno), cantidad, pFile);
    fclose(pFile);
    return true;
}

int Turno::getCantidad()
{
    FILE* pFile;
    pFile = fopen("Turnos.dat", "rb");
    if (pFile == NULL)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(Turno);
    fclose(pFile);
    return cantidad;
}

void Turno::mostrarTurno(int cant)
{

    int locateTurno = cant*7;
    rlutil::locate(2,5+locateTurno);
    cout << "Numero de turno: ";
    cout << _numeroTurno << endl;
    rlutil::locate(2,6+locateTurno);
    cout << "Numero de afiliado: ";
    cout << _numeroAfiliado << endl;
    rlutil::locate(2,7+locateTurno);
    cout << "Fecha: ";
    _fecha.MostrarFecha();
    rlutil::locate(2,8+locateTurno);
    cout << "Especialidad: ";
    cout << especialidades[_especialidad-1] << endl;
    rlutil::locate(2,9+locateTurno);
    if(_estado==true)
    {
        rlutil::locate(2,10+locateTurno);
        cout<<"Turno activo"<<endl;
    }
    else
    {
        rlutil::locate(2,10+locateTurno);
        cout<<"Turno dado de baja"<<endl;
    }
}



void Turno::cargarTurno()
{
    int diaSemana,opcTurno;
    Fecha fechaActual = fechaActual.FechaActual();
    Fecha turnosDisponibles[10];
    Afiliado af;
    int id[10];
    int semana = fechaActual.getSemana();

        system("cls");
        recuadroalu2(1,1,60,20);
        recuadroalu3(1,1,60,20);
        rlutil::locate(20,3);
        cout<< "| NUEVO TURNO |"<<endl;

        rlutil::locate(2,6);
        cout << "Ingrese numero de afiliado: ";
        cin >> _numeroAfiliado;

        while(buscarNumAfiliado(_numeroAfiliado)==1){

        rlutil::locate(2,7);
        cout<< "Ingrese un numero de afiliado valido: ";
        cin>>_numeroAfiliado;
    }
        if(!af.BuscarAfiliadoActivo(_numeroAfiliado)){
            rlutil::locate(2,7);
            cout << "El afiliado se encuentra dado de baja";
            return;
        }

    do
    {
        for(int i=0; i<10; i++)
        {
            rlutil::locate(2,i+9);
            cout << i+1 << ": " << especialidades[i] << endl;
        }
        rlutil::locate(2,19);
        cout << "Ingrese una especialidad: ";
        cin >> _especialidad;
        if(_especialidad < 1 || _especialidad > 10)
        {
            rlutil::locate(2,17);
            cout << "Ingrese un numero de especialidad entre 1 y 10" << endl;
            rlutil::locate(2,18);
            system("pause");
            system("cls");
        }
    }
    while(_especialidad < 1 || _especialidad > 10);
    switch(_especialidad)
    {
    case 1:
    case 6:
    {
        diaSemana= 1;
        break;
    }
    case 2:
    case 7:
    {
        diaSemana = 2;
        break;
    }

    case 3:
    case 8:
    {
        diaSemana = 3;
        break;
    }
    case 4:
    case 9:
    {
        diaSemana = 4;
        break;
    }
    case 5:
    case 10:
    {
        diaSemana = 5;
        break;
    }
    }
    Fecha fechaTurno = fechaActual.SumarDias(7-abs(semana-diaSemana));

    Medico m;
    int cantidadMedicos = m.getCantidad();
    Medico* medicos = new Medico[cantidadMedicos];
    m.leerTodos(medicos, cantidadMedicos);

    system("cls");
     recuadroalu2(1,1,60,20);
     recuadroalu3(1,1,60,20);
     rlutil::locate(20,3);
    cout<< "| NUEVO TURNO |"<<endl;

    Turno t;
    int cantidadTurnos = t.getCantidad();
    Turno* turnos = new Turno[cantidadTurnos];
    t.leerTodos(turnos, cantidadTurnos);



    bool turnoEncontrado;
    bool diaEncontrado;
    int indice = 0;
    while(indice < 10)
    {
        for(int i=0; i<cantidadMedicos; i++){
            turnoEncontrado = false;
            diaEncontrado = false;
            if(medicos[i].getEspecialidad() == _especialidad){
                for(int j=0;j<cantidadTurnos;j++){
                     if(turnos[j].getFecha().getDia() == fechaTurno.getDia() &&
                        turnos[j].getFecha().getMes() == fechaTurno.getMes() &&
                        turnos[j].getFecha().getAnio() == fechaTurno.getAnio()){
                            diaEncontrado = true;
                            if(turnos[j].getIdMedico() == medicos[i].getId() && turnos[j].getEstado() != false){
                                turnoEncontrado = true;
                            }
                        }
                }
                if((turnoEncontrado == false || diaEncontrado == false) && indice < 10){
                    turnosDisponibles[indice].setDia(fechaTurno.getDia());
                    turnosDisponibles[indice].setMes(fechaTurno.getMes());
                    turnosDisponibles[indice].setAnio(fechaTurno.getAnio());
                    id[indice] = medicos[i].getId();
                    indice++;
                }
            }
        }
        fechaTurno = fechaTurno.SumarSemana();
    }
    rlutil::locate(2,6);
    cout << "Ingrese el numero con la fecha y medico que desee: ";

    for(int i=0; i<10; i++)
    {
        rlutil::locate(2,8+i);
        cout << i+1 << " - ";
        turnosDisponibles[i].MostrarFecha();
        cout << " - ";
        for(int j = 0; j<cantidadMedicos; j++)
        {
            if(id[i] == medicos[j].getId())
            {
                cout << medicos[j].getApellido() << " " << medicos[j].getNombre() << endl;
            }

        }
    }rlutil::locate(52,6);
    cin >> opcTurno;
    _fecha = turnosDisponibles[opcTurno-1];
    _idMedico = id[opcTurno-1];
    _numeroTurno =  t.getCantidad()+1;
    _estado=true;
    rlutil::locate(12,26);
    if(GrabarEnDiscoTurno())cout << "TURNO CARGADO CORRECTAMENTE "<<endl;


    delete[] turnos;
    delete[] medicos;

}

void Turno::mostrarTurnosRegistrados(){
    system("cls");
    int pos=0;
    Afiliado af;
    Medico m;

    cout << left;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t                            | TURNOS REGISTRADOS |"<< endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << "NUM TURNO";
    cout << setw(20) << "AFILIADO";
    cout << setw(25) << "FECHA";
    cout << setw(15) << "MEDICO";
    cout << setw(21) << "ESPECIALIDAD";
    cout << setw(15) << "ESTADO" << endl;

    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
      while(LeerEnDiscoTurno(pos++)){
            cout << left;
            cout << "    ";
            cout << setw(10) << _numeroTurno;
            af.BuscarAfiliadoNum2(_numeroAfiliado);
            cout << "\t  ";
            _fecha.MostrarFecha();
            cout << "\t\t";
            m.BuscarMedicoNum2(_idMedico);
            cout << "\t\t";
            cout << setw(15) << especialidades[_especialidad-1];
            if(_estado == 1){
            cout<< "Activo" << endl;
            } else{
            cout << "Inactivo" << endl;
            }
      }
            cout << endl << endl;
            system("pause");
}
