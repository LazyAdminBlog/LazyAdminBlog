#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void menu();
void dodaj_kwiat();
void dodaj_stan();
void odczytywanie_danych();
void zadanie_2_a();
void zadanie_2_b();
void zadanie_2_c();

class kwiat
{
    private:
        string nazwa_rosliny,typ_rosliny;
        int id_rosliny;

    public:
        kwiat()
        {
            nazwa_rosliny="";
            typ_rosliny="";
            id_rosliny=(-1);
        }

        kwiat(int id_rosliny,string typ_rosliny,string nazwa_rosliny)
        {
            this->id_rosliny=id_rosliny;
            this->typ_rosliny=typ_rosliny;
            this->nazwa_rosliny=nazwa_rosliny;
        }

        int daj_id_rosliny()
        {
            return id_rosliny;
        }

        string daj_typ_rosliny()
        {
            return typ_rosliny;
        }

        string daj_nazwe_rosliny()
        {
            return nazwa_rosliny;
        }
};

class kwiaciarnia
{
    private:
        string adres_kwiaciarni;
        int id_kwiaciarni;

    public:
        kwiaciarnia()
        {
            id_kwiaciarni=1;
            adres_kwiaciarni="Warszawska 4";
        }

        kwiaciarnia(int id_kwiaciarni,string adres_kwiaciarni)
        {
            this->id_kwiaciarni=id_kwiaciarni;
            this->adres_kwiaciarni=adres_kwiaciarni;
        }

        int daj_id_kwiaciarni()
        {
            return id_kwiaciarni;
        }

        string daj_adres_kwiaciarni()
        {
            return adres_kwiaciarni;
        }
};

class stan
{
    private:
        int id_kwiaciarni;
        int id_rosliny;
        int liczba_sztuk;

    public:
        stan()
        {
            id_kwiaciarni=1;
            id_rosliny=1;
            liczba_sztuk=2;
        }

        stan(int id_kwiaciarni,int id_rosliny,int liczba_sztuk)
        {
            this->id_kwiaciarni=id_kwiaciarni;
            this->id_rosliny=id_rosliny;
            this->liczba_sztuk=liczba_sztuk;
        }

        int daj_id_rosliny()
        {
            return id_rosliny;
        }

        int daj_id_kwiaciarni()
        {
            return id_kwiaciarni;
        }

        int daj_liczbe_sztuk()
        {
            return liczba_sztuk;
        }
};

// Kwiacairnia
kwiaciarnia tk[100];
int liczba_kwiaciarnia=0;
int liczba_kwiaciarnia1=0;
string adres_k;
int id_k;
int id_kwiaciarni;
string adres_kwiaciarni;
// Kwiat
kwiat tr[100];
int liczba_kwiat=0;
int liczba_kwiat1=0;
string nazwa_r;
string typ_r;
int id_r;
// Stan
int ilosc;
stan ts[100];
int liczba_stan=0;
int liczba_stan1=0;


void dodaj_kwiaciarnie()
{
    cout<<endl<<"Podaj id kwiaciarni: ";
    cin>>id_kwiaciarni;
    cout<<endl<<"Podaj adres kwiaciarni ";
    cin>>adres_kwiaciarni;
    system("cls");
    cout<<"Dane wprowadzono poprawnie."<<endl<<"Wprowadzone dane to: "<<id_kwiaciarni<<" "<<adres_kwiaciarni<<"."<<endl;

    kwiaciarnia tmp(id_kwiaciarni,adres_kwiaciarni);
	tk[liczba_kwiaciarnia]=tmp;
	liczba_kwiaciarnia++;

	ofstream dopliku2("kwiaciarnia.txt",ios_base::app);
	for(int i=liczba_kwiaciarnia1;i<liczba_kwiaciarnia;i++)
	{
		dopliku2<<tk[i].daj_id_kwiaciarni()<<" "<<tk[i].daj_adres_kwiaciarni()<<endl;
	}
	dopliku2.close();

    system("pause");
    system("cls");
    menu();
}

void dodaj_kwiat()
{
	liczba_kwiat1=liczba_kwiat;
	cout<<endl<<"podaj id rosliny: ";
	cin>>id_r;
	cout<<endl<<"podaj typ rosliny ";
	cin>>typ_r;
	cout<<endl<<"podaj nazwe rosliny ";
	cin>>nazwa_r;
	kwiat tmp(id_r,typ_r,nazwa_r);
	tr[liczba_kwiat]=tmp;
	liczba_kwiat++;

	ofstream dopliku("kwiat.txt",ios_base::app);
	for(int i=liczba_kwiat1;i<liczba_kwiat;i++)
	{
		dopliku<<tr[i].daj_id_rosliny()<<" "<<tr[i].daj_typ_rosliny()<<" "<<tr[i].daj_nazwe_rosliny()<<endl;
	}
	dopliku.close();

    system("pause");
    system("cls");
    menu();
}

