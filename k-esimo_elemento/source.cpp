// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include "TreeSet_AVL.h"

using namespace std;

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int n;
    cin >> n;

    if (n == 0)
        return false;


    //Resolver problema
    Set<int> arbol = Set<int>();
    
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        arbol.insert(elem);
    }

    //Escribir resultado
    
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int position;
        cin >> position;

        try {
            int result = arbol.kesimo(position);
            cout << result << endl;
        }
        catch (std::out_of_range) {
            cout << "??" << endl;
        }
    }

    cout << "---" << endl;

    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    //std::ifstream in("casos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    //std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}