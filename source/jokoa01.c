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
void jokoa01()
{	
	EGOERA=HASIERA;

	etenZerbErrutEzarri();
	TekEtenBaimendu();
	DenbEtenBaimendu();	
	konfiguratuTenporizadorea(39322, 0x42);
	konfiguratuTeklatua(0x403D);
	changePlaneSprite(sprite);
	ErlojuaMartxanJarri();
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
hegazkinX = 112;
hegazkinY = 160;
updateSpritePosition(0, hegazkinX, hegazkinY);
spawnClouds();

}
