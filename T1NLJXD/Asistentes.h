#pragma once
#ifndef ASISTENTES_H
#define ASISTENTES_H

#include <string>

#define Max_Asist 100

using namespace std;

class Asistentes {
private:
    string nombres;
    string apellidos;
    int ano;
    int dias;
    int identificador;
public:
    //Asistente();
    Asistentes();
    Asistentes(const Asistentes&);
    void setNombres(string x);
    void setApellidos(string x);
    void setNacimiento(int y);
    void setDias(int y);
    void setId(int y);
    //Conseguir valores
    string getNombres();
    string getApellidos();
    int getNacimiento();
    int getDias();
    int getId();
    //funciones
    void AgregarAsistentes();
    void MostrarAsistentes();
    void OrdenarPorEdad();
    void EditarAsistentes();
    void EliminarAsistentes();
    void ver();
};
#endif
