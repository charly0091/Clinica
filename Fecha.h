#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
class Fecha{
private:
    int dia, mes, anio,semana,diasMes;
    bool bisiesto;

public:
    Fecha(int dia=0, int mes=0, int anio=0)
    {
        this->dia=dia;
        this->mes=mes;
        this->anio=anio;
    }
    void MostrarFecha();
    void CargarFecha();
    Fecha FechaActual();
    void SetBisiesto();
    void SetDiasMes();
    Fecha SumarSemana();
    Fecha SumarDias(int n);
    ///gets()
    int getDia()
    {
        return dia;
    }
    int getMes()
    {
        return mes;
    }
    int getAnio()
    {
        return anio;
    }
    int getSemana()
    {
        return semana;
    }
    ///sets()
    void setDia(int d)
    {
        dia=d;
    }
    void setMes(int m)
    {
        if(m>=1 && m<=12) mes=m;
    }
    void setAnio(int a)
    {
        anio=a;
    }
    ~Fecha(){};
};
#endif // FECHA_H_INCLUDED
