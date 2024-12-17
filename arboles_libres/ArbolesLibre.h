#pragma once

#include <vector>
#include "Grafo.h"

class ArbolesLibres {
private:
	std::vector<bool> visit;	// vector que nos indica si los nodos han sido visitados con anterioridad
	std::vector<int> ant;		// vector de nodos anteriores al nodo actual
	int _s;						// nodo desde el que se inicia el dfs
	bool _esArbLibre;			// booleano que nos indica si el grafo es un árbol libre
public:
	// El árbol será libre si no contiene ciclos y es conexo
	ArbolesLibres(Grafo const& g, int s) : visit(g.V(), false), ant(g.V(), -1), _s(s) {
		ant[_s] = _s;
		_esArbLibre = !contieneCiclo(g, _s) && esConexo();
	}
	// Realizamos dfs para comprobar que no hay ningún ciclo, y no existe ningún vértice sin visitar
	bool contieneCiclo(Grafo const& g, int s) {
		
		visit[s] = true;
		for (auto a : g.ady(s)) {
			if (ant[a] == -1) ant[a] = s;				// Si el anterior no está definido, decimos que es el nodo s
			if (visit[a] && ant[s] != a)		// Si el nodo ya ha sido visitado no es un arbol libre
				return true;
			else if (ant[s] != a)
				if (contieneCiclo(g, a)) return true;
		}

		return false;
	}

	// Recorremos el vector de visitados y si hay algún nodo no visitado el árbol no es conexo
	bool esConexo() {
		for (int i = 0; i < visit.size(); ++i) {
			if (!visit[i]) return false;
		}
		return true;
	}

	bool esArbLibre() { return _esArbLibre; }
};