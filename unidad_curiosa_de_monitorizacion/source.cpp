
// NOMBRE Y APELLIDOS

#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

struct registro {
    int momento; // cuándo le toca
    int id; // identificador (se utiliza en caso de empate)
    int periodo; // tiempo entre consultas
};

bool operator<(registro const& a, registro const& b) {
    return b.momento < a.momento ||
        (a.momento == b.momento && b.id < a.id);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int n;
    cin >> n;

    if (n==0)
        return false;

    priority_queue<registro> cola;

    for (int i = 0; i < n; i++) {
        int id_usu, periodo;
        cin >> id_usu >> periodo;
        cola.push({ periodo, id_usu, periodo });
    }

    //Resolver problema y escribir resultados
    
    int envios;
    cin >> envios;

    while (envios--) {
        auto e = cola.top(); cola.pop();
        cout << e.id << '\n';
        e.momento += e.periodo;
        cola.push(e);
    }

    cout << "---\n";

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}