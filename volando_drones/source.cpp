
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    
    int n, a, b;
    cin >> n >> a >> b;

    if (!std::cin)
        return false;

    priority_queue<int> pq9v = priority_queue<int>();
    priority_queue<int> pq1_5v = priority_queue<int>();
    int v;

    for (int i = 0; i < a; i++) {
        cin >> v;
        pq9v.push(v);
    }

    for (int i = 0; i < b; i++) {
        cin >> v;
        pq1_5v.push(v);
    }

    //Resolver problema y escribir resultado
    bool primera = true;
    while (!pq9v.empty() && !pq1_5v.empty()) {
        
        vector<int> usadas_9v, usadas_1_5v;
        int drones = 0;
        while (drones < n && !pq9v.empty() && !pq1_5v.empty()) {
            usadas_9v.push_back(pq9v.top()); 
            pq9v.pop();
            usadas_1_5v.push_back(pq1_5v.top()); 
            pq1_5v.pop();
            drones++;
        }

        int horas = 0;
        for (int i = 0; i < usadas_9v.size(); ++i) {
            int uso = min(usadas_9v[i], usadas_1_5v[i]);
            horas += uso;
            if (usadas_9v[i] - uso > 0) pq9v.push(usadas_9v[i] - uso);
            if (usadas_1_5v[i] - uso > 0) pq1_5v.push(usadas_1_5v[i] - uso);
        }

        if (!primera) cout << ' ';
        cout << horas;
        primera = false;
    }
    cout << '\n';
    
    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}