# Hokejový turnaj
Vytvorte projekt pre konzolovú aplikáciu, v ktorom
	 vytvorte triedy a algoritmy ktoré budú pre simuláciu hokejového turnaja. 
	 Z textového súboru načítajte názvy 6 štátov, ktorých tímy budú v turnaji. Predpokladajte, že v textovom súbore jeden riadok obsahuje jeden názov. 
	 Meno vstupného súboru sa bude zadávať ako parameter štartu programu.
	 Simulácia turnaja: V turnaji bude hrať každý tím s každým tímom 1 zápas. Víťaza zápasu určite tak, že pre každý tím v zápase vygenerujete náhodné číslo z intervalu <0, 10>, ktoré bude predstavovať počet strelených gólov v zápase. Za víťazstvo získava víťazný tím 2 b, za remízu 1 bod a za prehru 0 bodov.
	 Do súboru zapíšte výsledky všetkých zápasov v tvare:


 Názov 1.tímu : Názov 2. tímu 

 počet strelených gólov : počet strelených gólov

Napr: Slovensko : Rusko

 1 : 4


	
 Výsledky zápasov každého kola vypisujte na konzole v tvare:


 Krajina (vygenerovaná hodnota) – Krajina (vygenerovaná hodnota)


	
 Na konzolu vypíšte výsledne poradie turnaja od 1. miesta po posledné v tvare:


Poradie. Názov tímu Počet strelených gólov Počet dostaných gólov Počet bodov 

Napr. 


	
 Kanada 21 7 15
	 Rusko 27 13 14


Atď.

 Ak majú dva tímy rovnaký počet bodov, tak vyššie v poradí bude tím, ktorý strelí viac gólov.