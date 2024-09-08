/*
9/9/2024
Vectores - Estructura de Datos
Cesar Ahumada y Joshua Ibarra
*/

#include <iostream>
using namespace std;

void imprimirVector(int vector[], int n);
void imprimirMax(int vector[], int n);
void imprimirMin(int vector[], int n);
void buscarValor(int vector[], int n);
void insertarValor(int vector[], int &n, int max_size);

int main()
{
    int n = 0; // tamanio del vector
    const int max_size = 100; // tamaño máximo del vector

    cout << "Ingrese el tamaño del vector: ";
    cin >> n;

    int vector[max_size]; // se define con tamaño máximo

    for (int i = 0; i < n; i++) // llenar vector
    {
        cout << "Ingrese un numero para la posicion " << i + 1 << ": ";
        cin >> vector[i];
    }

    int opc = 0;

    do
    {
        cout << "1.- Imprimir Vector" << endl
             << "2.- Imprimir valor máximo" << endl
             << "3.- Imprimir valor mínimo" << endl
             << "4.- Buscar valor" << endl
             << "5.- Insertar valor" << endl
             << "6.- Salir del programa" << endl
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
            insertarValor(vector, n, max_size);
        }
        else if (opc != 6)
        {
            cout << "Vuelva a elegir." << endl;
        }
    } while (opc != 6);

    return 0;
}

void imprimirVector(int vector[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Elemento en la posicion " << i << ": " << vector[i] << endl;
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
    cout << "Se encuentra en la posicion: " << max_posicion << endl;
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
    cout << "Se encuentra en la posición: " << min_posicion << endl;
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
            cout << "El valor " << value << " se encuentra en el índice: " << i << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "El valor " << value << " no existe en el vector." << endl;
    }
}

void insertarValor(int vector[], int &n, int max_size)
{
    if (n == max_size)
    {
        cout << "El vector esta lleno." << endl;
    }
    else
    {
        int value;
        cout << "Ingrese el valor a insertar: ";
        cin >> value;
        vector[n] = value;
        n++;
        cout << "Valor insertado." << endl;
    }
}
