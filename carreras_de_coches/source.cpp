// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;

void resuelveCaso() {
    //resuelve aqui tu caso
    //Lee los datos

    int N, V;
    cin >> N >> V;

    deque<int> pilas;
    for (int i = 0; i < N; ++i) {
        int voltajes;
        cin >> voltajes;
        pilas.push_back(voltajes);
    }

    //Calcula el resultado
    sort(pilas.begin(), pilas.end());
    
    int coches = 0;
    while (pilas.size() > 1) {
        if (pilas.front() + pilas.back() >= V) {
            coches++;
            pilas.pop_front();
            pilas.pop_back();
        }
        else pilas.pop_front();
    }

    //Escribe el resultado
    cout << coches << '\n';
}

int main() {
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    return 0;
}