#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdlib>
#include "rlutil.h"
#include "Medico.h"
#include <cstdio>
#include <iomanip>
#include "Fecha.h"
#include "Afiliado.h"

void recuadroAfi(int x, int y, int ancho, int alto){

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

void recuadroAfi1(int x, int y, int ancho, int alto){

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

bool Afiliado::GrabarEnDisco(){
    FILE *p;
    p=fopen ("Afiliado.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Afiliado),1,p);
    fclose(p);
    return escribio;
}

bool Afiliado::LeerEnDisco(int nroRegistro){
    FILE *p = fopen("Afiliado.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Afiliado), SEEK_SET);
    bool leyo = fread(this, sizeof(Afiliado), 1, p);
    fclose(p);
    return leyo;
}

int Afiliado::ModificarEnDisco(int Pos){

    FILE *pAlu;
    int escribio;
    pAlu=fopen("Afiliado.dat","rb+");
    if(pAlu==NULL){
        return -1;
    }
    fseek(pAlu, Pos*sizeof(Afiliado),0);
    escribio=fwrite(this,sizeof(Afiliado),1,pAlu);
	fclose(pAlu);
	return escribio;

}
void Afiliado::ModificarDatos(){

    Afiliado reg;
    int Pos=0;
    int num=0;
    char n[30],mail[30];
    int dn;
    rlutil::locate(2,6);
    cout<< "Ingrese el Numero de afiliado: ";
    cin>>num;
    while(reg.LeerEnDisco(Pos++)==1){
        if(num==reg.getNumAfiliado()){
            rlutil::locate(10,7);
            cout<< "Actualice los nuevos datos del afiliado"<<endl;
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
            cin >> mail;
            reg.setEmail(mail);
            rlutil::locate(2,12);
            cout << "Fecha de nacimiento: ";
            reg.getfecha().CargarFecha();
            reg.ModificarEnDisco(Pos-1);
            break;
        }
    }




}


void Afiliado::mostrarAfiliadoRegistrados(){
    system("cls");
    int pos=0;

    cout << left;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t                            | AFILIADOS REGISTRADOS |"<< endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << "NUM AFILIADO";
    cout << setw(30) << "APELLIDOS";
    cout << setw(30) << "NOMBRES";
    cout << setw(15) << "DNI";
    cout << setw(15) << "ESTADO" << endl;

    cout << "------------------------------------------------------------------------------------------------------" << endl;
      while(LeerEnDisco(pos++)){
            cout << left;
            cout << setw(15) << NumAfiliado;
            cout << setw(30) << apellido;
            cout << setw(30) << nombre;
            cout << setw(15) << DNI;
            if(estado == 1){
            cout<< "Activo" << endl;
            } else{
            cout << "Inactivo" << endl;
            }
      }

            system("pause");
}

int buscarNumAfi(int n){
    Afiliado Reg;
    int Pos=0;

    while(Reg.LeerEnDisco(Pos++)){
        if(Reg.getNumAfiliado()==n){
            return 0;
        }
    }
    return 1;

}

void Afiliado::cargarAfiliado(){
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
    cout << "Num Afiliado: ";
    cin >> NumAfiliado;
    while(buscarNumAfi(NumAfiliado)==0){
        rlutil::locate(2,18);
        cout<< "Ingrese un Numero de afiliado no existente: ";
        cin>>NumAfiliado;
    }
     estado=true;
    rlutil::locate(12,20);
    if(GrabarEnDisco())cout << "AFILIADO CARGADO CORRECTAMENTE "<<endl;

}

void Afiliado::mostrarAfiliado(){
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


void Afiliado::BuscarAfiliadoNum(){
    Afiliado Reg;
    int Pos=0;
    int num=0;
    rlutil::locate(2,6);
    cout<< "Ingrese Numero de afiliado: ";
    cin>> num;
    while(Reg.LeerEnDisco(Pos++)==1){
        if(Reg.getNumAfiliado()==num){
            Reg.mostrarAfiliado();
        }
    }
    rlutil::locate(10,20);
    system("pause");
}
void Afiliado::BuscarAfiliadoNum2(int num){
    Afiliado Reg;
    int Pos=0;
    while(Reg.LeerEnDisco(Pos++)==1){
        if(Reg.getNumAfiliado()==num){
            cout << Reg.getNombre();
            cout << " ";
            cout << Reg.getApellido();
        }
    }
}

bool Afiliado::BuscarAfiliadoActivo(int num){
    Afiliado Reg;
    int Pos=0;
    while(Reg.LeerEnDisco(Pos++)==1){
        if(Reg.getNumAfiliado()==num){
            if(Reg.getEstado()){
                return true;
            }
        }
    }
    return false;
}


void Afiliado::borrarRegistroAfiliado(){
    Afiliado alu;
    int pos=0;
    int num;
    rlutil::locate(2,6);
    cout<<"Ingrese el numero de afiliado a borrar: ";
    cin>>num;
    while(alu.LeerEnDisco(pos)){
    if(alu.getNumAfiliado()==num){
        alu.setEstado(false);
        alu.ModificarEnDisco(pos);
        rlutil::locate(2,8);
        cout << "Se realizo la baja" << endl;
        rlutil::locate(10,20);
        system("pause");
        break;
    }
    pos++;
  }
    cout << "No se encontro el id" << endl;
}

void Afiliado::recuperarRegistrosAfiliado(){
    Afiliado alu;
    int pos=0;
    int num;
    rlutil::locate(2,6);
    cout<<"Ingrese el numero de afiliado a dar de alta: ";
    cin>>num;
    while(alu.LeerEnDisco(pos)==1){
        if(alu.getEstado()==false && alu.getNumAfiliado()==num){
            alu.setEstado(true);
            alu.ModificarEnDisco(pos);
            rlutil::locate(2,10);
            cout << "Se realizo el alta" << endl;
            rlutil::locate(10,20);
            system("pause");
            break;

        }
        pos++;
    }
}


int Afiliados(){
{

    int Opc;
    int pos=0;
    Afiliado obj;

    while(true)
    {
      system("cls");
      recuadroAfi(1,1,60,20);
      recuadroAfi1(1,1,60,20);
        rlutil::locate(23,3);
        cout<< "| MENU AFILIADO |"<<endl;
        rlutil::locate(11,6);
        cout<< "F1 - Cargar Afiliado"<<endl;
        rlutil::locate(11,8);
        cout<< "F2 - Mostrar Afiliado"<<endl;
        rlutil::locate(11,10);
        cout<< "F3 - Buscar por Numero de afiliado"<<endl;
        rlutil::locate(11,12);
        cout<< "F4 - Modificar Afiliado Por Numero de afiliado"<<endl;
        rlutil::locate(11,14);
        cout<< "F5 - Dar de baja por Numero de afiliado"<<endl;
        rlutil::locate(11,16);
        cout<< "F6 - Dar de alta por Numero de afiliado"<<endl;
        rlutil::locate(11,18);
        cout <<"F7 - Volver a menu" << endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18: //F1
            system("cls");
             recuadroAfi(1,1,60,20);
             recuadroAfi1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CARGAR AFILIADO |"<<endl;
            obj.cargarAfiliado();
            rlutil::locate(10,22);
            system("pause");
            system("cls");

            break;


        case 19: //F2
        system("cls");
        obj.mostrarAfiliadoRegistrados();

        break;


        case 20: //F3
            system("cls");
             recuadroAfi(1,1,60,20);
             recuadroAfi1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| BUSCAR AFILIADO |"<<endl;
            rlutil::locate(11,8);
              obj.BuscarAfiliadoNum();
              rlutil::locate(10,20);
              system("pause");
              system("cls");

            break;
        case 21: //F4
            system("cls");
            recuadroAfi(1,1,60,20);
            recuadroAfi1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MODIFICAR AFILIADO |"<<endl;
                obj.ModificarDatos();

            break;
        case 22: //F5
            system("cls");
            recuadroAfi(1,1,60,20);
            recuadroAfi1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| DAR DE BAJA AFILIADO |"<<endl;
            obj.borrarRegistroAfiliado();

            break;
        case 23:
            system("cls");
            recuadroAfi(1,1,60,20);
            recuadroAfi1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| DAR DE ALTA AFILIADO |"<<endl;
            obj.recuperarRegistrosAfiliado();

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


 return 0;
}

