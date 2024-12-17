#include <iostream>
#include <string>
#include <vector>
#include "ConjuntosDisjuntos.h"
using namespace std;

using Mapa = vector<string>; // grafo implícito en el mapa
class Manchas {
public:
	Manchas(Mapa const& M, int F, int C) : mapa(M), F(F), C(C), maxim(0), cd(F* C) {
		inicializarMapa();
	}

	void anadirCeldaPetroleo(int a, int b) {
		int index = a * C + b;
		mapa[a][b] = '#';
		for (auto d : dirs) {
			int ni = a + d.first, nj = b + d.second;
			if (correcta(ni, nj) && mapa[ni][nj] == '#') {
				int vecinoIdx = ni * C + nj;
				if (!cd.unidos(index, vecinoIdx)) {
					cd.unir(index, vecinoIdx);
				}
			}
		}
		maxim = max(maxim, cd.tam(index));
	}

	int maximo() const {
		return maxim;
	}

private:
	int F, C; // tamaño del mapa
	int maxim; // tamaño de la mancha más grande
	Mapa mapa;
	ConjuntosDisjuntos cd;

	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}

	const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1}, {-1,-1}, {1,1}, {1,-1}, {-1,1} };
	void inicializarMapa() {
		for (int i = 0; i < F; ++i) {
			for (int j = 0; j < C; ++j) {
				if (mapa[i][j] == '#') {
					int index = i * C + j;//manera de representar un array bidireccional en un vector
					for (auto d : dirs) {
						int ni = i + d.first, nj = j + d.second;
						if (correcta(ni, nj) && mapa[ni][nj] == '#') {
							cd.unir(index, ni * C + nj);
						}
					}
					maxim = max(maxim, cd.tam(index));
				}
			}
		}
	}
};

bool resuelveCaso() { // O(F*C)
	int F, C;
	cin >> F >> C; // número de filas y columnas
	if (!cin)
		return false;
	Mapa mapa(F);
	// leemos la imagen
	for (string& linea : mapa)
		cin >> linea;
	// la analizamos
	Manchas manchas(mapa, F, C);
	cout << manchas.maximo() << '\n';

	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		manchas.anadirCeldaPetroleo(a - 1, b - 1);
		cout << manchas.maximo() << endl;
	}

	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}