
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <algorithm>
using namespace std;

bool resuelveCaso() {

	//Leer caso de prueba: cin>>...
	int C, F, n;
	std::cin >> C >> F >> n;

	if (C == 0 && F == 0 && n == 0)
		return false;

	vector <pair<int, int>> trabajos;
	for (int i = 0; i < n; ++i) {
		int ini, fin;
		std::cin >> ini >> fin;
		trabajos.push_back({ ini, fin });
	}

	//Resolver problema
	int min = 0;
	int fin = C;
	
	sort(trabajos.begin(), trabajos.end());
	
	bool imposible = false, salir = false;
	stack <pair<int, int>> pila;
	int i = 0;
	while (i < n && !imposible && !salir) {
		if (trabajos[i].first > fin && !pila.empty()) {
			if (pila.top().first <= fin) {
				min++;
				fin = pila.top().second;
				pila.pop();
			}
			else imposible = true;
		}
		if (fin >= F) salir = true;
		if (trabajos[i].first <= fin && !salir) {
			if (pila.empty() || trabajos[i].second >= pila.top().second) pila.push(trabajos[i]);
		}
		++i;
	}

	if (!pila.empty() && !salir) {
		if (pila.top().first <= fin) {
			min++;
			fin = pila.top().second;
			pila.pop();
		}
		else imposible = true;
	}

	//Escribir resultado
	if (fin < F) imposible = true;

	if (imposible) cout << "Imposible\n";
	else cout << min << '\n';

	return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}