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

//funcion seguida de la entrada de la contrasenia para el usuario administrador 
//entrando en funciones especiales que solo el admin tiene acceso 

void admin()
{
    password();

    system("cls");
    cout << "\tAccedio correctamente al sistema \n";
    cout << "\tQue desea hacer? \n";

};
