#include "Digrafo.h"
#include <iostream>
#include <queue>

using namespace std;



class BFSDirigido {
public:
	BFSDirigido(Digrafo const& g, int destino) : visit(g.V(), false),
		ant(g.V()), distancia(g.V(), destino), s(0), maxDistance(destino) {
		bfs(g, s, destino);
	}

	int distanciaDI(int v) const {
		return distancia[v];
	}

private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	std::vector<int> distancia; // dist[v] = aristas en el camino s->v más corto
	int maxDistance;
	int s;
	//Busqueda en anchura
	int bfs(Digrafo const& dg, int origen, int destino) {
		if (origen == destino)
			return 0;
		distancia[origen] = 0;
		queue<int> cola;
		cola.push(origen);

		while (!cola.empty()) {
			int v = cola.front(); cola.pop();
			for (int w : dg.ady(v)) {
				if (distancia[w] == maxDistance) {
					distancia[w] = distancia[v] + 1;
					if (w == destino)
						return distancia[w];
					else cola.push(w);
				}
			}
		}
	}
};

bool resuelveCaso() {
	int N, K, S, E;
	cin >> N >> K >> S >> E;

	if (N == 0 && K == 0 && S == 0 && E == 0)
		return false;

	vector<int> destinos(N * N, -1);
	//Leer las serpientes
	for (int i = 0; i < S; i++) {
		int a, b;
		cin >> a >> b;
		destinos[a - 1] = b - 1;
	}
	//Leer las escaleras, en verdad se podria hacer en el mismo for loop
	for (int i = 0; i < E; i++) {
		int a2, b2;
		cin >> a2 >> b2;
		destinos[a2 - 1] = b2 - 1;
	}

	Digrafo dg(N * N);
	for (int i = 0; i < N * N - 1; i++) {
		if (destinos[i] == -1) {
			for (int a = i + 1; a < (K + i) + 1 && a < N * N; a++) {
				if (destinos[a] != -1) {
					dg.ponArista(i, destinos[a]);
				}
				else {
					dg.ponArista(i, a);
				}
			}
		}
	}

	BFSDirigido bfsDir(dg, N * N - 1);
	cout << bfsDir.distanciaDI(N * N - 1) << endl;

	return true;
}



int main() {
	while (resuelveCaso());

	return 0;
}


