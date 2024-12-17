
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include "DigrafoValorado.h"
#include "Dijkstra.h"

using namespace std;

const int INF = numeric_limits<int>::max();

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int N, C;
    cin >> N >> C;

    if (!std::cin)
        return false;

    DigrafoValorado<int> grafo(N), grafoInverso(N);
    for (int i = 0; i < C; ++i) {
        int origen, destino, esfuerzo;
        cin >> origen >> destino >> esfuerzo;
        --origen; --destino; // Ajustar índices a 0-based
        grafo.ponArista({ origen, destino, esfuerzo });
        grafoInverso.ponArista({ destino, origen, esfuerzo });
    }

    int oficina, P;
    cin >> oficina >> P;
    --oficina; // Ajustar índice a 0-based

    vector<int> destinatarios(P);
    for (int i = 0; i < P; ++i) {
        cin >> destinatarios[i];
        --destinatarios[i]; // Ajustar índice a 0-based
    }

    // Calcular distancias desde la oficina y hacia la oficina
    Dijkstra<int> dijk(grafo, oficina);
    Dijkstra<int> dijki(grafoInverso, oficina);

    long long esfuerzoTotal = 0;
    bool posible = true;
    for (int casa : destinatarios) {
        if (dijk.distancia(casa) == INF || dijki.distancia(casa) == INF) {
            posible = false;
            break;
        }
        esfuerzoTotal += dijk.distancia(casa) + dijki.distancia(casa);
    }

    if (posible) {
        cout << esfuerzoTotal << '\n';
    }
    else {
        cout << "Imposible\n";
    }

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}
