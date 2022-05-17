/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"
#include "jokoa01.h"
int counter_1s; //Aldagai honek 3s neurtzeko erabiltzen da. Etenak	
int sprite;
int segunduak = 0;
int counter = 0;
int hegazkinX;
int hegazkinY;
EGOERA;

int borrar = 0;
void tekEten ()
{
			int tekla = SakatutakoTekla();

			if (tekla == SELECT){
				if (EGOERA == EGUNA || EGOERA == GAUA){
				ErlojuaGelditu();
				EGOERA = PAUSA;
				hideSprite(0, hegazkinX, hegazkinY);
				iprintf("\x1b[7:0HPresionado: %d", borrar);
				borrar++;
				hideClouds();
				}else{
					if (EGOERA == PAUSA){
						iprintf("\x1b[6;0HMartxan berriz");
				displayClouds();
				updatePlanePosition(hegazkinX, hegazkinY);
				EGOERA = EGUNA;
				ErlojuaMartxanJarri();
					}				
				}
			}	
		if(EGOERA == EGUNA || EGOERA == GAUA){
		if (SakatutakoTekla() == EZKER && hegazkinX != 27){
			hideSprite(0, hegazkinX, hegazkinY);
			hegazkinX -= 85;
			updateSpritePosition(0, hegazkinX, hegazkinY);			
		}
		if (SakatutakoTekla() == ESKUBI && hegazkinX != 197){
			int i;
			hideSprite(0, hegazkinX, hegazkinY);
			hegazkinX += 85;
			updateSpritePosition(0, hegazkinX, hegazkinY);			
			
		}
		
	}
	
}

void tenpEten()
{

	if (EGOERA == EGUNA || EGOERA == GAUA){
	//Denboragailua bakarrik jokuan gauden bitartean funtzionatuko du.
	counter_1s++;
	counter++;
	iprintf("\x1b[22;0HDenbora: %d", segunduak);
	moveClouds(counter);
		if (counter_1s == 5){
			segunduak++;
			counter_1s = 0;
		}	
		if (EGOERA == EGUNA && segunduak >= 60){
				EGOERA = GAUA;	
				switchBG(1); //Gaueko fondoa jarri	
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

