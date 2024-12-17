
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include <queue>
#include "GrafoValorado.h"

using namespace std;

// Función que realiza una búsqueda BFS restringida por anchura mínima
bool puedeViajar(const GrafoValorado<int>& grafo, int origen, int destino, int anchura_minima) {
    vector<bool> visitado(grafo.V(), false);
    queue<int> pendientes;
    pendientes.push(origen);
    visitado[origen] = true;

    while (!pendientes.empty()) {
        int v = pendientes.front();
        pendientes.pop();

        for (const auto& arista : grafo.ady(v)) {
            int w = arista.otro(v);
            if (!visitado[w] && arista.valor() >= anchura_minima) {
                if (w == destino) return true;
                visitado[w] = true;
                pendientes.push(w);
            }
        }
    }
    return false;
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int V, E;
    cin >> V >> E;

    if (!std::cin)
        return false;

    GrafoValorado<int> grafo(V);

    // Leer las calles
    for (int i = 0; i < E; ++i) {
        int v, w, anchura;
        cin >> v >> w >> anchura;
        grafo.ponArista({ v - 1, w - 1, anchura }); // Ajustar a índices base 0
    }

    int K;
    cin >> K;

    // Leer las consultas
    for (int i = 0; i < K; ++i) {
        int origen, destino, anchura_camion;
        cin >> origen >> destino >> anchura_camion;
        if (puedeViajar(grafo, origen - 1, destino - 1, anchura_camion)) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }
    }

    //Escribir resultado
    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}