#include <iostream>

using namespace std;

struct liczba
{
    int a;
    struct liczba*wsk;
};

void dodaj(int x, struct liczba *&kolejka)
{
	if(kolejka == NULL)
	{
	kolejka = new struct liczba;
	kolejka -> wsk = NULL;
	kolejka -> a = x;
	} else if(kolejka -> wsk == NULL){
        kolejka -> wsk = new struct liczba;
        kolejka -> wsk -> wsk =NULL;
        kolejka -> wsk -> a = x;

	}else {
        dodaj(x, kolejka -> wsk);
	}
}

void wypisz(struct liczba *kolejka)
{
	if(kolejka != NULL)
	{
        cout << kolejka -> a << " ";
        wypisz(kolejka -> wsk);
	}
}


int main()
{
	struct liczba * kolejka = NULL;

    dodaj(5, kolejka);
    dodaj(7, kolejka);
    dodaj(2, kolejka);
    dodaj(4, kolejka);
    dodaj(9, kolejka);
    wypisz(kolejka);
    return 0;
}

