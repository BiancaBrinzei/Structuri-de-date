#include <iostream>

using namespace std;


void initializare_vector(int v[100],int &dimensiune)
{
    for (int i=1;i<=5;i++)
        v[i]=i;

    dimensiune=5;

}
void inserare_la_inceput(int v[100],int &dimensiune,int numar)
{
    for(int i=dimensiune;i>=1;i--)
        v[i+1]=v[i];
    v[1]=numar;
    dimensiune++;

}
void inserare_la_final(int v[100],int &dimensiune, int numar)
{

    v[dimensiune+1]=numar;
    dimensiune++;

}
void inserare_la_pozitie(int v[100],int &dimensiune,int numar,int pozitie)
{
    for(int i=dimensiune;i>=pozitie;i--)
        v[i+1]=v[i];
    v[pozitie]=numar;
    dimensiune++;

}
void stergere(int v[100],int &dimensiune,int numar)
{int i,j;
    for( i=1;i<=dimensiune;i++)
        if(v[i]==numar)
            {for( j=i;j<dimensiune;j++)
                v[j]=v[j+1];
                dimensiune--;
            }
}
void afisare(int v[100],int dimensiune)
{
    for(int i=1;i<=dimensiune;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void sortare_cu_pivotare_crescator(int v[100],int dimensiune)
{int aux,i,j;

    for( i=1;i<dimensiune;i++)
        for(j=i+1;j<=dimensiune;j++)
        if(v[i]>v[j])
    {
        aux=v[i];
        v[i]=v[j];
        v[j]=aux;
    }



}

void bubble_sort(int v[100],int dimensiune)
{int i,j,aux;
    for(i=1; i<=dimensiune-1; i++)
    for(j=1; j<=dimensiune-i; j++)
        if(v[j]>v[j+1])
            {aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
            }
}



int main()
{int v[100],dimensiune=0;
initializare_vector(v,dimensiune);
cout<<"Afisare vector initial: ";afisare(v,dimensiune);
inserare_la_inceput(v,dimensiune,45);
inserare_la_inceput(v,dimensiune,90);
inserare_la_inceput(v,dimensiune,120);
cout<<"Afisare dupa inserarea la inceput: ";afisare(v,dimensiune);
inserare_la_final(v,dimensiune,12);
inserare_la_final(v,dimensiune,401);
cout<<"Afisare dupa inserarea la final: ";afisare(v,dimensiune);
inserare_la_pozitie(v,dimensiune,20,5);
cout<<"Afisare dupa inserarea la pozitie: ";afisare(v,dimensiune);
///sortare_cu_pivotare_crescator(v,dimensiune);
bubble_sort(v,dimensiune);
cout<<"Afisare dupa sortarea crescatoare: ";afisare(v,dimensiune);
stergere(v,dimensiune,1);
stergere(v,dimensiune,2);
stergere(v,dimensiune,3);
cout<<"Afisare dupa stergere: ";afisare(v,dimensiune);
    return 0;
}
