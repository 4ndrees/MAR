#pragma once

#include <vector>
#include <queue>
#include "Digrafo.h"

using Camino = std::deque<int>; // para representar caminos

class OrdenTareas {
public:
	OrdenTareas(Digrafo const& g) : visit(g.V(), false), ant(g.V()),
		apilado(g.V(), false), hayciclo(false) {
		for (int v = 0; v < g.V() ; ++v)
			if (!visit[v])
				dfs(g, v);
	}
	bool hayCiclo() const { return hayciclo; }
	Camino const& ciclo() const { return _ciclo; }
	Camino const& orden() const { return _orden; }

private:
	std::vector<bool> visit; // visit[v] = �se ha alcanzado a v en el dfs?
	std::vector<int> ant; // ant[v] = v�rtice anterior en el camino a v
	std::vector<bool> apilado; // apilado[v] = �est� el v�rtice v en la pila?
	Camino _orden;	// ordenaci�n topol�gica
	Camino _ciclo; // ciclo dirigido (vac�o si no existe)
	bool hayciclo;

	void dfs(Digrafo const& g, int v) {
		apilado[v] = true;
		visit[v] = true;
		for (int w : g.ady(v)) {
			if (hayciclo) // si hemos encontrado un ciclo terminamos
				return;
			if (!visit[w]) { // encontrado un nuevo v�rtice, seguimos
				ant[w] = v; dfs(g, w);
			}
			else if (apilado[w]) { // hemos detectado un ciclo
				// se recupera retrocediendo
				hayciclo = true;
				for (int x = v; x != w; x = ant[x])
					_ciclo.push_front(x);
				_ciclo.push_front(w); _ciclo.push_front(v);
			}
		}
		_orden.push_front(v);
		apilado[v] = false;
	}
};