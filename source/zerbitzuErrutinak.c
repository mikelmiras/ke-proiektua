/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"
#include "jokoa01.h"

int EGOERA;
int counter_3s; //Aldagai honek 3s neurtzeko erabiltzen da. Etenak	
int sprite;
void tekEten ()
{	
	iprintf("\x1b[11;0HSakatutako tekla: %d", SakatutakoTekla());
	iprintf("\x1b[10;0HEgoera: %d", EGOERA);
	if ((EGOERA == EGUNA || EGOERA == GAUA) && SakatutakoTekla() == SELECT){
		EGOERA = PAUSA;			
	}
}

void tenpEten()
{
	if (EGOERA != HASIERA && EGOERA!=PAUSA){
	//Denboragailua bakarrik jokuan gauden bitartean funtzionatuko du.
	counter_3s++;	
	}
	if (EGOERA == HASIERA) {
			touchPosition pos;
			touchRead(&pos);
			if (pos.px != 0 && pos.py != 0){
				if (sprite < 2)
					sprite++;
				else
					sprite = 0;				
				changePlaneSprite(sprite); //Funtzio honek spritearen itxura aldatzen du. Funtzio hau spriteak.h-n dago.
				
			}
		}
	


}
void etenZerbErrutEzarri()
{
	irqSet(IRQ_KEYS, tekEten);
	irqSet(IRQ_TIMER0, tenpEten);
}

