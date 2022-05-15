/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"

int EGOERA;
int seg3;

void tekEten ()
{
	if (EGOERA == HASIERA && SakatutakoTekla() == START)
	{
   		EGOERA = EGUNA;
	}
	if ((EGOERA == EGUNA || EGOERA == GAUA) && SakatutakoTekla() == SELECT){
		EGOERA = PAUSA;			
	}
}

void tenpEten()
{
	static int tik=0;
	static int seg=0;
	

if (EGOERA!=HASIERA && EGOERA != BUKAERA && EGOERA != PAUSA)
{
	tik++; 
	
}
}
void etenZerbErrutEzarri()
{
	irqSet(IRQ_KEYS, tekEten);
	irqSet(IRQ_TIMER0, tenpEten);
}

