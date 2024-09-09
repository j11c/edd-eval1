/*
9/9/2024
Vectores - Estructura de Datos
Cesar Ahumada y Joshua Ibarra
*/

#include <iostream>
using namespace std;

void ordenarVector(int vector[], int n);
void imprimirVector(int vector[], int n);
void imprimirMax(int vector[], int n);
void imprimirMin(int vector[], int n);
void buscarValor(int vector[], int n);

int main()
{
    system ("cls"); // funcion para borrar la pantalla
    int n = 0;                // tamaño del vector
    const int max_size = 100; // tamaño maximo del vector

    cout << "Ingrese el tamano del vector: ";
    cin >> n;

    int vector[max_size]; // se define con tamaño maximo

    for (int i = 0; i < n; i++) // llenar vector
    {
        cout << "Ingrese un numero para la posicion " << i + 1 << ": ";
        cin >> vector[i];
    }

    // bubble sort para organizar el vector de menor a mayor
    ordenarVector(vector, n);

    int opc = 0;

    do
    {
        cout << "1.- Imprimir Vector" << endl
             << "2.- Imprimir valor maximo" << endl
             << "3.- Imprimir valor minimo" << endl
             << "4.- Buscar valor" << endl
             << "5.- Salir del programa" << endl
             << "> ";
        cin >> opc;

        if (opc == 1)
        {
            imprimirVector(vector, n);
        }
        else if (opc == 2)
        {
            imprimirMax(vector, n);
        }
        else if (opc == 3)
        {
            imprimirMin(vector, n);
        }
        else if (opc == 4)
        {
            buscarValor(vector, n);
        }
        else if (opc == 5)
        {
            return 0;
        }
        else 
        {
            cout << "Vuelva a elegir." << endl;
        }
    } while (opc != 6);

    return 0;
}

void ordenarVector(int vector[], int n)
{ // bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                int x = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = x;
            }
        }
    }
}

void imprimirVector(int vector[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Elemento en la posicion " << i + 1 << ": " << vector[i] << endl;
    }
}

void imprimirMax(int vector[], int n)
{
    int max_value = vector[0];
    int max_posicion = 0;

    for (int i = 1; i < n; i++)
    {
        if (vector[i] > max_value)
        {
            max_value = vector[i];
            max_posicion = i;
        }
    }

    cout << "El valor maximo del vector es: " << max_value << endl;
}

void imprimirMin(int vector[], int n)
{
    int min_value = vector[0];
    int min_posicion = 0;

    for (int i = 1; i < n; i++)
    {
        if (vector[i] < min_value)
        {
            min_value = vector[i];
            min_posicion = i;
        }
    }

    cout << "El valor minimo del vector es: " << min_value << endl;
}

void buscarValor(int vector[], int n)
{
    int value;
    cout << "Ingrese el valor a buscar: ";
    cin >> value;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (vector[i] == value)
        {
            cout << "El valor " << value << " se encuentra en el indice: " << i << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "El valor " << value << " no existe en el vector." << endl;
    }
}