
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include "MaximaCompConexa.h"

using namespace std;

// O(N + M) siendo N el número de personas de la ciudad y M el número
// de relaciones entre las mismas
void resuelveCaso() {
    //resuelve aqui tu caso
    //Lee los datos
    
    int N, M;
    cin >> N >> M;

    Grafo amigos(N);

    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        amigos.ponArista(v-1, w-1);
    }
    
    //Calcula el resultado
    MaximaCompConexa mcc(amigos);

    //Escribe el resultado
    cout << mcc.maximo() << '\n';
}

int main() {
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    return 0;
}