void dodaj_stan()
{
	cout<<endl<<"podaj id kwiaciarni: ";
	cin>>id_k;
	cout<<endl<<"podaj id rosliny ";
	cin>>id_r;
	cout<<endl<<"podaj ilosc ";
	cin>>ilosc;
	stan tmp(id_k,id_r,ilosc);
	ts[liczba_stan]=tmp;
	liczba_stan++;

	ofstream dopliku3("stan.txt",ios_base::app);
	for(int i=liczba_stan1;i<liczba_stan;i++)
	{
		dopliku3<<ts[i].daj_id_kwiaciarni()<<" "<<ts[i].daj_id_rosliny()<<" "<<ts[i].daj_liczbe_sztuk()<<endl;
	}
	dopliku3.close();

	system("pause");
    system("cls");
    menu();
}

wyswietl_kwiaciarnie()
{
	for(int i=0;i<liczba_kwiaciarnia;i++)
	{
        cout<<"\nid kwiaciarni: "<<tk[i].daj_id_kwiaciarni()<<" ";
        cout<<"adres kwiaciarni: "<<tk[i].daj_adres_kwiaciarni();
	}
	cout<<endl;
	system("pause");
	system("cls");
	menu();
}

wyswietl_kwiat()
{
	for(int i=0;i<liczba_kwiat;i++)
	{
        cout<<endl<<"id rosliny: "<<tr[i].daj_id_rosliny()<<" ";
        cout<<"typ: "<<tr[i].daj_typ_rosliny()<<" ";
        cout<<"nazwa: "<<tr[i].daj_nazwe_rosliny();
	}
	cout<<endl;
	system("pause");
	system("cls");
	menu();
}

wyswietl_stan()
{
	for(int i=0;i<liczba_stan;i++)
	{
		cout<<endl<<"Id kwiaciarni: "<<ts[i].daj_id_kwiaciarni()<<" ";
		cout<<"Id rosliny: "<<ts[i].daj_id_rosliny()<<" ";
		cout<<"Ilosc: "<<ts[i].daj_liczbe_sztuk();
	}
	cout<<endl;
	system("pause");
	system("cls");
	menu();
}

void zadanie_2_a()
{
	string typy[100];
	string nazwa_rosliny;

	cout<<"Tresc zadania:"<<endl;
	cout<<"Wyswietl liste dostepnych typow dla rosliny (kwiatu) o wskazanej nazwie."<<endl<<endl;
	cout<<"Podaj nazwe rosliny: "<<endl;
	cin>>nazwa_rosliny;

	for(int i=0; i<100; ++i)
	{
        if(nazwa_rosliny==tr[i].daj_nazwe_rosliny())
        {
            typy[i]=tr[i].daj_typ_rosliny();
        }
        else
        {
            typy[i]="0";
        }
	}

	cout<<"Lista typow rosliny dla "<<nazwa_rosliny<<":"<<endl;

	for (int i=0; i<100; ++i)
	{
		if(typy[i]!="0")
		{
            cout<<typy[i]<<endl;
		}
	}

	system("pause");
	system("cls");
	menu();
}

void zadanie_2_b()
{
	float wartosc=0;
	int ididr=0;
	int ididkw=0;
	string nazwa;

	cout<<"Tresc zadania:"<<endl;
	cout<<"Wyswietl liczbe sztuk doniczkowych roz znajdujacych sie w kwiaciarni o danym adresie."<<endl<<endl;
	cout<<"Podaj adres kwiaciarni aby  pokazac ilosc roz doniczkowych :";
	cin>>nazwa;

	for(int i=0;i<liczba_kwiaciarnia;i++)
	{
		if(tk[i].daj_adres_kwiaciarni()==nazwa)
		{
			ididkw=tk[i].daj_id_kwiaciarni();
		}
	}

 	for(int i=0;i<liczba_kwiat;i++)
	{
   		if((tr[i].daj_typ_rosliny()=="doniczkowa")&&(tr[i].daj_nazwe_rosliny()=="roza"))
		{
     		ididr=tr[i].daj_id_rosliny();
   			for(int j=0;j<liczba_stan;j++)
   			{
    			if((ts[j].daj_id_kwiaciarni()==ididkw)&&(ts[j].daj_id_rosliny()==ididr))
       			{
					wartosc=wartosc+ts[j].daj_liczbe_sztuk();
				}
       		}
		}
	}
	cout<<"W kwiaciarni o adresie: "<<nazwa<<" znajduje sie: "<<wartosc<<" sztuk roz doniczkowych"<<endl;
	system("pause");
	system("cls");
	menu();
}

