#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct paciente
{
    string name, lastname;
    int dui;
    string family;
    string sintomas;
    string doctor;
    int habitacion;
};

struct sala_de_emergencia
{
    paciente pac;
};
void admin();

void secretaria();

void admin()
{
    		cout<<"2.- Mostrar pacientes";

};
void secretaria()
{
    int opcion2;
    bool status2=true;
    do
    {
        cout<<"Bienvenido, ingrese la opcion de su preferencia: \n";
		cout<<"1.- Ingresar pacientes \n";
		cout<<"2.- Buscar paciente por su nombre";
		cout<<"3.- Buscar pacientes de doctor especifico";
		cout<<"4.- Dar de alta paciente";
		cout<<"5.- Salir \n";
		cin>>opcion2;

        switch (opcion2)
        {
        case 1:
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 6:
            break;
        default:
            break;
        }
    } while (status2);
    

};

int main()
{
    //hospital de centro america 
    int option;
    bool status=true;

    do
    {
        cout<<"Bienvenido al hospital de centro america \n";
        cout<<"USUARIOS\n";
        cout<<"1. ADMIN\n";
        cout<<"2. Secretaria \n";
        cout<<"3. Cerrar";
        cin>>option;
        system("cls");

        switch (option)
        {
        case 1:admin();
            break;
        case 2: secretaria();
            break;
        case 3: status=false;
            break;
        default:cout<<"numero incorrecto";
                    break;
        }
    } while (status);

    return 0;
}
