
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10000;
const int INF = 1000000000; // infinito

// Las operaciones de la máquina calculadora son +1, *2 y /3
// las cuales representan las aristas del grafo
int adyacente(int v, int i) {
    switch (i) {
        case 0: return (v + 1) % MAX; // +1
        case 1: return (v * 2) % MAX; // *2
        case 2: return (v / 3);       // /3
    }
}

// Realizamos una búsqueda en anchura a través del grafo que representa
// la máquina calculadora para encontrar el camino más corto del origen
// al destino
// 
// Coste O(V+A), siendo V todos los valores posibles a los que se pude llegar 
// y A, las operaciones sobre dichos valores
int bfs(int origen, int destino) {
    if (origen == destino) return 0;
    vector<int> distancia(MAX, INF);
    distancia[origen] = 0;
    queue<int> cola; cola.push(origen);
    while (!cola.empty()) {
        int v = cola.front(); cola.pop();
        for (int i = 0; i < 3; ++i) {   // Expandimos cada nodo del árbol con los 3 cálculos posibles 
            int w = adyacente(v, i);
            if (distancia[w] == INF) {
                distancia[w] = distancia[v] + 1;
                if (w == destino) return distancia[w]; // Si llega al destino devolvemos el valor, que será el mínimo
                else cola.push(w);
            }
        }
    }
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int origen, destino;
    cin >> origen >> destino;

    if (!std::cin)
        return false;

    //Resolver el caso y escribir el resultado
    cout << bfs(origen, destino) << '\n';

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}