
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include "DigrafoValorado.h"

using namespace std;

// Estructura para almacenar un nodo con su tiempo acumulado
struct NodoTiempo {
    int nodo;
    int tiempo;
    bool operator>(const NodoTiempo& otro) const {
        return tiempo > otro.tiempo; // Para usar en priority_queue (menor primero)
    }
};

// Función para encontrar el tiempo mínimo usando Dijkstra
int tiempoMinimo(const DigrafoValorado<int>& grafo, const vector<int>& tiemposCarga) {
    int N = grafo.V(); // Número de nodos
    vector<int> dist(N, numeric_limits<int>::max()); // Distancias mínimas
    priority_queue<NodoTiempo, vector<NodoTiempo>, greater<NodoTiempo>> pq;

    // Nodo inicial
    dist[0] = tiemposCarga[0];
    pq.push({ 0, tiemposCarga[0] });

    while (!pq.empty()) {
        NodoTiempo actual = pq.top();
        pq.pop();

        if (actual.tiempo > dist[actual.nodo]) continue; // Si ya fue procesado

        for (auto arista : grafo.ady(actual.nodo)) {
            int vecino = arista.hasta();
            int nuevoTiempo = actual.tiempo + arista.valor() + tiemposCarga[vecino];
            if (nuevoTiempo < dist[vecino]) {
                dist[vecino] = nuevoTiempo;
                pq.push({ vecino, nuevoTiempo });
            }
        }
    }

    return dist[N - 1]; // Tiempo mínimo para llegar al último nodo
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int N;
    cin >> N;

    if (N == 0)
        return false;

    vector<int> tiemposCarga(N);
    for (int i = 0; i < N; ++i) {
        cin >> tiemposCarga[i];
    }

    int M;
    cin >> M;
    DigrafoValorado<int> grafo(N);
    for (int i = 0; i < M; ++i) {
        int desde, hasta, tiempo;
        cin >> desde >> hasta >> tiempo;
        grafo.ponArista({ desde - 1, hasta - 1, tiempo }); // Índices ajustados
    }

    int resultado = tiempoMinimo(grafo, tiemposCarga);
    if (resultado == numeric_limits<int>::max()) {
        cout << "IMPOSIBLE" << endl;
    }
    else {
        cout << resultado << endl;
    }

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}