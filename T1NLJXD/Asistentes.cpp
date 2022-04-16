#include "Asistentes.h"
#include <iostream>
using namespace std;

Asistentes::Asistentes() { //constructor
	this->nombres = "";
	this->apellidos="";
	this->ano = 0;
	this->dias = 0;
	this->identificador = 0;
}

Asistentes::Asistentes(const Asistentes& other) {//constructor copia
	this->nombres = other.nombres;
	this->apellidos = other.apellidos;
	this->ano = ano;
	this->dias = dias;
	this->identificador = identificador;
}

void Asistentes::setNombres(string value) {
	this->nombres = value;
}

void Asistentes::setApellidos(string value) {
	this->apellidos = value;
}

void Asistentes::setNacimiento(int value) {
	this->ano = value;
}

void Asistentes::setDias(int value) {
	this->dias = value;
}

void Asistentes::setId(int value) {
	this->identificador = value;
}

string Asistentes::getNombres() {
	return this->nombres;
}

string Asistentes::getApellidos() {
	return this->apellidos;
}

int Asistentes::getNacimiento() {
	return this->ano;
}

int Asistentes::getDias() {
	return this->dias;
}

int Asistentes::getId() {
	return this->identificador;
}

void Asistentes::ver() {
	cout << "[Registro: " << getId() << "]" << endl;
	cout << "\tNombre: " << getNombres() << " " << getApellidos() << endl;
	cout << "\tAño Nacimiento: " << getNacimiento() << endl << endl;
	cout << "\tDias Participando:"<< getDias() <<endl;
}