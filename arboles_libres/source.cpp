
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include "ArbolesLibre.h"
using namespace std;

bool resuelveCaso() {

    // Leer caso de prueba: cin>>...
    
    int V, A;
    cin >> V >> A;

    if (!std::cin)
        return false;

    Grafo g(V);

    for (int i = 0; i < A; ++i) {
        int v, w;
        cin >> v >> w;
        g.ponArista(v, w);
    }

    // Resolver problema
    ArbolesLibres al = ArbolesLibres(g, 0);
    
    // Escribir el resultado
    if (al.esArbLibre()) cout << "SI\n";
    else cout << "NO\n";

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}