#pragma once

#include <vector>
#include <iostream>
#include <fstream>

using Mapa = std::vector<std::string>; // grafo implícito en el mapa

class Manchas {
public:
	Manchas(Mapa const& M) : F(M.size()), C(M[0].size()),
		visit(F, std::vector<bool>(C, false)), num(0), maxim(0) {

		for (int i = 0; i < F; ++i) {
			for (int j = 0; j < C; ++j) {
				if (!visit[i][j] && M[i][j] == '#') { // se reconoce una nueva mancha
					++num;
					int nuevotam = dfs(M, i, j);
					maxim = std::max(maxim, nuevotam);
				}
			}
		}
	}

	int numero() const { return num; }

	int maximo() const { return maxim; }

private:
	int F, C; // tamaño del mapa
	std::vector<std::vector<bool>> visit; // visit[i][j] = se ha visitado el pixel <i, j>?
	int num;	// número de manchas
	int maxim;  // tamaño de la mancha más grande

	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}

	const std::vector<std::pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };

	int dfs(Mapa const& M, int i, int j) {
		visit[i][j] = true;
		int tam = 1;
		for (auto d : dirs) {
			int ni = i + d.first, nj = j + d.second;
			if (correcta(ni, nj) && M[ni][nj] == '#' && !visit[ni][nj]) {
				tam += dfs(M, ni, nj);
			}
		}
		return tam;
	}
};