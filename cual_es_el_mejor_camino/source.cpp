
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), numCalles(g.V(), 0), ult(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v)) {
                relajar(a);
            }
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }
  
    Valor distancia(int v) const { return dist[v]; }

    int calles(int v) const { return numCalles[v]; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<int> numCalles;
    std::vector<AristaDirigida<Valor>> ult;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ult[w] = a;
            numCalles[w] = numCalles[v] + 1;
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int N, C;
    cin >> N >> C;

    if (!std::cin)
        return false;

    DigrafoValorado<int> distMin(N);
    DigrafoValorado<int> callesMin(N);
    for (int i = 0; i < C; ++i) {
        int u, v, peso;
        cin >> u >> v >> peso;
        distMin.ponArista({ u - 1, v - 1, peso });
        distMin.ponArista({ v - 1, u - 1, peso });
        callesMin.ponArista({ u - 1, v - 1, 1 });
        callesMin.ponArista({ v - 1, u - 1, 1 });
    }

    //Resolver problema
    int K;
    cin >> K;

    for (int i = 0; i < K; ++i) {
        int orig, dest;
        cin >> orig >> dest;

        Dijkstra<int> masCorto(distMin, orig - 1);
        Dijkstra<int> menosCalles(callesMin, orig - 1);

        //Escribir resultado
        if (masCorto.distancia(dest - 1) == std::numeric_limits<int>::max())
            cout << "SIN CAMINO\n";
        else {
            cout << masCorto.distancia(dest - 1);
            if (masCorto.calles(dest - 1) != menosCalles.calles(dest - 1))
                cout << " NO\n";
            else
                cout << " SI\n";
        }
    }

    cout << "---\n";

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}