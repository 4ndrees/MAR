
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int N, L;
    cin >> N >> L;

    if (!std::cin)
        return false;


    vector<int> distancias(N);
    distancias[0] = 0; // La distancia al primer agujero empieza en cero
    int ant;
    cin >> ant;
    for (int i = 0; i < N - 1; ++i) {
        int actual;
        cin >> actual;
        distancias[i] = actual - ant;
        ant = actual;
    }

    //Resolver problema
    int parches = 1;
    int distanciaActual = 0;
    for (int i = 0; i < distancias.size(); ++i) {
        if (distanciaActual + distancias[i] > L) {
            parches++;
            distanciaActual = 0;
        }
        else
            distanciaActual += distancias[i];
    }

    //Escribir resultado
    cout << parches << '\n';

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}