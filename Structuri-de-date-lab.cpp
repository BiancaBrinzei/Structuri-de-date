#include <iostream>
using namespace std;
struct nod
{
  int info;
  nod* urm;
};

nod* prim = NULL;

void AdaugaFinal(nod*& prim, int x)
{
  // creăm nod nou
  nod* q = new nod;
  q->info = x;
  q->urm = NULL;
  // adăugăm noul nod la sfârșitul listei
  if (prim == NULL)
  { // lista este vidă
    prim = q;
  }
  else
  { // lista nu este vidă
    nod* t = prim;
    while (t->urm != NULL)
      t = t->urm;
    t->urm = q;
  }
}
void ordonare()
{
    nod*c;
    int ord,aux;
    do
    {
        c=prim;
        ord=1;
        while(c->urm)
        {
        if(c->info>(c->urm)->info)
        {
            aux=c->info;
            c->info=(c->urm)->info;
            (c->urm)->info=aux;
            ord=0;
        }
        c=c->urm;
        }
    }while(ord==0);
}
void InserareInceput(nod*& prim, int x)
{
  // creăm nod nou
  nod* q = new nod;
  q->info = x;
  q->urm = prim;
  // actualizăm începutul listei
  prim = q;
}

void Afisare(nod* prim)
{
  nod* t = prim;
  while (t != NULL)
  {
    cout << t->info << " ";
    t = t->urm;
  }
 cout<<endl;
}
void StergereElement(nod* &prim, int x)
{
  nod* t = prim;
  nod* prev = NULL;

  while (t != NULL && t->info != x)
    {
    prev = t;
    t = t->urm;
  }

  if (t == NULL)
  { // elementul nu a fost găsit
    return;
  }
  else if (prev == NULL)
  { // ștergerea primului element din listă
    prim = t->urm;
  }
  else
  { // ștergerea unui element din interiorul listei
    prev->urm = t->urm;
  }

  delete t; // eliberăm memoria alocată pentru nodul șters
}
void InserarePozitie(nod* &prim, int x, int pozitie)
{
  // creăm nod nou cu elementul de inserat
  nod* q = new nod;
  q->info = x;

  nod* t = prim;
  nod* prev = NULL;
  int i = 1;

  // parcurgem lista pana ajungem la pozitia dorita
  while (t != NULL && i < pozitie)
  {
    prev = t;
    t = t->urm;
    i++;
  }

  // verificam daca pozitia specificata este valida
  if (i < pozitie)
 {
    std::cout << "Pozitie invalida!" << std::endl;
    return;
  }

  // inseram noul nod in lista la pozitia specificata
  if (prev == NULL)
 { // inserare la inceputul listei
    q->urm = prim;
    prim = q;
  }
  else
  { // inserare la mijlocul sau sfarsitul listei
    q->urm = t;
    prev->urm = q;
  }
}

int main()
{
  InserareInceput(prim,1);
  InserareInceput(prim,2);
  InserareInceput(prim,3);
  ordonare();
  cout << "Lista initiala: ";
  Afisare(prim);
  InserarePozitie(prim,69,2);
  cout << "Lista dupa inserarea la inceput: ";
  Afisare(prim);
  ordonare();
  return 0;
}
