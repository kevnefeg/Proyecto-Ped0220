#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <conio.h>

using namespace std;

#define Pass "hospital"

//listas globales
       //  vector<Patient> PatientList;

void password()
{
    string password;
    bool ingress = true;

    while (ingress)
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
            ingress = false;
        }
        else
        {
            cout << "\n";
            cout << "Contrasenia incorrecta \n";
            cout << "Presione enter para volver a intentarlo \n"; 
        }
    }
}


void showtotalP()
{
     cout<<"\tPacientes en todo el hospital\n";
     cout<<"\n ACTIVOS \n";

    if (PatientList.empty())
    {
        cout << "No hay pacientes en sala de emergencia \n";
    }
    else
    {
        for (int i = 0; i < PatientList.size(); i++)
        {
            cout << "Paciente: " << PatientList[i].name << " " << PatientList[i].lastname << " se encuentra en la habitacion " << PatientList[i].room;
            cout << " , doctor encargado: Dr." << PatientList[i].doctor << "\n";
        }
        
    }
//maquillaje
      queue<Consult> clone = ConsultPatient;
    cout<<"pacientes en consulta \n";
    while (!clone.empty()) {
        cout <<"Paciente: "<< clone.front().name << " " << clone.front().lastname << "  ";
        clone.pop();
    }
   
    getch();
    system("cls");
}

//funcion seguida de la entrada de la contrasenia para el usuario administrador 
//entrando en funciones especiales que solo el admin tiene acceso 
void admin()
{
    password();
    system("cls");
    bool status3 = true;
    int option6;
    cout << "\tAccedio correctamente al sistema \n";
    cout << "\tQue desea hacer? \n";
do
{
    
    cout<<"1.Ver todos los pacientes en el hospital \n";
    cout<<"2.Mostrar ganancias \n";
    cin>>option6;

    switch (option6)
    {
    case 1:showtotalP();
        break;

    case 2:
        break;
    default:
        break;
    }

} while (status3);

};
