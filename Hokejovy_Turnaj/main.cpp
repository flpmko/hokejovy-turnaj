#include "Turnaj.h"
#include <iostream>

#define _CRT_SECURE_NO_DEPRECATE

using namespace std;

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Turnaj turnaj(6);
	turnaj.nacitajTimy(argv[1]);
	
	cout << "-------PRIEBEH--TURNAJA-------" << endl;
	turnaj.simulujTurnaj();

	cout << "\n-------VYSLEDNA--TABULKA-------" << endl;
	//cout << "--tim----S--D--B--" << endl;
	turnaj.zorad();
	turnaj.vypis();

	return 0;
}