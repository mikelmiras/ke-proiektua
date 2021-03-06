/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia

/* Fondo desberdinak erakutsi nahi izango baditugu, hemen fondo bakoitzaren burukoa (.h fitxategia) gehitu behar da. Buruko horiek
automatikoki sortzen dira, konpilatzerako garaian, baina horretarako gogoratu behar da */

#include "fondoak.h"
#include "grafikoak.h"
#include "sky.h"
#include "PAUSA.h"
#include "hasiera.h"
#include "night.h"
#include "BUKAERA.h"
/* irudiak memorian kopiatzeko DMA kanala aukeratu (3.a) */
static const int DMA_CHANNEL = 3;

/* Pantailaratu nahi den grafiko bakoitzerako horrelako prozedura bat idatzi behar da */

//Fondoa aldatzen du, n balioaren arabera fondo bat edo beste bat jartzen du.
void switchBG(int n){
	switch(n){
	case 0:
		dmaCopyHalfWords(DMA_CHANNEL,
                     skyBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     skyBitmapLen);
	break;
	case 1:
		dmaCopyHalfWords(DMA_CHANNEL,
                     nightBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     nightBitmapLen);
	break;
	case 2:
	dmaCopyHalfWords(DMA_CHANNEL,
                     PAUSABitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     PAUSABitmapLen);
	
	break;
	case 3:
	dmaCopyHalfWords(DMA_CHANNEL,
                     hasieraBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     hasieraBitmapLen);
	
	break;
	case 4:
	dmaCopyHalfWords(DMA_CHANNEL,
                     BUKAERABitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                    BUKAERABitmapLen);
	
	break;
	default:
	dmaCopyHalfWords(DMA_CHANNEL,
                     skyBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     skyBitmapLen);
	
	}
	
}
