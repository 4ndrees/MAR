
// ANDR�S VI�� S�NCHEZ

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include "GrafoValorado.h"

using namespace std;

class CaminosMinimos {
private:
    vector<int> dist;        // Distancia m�nima a cada nodo
    vector<int> ways;        // N�mero de caminos m�nimos a cada nodo
    const int INF = numeric_limits<int>::max();

public:
    CaminosMinimos(const GrafoValorado<int>& grafo, int origen) {
        int N = grafo.V();
        dist.assign(N, INF);
        ways.assign(N, 0);

        // Priority queue para Dijkstra (distancia, nodo)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[origen] = 0;
        ways[origen] = 1;
        pq.push({ 0, origen });

        while (!pq.empty()) {
            auto vertices = pq.top();
            pq.pop();

            // Si encontramos una distancia mayor, la ignoramos
            if (vertices.first > dist[vertices.second]) continue;

            for (const auto& arista : grafo.ady(vertices.second)) {
                int v = arista.otro(vertices.second);
                int peso = arista.valor();

                // Si encontramos un camino m�s corto
                if (dist[vertices.second] + peso < dist[v]) {
                    dist[v] = dist[vertices.second] + peso;
                    ways[v] = ways[vertices.second];
                    pq.push({ dist[v], v });
                }
                // Si encontramos otro camino con la misma distancia m�nima
                else if (dist[vertices.second] + peso == dist[v]) {
                    ways[v] += ways[vertices.second];
                }
            }
        }
    }

    int numeroCaminos(int destino) const {
        return ways[destino];
    }
};

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int N, C;
    cin >> N >> C;

    if (!std::cin)
        return false;

    GrafoValorado<int> grafo(N);

    for (int i = 0; i < C; ++i) {
        int u, v, peso;
        cin >> u >> v >> peso;
        grafo.ponArista(Arista<int>(u - 1, v - 1, peso));
    }

    //Resolver problema
    CaminosMinimos caminos(grafo, 0);  // Casa de Lucas (nodo 1 -> �ndice 0)

    //Escribir resultado
    cout << caminos.numeroCaminos(N - 1) << '\n';  // Colegio de Lucas (nodo N -> �ndice N-1)
    
    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}