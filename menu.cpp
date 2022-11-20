#include <iostream>
using namespace std;
#include <cstdlib>
#include "funciones.h"
///MENU PRINCIPAL
void menuPrincipal()
{
    int opc;
    do{
        cout << "1 - TURNOS" << endl,
        cout << "2 - AFILIADOS" << endl;
        cout << "3 - ATENCION POR GUARDIA" << endl;
        cout << "4 - INTERNACION" << endl;
        cout << "5 - INFORMES" << endl;
        cout << "0 - SALIR" << endl;
        cin >> opc;
        system("cls");
        switch(opc){

        case 1:
            //Menu Turnos
            menu1();
            break;
        case 2:
            //Menu Afiliados
            menu2();
            break;
        case 3:
            //Menu Atencion por guardia
            menu3();
            break;
        case 4:
            //Menu Internacion
            menu4();
            break;
        case 5:
            //Menu informes
            menu5();
            break;
        case 0:
            menuSalir();
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }

    }
    while(opc!=0);
}

///MENU TURNOS
void menu1()
{
    int opc;
    do
    {
        cout << "1 - ATENCION MEDICA" << endl;
        cout << "2 - ESTUDIOS" << endl;
        cout << "0 - MENU PRINCIPAL" << endl;
        cin >> opc;
        system("cls");
        switch(opc)
        {
        case 1:
            //Menu Turnos -> Atencion Medica
            menu1_1();
            break;
        case 2:
            //Menu Turnos -> Estudios
            menu1_2();
            break;
        case 0:
            menuPrincipal();
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    }
    while(opc!=0);
    }
    //Menu Turnos -> Atencion Medica
void menu1_1()
{
    int opc;
    do
    {
        cout << "1 - NUEVO TURNO" << endl;
        cout << "2 - REPROGRAMAR" << endl;
        cout << "3 - CANCELAR TURNO" << endl;
        cout << "0 - MENU PRINCIPAL" << endl;
        cin >> opc;
        system("cls");
        switch(opc)
        {
        case 1:
            menu1_1_1();
            break;
        case 2:
            menu1_1_2();
            break;
        case 3:
            menu1_1_3();
        case 0:
            menuPrincipal();
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    }
    while(opc!=0);

}
    //Menu Turnos -> Estudios
void menu1_2()
{
     int opc;
    do
    {
        cout << "1 - NUEVO TURNO" << endl;
        cout << "2 - REPROGRAMAR" << endl;
        cout << "3 - CANCELAR TURNO" << endl;
        cout << "0 - MENU PRINCIPAL" << endl;
        cin >> opc;
        system("cls");
        switch(opc)
        {
        case 1:
            menu1_2_1();
            break;
        case 2:
            menu1_2_2();
            break;
        case 3:
            menu1_2_3();
        case 0:
            menuPrincipal();
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    }
    while(opc!=0);
}
    //Menu Turnos -> Atencion Medica -> Nuevo Turno
void menu1_1_1()
{

}
    //Menu Turnos -> Atencion Medica -> Reprogramar
void menu1_1_2()
{

}
    //Menu Turnos -> Atencion Medica -> Cancelar
void menu1_1_3()
{

}
//Menu Turnos -> Estudios -> Nuevo Turno
void menu1_2_1()
{

}
//Menu Turnos -> Estudios -> Reprogramar
void menu1_2_2()
{

}
//Menu Turnos -> Estudios -> Cancelar
void menu1_2_3()
{

}
///MENU AFILIADOS
void menu2()
{
    int opc;
    do
    {
        cout << "1 - NUEVO AFILIADO" << endl;
        cout << "2 - MODIFICAR" << endl;
        cout << "3 - LISTAR AFILIADOS" << endl;
        cout << "0 - MENU PRINCIPAL" << endl;
        cin >> opc;
        system("cls");
        switch(opc)
        {
        case 1:
            //Menu Afiliados -> Nuevo afiliado
            menu2_1();
            break;
        case 2:
            //Menu Afiliados -> Modificar
            menu2_2();
            break;
        case 3:
            //Menu Afiliados -> Listar afiliados
            menu2_3();
        case 0:
            menuPrincipal();
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    }
    while(opc!=0);
}
//Menu Afiliados -> Nuevo afiliado
void menu2_1()
{

}
//Menu Afiliados -> Modificar
void menu2_2()
{

}
//Menu Afiliados -> Listar Afiliados
void menu2_3()
{

}
///Menu Atencion por guardia
void menu3()
{

}
///MENU INTERNACION
void menu4()
{

}
///MENU INFORMES
void menu5()
{

}
///MENU SALIR
void menuSalir()
{
    exit(0);
}


