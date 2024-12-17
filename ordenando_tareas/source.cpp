
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include <queue>
#include "Digrafo.h"
#include "OrdenTareas.h"

using namespace std;

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int N, M;
    cin >> N >> M;

    if (!std::cin)
        return false;

    Digrafo dg(N);
    for (int i = 0; i < M; ++i) {
        int v, w;
        cin >> v >> w;
        dg.ponArista(v - 1, w - 1);
    }

    //Resolver problema
    
    OrdenTareas ot(dg);

    //Escribir resultado
    if (!ot.hayCiclo()) {
        deque<int> dq = ot.orden();
        while (!dq.empty()) {
            int a = dq.front(); dq.pop_front();
            cout << a + 1 << ' ';
        }
        cout << '\n';
    }
    else
        cout << "Imposible\n";

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}