void zadanie_2_c()
{
	cout<<"Tresc zadania:"<<endl;
	cout<<"Wyswietl liste kwiaciarni (adresy) posiadajacych w sprzedazy przynajmniej jedna wiazanke z roslin o podanej nazwie."<<endl;
	cout<<endl<<endl;
	int ididr=0;
	int ididkw=0;
	string nazwa_rosliny;
	cout<<"Podaj nazwe rosliny:"<<endl;
	cin>>nazwa_rosliny;

	for(int i=0;i<liczba_kwiat;i++)
	{
		if((tr[i].daj_typ_rosliny()=="wiazanka")&&(tr[i].daj_nazwe_rosliny()==nazwa_rosliny))
		{
			ididr=tr[i].daj_id_rosliny();
			for(int j=0;j<liczba_stan;j++)
			{
				if((ts[j].daj_id_rosliny()==ididr)&&(ts[j].daj_liczbe_sztuk()>=1))
				{
					ididkw=ts[j].daj_id_kwiaciarni();
					for(int k=0;k<liczba_kwiaciarnia;k++)
					{
						if(tk[k].daj_id_kwiaciarni()==ididkw)
						{
							cout<<tk[k].daj_adres_kwiaciarni()<<" "<<endl;
						}
					}
				}
			}
		}
	}
	cout<<endl;
	system("pause");
	system("cls");
	menu();
}

void odczytywanie_danych()
{
    int s;
    cout << "\n +----------------------------+"<< endl;
    cout << " |     Program Kwiaciarnia    |"<< endl;
    cout << " |     Odczytywanie danych    |"<< endl;
    cout << " |                            |"<< endl;
    cout << " |  1 - Wyswietl kwiacairnie  |"<< endl;
    cout << " |  2 - Wyswietl kwiaty       |"<< endl;
    cout << " |  3 - Wyswietl stan         |"<< endl;
    cout << " |  4 - Zadanie 2 a)          |"<< endl;
    cout << " |  5 - Zadanie 2 b)          |"<< endl;
    cout << " |  6 - Zadanie 2 c)          |"<< endl;
    cout << " |  7 - Cofnij                |"<< endl;
    cout << " +----------------------------+"<< endl;

    cin >> s;
    system("cls");
    switch(s)
    {
        case 1:
            wyswietl_kwiaciarnie();
            break;

        case 2:
            wyswietl_kwiat();
            break;

        case 3:
            wyswietl_stan();
            break;

        case 4:
            zadanie_2_a();
            break;

        case 5:
            zadanie_2_b();
            break;

        case 6:
            zadanie_2_c();
            break;

        case 7:
            menu();
            break;
    }
}

void wprowadzanie_danych()
{
    int s;
    cout << "\n +----------------------------+"<< endl;
    cout << " |     Program Kwiaciarnia    |"<< endl;
    cout << " |     Wprowadzanie danych    |"<< endl;
    cout << " |                            |"<< endl;
    cout << " |  1 - Dodaj kwiaciarnie     |"<< endl;
    cout << " |  2 - Dodaj kwiat           |"<< endl;
    cout << " |  3 - Dodaj stan            |"<< endl;
    cout << " |  4 - Cofnij                |"<< endl;
    cout << " +----------------------------+"<< endl;
    cin >> s;
    system("cls");
    switch(s)
    {
        case 1:
            dodaj_kwiaciarnie();
            break;

        case 2:
            dodaj_kwiat();
            break;

        case 3:
            dodaj_stan();

        case 4:
            menu();
            break;
    }
}

void menu()
{
    int s;
    cout << endl;
    cout << " +----------------------------+"<< endl;
    cout << " |     Program Kwiaciarnia    |"<< endl;
    cout << " |                            |"<< endl;
    cout << " |  1 - Wprowadzanie danych   |"<< endl;
    cout << " |  2 - Odczytywanie danych   |"<< endl;
    cout << " |  3 - Koniec                |"<< endl;
    cout << " +----------------------------+"<< endl;
    cin >> s;
    system("cls");
    switch(s)
    {
        case 1:
            wprowadzanie_danych();
            break;

        case 2:
            odczytywanie_danych();
            break;

        case 3:
            system("exit");
            break;
    }
}

int main()
{
	ifstream zpliku("kwiat.txt");

	for(;;)
	{
		if(!(zpliku>>id_r))
		break;
		zpliku>>typ_r>>nazwa_r;
		kwiat tmp(id_r,typ_r,nazwa_r);
		tr[liczba_kwiat]=tmp;
		liczba_kwiat++;
	}

	ifstream zpliku2("kwiaciarnia.txt");
	for(;;)
    {
		if(!(zpliku2>>id_k))
		break;
		zpliku2>>adres_k;
		kwiaciarnia tmp(id_k,adres_k);
		tk[liczba_kwiaciarnia]=tmp;
		liczba_kwiaciarnia++;
	}

	ifstream zpliku3("stan.txt");
	for(;;)
	{
		if(!(zpliku3>>id_k))
		break;
		zpliku3>>id_r>>ilosc;
		stan tmp(id_k,id_r,ilosc);
		ts[liczba_stan]=tmp;
		liczba_stan++;
	}

	menu();
}
