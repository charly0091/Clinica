using namespace std;
#include <iostream>
#include <cstdlib>
#include "menu.h"
#include "funcionesRecuadro.h"
#include "Medico.h"
#include "Afiliado.h"
#include "turnos.h"



int main()
{
///funciones adiccionales para los demas menus
    int Medicos();
    int Afiliados();
    int Quejas();
    int Turnos();

    int Opc;
    Turno t;

    while(true)
    {
        system("cls");
        recuadro(1,1,60,20);
        recuadro(8,4,46,15);
        rlutil::locate(23,3);
        cout<< "\t MENU PRINCIPAL "<<endl;
        rlutil::locate(11,7);
        cout<< "F1 - INGRESAR MENU TURNOS"<<endl;
        rlutil::locate(11,9);
        cout<< "F2 - INGRESAR MENU AFILIADOS"<<endl;
        rlutil::locate(11,11);
        cout<< "F3 - INGRESAR MENU QUEJAS"<<endl;
         rlutil::locate(11,13);
        cout<< "F4 - INGRESAR MENU MEDICOS"<<endl;
        rlutil::locate(11,15);
        cout<< "F5 - SALIR"<<endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18:
            Turnos();

            break;
        case 19:
          Afiliados();


            break;
        case 20:
          Quejas();

            break;
        case 21:
          Medicos();

            break;
        case 22:
          salida();
          char salir;
          rlutil::locate(23,6);
          cin >> salir;
          if(salir=='s'|| salir=='S'){
            rlutil::locate(16,10);
            cout << "Gracias por utilizar el programa!" << endl;
            rlutil::locate(1,22);
            return 0;

            }
          else if(salir=='n'|| salir=='N'){
            rlutil::locate(10,20);
            system("pause");
            system("cls");

          }


            break;

        default:

            recuadro(1,1,60,20);
            rlutil::locate(17,10);
            rlutil::setColor(rlutil::BLACK);
            cout << "Comando incorrecto!" << endl;
            rlutil::setColor(rlutil::BLACK);
            rlutil::locate(10,20);
            system("pause");
            system("cls");
            break;




        }
    }
    cout<< endl;
    system("pause");
    return 0;
}
