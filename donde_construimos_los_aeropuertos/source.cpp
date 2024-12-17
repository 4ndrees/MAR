
//Andrés Viñé Sánchez - anvine01@ucm.es
//Adrián Corrochano Colmenares - adrcorro@ucm.es

#include <stdio.h>
#include <iostream>
using namespace std;

#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"


// Para resolver el problema hemos utilizado al algoritmo de kruskal en el que calculamos el árbol de recubrimiento minimoo el bosque recubrimiento mínimos si los grafos tienen varias componentes conexas
// Modificamos el algoritmo de Kruskal para que no una los conjuntos si el coste de la carretera es mayor que el coste del aeropuerto. De esta manera nos da una serie de conjutnos cada uno con un aeropuerto
// y una serie de carreteras que unen las ciudades por lo que el coste que devolvería sería el coste de los aeropuertos mas el coste de las carreteras
class Aeropuerto {

public:
    Aeropuerto(GrafoValorado<int> const& g, int A) : _A(A), _coste(0), num_conjuntos(g.V()){
        //Resuelve el problema para el grafo g y coste A por aeropuerto
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                if (a.valor() < A) {
                    cjtos.unir(v, w);
                    num_conjuntos = cjtos.num_cjtos();
                    _ARM.push_back(a); _coste += a.valor();
                    if (_ARM.size() == g.V() - 1) break;
                }
            }
        }
    }
    int coste() {
        //devuelve el mejor coste
        return _coste + num_conjuntos*_A;
    }
    int aeropuertos() {
        //devuelve el numero de aeropuertos
        return num_conjuntos;
    }
private:
    std::vector<Arista<int>> _ARM;
    int _coste;
    int num_conjuntos;
    int _A;
};


bool resuelveCaso() { // O(log A) siendo A las aristas del garfo
    int V, E, A; 
    cin >> V >> E >> A;
    if (!cin) return false;
    GrafoValorado<int> grafo(V);
    int u, v, c;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> c;
        grafo.ponArista({ u - 1,v - 1,c });
    }

    Aeropuerto solucion(grafo, A);

    cout << solucion.coste() << ' ' << solucion.aeropuertos() << '\n';
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;

}