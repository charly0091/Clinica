#include <iostream>
using namespace std;
#include <cstdlib>
#include "Quejas.h"
#include "rlutil.h"
#include <cstring>


void recuadroque(int x, int y, int ancho, int alto){

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

void recuadroque1(int x, int y, int ancho, int alto){

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




bool Queja::GrabarEnDisco(){
    FILE *p;
    p=fopen ("Queja.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Queja),1,p);
    fclose(p);
    return escribio;
}

bool Queja::LeerEnDisco(int nroRegistro){
    FILE *p = fopen("Queja.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Queja), SEEK_SET);
    bool leyo = fread(this, sizeof(Queja), 1, p);
    fclose(p);
    return leyo;
}


int Queja::ModificarEnDisco(int Pos){

    FILE *pAlu;
    int escribio;
    pAlu=fopen("Queja.dat","rb+");
    if(pAlu==NULL){
        return -1;
    }
    fseek(pAlu, Pos*sizeof(Queja),0);
    escribio=fwrite(this,sizeof(Queja),1,pAlu);
	fclose(pAlu);
	return escribio;

}

void Queja::cargarQueja(){
    rlutil::locate(2,8);
    cout << "Informe su Queja: ";
    cin.getline(quejas,200,'\n');
    rlutil::locate(10,20);
    if(GrabarEnDisco())cout << "SU QUEJA FUE CARGADA CORRECTAMENTE! "<<endl;
}

int Queja::BuscarUser(const char u[30], const char c[30]){

  Queja obj;
  int pos=0;


  while(obj.LeerEnDisco(pos)){
    if(strcmp(obj.getUsuario(),u)==0 && strcmp(obj.getPassword(),c)==0 ){
      return 1;
    }

    pos++;
  }

  return 0;

}



int Queja::BuscarNombre(const char u[30]){

  Queja obj;
  int pos=0;


  while(obj.LeerEnDisco(pos)){
    if(strcmp(obj.getUsuario(),u)==0){
      return 1;
    }

    pos++;
  }

  return 0;

}





void Queja::CrearUsuario(){
   rlutil::locate(2,8);
  cout << "Nombre de usuario: ";
  cin >> usuario;
  rlutil::locate(2,9);
  cout << "Contrasenia: ";
  cin >> password;
    while(BuscarNombre(usuario)==1){
        rlutil::locate(2,11);
        cout << "Ingrese un usuario no existente!! ";
        rlutil::locate(2,12);
        cout << "Nombre de usuario: ";
        cin >> usuario;
        rlutil::locate(2,13);
        cout << "Contrasenia: ";
        cin >> password;
    }
  if(GrabarEnDisco())cout << "USUARIO CARGADO CORRECTAMENTE! "<<endl;
}


void Queja::mostrarQuejas(){
 Queja reg;
 int pos=0;


    recuadroque(1,1,60,20);
    recuadroque1(1,1,60,20);
    rlutil::locate(20,3);
    cout<< "| QUEJAS REGISTRADAS |"<<endl;
    rlutil::locate(2,8);
    cout << quejas << endl;
    rlutil::locate(10,20);
    //system("pause");




}

void Queja::VerificarUser(){
  Queja mas;
  int Pos=0;
  char user[30];
  char contra[30];

    rlutil::locate(2,8);
    cout << "Nombre de usuario: ";
    cin >> user;
    rlutil::locate(2,9);
    cout << "Contrasenia: ";
    cin >> contra;
    rlutil::locate(10,20);
     system("pause");
    system("cls");



   if(mas.BuscarUser(user,contra)){

    while(mas.LeerEnDisco(Pos++)==1){

      rlutil::locate(1,3);
      cout << "Usuario cargado correctamente" << endl;
       mas.mostrarQuejas();
       rlutil::locate(10,20);
       system("pause");
        system("cls");
    }
  }

}















int Quejas(){

    int Opc;
    Queja obj;

    while(true)
    {
      system("cls");
      recuadroque(1,1,60,20);
      recuadroque1(1,1,60,20);
        rlutil::locate(23,3);
        cout<< "| MENU QUEJAS |"<<endl;
        rlutil::locate(11,6);
        cout<< "F1 - Cargar Queja"<<endl;
        rlutil::locate(11,8);
        cout<< "F2 - Mostrar Quejas"<<endl;
        rlutil::locate(11,10);
        cout<< "F3 - Crear Usuario Admin"<<endl;
        rlutil::locate(11,12);
        cout<< "F4 - Salir"<<endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18: //F1
            system("cls");
            recuadroque(1,1,60,20);
            recuadroque1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CARGAR QUEJA |"<<endl;
            obj.cargarQueja();
            rlutil::locate(10,22);
            system("pause");
            system("cls");

            break;


        case 19: //F2
            system("cls");
            recuadroque(1,1,60,20);
            recuadroque1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| QUEJAS REGISTRADAS |"<<endl;
            obj.VerificarUser();

        break;

        case 20: //F3
            recuadroque(1,1,60,20);
            recuadroque1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CREAR USUARIO |"<<endl;;
            obj.CrearUsuario();
            rlutil::locate(10,22);
            system("pause");
            system("cls");

        break;

        case 21: //F4
            return 0;

        break;
        }

}


 return 0;
}
