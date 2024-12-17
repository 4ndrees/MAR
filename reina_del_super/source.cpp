
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

struct caja {
    int sec;
    int id;
};

bool operator<(caja const& a, caja const& b) {
    return b.sec < a.sec ||
        (a.sec == b.sec && b.id < a.id);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int n, c;
    
    cin >> n >> c;

    if (n==0&&c==0) return false;

    priority_queue<caja> pq = priority_queue<caja>();

    for (int i = 1; i <= n; i++) {
        pq.push({0, i});
    }

    //Resolver problema
    
    while (c--) {
        int t;
        cin >> t;
        auto e = pq.top(); pq.pop();
        e.sec += t;
        pq.push(e);
    }
    
    //Escribir resultado
    
    cout << pq.top().id << '\n';

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}