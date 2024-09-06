/*
3/9/2024
Vectores - Estructura de Datos
Cesar Ahumada y Joshua Ibarra
*/

#include <iostream>
using namespace std;

int main()
{
    int n = 0; // tamanio del vector

    cout << "Ingrese el tamanio del vector: ";
    cin >> n;

    int vector[n];

    for (int i = 0; i < n; i++) // llenar vector
    {
        cout << "Ingrese un numero para la posicion: " << i + 1 << ": ";
        cin >> vector[i];
    }

    int opc = 0;

    do
    {
        cout << "1.- Imprimir Vector" << endl
             << "2.- Imprimir valor max." << endl
             << "3.- Imprimir valor min." << endl
             << "4.- Buscar valor." << endl
             << "5.- Salir de programa." << endl
             << "> ";
        cin >> opc;

        if (opc == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "Elemento en la posicion " << i << ": " << vector[i] << endl;
            }
        }
        else if (opc == 2)
        {
            int max_value = vector[0];
            int max_index = 0;

            for (int i = 1; i < n; i++)
            {
                if (vector[i] > max_value)
                {
                    max_value = vector[i];
                    max_index = i;
                }
            }

            cout << "El valor maximo del vector es: " << max_value << endl;
            cout << "Se encuentra en el indice: " << max_index << endl;
        }
        else if (opc == 3)
        {
            int min_value = vector[0];
            int min_index = 0;

            for (int i = 1; i < n; i++)
            {
                if (vector[i] < min_value)
                {
                    min_value = vector[i];
                    min_index = i;
                }
            }

            cout << "El valor minimo del vector es: " << min_value << endl;
            cout << "Se encuentra en el indice: " << min_index << endl;
        }
        else if (opc == 4)
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
        else if (opc == 5)
        {
            return 0;
        }
        else
        {
            cout << "Vuelva a elegir:" << endl;
        }
    } while (opc != 5);
    return 0;
}
