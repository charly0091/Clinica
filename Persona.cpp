
#include<iostream>
#include<conio.h>
#include "Persona.h"
#include "Fecha.h"
using namespace std;
#include "rlutil.h"

void Persona::cargarPersona()
{
    rlutil::locate(2,5);
    cout << "Nombre: ";
    cin >>nombre;
    rlutil::locate(2,6);
    cout << "Apellido: ";
    cin >> apellido;
    rlutil::locate(2,7);
    cout << "DNI: ";
    cin >> DNI;
    rlutil::locate(2,8);
    cout << "Email: ";
    cin >> email;
    rlutil::locate(2,9);
    cout << "Fecha de nacimiento: ";
    fechaN.CargarFecha();
    estado=true;
}
void Persona::mostrarPersona()
{   rlutil::locate(2,5);
    cout << "Nombre: ";
    cout << nombre << endl;
    rlutil::locate(2,6);
    cout << "Apellido: ";
    cout << apellido << endl;
    rlutil::locate(2,7);
    cout << "DNI: ";
    cout << DNI << endl;
    rlutil::locate(2,8);
    cout << "Email: ";
    cout << email << endl;
    rlutil::locate(2,9);
    cout << "Fecha de nacimiento: ";
    rlutil::locate(2,10);
    fechaN.MostrarFecha();
    if(estado==true){
        rlutil::locate(2,11);
        cout<<"Persona activa"<<endl;
    }

}


