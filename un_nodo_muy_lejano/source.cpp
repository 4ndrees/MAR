
// ANDR�S VI�� S�NCHEZ

#include <iostream>
#include <fstream>
#include <vector>
#include "Grafo.h"
#include "NodosAccesibles.h"

using namespace std;

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int N, C;
    cin >> N >> C; // N: n�mero de nodos de la red; C: n�mero de conexiones en la red

    if (!std::cin)
        return false;

    Grafo g(N);
    
    for (int i = 0; i < C; ++i) {
        int v, w;
        cin >> v >> w;
        g.ponArista(v - 1, w - 1);
    }

    //Resolver problema y escribir el resultado
    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int s, ttl;
        cin >> s >> ttl;
        NodosAccesibles na(g, s - 1, ttl);

        cout << N - na.numAccesibles() << '\n';
    }
    cout << "---\n";

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}