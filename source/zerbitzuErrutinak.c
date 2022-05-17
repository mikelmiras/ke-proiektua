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
int talkak;
int bihotzakX[];
void tekEten ()
{
			int tekla = SakatutakoTekla();

			if (tekla == SELECT){
				if (EGOERA == EGUNA || EGOERA == GAUA){
				ErlojuaGelditu();
				int i;
				for (i = 5; i < 8; i++){
					kenduBihotza(i);				
				}
				EGOERA = PAUSA;
				hideSprite(0, hegazkinX, hegazkinY);
				switchBG(2);
				hideClouds();
				}else{
					if (EGOERA == PAUSA){
				displayClouds();
				updatePlanePosition(hegazkinX, hegazkinY);
				
				if (segunduak > 60){
					EGOERA = GAUA;
					switchBG(1);				
				}else{
					EGOERA = EGUNA;
					switchBG(0);					
				}
				ErlojuaMartxanJarri();
				int i;
				for (i = talkak + 5; i < 8; i++){
					erakutsiBihotza(i, bihotzakX[i - 5], 1);				
				}
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
	if (SakatutakoTekla() == A && EGOERA == BUKAERA){
	iprintf("\x1b[2J");
	EGOERA=HASIERA;
	switchBG(3);
	TekEtenBaimendu();
	DenbEtenBaimendu();	
	konfiguratuTenporizadorea(61167, 0x42);
	konfiguratuTeklatua(0x403D);
	ErlojuaMartxanJarri();
	changePlaneSprite(0);
	centerSprite(0);
	hegazkinX = 112;
	hegazkinY = 80;	
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
		if (counter_1s == 30){
			segunduak++;
			counter_1s = 0;
		}	
		if (EGOERA == EGUNA && segunduak >= 40){
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
void resetTimer(){
segunduak = 0;
counter = 0;
counter_1s = 0;
}
void etenZerbErrutEzarri()
{
	irqSet(IRQ_KEYS, tekEten);
	irqSet(IRQ_TIMER0, tenpEten);
}

