#include <iostream>
#include <vector>

using namespace std;

// Funcția pentru parcurgerea în adâncime
void DFS(int nod, vector<vector<int>>& graf, vector<bool>& vizitat) {
    // Marchează nodul curent ca vizitat
    vizitat[nod] = true;

    cout << nod << " "; // Afiseaza nodul curent

    // Parcurge toți vecinii nodului curent
    for (int vecin : graf[nod]) {
        // Dacă vecinul nu a fost vizitat, apelează DFS recursiv pentru el
        if (!vizitat[vecin]) {
            DFS(vecin, graf, vizitat);
        }
    }
}

// Funcția principală pentru parcurgerea în adâncime
void DFS_main(vector<vector<int>>& graf, int nod_start) {
    int numar_noduri = graf.size();

    // Vector pentru a marca nodurile vizitate
    vector<bool> vizitat(numar_noduri, false);

    // Apelează DFS pentru nodul de start
    DFS(nod_start, graf, vizitat);
}

int main() {
    int numar_noduri, numar_arce;
    cout << "Introduceti numarul de noduri si numarul de arce ale grafului: ";
    cin >> numar_noduri >> numar_arce;

    // Inițializarea listei de adiacență
    vector<vector<int>> graf(numar_noduri);

    cout << "Introduceti perechile de noduri care formează arcele:\n";
    for (int i = 0; i < numar_arce; i++) {
        int nod1, nod2;
        cin >> nod1 >> nod2;

        // Adaugă nod2 ca vecin al nodului nod1
        graf[nod1].push_back(nod2);
    }

    int nod_start;
    cout << "Introduceti nodul de start pentru parcurgere: ";
    cin >> nod_start;

    cout << "Parcurgerea în adâncime a grafului: ";
    DFS_main(graf, nod_start);

    return 0;
}
