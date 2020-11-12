#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <conio.h>

using namespace std;

//Se declara la contraseña para la funcion del admin como constante
#define Pass "hospital"

struct Patient
{
    string name, lastname;
    int dui;
    string family;
    string sintomas;
    string doctor;
    int habitacion;
};

Patient patient;
vector<Patient> PatientList;
vector<Patient> EmergencyRoomList;
vector<Patient> ICUList;

void ingresarPaciente();
void admin();
void searching();
void searchDR();
void secretaria();
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
        cout<<"3. Cerrar \n";
        cout << "Opcion: ";
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

void ingresarPaciente(){
    cin.ignore();
    cout << "Ingrese el nombre del paciente \n";
    getline(cin,patient.name);
    cout << "Ingrese el apellido del paciente \n";
    getline(cin, patient.lastname);
    cout << "Ingrese el DUI del paciente \n";
    cin >> patient.dui;
    cout << "Ingrese el nombre del familiar encargado \n";
    cin.ignore();
    getline(cin, patient.family);
    cout << "Ingrese el nombre del doctor encargado \n";
    cout<<"Dr. Juarez \t"<<"Dr. Cerna \t";
    getline(cin, patient.doctor);
    cout << "Ingrese la habitacion del paciente \n";
    cin >> patient.habitacion;

    PatientList.push_back(patient);

    int opcion3;

    cout << "A que area se trasladara el paciente \n";
    cout << "1. Sala de Emergencias \n";
    cout << "2. Cuidados Intensivos \n";
    cout << "Opcion :";
    cin >> opcion3;
        system("cls");

    
    switch (opcion3)
    {
    case 1:
        EmergencyRoomList.push_back(patient);
        break;
    case 2:
        ICUList.push_back(patient);
    default: 
        cout << "Opcion incorrecta \n";
        break;
    }
}

void admin()
{
    string password;
    bool ingres = true;

    while (ingres)
    {
        cin.ignore();
        cout << "Ingrese la contrasenia: ";
        
        char caracter;
        caracter = getch();

        password = "";

        //El caracter tiene que ser diferente que Enter
        while (caracter != 13)
        {
            if (caracter != 8) //El caracter tiene que ser diferente que backspace
            {
                password.push_back(caracter);
                cout << "*"; 
            }
            else
            {
                if (password.size() > 0)
                {
                    cout << "\b \b"; //Poder borrar los caracteres ingresados
                    password.pop_back();
                }
                
            }
            
            caracter = getch();
        }
        

        if (password == Pass)
        {
            ingres = false;
        }
        else
        {
            cout << "\n";
            cout << "Contrasenia incorrecta \n";
            cout << "Presione enter para volver a intentarlo... \n"; 
        }
    }

    system("cls");
    cout << "\tAccedio correctamente al sistema \n";
    cout << "\tQue desea hacer? \n";

};

void searching()
{
    bool search = false;
    string name;

    cout << "Ingrese el nombre del paciente que desea buscar \n";
    cout << "Nombre: ";
    cin >> name;

    if (PatientList.empty())
    {
        cout << "No hay pacientes \n";
        return;
    }
    else
    {
        for (int i = 0; i < PatientList.size(); i++)
        {
            if (PatientList.at(i).name == name)
            {
                search = true;
                cout << "El paciente " << PatientList.at(i).name << " se ncuentra en el hospital \n";
                cout << "Dui";
            }
        }
        if (search == false)
        {
            cout << "No hay ningun paciente con ese nombre \n";
        }
    }
}

void searchDR()
{
    int option4;
    cout<<"Doctores en turno \n";
    cout<<"1. DR .JUAREZ \n"<<" 2. DR. CERNA \n";
    cin>>option4;

    switch (option4)
    {
    case 1: 
        break;

    case 2:
        break;
    
    default:
        break;
    }

}

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
        cout<<"4.- Mostrar pacientes en sala de emergencia \n";
        cout<<"5.- Mostrar pacientes en cuidados intensivos \n";
		cout<<"6.- Dar de alta paciente \n";
		cout<<"7.- Salir \n";
        cout << "Opcion: ";
		cin>>opcion2;
        system("cls");

        switch (opcion2)
        {
        case 1: ingresarPaciente();
            break;
        case 2: searching();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
          
            break;
        case 6:
            break;
        case 7: status2 = false;
            break;
        default:
            break;
        }
    } while (status2);
    

};
