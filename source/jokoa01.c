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

int denb;

void jokoa01()
{	
	EGOERA=HASIERA;
	
	
	iprintf("\x1b[13;0HOngi etorri jure jokura.");	//Honek, 13 lerroan eta 0 zutabean testua idatziko du.
													//Aldagai baten idatzi nahi izanez gero, %d komatxoen barruan eta 
													 //komatxoen kanpoan aldagaiaren balioa.
	iprintf("\x1b[16;0HHegazkina aldatzeko, pantaila ukitu. Jokua hasteko, sakatu START.");


	TekEtenBaimendu();
	DenbEtenBaimendu();	
	konfiguratuTenporizadorea(39322, 0x42);
	konfiguratuTeklatua(0x4001);
	ErlojuaMartxanJarri();
	etenZerbErrutEzarri();
	//erakutsiAtea();
	int sprite = 0;
	while(1)
	{
		if (TeklaDetektatu() == 1){
		int tekla = SakatutakoTekla();
			if (tekla == START){	
				EGOERA = EGUNA;
				ErlojuaMartxanJarri();
			}	
		}
		if (EGOERA == HASIERA) {
			
			touchPosition pos;
			touchRead(&pos);
			if (pos.px != 0 && pos.py != 0){
				changePlaneSprite(sprite); //Funtzio honek spritearen itxura aldatzen du. Funtzio hau spriteak.h-n dago.
				if (sprite < 3)
					sprite++;
				else
					sprite = 0;
			}
			iprintf("\x1b[22;5HSpriteak: %d", sprite);
		}
//		if (EGOERA == EGUNA){
//			jokuaHasi();
//		}
			
	}
}
