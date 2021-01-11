#include "Turnaj.h"
#include <fstream>
#include <iostream>

using namespace std;

Turnaj::Turnaj()
{
}

Turnaj::Turnaj(int paPocetTimov)
{
	this->pocetTimov = paPocetTimov;
	this->zoznam = new Tim * [paPocetTimov];
}

Turnaj::Turnaj(const Turnaj& zdroj)
{
	if (this != &zdroj)
	{
		this->pocetTimov = zdroj.pocetTimov;
		this->prveOtvorenieSuboru = zdroj.prveOtvorenieSuboru;
		this->zoznam = new Tim * [zdroj.pocetTimov];
		for (int i = 0; i < zdroj.pocetTimov; i++)
		{
			this->zoznam[i] = new Tim(zdroj.zoznam[i]->getMeno(),
				zdroj.zoznam[i]->getBody(),
				zdroj.zoznam[i]->getStrelene(),
				zdroj.zoznam[i]->getDostane());
		}
	}
}

Turnaj Turnaj::operator=(const Turnaj& zdroj)
{
	if (this != &zdroj)
	{
		Turnaj::~Turnaj();
		this->pocetTimov = zdroj.pocetTimov;
		this->prveOtvorenieSuboru = zdroj.prveOtvorenieSuboru;
		this->zoznam = new Tim * [zdroj.pocetTimov];
		for (int i = 0; i < zdroj.pocetTimov; i++)
		{
			this->zoznam[i] = new Tim(zdroj.zoznam[i]->getMeno(),
				zdroj.zoznam[i]->getBody(),
				zdroj.zoznam[i]->getStrelene(),
				zdroj.zoznam[i]->getDostane());
		}
	}
	return *this;
}

void Turnaj::nacitajTimy(char* nazovSuboru)
{
	if (nazovSuboru != nullptr)
	{
		ifstream input;
		input.open(nazovSuboru);
		if (input.is_open())
		{
			int i = 0;
			string text;
			while (!input.eof())
			{
				input >> text;
				this->zoznam[i] = new Tim((char*)text.c_str());
				i++;
			}
		}
		input.close();
	}
}

void Turnaj::simulujTurnaj()
{
	for (int i = 0; i < this->pocetTimov; i++)
	{
		for (int j = i + 1; j < this->pocetTimov; j++)
		{
			this->simulujZapasy(this->zoznam[i], this->zoznam[j]);
		}
	}
}

void Turnaj::simulujZapasy(Tim* tim1, Tim* tim2)
{
	unsigned int golyTim1 = rand() % 11;
	unsigned int golyTim2 = rand() % 11;

	tim1->setStrelene(tim1->getStrelene() + golyTim1);
	tim2->setStrelene(tim2->getStrelene() + golyTim2);

	tim1->setDostane(tim1->getDostane() + golyTim2);
	tim2->setDostane(tim2->getDostane() + golyTim1);

	if (golyTim1 > golyTim2)
	{
		tim1->setBody(tim1->getBody() + 2);
	}
	else if (golyTim1 < golyTim2)
	{
		tim2->setBody(tim2->getBody() + 2);
	}
	else
	{
		tim1->setBody(tim1->getBody() + 1);
		tim2->setBody(tim2->getBody() + 1);
	}

	cout << tim1->getMeno() << " " << golyTim1 << " - "
		<< tim2->getMeno() << " " << golyTim2 << endl;

	ofstream output;
	if (this->prveOtvorenieSuboru)
	{
		output.open("turnaj.out");
		this->prveOtvorenieSuboru = false;
	}
	else
	{
		output.open("turnaj.out", ios::app); //otvorenie suboru v append mode (zapisuje na koniec)
	}
	if (output.is_open())
	{
		//output.seekp(output.eof());
		output << tim1->getMeno() << " : " << tim2->getMeno() << endl;
		output << golyTim1 << " : " << golyTim2 << endl;
	}
	output.close();
}

void Turnaj::zorad()
{
	for (int i = 0; i < this->pocetTimov - 1; i++)
	{
		for (int j = 0; j < this->pocetTimov - i - 1; j++)
		{
			if (this->zoznam[j]->getBody() < this->zoznam[j + 1]->getBody())
			{
				vymen(*this->zoznam[j], *this->zoznam[j + 1]);
			}
			else if (this->zoznam[j]->getBody() == this->zoznam[j + 1]->getBody())
			{
				if (this->zoznam[j]->getStrelene() < this->zoznam[j + 1]->getStrelene())
				{
					vymen(*this->zoznam[j], *this->zoznam[j + 1]);
				}
			}
		}
	}
}

void Turnaj::vymen(Tim& a, Tim& b)
{
	Tim c = a;
	a = b;
	b = c;
}

void Turnaj::vypis()
{
	if (this->zoznam != nullptr)
	{
		for (int i = 0; i < this->pocetTimov; i++)
		{
			cout << i + 1 << ". ";
			this->zoznam[i]->vypis();
		}
	}
}

Turnaj::~Turnaj()
{
	if (this->zoznam != nullptr)
	{
		for (int i = 0; i < this->pocetTimov; i++)
		{
			delete this->zoznam[i];
		}
		delete[] this->zoznam;
	}
}
