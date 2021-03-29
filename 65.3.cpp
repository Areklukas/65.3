#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 1000;
float tab[SIZE][2];

int nwd(int x, int y)
{
    if (x<y) return nwd(y, x);
    if (y==0) return x;
    return nwd(y, x % y);
}
void zadanie()
{
    int sum=0, aktualneNWD;
    for (int i=0; i<SIZE; i++)
    {
        float licznik=tab[i][0];
        float mianownik=tab[i][1];
        while (nwd(licznik, mianownik)>1)
        {
            aktualneNWD = nwd(licznik, mianownik);
            licznik = licznik / aktualneNWD;
            mianownik = mianownik / aktualneNWD;
        }
        sum += licznik;
    }
    cout<<sum<<endl;
}

int main()
{
    ifstream in("dane_ulamki.txt");
    for (int i=0; i<SIZE; i++)
    {
        in>>tab[i][0]>>tab[i][1];
    }
in.close();
zadanie();
}
