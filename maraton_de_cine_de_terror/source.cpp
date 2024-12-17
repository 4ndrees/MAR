
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool resuelveCaso() { // Coste: O(NlogN) -> ordenación del vector de películas + N -> algoritmo voraz (siendo N el número de películas)

    // Leer caso de prueba: cin>>...
    int N;
    cin >> N;

    if (N==0)
        return false;

    int horas1, minutos1;
    char aux;
    vector <pair <int, int>> p;
    int dur;
    for (int i = 0; i < N; ++i) {
        cin >> horas1 >> aux >> minutos1 >> dur;
        int mins = horas1 * 60 + minutos1;
        p.push_back({ mins, mins + dur });
    }

    // Resolver problema
    // La estrategia voraz consiste en, una vez ordenado el vector de películas en función de la finalización de las mismas de menor a mayor,
    // se selecciona una película si no coincide con la finalización de la última película que se irá a ver
    
    sort(p.begin(), p.end());

    // Aplicar la estrategia voraz
    int iInt = p[0].first, fInt = p[0].second;
    int pelis = 1;

    for (int i = 1; i < p.size(); ++i) {
        if (p[i].first < fInt) {
            if (p[i].second < fInt) fInt = p[i].second;
        }
        else if (p[i].first >= fInt + 10) {
            pelis++;
            fInt = p[i].second;
        }
    }
    
    // Escribir resultado
    cout << pelis << '\n';

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}