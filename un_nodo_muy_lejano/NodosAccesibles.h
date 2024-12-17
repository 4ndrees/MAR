#pragma once

#include <vector>
#include <queue>
#include "Grafo.h"

class NodosAccesibles {
public:
	NodosAccesibles(Grafo const& g, int s, int TTL) : visit(g.V(), false), ant(g.V()),
														dist(g.V()), _TTL(TTL), _s(s) {
		bfs(g);
	}

	int numAccesibles() { return nacces; }

private:
	int _TTL;
	int _s;
	std::vector<bool> visit;
	std::vector<int> ant;
	std::vector<int> dist;
	int nacces;

	void bfs(Grafo const& g) {
		nacces = 0;
		std::queue<int> q;
		dist[_s] = 0; visit[_s] = true;
		q.push(_s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			++nacces;
			for (int w : g.ady(v)) {
				if (!visit[w] && dist[v] < _TTL) {
					ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
					q.push(w);
				}
			}
		}
	}

};