#pragma once
class Tim
{
private:
	char* meno = nullptr;
	int body = 0;
	int strelene = 0;
	int dostane = 0;
public:
	Tim();
	Tim(char* paMeno);
	Tim(char* paMeno, int paBody, int paStrelene, int paDostane);
	Tim(const Tim& zdroj);
	Tim operator=(const Tim& zdroj);
	void vypis();
	~Tim();

	inline char* getMeno() { return this->meno; };
	inline int getBody() { return this->body; };
	inline int getStrelene() { return this->strelene; };
	inline int getDostane() { return this->dostane; };
	
	inline void setBody(int paBody) { this->body = paBody; };
	inline void setStrelene(int paStrelene) { this->strelene = paStrelene; };
	inline void setDostane(int paDostane) { this->dostane = paDostane; };
};

