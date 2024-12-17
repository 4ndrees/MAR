#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Explica la estrategia voraz
// La estrategia voraz que hemos utilizado es ordenar el vector de pesos de menor a mayor y, utilizando dos índices,
// hemos juntado el peso máximo con el peso mínimos de los subproblemas en caso de ser posible. Si esto no es posible, dejamos el peso máximo
// del vector en un viaje a parte (solo en el telesilla) y juntamos el segundo peso máximo con el mínimo, y esto sucesivamente hasta cubrir todos
// los pasajeros 
// -Si pesos[i] + pesos[j] ≤ pesoMaximo, entonces emparejar pesos[i] con pesos[j] no afecta las posibilidades de emparejar otros pesos más adelante. 
// Esto se debe a que los pesos intermedios (pesos[j+1], ..., pesos[i-1]) tienen mayores probabilidades de formar un par que respete la restricción con el 
// siguiente peso mayor (pesos[i-1]).
// -Si pesos[i] + pesos[j] > pesoMaximo, entonces no hay ninguna opción para pesos[i] más que subir solo.Esto es una decisión necesaria y no afecta la solución 
// óptima, porque emparejar pesos[i] con cualquier otro peso no sería viable.

int telesilla(int pesoMaximo, vector<int>& pesos) {
    int numeroViajes = 0;
    sort(pesos.begin(), pesos.end());   // Ordenamos los pesos de los viajes 

    int j = 0;
    int i;
    for (i = pesos.size() - 1; i != j - 1 && j != i; --i) {
        if ((pesos[i] + pesos[j]) <= pesoMaximo) {      // Si caben las dos personas en el telesilla (la más pesada con la menos pesada), se introducen las dos, sino solo la de mayor peso
            j++;
        }
        numeroViajes++;
    }

    if (j == i) {           // si sobra una persona que no hemos emparejado, es necesario hacer otro viaje
        numeroViajes++;
    }

    return numeroViajes;
}

/*
Demostracion de correccion de la estrategia voraz
Solucion Voraz: no dejar la persona mas pesada en tierra a no ser que exista otra persona con el menor peso de todas que no supere el peso del telesilla
Combinar las persona mas pesada con la persona menos pesada maximiza la "utilizacion" del peso permitido en el telesilla.
Esto es así ya que si el emparejamiento de un viaje no sigue la estrategia voraz entonces:
    - O bien algunos viajes tendrán más peso desaprovechado
    - O habrá al menos un peso más difícil de emparejar en los siguientes viajes puesto que los pesos restantes son mayores que el peso con el que
      no se habría emparejado en esta ocasión 

Además, cualquier solución alternativa tendría el mismo número de viajes o más, ya que no existe una mejor forma de emparejar los pesos sin violar 
las restricciones.


*/

bool resuelveCaso() { // Coste O(N + N log (N)) = O(NlogN) siendo N el número de pasajeros
    int a, b, j;
    cin >> a >> b;
    if (!cin) return false;

    vector<int> v(b);
    for (int i = 0; i < b; i++) {
        cin >> j;
        v[i] = j;
    }
    int sol = telesilla(a, v);
    cout << sol << '\n';
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}