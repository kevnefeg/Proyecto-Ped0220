#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <conio.h>
#include "proyecto1.hpp"

using namespace std;

//funciones 
void password();
void PatientData();
void admitPatient();
void admin();
void searching();
void searchDR();
void emergency();
void surgery();
void ICU();
void removePatient();
void secretary();


//main del "hospital de centroamerica"
int main()
{
    int option;
    bool status=true;

    do
    {
//menu de inicio (opciones de usuarios admin - secretaria)

        cout<<"-*-*-*-* \t BIENVENIDOS AL HOSPITAL DE CENTROAMERICA \t -*-*-*-*\n";
        cout<<"USUARIOS DISPONIBLES \n";
        cout<<"1. Administrador(a) \n";
        cout<<"2. Secretaria \n";
        cout<<"3. Cerrar \n";
        cout << "Opcion: ";
        cin>>option;
        system("cls");

        switch (option)
        {
        case 1: admin();
            break;
        case 2: secretary();
            break;
        case 3: status=false;
            break;
        default: cout<<"Opcion incorrecta";
            break;
        }
    } while (status);

    return 0;
}

