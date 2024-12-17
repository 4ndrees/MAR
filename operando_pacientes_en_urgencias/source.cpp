
// NOMBRE Y APELLIDOS

#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

struct enfermo {
    string nombre;
    int gravedad;
    int momento;
};

// gravedad de b menor que a 
// gravedad de b igual que gravedad de a pero momento en el que se ha introducido a menor que el momento en el que se ha introducido b
bool operator<(enfermo const& a, enfermo const& b) {
    return a.gravedad < b.gravedad ||
        (a.gravedad==b.gravedad && b.momento < a.momento);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int n;
    cin >> n;

    if (n==0) return false;

    priority_queue<enfermo> pq = priority_queue<enfermo>();

    //Resolver problema
    
    int momento = 0;

    while (n--) {
        char event;
        cin >> event;
        if (event == 'I') {
            string nombre;
            int gravedad;
            cin >> nombre >> gravedad;
            pq.push({ nombre, gravedad, momento });
        }
        else {
            cout << pq.top().nombre << '\n';
            pq.pop();
        }
        momento++;
    }

    cout << "---\n";

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}