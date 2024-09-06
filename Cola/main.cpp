/*
16/08/2024
Cola - Estructura de Datos
Cesar Ahumada y Joshua Ibarra
*/

#include <iostream> 
using namespace std;

void push();
void pop();
void print();

int const tamMax = 10; // tamanio maximo de la fila
int tamAct = 0; // tamanio actual de la fila
int i = 0; // Inicio de la fila
int f = -1; // Final de la fila

int fila[tamMax]; // declaracion del arreglo que representa la fila
int opc = 0;

int main()
{
    // presentar menu de opciones
    do { 
        cout << "1 - Push (Insertar)" << endl
             << "2 - Pop (Quitar)" << endl
             << "3 - Print (Imprimir todos los miembros de la cola)" << endl
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
        }
        else if (opc != 4)
        {
            cout << "Esa opción no existe.";
        }
    } while (opc != 4); // condicion de salida

    return 0; 
}

void push()
{
    if (tamAct == tamMax)
    {
        cout << "Cola llena." <<endl;
    }
    else
    {
        f++;
        if (f == tamMax)
        {
            f = 0;
        }
        cout << "Valor: ";
        cin >> fila[f];
        tamAct++; // La fila aumenta de tamaño
    }

    return;
}

void pop()
{
    if(tamAct == 0)
    {
        cout << "Cola vacia." << endl;
    } 
    else
    {
        i++;
    
        if(i == tamMax)
        {
            i=0;
        }

        tamAct--; // La fila disminuye de tamaño
    }
    
    return;
}

void print()
{
    // revisar que haya minimo un elemento
    if (tamAct == 0)
    {
        cout << "No hay elementos para imprimir." << endl;
    }
    else
    {
        /* 
        se imprimen todos los elementos de la fila iniciando desde el indice i
        hasta que se hayan impreso todos los elementos
        */ 
        
        int copia_i = i;
        int copia_tamAct = tamAct;

        // se crea una copia del tamanio actual para saber cuando se imprimieron todos los elementos
        while (copia_tamAct > 0)
        {
            cout << "Indice: " << copia_i << " - Elemento: " << fila[copia_i] << endl;
            copia_i++;

            // reiniciar indice cuando se llega al maximo del arreglo
            if (copia_i == tamMax)
            {
                copia_i = 0;
            }

            copia_tamAct--;
        }
    }
    
    return;
}