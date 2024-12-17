//ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

bool esAvl(bintree<int> arb, int& altura, int& minimo, int& maximo) {

    if (arb.empty()) {
        minimo = 9999999;
        maximo = -999999;
        altura = 0;
        return true;
    }
    else {

        int tallaIz, tallaDer, minIz, minDer, maxIz, maxDer;
        if (esAvl(arb.left(), tallaIz, minIz, maxIz) && esAvl(arb.right(), tallaDer, minDer, maxDer)) {
            altura = max(tallaIz, tallaDer) + 1;
            minimo = min(minIz, arb.root());	// El elemento mínimo del árbol se encuentra en el subárbol izquierdo
            maximo = max(maxDer, arb.root());	// El elemento máximo del árbol se encuentra en el subárbol derecho
            return (abs(tallaIz - tallaDer) <= 1 && maxIz < arb.root() && minDer > arb.root());
        }
        else
            return false;
    }
}

void resuelveCaso() {
    //resuelve aqui tu caso
    //Lee los datos
    
    int vacio = -1;
    bintree<int> arb = leerArbol(vacio);

    //Calcula el resultado
    //Escribe el resultado

    int altura, min, max;

    if (esAvl(arb, altura, min, max))
        cout << "SI\n";
    else
        cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    //std::ifstream in("casos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    //std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}