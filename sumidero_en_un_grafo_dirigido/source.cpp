
// ANDR�S VI�� S�NCHEZ

#include <iostream>
#include <vector>
#include <fstream>
#include "Digrafo.h"

using namespace std;

// Funci�n para determinar si existe un v�rtice sumidero
void detectarSumidero(Digrafo const& g) {
    int V = g.V(); // N�mero de v�rtices
    vector<int> gradoEntrada(V, 0), gradoSalida(V, 0);

    // Calcular el grado de entrada y salida para cada v�rtice
    for (int v = 0; v < V; ++v) {
        for (int w : g.ady(v)) {
            gradoSalida[v]++;
            gradoEntrada[w]++;
        }
    }

    // Buscar un v�rtice sumidero
    int sumidero = -1;
    for (int v = 0; v < V; ++v) {
        if (gradoSalida[v] == 0 && gradoEntrada[v] == V - 1) {
            sumidero = v;
            break;
        }
    }

    // Imprimir el resultado
    if (sumidero != -1) {
        cout << "SI " << sumidero << '\n';
    }
    else {
        cout << "NO\n";
    }
}


bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int V, A;
    cin >> V >> A;

    if (!std::cin)
        return false;

    Digrafo g(V);
    for (int i = 0; i < A; ++i) {
        int v, w;
        cin >> v >> w;
        g.ponArista(v, w);
    }

    //Resolver problema
    detectarSumidero(g);

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}