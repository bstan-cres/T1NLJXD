#include <iostream>                 // Integrantes: Bastián Cares, Marcelo 
#include <fstream>                  // Seccion: 303
#include <sstream>                  // Profesor: ADRIAN ANDRÉS JARAMILLO SEPULVEDA
#include <limits>                   // Taller n°1
#include "Ut.h"                     // Hecho con conocimientos en clase y mucho, pero mucho youtube
#include "Asistentes.h"

#define Max_Asist 100

using namespace std;

void Menu() {

    int control = 0;
    CargaD(NombreAr, Datos, index);
    do {
        system("CLS");
        std::cout << "Sistema Lolapalooza V1.0" << endl;

        std::cout << "1)Agregar Asistentes" << endl;
        std::cout << "2)Mostrar Asistentes" << endl;
        std::cout << "3)Ordenar Por Edad" << endl;
        std::cout << "4)Editar Asistentes" << endl;
        std::cout << "5)Eliminar Asistentes" << endl;
        std::cout << "6)Salir" << endl;
        cin >> control;

        switch (control)
        {
        case 1:
        {
            AgregarAsistentes(Datos, index);
            break;
        }
        case 2:
        {
            MostrarAsistentes(Datos,index);
            break;
        }
        case 3:
        {
          

        }
        case 4:
        {
          

        }
        case 5:
        {
            

        }
        case 6:
        {
            GuardarC(NombreAr, Datos, index);
            break;
        }
        default:
            cout << "Opcion Ingresada No Es Valida, Ingrese Una Opcion Valida" << endl;
            pause();
            break;
        }

    } while (control != 6);
}
int main()
{
    Menu();
}

