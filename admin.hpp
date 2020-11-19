#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <conio.h>
#include <locale.h>

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
        cout << "\tIngrese la contrasenia: " <<"\t" <<"\n";
        
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
     cout<<"\tPACIENTES EN TODO EL HOSPITAL\n";
     cout<<"\n ACTIVOS \n";

    if (PatientList.empty())
    {
        cout << "*No hay pacientes en sala de emergencia* \n";
    }
    else
    {
        for (int i = 0; i < PatientList.size(); i++)
        {
            cout << "----------------------------------------------------------------\n";
            cout << "Paciente: " << PatientList[i].name << " " << PatientList[i].lastname << " se encuentra en la habitacion |" << PatientList[i].room;
            cout << "|, Doctor encargado: Dr." << PatientList[i].doctor <<", Costo $"<<PatientList[i].payment<< "\n";
        }
        
    }

    queue<Consult> clone = ConsultPatient;
    cout<<"\n PACIENTES EN CONSULTA \n";
    if (clone.empty())
    {
        cout << "*No hay pacientes en consulta* \n";
    }
    else
    {
        while (!clone.empty()) {
        cout <<"\n----------------------------------------------------------------\n";
        cout <<"Paciente: "<< clone.front().name << " " << clone.front().lastname << " -> "<<" $"<<clone.front().pay;
        clone.pop();
        }
    }
    getch();
    system("cls");
}

void showProfits(){
    float amount=0;
    float amount2=0;
    float totalamount=0;

    for (int i = 0; i < PatientList.size(); i++)
    {
        amount += PatientList[i].payment;
    }
    while (!ConsultPatient.empty())
    {
        amount2 += ConsultPatient.front().pay;
        ConsultPatient.pop();
    }
    
    totalamount = amount + amount2;

    cout << "EL TOTAL DE GANACIAS DEL HOSPITAL ES DE: $" << totalamount << "\n";

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
do
{
    cout<<"*-*-*-*- \t Bienvenido administrador(a) \t -*-*-*-*\n \n";
    cout<<"\t \t  1. Ver todos los pacientes en el hospital \n";
    cout<<"\t \t  2. Mostrar ganancias \n";
    cout<<"\t \t  3. Salir \n";
    cout<<"Opcion: ";
    cin>>option6;
       system("cls");

    switch (option6)
    {
    case 1:showtotalP();
        break;

    case 2: showProfits();
        break;
    case 3: status3 = false;
    break;

    default:cout<<"La opcion ingresada es incorrecta \n";
        break;
    }

} while (status3);

};
