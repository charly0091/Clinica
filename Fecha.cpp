#include<iostream>
#include<conio.h>
#include "Fecha.h"
using namespace std;
#include "rlutil.h"
#include <ctime>

void Fecha::MostrarFecha()
{
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio;
}
void Fecha::CargarFecha()
{
    int d;
    rlutil::locate(4,14);
    cout<<"DIA: ";
    cin>>d;
    while(d<1 || d>31){
        rlutil::locate(15,14);
        cout<<"ELIGA UN DIA VALIDO: ";
        cin>>d;
    }
    setDia(d);
    rlutil::locate(4,15);
    cout<<"MES: ";
    cin>>d;
    while(d<1 || d>12){
      rlutil::locate(15,15);
        cout<<"ELIGA UN MES VALIDO: ";
        cin>>d;
    }
    setMes(d);
    rlutil::locate(4,16);
    cout<<"ANIO: ";
    cin>>d;
    setAnio(d);
}

Fecha Fecha::FechaActual()
{
    Fecha fa;
    time_t t;
    t = time(NULL);
    struct tm *f;
    f = localtime(&t);
    this->dia = f->tm_mday;
    this->mes = f->tm_mon+1;
    this->anio = f->tm_year+1900;
    this->semana = f->tm_wday;
    fa.dia = this->dia;
    fa.mes = this->mes;
    fa.anio = this->anio;
    fa.semana = this->semana;
    return fa;

    //cout << dia << "/" << mes << "/" << anio << " - " << semana << endl;


}

void Fecha::SetBisiesto()
{
    this->bisiesto = ((this->anio%4 == 0) && (this->anio%100 != 0) || (this->anio%400 == 0));
}
void Fecha::SetDiasMes()
{
    int dias = 31;
    this->SetBisiesto();
    if(this->mes == 4 || this->mes == 6 || this->mes == 9 || this->mes == 11)
    {
        dias = 30;
    }
    else if(this->mes == 2)
    {
        if(this->bisiesto)
        {
            dias = 29;
        }
        else
        {
            dias = 28;
        }
    }
    this->diasMes = dias;
}

Fecha Fecha::SumarSemana()
{
    Fecha fecha;
    this->SetDiasMes();
    fecha.dia = this->dia+7;
    fecha.mes = this->mes;
    fecha.anio = this->anio;
    fecha.semana = this->semana;
    if(fecha.dia>this->diasMes)
    {
        fecha.dia = 7-(this->diasMes-this->dia);
        fecha.mes++;
        if(fecha.mes>12){
            fecha.mes=1;
            fecha.anio++;
        }
    }
    return fecha;
}
Fecha Fecha::SumarDias(int n)
{
    Fecha fecha;
    this->SetDiasMes();
    fecha.dia = this->dia+n;
    fecha.mes = this->mes;
    fecha.anio = this->anio;
    if(fecha.dia>this->diasMes)
    {
        fecha.dia = n-(this->diasMes-this->dia);
        fecha.mes++;
        if(fecha.mes>12){
            fecha.mes=1;
            fecha.anio++;
        }
    }

    return fecha;
}

