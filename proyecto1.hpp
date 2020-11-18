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

    struct Consult
    {
        string name, lastname;
        int dui;
        int pay = 50;
    };

Patient patient;
Consult consult;
//listas globales
         vector<Patient> PatientList;
         vector<Patient> EmergencyRoomList;
         queue<Consult>  ConsultPatient;
         vector<Patient> Surgeries;
         vector<Patient> ICUList;
         vector<Patient> DischargedList;


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
        cin.ignore();
        cout << "Ingrese el nombre del paciente \n --";
        getline(cin,consult.name);
        cout << "Ingrese el apellido del paciente \n --";
        getline(cin, consult.lastname);
        cout << "Ingrese el DUI del paciente \n --";
        cin >> consult.dui;

        ConsultPatient.push(consult);

        system("cls");
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

void ShowQueue() {
    queue<Consult> clone = ConsultPatient;
    while (!clone.empty()) {
        cout << clone.front().name << " " << clone.front().lastname << "  ";
        clone.pop();
    }
    getch();
    system("cls");
}

void cobrar(){
    int amount=0;
    while (!ConsultPatient.empty())
    {
        amount += ConsultPatient.front().pay;
        ConsultPatient.pop();
    }
        ConsultPatient.pop();
    cout << "Se le ha cobrado a los clientes un total de $" << amount << endl;
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

     bool encontrado = false;

    if(EmergencyRoomList.empty()) {
        cout << "No hay productos en la lista" << endl;
        return;
    }else {
        for (int pos = 0; pos < EmergencyRoomList.size(); pos++) {
            if(EmergencyRoomList.at(pos).name == DischargedName && EmergencyRoomList.at(pos).lastname == DischargedLastname)
            {
                encontrado = true;

                EmergencyRoomList.erase(EmergencyRoomList.begin()+pos);
                PatientList.erase(PatientList.begin()+pos);

                cout << "Se borro el producto correctamente" << endl;
                break;
            }
        }

        if(encontrado == false) {
            cout << "No habia ningun producto con ese nombre" << endl;
        }
    }

//funcion
  if(PatientList.empty()) {
        cout << "No hay productos en la lista" << endl;
        return;
    }else {
        for (int pos = 0; pos < PatientList.size(); pos++) {
            if(PatientList.at(pos).name == DischargedName && PatientList.at(pos).lastname == DischargedLastname)
            {
                encontrado = true;

                PatientList.erase(PatientList.begin()+pos);

                cout << "Se borro el producto correctamente" << endl;
                break;
            }
        }

        if(encontrado == false) {
            cout << "No habia ningun producto con ese nombre" << endl;
        }
    }
    
// funcion
 if(ICUList.empty()) {
        cout << "No hay productos en la lista" << endl;
        return;
    }else {
        for (int pos = 0; pos < ICUList.size(); pos++) {
            if(ICUList.at(pos).name == DischargedName && ICUList.at(pos).lastname == DischargedLastname)
            {
                encontrado = true;

                ICUList.erase(ICUList.begin()+pos);

                cout << "Se borro el producto correctamente" << endl;
                break;
            }
        }

        if(encontrado == false) {
            cout << "No habia ningun producto con ese nombre" << endl;
        }
    }

//funcion
 if(Surgeries.empty()) {
        cout << "No hay productos en la lista" << endl;
        return;
    }else {
        for (int pos = 0; pos < Surgeries.size(); pos++) {
            if(Surgeries.at(pos).name == DischargedName && Surgeries.at(pos).lastname == DischargedLastname)
            {
                encontrado = true;

                Surgeries.erase(Surgeries.begin()+pos);

                cout << "Se borro el producto correctamente" << endl;
                break;
            }
        }

        if(encontrado == false) {
            cout << "No habia ningun producto con ese nombre" << endl;
        }
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
        cout<<"\t \t \t 4. Mostrar cola de pacientes en consulta \n";
        cout<<"\t \t \t 5. Despachar paciente de consulta \n";
        cout<<"\t \t \t 6. Mostrar pacientes en sala de emergencia \n";
        cout<<"\t \t \t 7. Mostrar pacientes en cirujia \n";
        cout<<"\t \t \t 8. Mostrar pacientes en cuidados intensivos \n";
		cout<<"\t \t \t 9. Dar de alta paciente \n";
		cout<<"\t \t \t 10. Salir \n";
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
        case 4: ShowQueue();
            break;
        case 5: cobrar();
            break;
        case 6: emergency();
            break;
        case 7: surgery();
            break;
        case 8:
            break;
        case 9: removePatient();
            break;
        case 10:
            status2 = false;
            break;
        default:
            cout << "Opcion incorrecta \n"; 
            break;
        }
    } while (status2);
    
};
