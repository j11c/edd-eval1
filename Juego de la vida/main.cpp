/*
3/9/2024
Juego de la vida - Estructura de Datos
Cesar Ahumada y Joshua Ibarra
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main()
{
    std::srand(std::time(0)); // semilla para la generacion pseudoaleatoria de numeros

    unsigned int n; // tamanio del universo N*N
    int x, y; // coordenadas x, y
    int g; // numero de generaciones
    int p; // porcentaje de poblacion inicial respecto al tamanio del universo
    int suma = 0; // variable para revisar numero de celdas adyacentes
    bool generacionSiguiente = 1; // alterna entre ambas matrices 2D, la del universo actual y la que esta siendo calculada

    std::cout << "Universo de tamanio N*N. Valor de N: ";
    std::cin >> n;
    std::cout << "Porcentaje poblacion inicial: ";
    std::cin >> p;
    std::cout << "Numero de generaciones: ";
    std::cin >> g;

    int universo[n][n][2]; // inicializacion de la matriz 3D: el universo, compuesta por 2 matrices 2D

    // iterar para inicializar todas las celdas del universo en 0
    for (int k=0; k<2; k++)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                universo[i][j][k] = 0;
            }
        }
    }
    
    // calcular cantidad de poblacion inicial
    int poblacionInicial = (n * n * p)/100;

    // asignar lugar aleatorio en el universo a la poblacion inicial
    for (int i=0; i<poblacionInicial; i++)
    {
        // coordenadas x,y son un numero aleatorio entre 0 y n
        x = std::rand()%n;
        y = std::rand()%n;

        // no repetir lugar para asegurar numero de poblacion inicial, volver a intentar (afecta rendimiento)
        if (universo[x][y][!generacionSiguiente] == 1) 
        {
            i--;
        }
        else 
        {
            universo[x][y][!generacionSiguiente] = 1;
        }
    }

    // mostrar numero de poblacion inicial
    std::cout << "Poblacion inicial: " << poblacionInicial << "\n\n";

    // se desarrolla el juego de la vida
    for (int i = 0; i < g; i++) // ciclo que se repite el numero de generaciones establecido
    {
        // mostrar generacion actual
        std::cout << "Generacion " << i+1 << "\n";
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (universo[i][j][!generacionSiguiente] == 1)
                {
                    std::cout << std::setw(3) << "#"; // simbolo voluminoso para representar una celda viva
                }
                else 
                {
                    std::cout << std::setw(3) << "-"; // simbolo poco voluminoso para representar una celda muerta
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";

        // calcular la siguiente generacion
        for (y = 0; y < n; y++)
        {
            for (x = 0; x < n; x++)
            {
                // Revisar existencia de vecinos, revisa si esta en orilla y sumar el valor de todos los vecinos
                if (x!=0 && y!=n-1){ suma += universo[x-1][y+1][!generacionSiguiente]; }
                if (y!=n-1){ suma += universo[x][y+1][!generacionSiguiente]; }
                if (x!=n-1 && y!=n-1){ suma += universo[x+1][y+1][!generacionSiguiente]; }
                
                if (x!=0){ suma += universo[x-1][y][!generacionSiguiente]; }
                // [x,y] es la celda actual, no cuenta su valor en la suma
                if (x!=n-1){ suma += universo[x+1][y][!generacionSiguiente]; }
                
                if (x!=0 && y!=0){ suma += universo[x-1][y-1][!generacionSiguiente]; }
                if (y!=0){ suma += universo[x][y-1][!generacionSiguiente]; }
                if (x!=n-1 && y!=0){ suma += universo[x+1][y-1][!generacionSiguiente]; }
                
                /*
                [x-1][y+1]  [x][y+1]    [x+1][y+1]
                [x-1][y  ]  [x][y  ]    [x+1][y  ]
                [x-1][y-1]  [x][y-1]    [x+1][y-1]
                */

                // Decidir destino de la celda
                if (universo[x][y][!generacionSiguiente] == 1 && suma < 2){ universo[x][y][generacionSiguiente] = 0; } // muerte por aislamiento
                else if (universo[x][y][!generacionSiguiente] == 1 && (suma == 2 || suma == 3)){ universo[x][y][generacionSiguiente] = 1; } // permanece viva
                else if (universo[x][y][!generacionSiguiente] == 1 && suma > 3){ universo[x][y][generacionSiguiente] = 0; } // muerte por sobrepoblacion
                else if (universo[x][y][!generacionSiguiente] == 0 && suma == 3){ universo[x][y][generacionSiguiente] = 1; } // nace nueva celda
                else { universo[x][y][generacionSiguiente] = 0; }

                suma = 0; // restablecer suma de vecinos en cero para la siguiente celda
            }
        }

        // pasar al siguiente universo
        generacionSiguiente = !generacionSiguiente;
    }

    return 0;
}
