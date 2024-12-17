
// ANDRÉS VIÑÉ SÁNCHEZ

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "IndexPQ.h"

using namespace std;

struct Mencion
{
    int menciones;
    int ultAct;

    bool operator<(Mencion const& b) const
    {
        return menciones > b.menciones || (menciones == b.menciones && ultAct > b.ultAct);
    }

    Mencion operator+=(Mencion const& m2)
    {
        menciones += m2.menciones;
        ultAct = m2.ultAct;
        return *this;
    }

    Mencion operator-=(Mencion const& m2)
    {
        menciones -= m2.menciones;
        ultAct = m2.ultAct;
        return *this;
    }
};

bool resuelveCaso()
{
    int numEventos;

    cin >> numEventos;
    if (!std::cin)
    {
        return false;
    }

    IndexPQ<string, Mencion, less<Mencion>> pq;

    for (int i = 0; i < numEventos; ++i)
    {
        string evento;

        cin >> evento;

        if (evento == "C")
        {
            string tema;
            int menciones;
            cin >> tema >> menciones;
            pq.update(tema, { menciones, i }, true);
        }
        else if (evento == "E")
        {
            string tema;
            int menciones;
            cin >> tema >> menciones;
            pq.update(tema, { menciones, i }, false);
        }
        else if (evento == "TC")
        {
            vector<IndexPQ<string, Mencion, less<Mencion>>::Par> aux;

            int i = 0;

            while (i < 3 && !pq.empty())
            {
                aux.push_back(pq.top());
                if (pq.top().prioridad.menciones > 0)
                    cout << i + 1 << " " << pq.top().elem << "\n";
                pq.pop();
                ++i;
            }

            for (int i = 0; i < aux.size(); ++i)
            {
                pq.push(aux[i].elem, aux[i].prioridad);
            }
        }
    }

    cout << "---\n";

    return true;
}

int main()
{
    while (resuelveCaso());
    return 0;
}