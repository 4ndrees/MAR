
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool resuelveCaso() { // Complejidad: Sort -> O(NlogN); estrategia voraz -> O(N)

    //Leer caso de prueba: cin>>...

    int N;
    cin >> N;

    if (!std::cin)
        return false;

    vector<int> e(N);   // Hay N grupos de atacantes
    for (int i = 0; i < N; ++i) {
        int enem;
        cin >> enem;
        e[i] = enem;
    }

    vector<int> d(N);   // Hay N grupos de defensores
    for (int i = 0; i < N; ++i) {
        int def;
        cin >> def;
        d[i] = def;
    }

    //Resolver problema
    // Estrategia voraz: ordenar los dos vectores e y d de menor a mayor. Para cada ciudad se asigna el menor equipo defensor capaz de
    // ganar (cuyo tamaño sea al menos del tamaño del equipo atacante), en caso de no poder defender una ciudad, se descarta la victoria mediante
    // dicho equipo al estar las ciudades ordenadas por atacantes de menor a mayor.

    sort(d.begin(), d.end());
    sort(e.begin(), e.end());

    int defensas = 0;   // contador de defensas exitosas máximas
    int j = 0;  // indice de la ciudad que se quiere defender
    for (int i = 0; i < d.size(); ++i) {
        if (d[i] >= e[j]) {
            defensas++;
            j++;
        }
    }
    
    //Escribir resultado
    cout << defensas << '\n';
    
    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}