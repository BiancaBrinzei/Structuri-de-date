#include <iostream>
using namespace std;
struct nod {
  int info;
  nod* urm;
};

nod* prim = NULL;

void AdaugaFinal(nod*& prim, int x) {
  nod* q = new nod;
  q->info = x;
  q->urm = NULL;
  if (prim == NULL) {
    prim = q;
  }
  else {
    nod* t = prim;
    while (t->urm != NULL)
      t = t->urm;
    t->urm = q;
  }
}

void InserareInceput(nod*& prim, int x) {
  nod* q = new nod;
  q->info = x;
  q->urm = prim;
  prim = q;
}

void Afisare(nod* prim) {
  nod* t = prim;
  while (t != NULL) {
    cout << t->info << " ";
    t = t->urm;
  }
 cout<<endl;
}
void StergereElement(nod* &prim, int x) {
  nod* t = prim;
  nod* prev = NULL;

  while (t != NULL && t->info != x) {
    prev = t;
    t = t->urm;
  }

  if (t == NULL) {
    return;
  }
  else if (prev == NULL) {
    prim = t->urm;
  }
  else {
    prev->urm = t->urm;
  }

  delete t;
}
void InserarePozitie(nod* &prim, int x, int pozitie) {
  nod* q = new nod;
  q->info = x;

  nod* t = prim;
  nod* prev = NULL;
  int i = 1;

  while (t != NULL && i < pozitie) {
    prev = t;
    t = t->urm;
    i++;
  }


  if (i < pozitie) {
    std::cout << "Pozitie invalida!" << std::endl;
    return;
  }

  if (prev == NULL) {
    q->urm = prim;
    prim = q;
  }
  else {
    q->urm = t;
    prev->urm = q;
  }
}

int main() {
  InserareInceput(prim,1);
  InserareInceput(prim,2);
  InserareInceput(prim,3);
  cout << "Lista initiala: ";
  Afisare(prim);
 InserarePozitie(prim,69,2);
  cout << "Lista dupa inserarea la inceput: ";
  Afisare(prim);
  AdaugaFinal(prim,61);
  cout<<endl<<" Lista dupa inserarea la final: ";
    Afisare(prim);
  StergereElement(prim,1);
  StergereElement(prim,2);
  cout<<endl<<" Lista dupa stergerea unor elemente: ";
  Afisare(prim);

  return 0;
}
