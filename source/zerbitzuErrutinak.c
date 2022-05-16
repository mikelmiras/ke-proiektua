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
int segunduak = 0;
int counter = 0;
int hegazkinX;
int hegazkinY;
void tekEten ()
{	
	if ((EGOERA == EGUNA || EGOERA == GAUA) && SakatutakoTekla() == SELECT){
		EGOERA = PAUSA;			
	}
	if(EGOERA == EGUNA || EGOERA == GAUA){
		if (SakatutakoTekla() == EZKER && hegazkinX != 27){
			int i;
			
			for(i = 0; i < 17; i++) 
			{
			hideSprite(0, hegazkinX, hegazkinY);
			hegazkinX -= 5;
			updateSpritePosition(0, hegazkinX, hegazkinY);			
			}
		}
		if (SakatutakoTekla() == ESKUBI && hegazkinX != 197){
			int i;
			for(i = 0; i < 17; i++) 
			{
			hideSprite(0, hegazkinX, hegazkinY);
			hegazkinX += 5;
			updateSpritePosition(0, hegazkinX, hegazkinY);			
			}
		}
		
	}
	
}

void tenpEten()
{
	if (EGOERA != HASIERA && EGOERA!=PAUSA){
	//Denboragailua bakarrik jokuan gauden bitartean funtzionatuko du.
	counter_3s++;
	counter++;
	iprintf("\x1b[22;0HDenbora: %d", segunduak);
	moveClouds(counter);
		if (counter_3s == 5){
			segunduak++;
			//iprintf("\x1b[24;0HDenbora: %d", segunduak);
			counter_3s = 0;
		}	
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

