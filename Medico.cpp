#include <iostream>
using namespace std;
#include <cstdlib>
#include "rlutil.h"
#include "Medico.h"
#include <cstdio>
#include <iomanip>
#include "Fecha.h"

void recuadroalu(int x, int y, int ancho, int alto){

const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐

const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─


const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │




    /// Borramos el espacio del recuadro
    //COLOR DE FONDO
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){
            rlutil::setBackgroundColor(rlutil::DARKGREY);
            rlutil::locate(i, j);
            cout << " ";

        }
    }
    //COLOR DE LINEAS Y LETRAS
    rlutil::setColor(rlutil::YELLOW);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++){
        rlutil::locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;

    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++){
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
void recuadroalu1(int x, int y, int ancho, int alto){

const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐

const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─


const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │




    /// Borramos el espacio del recuadro
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){
            rlutil::setBackgroundColor(rlutil::DARKGREY);
            rlutil::locate(i, j);
            cout << " ";

        }
    }
    rlutil::setColor(rlutil::YELLOW);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++){
        rlutil::locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i,4);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;

    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++){
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
void Medico::mostrarMedico(){
 rlutil::locate(2,8);
        cout << "Nombre: ";
        cout << nombre << endl;
        rlutil::locate(2,9);
        cout << "Apellido: ";
        cout << apellido << endl;
        rlutil::locate(2,10);
        cout << "DNI: ";
        cout << DNI << endl;
        rlutil::locate(2,11);
        cout << "Email: ";
        cout << email << endl;
        rlutil::locate(2,12);
        cout << "Fecha de nacimiento: ";
        fechaN.MostrarFecha();
        if(estado==true){
            rlutil::locate(2,13);
            cout<<"Persona activa"<<endl;
        }
        else{
          rlutil::locate(2,13);
          cout<<"Persona inactiva"<<endl;
        }



}


void Medico::BuscarMedicoId(){
    Medico Reg;
    int Pos=0;
    int id=0;
    rlutil::locate(2,6);
    cout<< "Ingrese ID del medico: ";
    cin>> id;
    while(Reg.LeerEnDiscoMedico(Pos++)==1){
        if(Reg.getId()==id){
            Reg.mostrarMedico();
        }
    }
    rlutil::locate(10,20);
    system("pause");
}

int buscarId(int id){
    Medico Reg;
    int Pos=0;

    while(Reg.LeerEnDiscoMedico(Pos++)){
        if(Reg.getId()==id){
            return 0;
        }
    }
    return 1;

}




bool Medico::LeerEnDiscoMedico(int nroRegistro){
    FILE *p = fopen("Medico.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Medico), SEEK_SET);
    bool leyo = fread(this, sizeof(Medico), 1, p);
    fclose(p);
    return leyo;

}

bool Medico::GrabarEnDiscoMedico(){
    FILE *p;
    p=fopen ("Medico.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Medico),1,p);
    fclose(p);
    return escribio;
}


void Medico::cargarMedico(){
    rlutil::locate(2,8);
    cout << "Nombre: ";
    cin >>nombre;
    rlutil::locate(2,9);
    cout << "Apellido: ";
    cin >> apellido;
    rlutil::locate(2,10);
    cout << "DNI: ";
    cin >> DNI;
    while(DNI<=0){
        rlutil::locate(2,11);
        cout<< "Ingrese un DNI correcto: ";
        cin>>DNI;
    }

    rlutil::locate(2,12);
    cout << "Email: ";
    cin >> email;
    rlutil::locate(2,13);
    cout << "Fecha de nacimiento: ";
    fechaN.CargarFecha();
    rlutil::locate(2,17);
    cout << "ID: ";
    cin >> id;
    while(buscarId(id)==0){
        rlutil::locate(2,18);
        cout<< "Ingrese un ID no existente: ";
        cin>>id;
    }
    rlutil::locate(2,19);
    cout << "Ingrese Especialidad: ";
    cin >> especialidad;

     estado=true;
    rlutil::locate(12,20);
    if(GrabarEnDiscoMedico())cout << "MEDICO CARGADO CORRECTAMENTE "<<endl;

}

void Medico::mostrarMedicoRegistrados(){
    system("cls");
    int pos=0;

    cout << left;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t                            | MEDICOS REGISTRADOS |"<< endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << "ID";
    cout << setw(30) << "APELLIDOS";
    cout << setw(30) << "NOMBRES";
    cout << setw(15) << "DNI";
    cout << setw(15) << "ESPECIALIDAD";
    cout << setw(15) << "ESTADO" << endl;

    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
      while(LeerEnDiscoMedico(pos++)){
            cout << left;
            cout << setw(15) << id;
            cout << setw(30) << apellido;
            cout << setw(30) << nombre;
            cout << setw(15) << DNI;
            cout << setw(15) << especialidad;
            cout << setw(15) << estado<< endl;
      }
            cout << endl << endl;
            system("pause");
}

int Medico::ModificarEnDiscoMedico(int Pos){

    FILE *pAlu;
    int escribio;
    pAlu=fopen("Medico.dat","rb+");
    if(pAlu==NULL){
        return -1;
    }
    fseek(pAlu, Pos*sizeof(Medico),0);
    escribio=fwrite(this,sizeof(Medico),1,pAlu);
	fclose(pAlu);
	return escribio;

}

void Medico::ModificarDatosMedico(){
    Medico reg;
    int Pos=0;
    int id=0;
    char n[30];
    int dn;
    rlutil::locate(2,6);
    cout<< "Ingrese el ID del Medico: ";
    cin>>id;
    while(reg.LeerEnDiscoMedico(Pos++)==1){
        if(id==reg.getId()){
            rlutil::locate(10,7);
            cout<< "Actualice los nuevos datos del Medico"<<endl;
            rlutil::locate(2,8);
            cout<< "Nombre: ";
            cin>>  n;
            reg.setNombre(n);
            rlutil::locate(2,9);
            cout<< "Apellido: ";
            cin>> n;
            reg.setApellido(n);
            rlutil::locate(2,10);
            cout<< "DNI: ";
            cin >> dn;
            reg.setDNI(dn);
            rlutil::locate(2,11);
            cout << "Email: ";
            cin >> email;
            reg.setEmail(email);
            rlutil::locate(2,12);
            cout << "Fecha de nacimiento: ";
            reg.getfecha().CargarFecha();
            reg.ModificarEnDiscoMedico(Pos-1);
            break;
        }
    }


}

void borrarRegistro(){
    Medico alu;
    int pos=0;
    int id;
    rlutil::locate(2,6);
    cout<<"Ingrese el ID del Medico a borrar: ";
    cin>>id;
    while(alu.LeerEnDiscoMedico(pos)){
    if(alu.getId()==id){
        alu.setEstado(false);
        alu.ModificarEnDiscoMedico(pos);
        rlutil::locate(2,8);
        cout << "Se realizo la baja" << endl;
        rlutil::locate(10,20);
        system("pause");
        break;
    }
    pos++;
  }
          if(alu.getId()!=id){
          rlutil::locate(2,8);
          cout << "No se encontro un maestro con el DNI ingresado" << endl;
        }
}

void recuperarRegistros(){
    Medico alu;
    int pos=0;
    int id;
    rlutil::locate(2,6);
    cout<<"Ingrese el ID del Medico a dar de alta: ";
    cin>>id;
    while(alu.LeerEnDiscoMedico(pos)==1){
        if(alu.getEstado()==false && alu.getId()==id){
            alu.setEstado(true);
            alu.ModificarEnDiscoMedico(pos);
            rlutil::locate(2,10);
            cout << "Se realizo el alta" << endl;
            rlutil::locate(10,20);
            system("pause");
            break;

        }
        pos++;
    }
          if(alu.getId()!=id){
          rlutil::locate(2,8);
          cout << "No se encontro alumno con el legajo ingresado" << endl;
        }
}

bool Medico::leerTodos(Medico* resumen, int cantidad)
{
  FILE* pFile;
  pFile = fopen("Medico.dat", "rb");
  if (pFile == NULL) {
    return false;
  }

  fread(resumen, sizeof(Medico), cantidad, pFile);
  fclose(pFile);
  return true;
}

int Medico::getCantidad()
{
  FILE* pFile;
  pFile = fopen("Medico.dat", "rb");
  if (pFile == NULL) {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  int cantidad = ftell(pFile) / sizeof(Medico);
  fclose(pFile);
  return cantidad;
}
void Medico::BuscarMedicoNum2(int num){
    Medico Reg;
    int Pos=0;
    while(Reg.LeerEnDiscoMedico(Pos++)==1){
        if(Reg.getId()==num){
            cout << Reg.getNombre();
            cout << " ";
            cout << Reg.getApellido();
        }
    }
}


int Medicos()
{

    int Opc;
    int pos=0;
    Medico obj;

    while(true)
    {
      system("cls");
      recuadroalu(1,1,60,20);
      recuadroalu1(1,1,60,20);
        rlutil::locate(23,3);
        cout<< "| MENU MEDICOS |"<<endl;
        rlutil::locate(11,6);
        cout<< "F1 - Cargar Medico"<<endl;
        rlutil::locate(11,8);
        cout<< "F2 - Mostrar Medico"<<endl;
        rlutil::locate(11,10);
        cout<< "F3 - Buscar por ID"<<endl;
        rlutil::locate(11,12);
        cout<< "F4 - Modificar Medico Por ID"<<endl;
        rlutil::locate(11,14);
        cout<< "F5 - Dar de baja por ID"<<endl;
        rlutil::locate(11,16);
        cout<< "F6 - Dar de alta por ID"<<endl;
        rlutil::locate(11,18);
        cout <<"F7 - Volver a menu" << endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18: //F1
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CARGAR MEDICO |"<<endl;
            obj.cargarMedico();
            rlutil::locate(10,22);
            system("pause");
            system("cls");

            break;


        case 19: //F2
        system("cls");
        obj.mostrarMedicoRegistrados();

        break;


        case 20: //F3
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| BUSCAR MEDICO |"<<endl;
            rlutil::locate(11,8);
              obj.BuscarMedicoId();
              rlutil::locate(10,20);
              system("pause");
              system("cls");

            break;
        case 21: //F4
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MODIFICAR MEDICO |"<<endl;
                obj.ModificarDatosMedico();

            break;
        case 22: //F5
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| DAR DE BAJA MEDICO |"<<endl;
            borrarRegistro();

            break;
        case 23:
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| DAR DE ALTA MEDICO |"<<endl;
            recuperarRegistros();

            break;

        case 24: //F6
            return 0;
            break;


        }
    }
    cout<< endl;
    system("pause");
    return 0;
}

