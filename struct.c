/* Strukturen - MRT1, LUR (c) 2005-2007 */
#include <stdio.h>

/* Definition der Struktur bauteil */
struct bauteil {
	long number;
	char type;
	double value;
};

/** printbt - anzeige eines bauteils  */
void printbt(char *msg, struct bauteil *bt) 
{
	printf("%s:Bauteil at %p: %c-%ld (%f)\n",
		msg,
		bt,
		bt->type,
		bt->number,
		bt->value);
}

int main(void) {
	struct bauteil bt1 = { 1, 'R', 100 };
	struct bauteil bt2; // initialisiert?
	struct bauteil *pbt;// Wilder Zeiger!

	/* Nach Deklaration und Definition */
	printbt("bt1",&bt1);
	printbt("bt2",&bt2);
	printbt("pbt",pbt);	// autsch!
	getchar(); // Pause

	/* Zuweisung und Adressoperator */
	bt2 = bt1; 	// kopiere bt1 nach bt2
	pbt = &bt2;	// pbt zeigt auf bt2
	printbt("bt1",&bt1);
	printbt("bt2",&bt2);
	printbt("pbt",pbt);
	getchar();

	/* Zugriff auf Feld über Variable */
	bt2.value = 20;
	printbt("bt1",&bt1);
	printbt("bt2",&bt2);
	printbt("pbt",pbt);
	getchar();

	/* Zugriff auf Feld über Zeiger */
	pbt->value = 50;
	printbt("bt1",&bt1);
	printbt("bt2",&bt2);
	printbt("pbt",pbt);

	return 0;
}

