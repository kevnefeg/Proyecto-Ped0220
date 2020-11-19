#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <conio.h>
#include <locale.h>
#include "Secretaria.hpp"
#include "Admin.hpp"

using namespace std;

//funciones 
void password();
void PatientData();
void admitPatient();
void showtotalP();
void showProfits();
void admin();
void searching();
void searchDR();
void emergency();
void surgery();
void removePatient();
void ShowQueue();
void charge();
void secretary();


//main del "hospital de centroamerica"
int main()
{
    setlocale(LC_CTYPE, "Spanish");
    int option;
    bool status=true;

    do
    {
//menu de inicio (opciones de usuarios admin - secretaria)

        cout<<"-*-*-*-* \t BIENVENIDOS AL HOSPITAL DE CENTROAMERICA \t -*-*-*-*\n";
        cout<<"USUARIOS DISPONIBLES \n";
        cout<<"1. Administrador(a) \n";
        cout<<"2. Enfermero(a) \n";
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

