
// ANDR�S VI�� S�NCHEZ

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n;
    cin >> n;

    if (n==0)
        return false;

    vector<pair<int, int>> edificio;    // n edificios con su extremo occidental y oriental
    for (int i = 0; i < n; ++i) {
        int w, e;
        cin >> w >> e;
        edificio.push_back({w, e});
    }

    //Resolver problema: la estrategia voraz para resolver este problema ser� ordenar el vector de edificios en funci�n del  extremo oriental m�s pr�ximo al punto de inicio
    // Una vez hecho esto se pondr� un t�nel al final del primer edificio y para los siguientes edificios se mirar� si ese tunel entra dentro de sus m�rgenes. Si entra dentro
    // no es necesario construir m�s t�neles para ese edificio, si no entra detro de los m�rgenes se construir� un nuevo t�nel al final de dicho edificio
    
    sort(edificio.begin(), edificio.end());

    int iInt = edificio[0].first, fInt = edificio[0].second;
    int tuneles = 1;

    for (int i = 1; i < edificio.size(); ++i) {
        if (edificio[i].first < fInt) {
            iInt = edificio[i].first;
            if (edificio[i].second < fInt) fInt = edificio[i].second;
        }
        else {
            tuneles++;
            iInt = edificio[i].first;
            fInt = edificio[i].second;
        }
    }

    //Escribir resultado
    cout << tuneles << '\n';

    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}