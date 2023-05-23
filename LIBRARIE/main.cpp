//Scrieti un program pentru a gestiona o librărie.
//Informatii despre carte: autor, titlu, pret.
//Scrieti o funcție care afisează toate cărțile publicate de un anumit autor.
//Scrieti o funcție care afisează cartile sortate după pret alegând de la tastatura, crescător sau descrescător.

#include <iostream>

using namespace std;

//Numarul maxim de carti:
const int MAX_CARTI = 100;

//Structura cartii:
struct Carte {
    string autor;
    string titlu;
    double pret;
};

//Functia de afisare a cartilor dupa autor:
void afiseazaCartileDupaAutor(Carte carti[], int n, string autor) {
    for (int i = 0; i < n; i++) {
        if (carti[i].autor == autor) {
            cout << "Titlu: " << carti[i].titlu << ", Pret: $" << carti[i].pret<< endl;
        }
    }
}

//Functia de afișare a cartilor sortate dupa pret (in ordine crescatoare):
void afiseazaCartileDupaPretCrescator(Carte carti[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (carti[i].pret > carti[j].pret) {
                Carte temp = carti[i];
                carti[i] = carti[j];
                carti[j] = temp;
            }
        }
    }

//Afisarea cartilor sortate:
    for (int i = 0; i < n; i++) {
        cout << "Titlu: " << carti[i].titlu << ", Autor: " << carti[i].autor << ", Pret: $" << carti[i].pret << endl;
    }
}

//Functia de afișare a cartilor sortate dupa pret (in ordine descrescatoare):
void afiseazaCartileDupaPretDescrescator(Carte carti[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (carti[i].pret < carti[j].pret) {
                Carte temp = carti[i];
                carti[i] = carti[j];
                carti[j] = temp;
            }
        }
    }

//Afisarea cartilor sortate:
    for (int i = 0; i < n; i++) {
        cout << "Titlu: " << carti[i].titlu << ", Autor: " << carti[i].autor << ", Pret: $" << carti[i].pret << endl;
    }
}

int main() {
    int n;
    cout << "Introduceti numarul de carti: ";
    cin >> n;
    Carte carti[MAX_CARTI];
    for (int i = 0; i < n; i++) {
        cout << "Carte " << i+1 << " informatie:" << endl;
        cout << "Autor: ";
        cin.ignore();
        getline(cin, carti[i].autor);
        cout << "Titlu: ";
        getline(cin, carti[i].titlu);
        cout << "Pret: $";
        cin >> carti[i].pret;
    }

//Afisarea cartilor dupa autor:
    string autor;
    cout << "Introduceti numele autorului pentru a afisa cartile lor: ";
    cin.ignore();
    getline(cin, autor);
    afiseazaCartileDupaAutor(carti, n, autor);

//Afisarea cartilor dupa pret:
    char order;
    cout <<"Introduceti 'c' pentru a sorta in ordine crescatoare sau 'd' pentru a sorta in ordine descrescatoare: ";
    cin >> order;
    if (order == 'c') {
        afiseazaCartileDupaPretCrescator(carti, n);
    } else {
        afiseazaCartileDupaPretDescrescator(carti, n);
    }
    return 0;
}
