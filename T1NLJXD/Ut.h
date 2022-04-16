#pragma once
#ifndef UT_H
#define UT_H

//librerias y extras
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Asistentes.h"

//contexto
using namespace std;

//maximos a utilizar
#define Max_Asist 100

//------------------------------------------------------------------------------------------------------------------------------//Generalidades

void pause() {
    std::cout << endl << "presione una tecla para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string dummy;
    getline(cin, dummy);
}

bool añoValido(int año) {
    if (año < 1900 || año>3000) {
        return false;
    }
    else {
        return true;
    }
}

bool DiasValidos(int dias) {
    if (dias < 3 || dias>1) {
        return false;
    }
    return true;
}

vector<string> split(string lineaASeparar, char delimitador) {//Aqui declaramos vectores
    vector<string>vector_interno;
    stringstream linea(lineaASeparar);
    string parteDelString;
    while (getline(linea, parteDelString, delimitador)) {
        vector_interno.push_back(parteDelString);
    }
    return vector_interno;
}

//------------------------------------------------------------------------------------------------------------------------------//Cosas de Vectores


string NombreAr = "Datos.csv";
Asistentes Datos[Max_Asist];
int index = 0;

//cargar info
void CargaD(string NombreAr, Asistentes v[], int &index) { 

    ifstream archivoCar;
    archivoCar.open(NombreAr, ios::in);
    string booktag;
    while (getline(archivoCar, booktag, '\n')) {

        vector<string>items = split(booktag, ';');
        v[index].setNombres(items[0]);
        v[index].setApellidos(items[1]);
        v[index].setNacimiento(atoi(items[2].c_str()));
        v[index].setDias(atoi(items[3].c_str()));
        v[index].setId(atoi(items[4].c_str()));
        index++;
    }
    archivoCar.close();
    if (index == 0) {
        cout << "No hay registros cargados" << endl;
    }
}

//guardar info
void GuardarC(string NombreAr, Asistentes v[], int index) {
    
    ofstream archivoEsc;
    archivoEsc.open(NombreAr, ios::out);

    for (int i=0; i < index; i++) {
        archivoEsc << v[i].getNombres() << ";";
        archivoEsc << v[i].getApellidos() << ";";
        archivoEsc << v[i].getNacimiento() << ";";
        archivoEsc << v[i].getDias() << ";";
        archivoEsc << v[i].getId() << ";";
    }
    archivoEsc.close();
}

//Existe registro (v o f)
bool ENR(int NewNumero, Asistentes v[], int index) {

    for (int j=0; j < index; j++) {
        if (NewNumero == v[j].getId()) {
            return true;
        }
        else {
            return false;
        }
    }
}


//------------------------------------------------------------------------------------------------------------------------------//Funciones

void AgregarAsistentes(Asistentes v[], int& index) {
    char mover;
    cout << "[Nuevo Asistente]" << endl;

    string nombres;
    cout << "Nombres:";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombres);
    v[index].setNombres(nombres);

    string apellidos;
    cout << "Apellidos:";
    getline(cin, apellidos);
    v[index].setApellidos(apellidos);

    //Analizador de año
    int ano = 0;
    do {
        cout << "Año de Nacimiento:";
        cin >> ano;
        if (añoValido(ano) == false) {

            cout << "Año Invalido, ingrese algo realista" << endl << endl;
            ano = -1;
        }

    } while (ano == -1);
    v[index].setNacimiento(ano);

    int dias;
    do {
        cout << "Dias a participar:";
        cin >> dias;
        if (DiasValidos(dias)) {
            cout<< "Cantidad de dias invalido, ingrese cantidad valida" << endl << endl;
            dias = -1;
        }
    } while (dias == -1);
    v[index].setDias(dias);

    int identificador;
    do {
        cout << "id:";
        cin >> identificador;
        if (ENR(identificador,v,index)) {
            cout << "El id ingresado ya se encuentra registrado, intente con otra id"<<endl<<endl;
            identificador = -1;
        }
    } while (identificador == -1);
    v[index].setId(identificador);

    index++;

}

void MostrarAsistentes(Asistentes v[], int index) {

}

void OrdenarPorEdad(Asistentes v[], int index) {
    for (int i=0;i<index;i++) {

        for (int j=i+1;j<index;j++) {

            if (v[j].getNacimiento() < v[i].getNacimiento()) {
                Asistentes tpm = Asistentes(v[j]);
                v[j] = Asistentes(v[i]);
                v[i] = Asistentes(tpm);
            }
        }
    }
    cout << "Orden realizado con exito" << endl;
    pause();
}


#endif
