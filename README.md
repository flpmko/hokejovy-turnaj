# Hokejový turnaj
Vytvorte projekt pre konzolovú aplikáciu, v ktorom vytvorte triedy a algoritmy ktoré budú pre simuláciu hokejového turnaja.
Z textového súboru načítajte názvy 6 štátov, ktorých tímy budú v turnaji.
Predpokladajte, že v textovom súbore jeden riadok obsahuje jeden názov. Meno vstupného súboru sa bude zadávať ako parameter štartu programu.

Simulácia turnaja:
V turnaji bude hrať každý tím s každým tímom 1 zápas.
Víťaza zápasu určite tak, že pre každý tím v zápase vygenerujete náhodné číslo z intervalu **<0, 10>**,
ktoré bude predstavovať počet strelených gólov v zápase. Za víťazstvo získava víťazný tím **2b**, za remízu **1b** a za prehru **0b**.

Do súboru zapíšte výsledky všetkých zápasov v tvare:\n
*Názov 1.tímu* : *Názov 2. tímu*\n
*počet strelených gólov* : *počet strelených gólov*

Napríklad:\n
**Slovensko : Rusko**\n
**1 : 4**

Výsledky zápasov každého kola vypisujte na konzole v tvare:\n
*krajina (vygenerovaná hodnota)* – *krajina (vygenerovaná hodnota)*

Na konzolu vypíšte výsledne poradie turnaja od 1. miesta po posledné v tvare:\n
*poradie. Názov tímu Počet strelených gólov Počet dostaných gólov Počet bodov*

Napríklad:\n
`**1. Kanada 21 7 15**\n
**2. Rusko 27 13 14**\n
atď.`

Ak majú dva tímy rovnaký počet bodov, tak vyššie v poradí bude tím, ktorý strelí viac gólov.