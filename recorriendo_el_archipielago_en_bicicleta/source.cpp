
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include "Kruskal.h"

using namespace std;

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int I, P;
    cin >> I >> P;

    if (!std::cin)
        return false;

    GrafoValorado<int> g(I);
    for (int i = 0; i < P; ++i) {
        int v, w, coste;
        cin >> v >> w >> coste;
        g.ponArista({ v - 1, w - 1, coste });
    }

    //Resolver problema
    ARM_Kruskal<int> arm(g);

    //Escribir resultado
    if (arm.ARM().size() == I - 1)
        cout << arm.costeARM() << '\n';
    else
        cout << "No hay puentes suficientes\n";

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}