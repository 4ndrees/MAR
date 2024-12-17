// ANDRÉS VIÑÉ SÁNCHEZ

#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

struct tarea {
    long long c;
    long long f;
    long long periodo;
};

bool operator<(tarea const& a, tarea const& b) {
    if (a.c == b.c)  
        return a.f > b.f;
    return a.c > b.c;
}

bool resuelveCaso() {
    
    long long n, m, t;
    cin >> n >> m >> t;

    if (!std::cin) return false;

    // Mientras se puedan leer los tres valores
    priority_queue<tarea> pq;
    t--;  // Ajustamos el tiempo

    long long c, f, periodo;

    // Procesamos las actividades normales
    for (int i = 0; i < n; i++) {
        cin >> c >> f;
        pq.push(tarea{ c, min(t, f - 1), -1 });
    }

    // Procesamos las actividades repetidas
    for (int i = 0; i < m; i++) {
        cin >> c >> f >> periodo;
        pq.push(tarea{ c, min(t, f - 1), periodo });
    }

    bool conflicto = false;
    long long fin = -1;

    // Procesamos la cola de prioridad
    while (!pq.empty()) {
        auto e = pq.top(); pq.pop();

        // Si se solapan las actividades
        if (fin >= e.c) {
            conflicto = true;
            break;
        }

        fin = e.f;

        // Si la actividad es repetida, se reinsertará en la cola
        if (e.periodo != -1) {
            if (!pq.empty() && (e.c + e.periodo) <= t) {
                pq.push(tarea{ e.c + e.periodo, min(t, e.f + e.periodo), e.periodo });
            }
        }
    }

    // Resultado final
    if (conflicto)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
