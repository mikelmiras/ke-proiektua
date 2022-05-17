/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia

//Geuk garatutako fitxategiak
	
#include "definizioak.h"
#include "periferikoak.h"
#include "zerbitzuErrutinak.h"
#include "fondoak.h"
#include "oztopoak.h"
#include "spriteak.h"
int hegazkinX;
int hegazkinY;
int denb;
int sprite = 0;
int bihotzakX[] = {196, 213, 230};
int bihotzakY = 1;
int segunduak;

void jokoa01()
{	
	EGOERA=HASIERA;
	switchBG(3);
	etenZerbErrutEzarri();
	TekEtenBaimendu();
	DenbEtenBaimendu();	
	konfiguratuTenporizadorea(61167, 0x42);
	konfiguratuTeklatua(0x403D);
	ErlojuaMartxanJarri();
	changePlaneSprite(sprite);
	while(1)
	{
		if (TeklaDetektatu() == 1){
		int tekla = SakatutakoTekla();
			if (tekla == START && EGOERA == HASIERA){	
				hideSprite(0, hegazkinX, hegazkinY);
				EGOERA = EGUNA;
				switchBG(0);
				jokuaHasi();
			}	
			
		}
		
			
	}
}


void jokuaHasi(){
DenbEtenBaimendu();	
ErlojuaMartxanJarri();
hegazkinX = 112;
hegazkinY = 160;
updateSpritePosition(0, hegazkinX, hegazkinY);
spawnClouds();
int i;
for (i = 0; i < 3; i++){
erakutsiBihotza(i + 5, bihotzakX[i], bihotzakY);
}
}



