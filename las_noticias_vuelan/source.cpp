
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"
using namespace std;

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int N, M;
    cin >> N >> M;

    if (!std::cin)
        return false;

    ConjuntosDisjuntos cd(N);

    //Resolver problema
    for (int i = 0; i < M; ++i) {
        int nusr, a, b;
        cin >> nusr;
        if (nusr > 0) cin >> a;
        for (int i = 0; i < nusr - 1; ++i) {
            cin >> b;
            cd.unir(a - 1, b - 1);
        }
    }

    //Escribir resultado
    for (int i = 0; i < N; ++i) {
        cout << cd.tam(i) << ' ';
    }
    cout << '\n';

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}