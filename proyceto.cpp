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

paciente Paciente;

struct sala_de_emergencia
{
    paciente pac;
};

void admin();
void secretaria();

void ingresarPaciente(){
    cout << "Ingrese el nombre del paciente \n";
    getline(cin,Paciente.name);
    cout << "Ingrese el apellido del paciente \n";
    getline(cin, Paciente.lastname);
    cout << "Ingrese el DUI del paciente \n";
    cin >> Paciente.dui;
    cout << "Ingrese el nombre del familiar encargado \n";
    getline(cin, Paciente.family);
    cout << "Ingrese el nombre del doctor encargado \n";
    getline(cin, Paciente.doctor);
    cout << "Ingrese la habitacion del paciente \n";
    cin >> Paciente.habitacion;
}

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
		cout<<"2.- Buscar paciente por su nombre \n";
		cout<<"3.- Buscar pacientes de doctor especifico \n";
		cout<<"4.- Dar de alta paciente \n";
		cout<<"5.- Salir \n";
		cin>>opcion2;

        switch (opcion2)
        {
        case 1: ingresarPaciente();
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            status2 = false;
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
