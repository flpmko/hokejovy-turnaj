#include "Tim.h"
#include <string>
#include <iostream>

using namespace std;

Tim::Tim()
{
}

Tim::Tim(char* paMeno)
{
	if (paMeno != nullptr)
	{
		this->meno = new char[strlen(paMeno)+1];
		strcpy(this->meno, paMeno);
	}
}

Tim::Tim(char* paMeno, int paBody, int paStrelene, int paDostane)
{
	if (paMeno != nullptr)
	{
		this->meno = new char[strlen(paMeno)+1];
		strcpy(this->meno, paMeno);
		this->body = paBody;
		this->strelene = paStrelene;
		this->dostane = paDostane;
	}
}

Tim::Tim(const Tim& zdroj)
{
	if (this != &zdroj)
	{
		this->meno = new char[strlen(zdroj.meno)+1];
		strcpy(this->meno, zdroj.meno);
		this->body = zdroj.body;
		this->strelene = zdroj.strelene;
		this->dostane = zdroj.dostane;
	}
}

Tim Tim::operator=(const Tim& zdroj)
{
	if (this != &zdroj)
	{
		Tim::~Tim();

		this->meno = new char[strlen(zdroj.meno)+1];
		strcpy(this->meno, zdroj.meno);
		this->body = zdroj.body;
		this->strelene = zdroj.strelene;
		this->dostane = zdroj.dostane;
	}
	return *this;
}

void Tim::vypis()
{
	cout << this->meno << " " << this->strelene << " " << this->dostane << " " << this->body << endl;
}

Tim::~Tim()
{
	delete[] meno;
}
