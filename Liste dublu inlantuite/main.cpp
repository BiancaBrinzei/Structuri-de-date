
/*memorarea unei liste*/
struct Nod
{
 int numar;
 Nod*urmator;
 Nod*anterior;
};
Nod*cap==NULL;

/*parcurgerea si afisarea elemntelor*/

void afisareLista(Nod*cap)
{
    while (cap!=NULL)
    {
        cout<<cap->numar<<"\n";
        cap=cap->urmator;
    }
}

/*inserarea unui element*/
void inserareInceput(Nod* &cap.int valoare)
{
    Nod*elem=new Nod;
    elem->numar=valoare;

    elem->urnator=cap;
    elem->anterior=NULL;
    if(cap!=NULL)
        cap->anterior=elem;
    cap=elem;
}
/*inserare la final*/

void inserareFinal(Nod* &cap, int valoare)
{
    Nod *elem_final = new Nod;
    elem_final->numar = valoare;
    elem_final->urmator = NULL;
    elem_final->anterior = NULL;

    if (cap == NULL)
        cap = elem_final;
    else
    {
        Nod *nod_curent = cap;
        while (nod_curent->urmator != NULL)
            nod_curent = nod_curent->urmator;
        nod_curent->urmator = elem_final;
        elem_final->anterior = nod_curent;
    }
}

/* inserare dupa un elemnt dat*/

void inserareElement(Element* &cap, Element* element_dat, int valoare)
{
    Nod *elem_creat = new Nod;
    elem_creat->numar = valoare;
    elem_creat->urmator = NULL;
    elem_creat->anterior = NULL;
    if (cap == NULL)
    {
        cap = elem_creat;
        return;
    }
    if (cap == element_dat)
    {
        elem_creat->urmator = cap;
        cap->anterior = elem_creat;
        cap = elem_creat;
        return;
    }
    elem_creat->urmator = element_dat->urmator;
    elem_creat->anterior = element_dat;
    element_dat->urmator->anterior = elem_creat;
    element_dat->urmator = elem_creat;
}

/*cautare dupa valoare*/
Nod*cautareValoare(Nod*cap,int valoare)
{
while(cap!=NULL && cap->numar!=valoare)
    cap=cap->urmator;
return cap;
}

/*cautarea dupa pozitie*/
Nod*cautarePozitie(Nod*cap,int pozitie)
{
    int i=0;
    while (cap!=NULL && i<pozitie)
    {
        cap=cap->urmator;
        i++;
    }
    if(i==pozitie)
        return cap;
    else
        return NULL;
}

/*stergerea unui element din interiourul listei*/
void stergereElement(Nod*elem)
{
    elem->anterior->urmator=elem->urmator;
    elem->urmator->anterior=elem->anterior;
    delete elem;
}

/* stergerea unui elemenr de pe o anumita pozitie*/

void stergereElementPozitie(Nod*&cap,int pozitie)
{
    if(pozitie==0)
    {
        Nod*victima=cap;
        cap=cap->urmator;
        cap->anterior=NULL;
        delete victima;
    }
    else
    {
        Nod*predecesor=cautarePozitie(cap,pozitie);
    stergereElement(predecesor);

    }
}
/*stergere dupa o valoare*/

void stergereElementValoare(Nod*&cap,int valoare)
{
    if(cap->numar==valoare)
    {
        Nod*victima=cap;
        cap=cap->urmator;
        cap->anterior=NULL;
        delete victima;
        return;
    }
    Nod*elem=cap;
    while(elem->urmator!=NULL&& elem->urmator->numar!=valoare)
        elem=elem->urmator;
    if(elem->urmator!=NULL)
        stergereElement(elem);
}
