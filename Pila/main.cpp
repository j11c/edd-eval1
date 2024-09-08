/*
3/9/2024
Pila - Estructura de Datos
Cesar Ahumada y Joshua Ibarra
*/

#include <iostream>
using namespace std;

const int tamMax = 10; // tamaño maximo de la pila
int pila[tamMax]; // inicializacion de arreglo para la pila

int indice = 0; // posicion donde se ingresara el siguiente elemento de la pila
int entradaDelUsuario; 

void push();
void pop();
void print();

int main()
{
    int opc;

    // presentar menu de opciones
    do
    {
        cout << "1 - Push (Ingresar dato)" << endl
             << "2 - Pop (Quitar dato)" << endl  
             << "3 - Print (Imprimir la pila)" << endl
             << "4 - Exit" << endl
             << "> ";
        cin >> opc;

        // ejecutar metodo segun la opcion elegida
        if (opc == 1)
        {
            push();
        }
        else if (opc == 2)
        {
            pop();
        }
        else if (opc == 3)
        {
            print();
        }
        else if (opc == 4)
        {
            cout << "Saliendo...";
            break;
        }
        else
        {
            cout << "Opcion inexistente." << endl;
        }

    } while (opc != 4);

    return 0;
}

void push()
{
    // no se puede ingresar un nuevo elemento si la pila esta llena
    if (indice == tamMax)
    {
        cout << "Pila llena." << endl;
    }
    else
    {
        cout << "Valor: ";
        cin >> entradaDelUsuario;
        pila[indice] = entradaDelUsuario;
        indice++; // aumenta el tamanio de la pila
    }

    return;
}

void pop()
{
    // no se puede quitar un elemento de la pila si esta vacia
    if (indice == 0)
    {
        cout << "La pila ya esta vacia." << endl;
    }
    else
    {
        indice--; // disminuye el tamanio de la pila
        // no es necesario cambiar el valor de la posicion del elemento removido, solo no tomarlo en cuenta
    }

    return;
}

void print()
{
    // solo imprimir cuando hay elementos
    if (indice == 0)
    {
        cout << "No hay elementos para imprimir." << endl;
    }
    else
    {
        for (int i = indice; i >= 0; i--)
        {
            cout << "Indice: " << i << "\tElemento: " << pila[i] << endl;
        }
    }

    return;
}
