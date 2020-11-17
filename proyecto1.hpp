#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <conio.h>

using namespace std;

#define Pass "hospital"

//estrcutura de paciente 
    struct Patient
    {
    string name, lastname;
    int dui;
    string family;
    string doctor;
    int room;
    };

Patient patient;
//listas globales
         vector<Patient> PatientList;
         vector<Patient> EmergencyRoomList;
         queue<Patient>  ConsultPatient;
         vector<Patient> Surgeries;
         vector<Patient> ICUList;
         vector<Patient> DischargedList;


//funcion de contrasenia para el usuario de administrador 
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

//funcion ingresando los datos del paciente 
//nombre -- apellido -- dui -- familiar encargado -- doctor --  habitacon 
//almacenandose en la lista PatientList
void PatientData(){
    cin.ignore();
    cout << "Ingrese el nombre del paciente \n --";
    getline(cin,patient.name);
    cout << "Ingrese el apellido del paciente \n --";
    getline(cin, patient.lastname);
    cout << "Ingrese el DUI del paciente \n --";
    cin >> patient.dui;
    cout << "Ingrese el nombre del familiar encargado \n --";
    cin.ignore();
    getline(cin, patient.family);
    cout << "Ingrese el nombre del doctor encargado \n ";
    cout<<"\t Dr. Juarez \t"<<"\t Dr. Cerna \t";
    cout << "\nDoctor: ";
    getline(cin, patient.doctor);
    cout << "Ingrese la habitacion del paciente \n --";
    cin >> patient.room;

    PatientList.push_back(patient);

    system("cls");
}

//funcion donde muestra las opciones del hospital para poder ingresar al paciente 
//consulta -- sala de emergencias -- cirujias
//segun la opcion ingresada se almacenara en la lista :
//ConsultPatient, EmergencyRoomList, Surgeries 
void admitPatient(){
    int option3;

    cout << "Ingrese el area donde sera trasladado el paciente \n";
    cout << "1. Consulta \n";
    cout << "2. Sala de Emergencias \n";
    cout << "3. Cirujias \n";
    cout << "Opcion :";
    cin >> option3;
        system("cls");

    
    switch (option3)
    {
    case 1:
        PatientData();
        ConsultPatient.push(patient);
        break;
    case 2:
        PatientData();
        EmergencyRoomList.push_back(patient);
        break;
    case 3:
        PatientData();
        Surgeries.push_back(patient);
        break;
    default: 
        cout << "Opcion incorrecta \n";
        break;
    }
}

//funcion seguida de la entrada de la contrasenia para el usuario administrador 
//entrando en funciones especiales que solo el admin tiene acceso 
void admin()
{
    password();

    system("cls");
    cout << "\tAccedio correctamente al sistema \n";
    cout << "\tQue desea hacer? \n";

};

//funcion buscando el paciente por medio del nombre 
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
        cout << "Presione enter para continuar...";
        getch();
        system("cls");
        return;
    }
    else
    {
        for (int i = 0; i < PatientList.size(); i++)
        {
            if (PatientList.at(i).name == name)
            {
                search = true;
                cout << "El paciente " << PatientList.at(i).name << " " << PatientList.at(i).lastname << " se encuentra en la habitacion " << PatientList.at(i).room << "\n";
                cout << "Presione enter para continuar...";
                getch();
                system("cls");
            }
        }
        if (search == false)
        {
            cout << "No hay ningun paciente con ese nombre \n";
            cout << "Presione enter para continuar...";
            getch();
            system("cls");
        }
    }
}

//funcion buscando los pacientes que tiene cada doctor
//se muestran las opciones de los doctores en turno 
void searchDR()
{
    bool search2 = false;
    int option4;
    cout<<"Doctores en turno \n";
    cout<<"1. Dr.Juarez \n"<<"2. Dr. Cerna \n";
    cout << "Opcion: ";
    cin>>option4;

    switch (option4)
    {
        case 1: 
            if (PatientList.empty())
            {
                cout << "No hay pacientes en el hospital \n";
                cout << "Presione enter para continuar...";
                getch();
                system("cls");
                return;
            }
            else
            {
                for (int i = 0; i < PatientList.size(); i++)
                {
                    if (PatientList.at(i).doctor == "Juarez")
                    {
                        search2 = true;
                        cout << "Paciente: " << PatientList.at(i).name << " " << PatientList.at(i).lastname << ", se encuentra en la habitacion " << PatientList.at(i).room << "\n";
                    }
                }
                cout << "Presiones enter para continuar...";
                getch();
                system("cls");
                if (search2 == false)
                {
                    cout << "El doctor no tiene ningun paciente en estos momentos \n";
                    cout << "Presione enter para continuar...";
                    getch();
                    system("cls");
                }
            }
                break;
        case 2:
            if (PatientList.empty())
            {
                cout << "No hay pacientes en el hospital \n";
                cout << "Presione enter para continuar...";
                getch();
                system("cls");
                return;
            }
            else
            {
                for (int i = 0; i < PatientList.size(); i++)
                {
                    if (PatientList.at(i).doctor == "Cerna")
                    {
                        search2 = true;
                        cout << "Paciente: " << PatientList.at(i).name << " " << PatientList.at(i).lastname << ", se encuentra en la habitacion " << PatientList.at(i).room << "\n";
                    }
                }
                cout << "Presiones enter para continuar...";
                getch();
                system("cls");
                
                if (search2 == false)
                {
                    cout << "El doctor no tiene ningun paciente en estos momentos \n";
                    cout << "Presione enter para continuar...";
                    getch();
                    system("cls");
                }
            }
            break;
        default: cout << "Opcion incorrecta";
            break;
    }

}

