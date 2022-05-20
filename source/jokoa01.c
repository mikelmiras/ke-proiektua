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
{	//egoera hasierara ezarri, hasiera fondoa jarri, eten taula konfiguratu, baimendu etenak
	//erlojua martxan jarri
	EGOERA=HASIERA;
	switchBG(3);
	etenZerbErrutEzarri();
	TekEtenBaimendu();
	DenbEtenBaimendu();	
	konfiguratuTenporizadorea(61167, 0x42);
	konfiguratuTeklatua(0x403D);
	ErlojuaMartxanJarri();
	changePlaneSprite(sprite); //Hegazkinari defektuzko itxura jarri: 0 itxura
	iprintf("\x1b[5;0HEgileak: Mikel Miras, Naroa Iparraguirre eta Jon Mugica");
	iprintf("\x1b[9;0HKontrolak: Aukeratu hegazkina pantaila ukituz.");
	iprintf("\x1b[11;0H<R> eta <L>: Mugitu");
	iprintf("\x1b[12;0H<START> Hasi jokua");
	iprintf("\x1b[13;0H<SELECT> Pausa");
	while(1)
	{

		//Inkesta bidez detektatu ea <START> sakatu den HASIERAn gauden bitartean, jokua hasieratzeko.
		if (TeklaDetektatu() == 1){
		int tekla = SakatutakoTekla();
			if (tekla == START && EGOERA == HASIERA){	
				hideSprite(0, hegazkinX, hegazkinY); //Hegazkina pantaila erditik kendu
				EGOERA = EGUNA; //Egoera aldatu
				switchBG(0); //Jokuaren fondoa jarri
				jokuaHasi(); //Jokua hasieratzen duen funtzioa deitu
			}	
			
		}
		
			
	}
}


void jokuaHasi(){
DenbEtenBaimendu();	//Denboragailua baimendu
ErlojuaMartxanJarri(); //Denboragailua hasieratu, zenbat denbora daramagun jokatzen neurtzeko
hegazkinX = 112; //Hegazkinaren posizio berria ezarri
hegazkinY = 160;
updateSpritePosition(0, hegazkinX, hegazkinY);//Hegazkina ikusgai jarri koordenatu berriekin
spawnClouds(); //Hodeiak sortu
int i;
//Bizitza neurtzen duten spriteak sortu
for (i = 0; i < 3; i++){
erakutsiBihotza(i + 5, bihotzakX[i], bihotzakY);
}
}



