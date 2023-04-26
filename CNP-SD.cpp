#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");


			int an_curent=2023,luna_curenta=3,zi_curenta=24,varsta,i=1;
			int ann,lunaa,zii,id;
			char an[3],zi[3],luna[3],idd[3],cnp[10];
			string gender;

        while(f.getline(cnp,100))
        {
			idd[0]=cnp[0];
			strncpy(an,cnp+1,2);
			strncpy(luna,cnp+3,2);
			strncpy(zi,cnp+5,2);
			ann=10*int(an[0]-'0')+int(an[1]-'0');
			lunaa=10*int(luna[0]-'0')+int(luna[1]-'0');
			zii=10*int(zi[0]-'0')+int(zi[1]-'0');
			if (idd[0] == '1' || idd[0] == '2')
			{
 varsta = an_curent - (1800 + ann);
 ann = 1800 + ann;
			}

			if (idd[0] == '3' || idd[0] == '4')
			{
varsta = an_curent - (1900 + ann);
ann = 1900 + ann;
			}

			if (idd[0] == '5' || idd[0] == '6')
			{
varsta = an_curent - (2000 + ann);
ann = 2000 + ann;
			}


			if (lunaa > luna_curenta || (lunaa == luna_curenta && zii > zi_curenta)) {
				varsta--;
			}

			if (idd[0] == '5' || idd[0] == '3' || idd[0] == '1')
				gender = "Masculin";
			else
				gender = "Feminin";


				g<<"CNP "<<i<<":"<<endl<<"Data nastere:"<<ann<<" "<<lunaa<<" "<<zii<<endl<<"Varsta:"<<varsta<<endl<<"Gen:"<<gender<<endl<<endl<<endl<<endl;
i++;
        }
    f.close();
    g.close();
    return 0;
}