//funcion mostrando los pacientes ubicados en la sala de emergencia 
void emergency()
{
    cout<<"\tPacientes en la sala de emergencia \n";

    if (EmergencyRoomList.empty())
    {
        cout << "No hay pacientes en sala de emergencia \n";
    }
    else
    {
        for (int i = 0; i < EmergencyRoomList.size(); i++)
        {
            cout << "Paciente: " << EmergencyRoomList[i].name << " " << EmergencyRoomList[i].lastname << " se encuentra en la habitacion " << EmergencyRoomList[i].room;
            cout << " , doctor encargado: Dr." << EmergencyRoomList[i].doctor << "\n";
        }
        
    }
    getch();
    system("cls");
}

//funcion mostrando los pacientes ubicados en sala de operaciones
void surgery()
{
    cout<<"\tPacientes en cirujia \n";

        if (Surgeries.empty())
        {
            cout << "No hay pacientes en cirujia en estos momentos \n";
        }
        else
        {
            for (int i = 0; i < Surgeries.size(); i++)
            {
                cout << "Paciente: " << Surgeries[i].name << " " << Surgeries[i].lastname << " se encuentra en la habitacion " << Surgeries[i].room;
                cout << " , doctor encargado: Dr." << Surgeries[i].doctor << "\n";
            }
            
        } 
     
    getch();
    system("cls");
}

//funcion mostrando los pacientes en cuidados intensivos 
void ICU()
{
    cout<<"Pacientes en cuidados intensivos \t"; 
}

//funcion para dar de alta (eliminar) un paciente 
void removePatient()
{
    cin.ignore();
    string DischargedName, DischargedLastname;
    cout<<"\tA que paciente desea dar de alta \n";
    cout << "Nombre: ";
    getline(cin, DischargedName);
    cout << "Apellido: ";
    getline(cin, DischargedLastname);

    bool found = false;    

    for (int i = 0; i < PatientList.size(); i++)
    {
        if (PatientList.at(i).name == DischargedName && PatientList.at(i).lastname == DischargedLastname)
        {
            found = true;
            cout << "Se ha eliminado al paciente correctamente \n";
            PatientList.at(i).
        }   
    }
    for (int i = 0; i < EmergencyRoomList.size(); i++)
    {
        if (EmergencyRoomList.at(i).name == DischargedName && EmergencyRoomList.at(i).lastname == DischargedLastname)
        {
            found = true;
        }   
    }

    if (found == false)
    {
        cout << "No hay ningun paciente con dichos datos \n";
    }

    getch();
    system("cls");
}

//menu que tiene acceso el personal de secretaria 
//un menu amplio de opciones desde ingresar, buscar, mostrar y eliminar un paciente 
void secretary()
{
    int option2;
    bool status2=true;
    do
    {
        cout<<"*-*-*-*- \t Bienvenido, ingrese la opcion de su preferencia \t -*-*-*-*\n \n";
		cout<<"\t \t \t 1. Ingresar paciente  \n";
		cout<<"\t \t \t 2. Buscar paciente por su nombre \n";
		cout<<"\t \t \t 3. Buscar pacientes de doctor especifico \n";
        cout<<"\t \t \t 4. Mostrar pacientes en sala de emergencia \n";
        cout<<"\t \t \t 5. Mostrar pacientes en cirujia \n";
        cout<<"\t \t \t 6. Mostrar pacientes en cuidados intensivos \n";
		cout<<"\t \t \t 7. Dar de alta paciente \n";
		cout<<"\t \t \t 8. Salir \n";
        cout << "Opcion: ";
		cin>>option2;
        system("cls");

        switch (option2)
        {
        case 1: admitPatient();
            break;
        case 2: searching();
            break;
        case 3: searchDR();
            break;
        case 4: emergency();
            break;
        case 5: surgery();
            break;
        case 6:
            break;
        case 7: removePatient();
            break;
        case 8:
            status2 = false;
            break;
        default:
            cout << "Opcion incorrecta \n"; 
            break;
        }
    } while (status2);
    

};
