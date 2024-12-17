
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include <vector>
#include "Manchas.h"

using namespace std;

using Mapa = vector<string>; // grafo implícito en el mapa

bool resuelveCaso() { // O(F*C)

    //Leer caso de prueba: cin>>...
    int F, C;
    cin >> F >> C; 

    if (!std::cin)
        return false;

    //Resolver problema
    
    Mapa mapa = Mapa(F);
    for (string& linea : mapa)
        cin >> linea;

    Manchas manchas(mapa);

    //Escribir resultado
    cout << manchas.numero() << ' ' << manchas.maximo() << '\n';

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}