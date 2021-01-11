#pragma once
#include "Tim.h"

class Turnaj
{
private:
	Tim** zoznam = nullptr;
	int pocetTimov = 0;
	bool prveOtvorenieSuboru = true;
public:
	Turnaj();
	Turnaj(int paPocetTimov);
	Turnaj(const Turnaj& zdroj);
	Turnaj operator=(const Turnaj& zdroj);
	void nacitajTimy(char* nazovSuboru);
	void simulujTurnaj();
	void simulujZapasy(Tim* tim1, Tim* tim2);
	void zorad();
	void vymen(Tim& a, Tim& b);
	void vypis();
	~Turnaj();
};

