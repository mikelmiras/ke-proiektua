/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia
#include "spriteak.h"
#include "definizioak.h"

u16* gfxerronbo;
u16* gfxerronboHandia;

u16* gfxhegazkin1;
u16* gfxhegazkin2;
u16* gfxhegazkin3;

u16* currentPlane;

u16* gfxerrombo;


/* Pantailan erakutsi nahi den sprite bakoitzeko memoria erreserbatu.*/
void memoriaErreserbatu()
{
	/* Pantaila nagusian gehitu nahi den sprite bakoitzarentzako horrelako bat egin behar da. */
	gfxerronbo= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxerronboHandia=oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfxhegazkin1 = oamAllocateGfx(&oamMain, SpriteSize_16x16,SpriteColorFormat_256Color);
	currentPlane = oamAllocateGfx(&oamMain, SpriteSize_16x16,SpriteColorFormat_256Color);
}

/* Pixel bakoitzak har ditzakeen 256 balioetako bakoitzari kolore bat esleitu PANTAILA NAGUSIAN. 0 balioa gardena da 
   eta definitu gabeko balioak beltzak. SPRITEARI KOLOREAK ESLEITZEKO ALDATU*/
void PaletaNagusiaEzarri() {

	SPRITE_PALETTE[0] = RGB15(0,0,0);
SPRITE_PALETTE[1] = RGB15(7,8,1);
SPRITE_PALETTE[2] = RGB15(9,10,0);
SPRITE_PALETTE[3] = RGB15(2,2,3);
SPRITE_PALETTE[4] = RGB15(9,11,14);
SPRITE_PALETTE[5] = RGB15(9,11,14);
SPRITE_PALETTE[6] = RGB15(18,15,3);
SPRITE_PALETTE[7] = RGB15(10,11,14);
SPRITE_PALETTE[8] = RGB15(10,9,9);
SPRITE_PALETTE[9] = RGB15(7,7,1);
SPRITE_PALETTE[10] = RGB15(10,9,9);
SPRITE_PALETTE[11] = RGB15(6,7,0);
SPRITE_PALETTE[12] = RGB15(11,10,9);
SPRITE_PALETTE[13] = RGB15(9,10,0);
SPRITE_PALETTE[14] = RGB15(3,3,3);
SPRITE_PALETTE[15] = RGB15(18,15,3);
SPRITE_PALETTE[16] = RGB15(18,15,3);
SPRITE_PALETTE[17] = RGB15(18,14,3);
SPRITE_PALETTE[18] = RGB15(8,8,2);
SPRITE_PALETTE[19] = RGB15(18,15,3);
SPRITE_PALETTE[20] = RGB15(7,7,3);
SPRITE_PALETTE[21] = RGB15(6,6,5);
SPRITE_PALETTE[22] = RGB15(18,15,3);
SPRITE_PALETTE[23] = RGB15(18,15,3);

}

/* 16x16 pixeleko Sprite baten definizioa erronbo bat marrazteko */
/* Memoriako bankuek duten lan egiteko modua dela eta, lehenengo lau lerroak goiko
   ezkerreko koadrantean erakusten dira, hurrengo lauak goiko eskuineko kuadrantean,
   hurrengo lauak beheko ezkerreko koadrantean eta azkeneko lauak beheko ezkerreko koadrantean. 
   Alboko irudian ikusten den bezala. */

u8 erronbo[256] = 
{
	0,0,0,0,0,0,2,2,0,0,0,0,0,2,2,2,	//	0,0,0,0,0,0,2,2, 2,2,0,0,0,0,0,0,
	0,0,0,0,2,2,2,2,0,0,0,2,2,2,2,2,	//	0,0,0,0,0,2,2,2, 2,2,2,0,0,0,0,0,
	0,0,2,2,2,2,2,2,0,2,2,2,2,2,2,2,	//	0,0,0,0,2,2,2,2, 2,2,2,2,0,0,0,0,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,	//	0,0,0,2,2,2,2,2, 2,2,2,2,2,0,0,0,
 
	2,2,0,0,0,0,0,0,2,2,2,0,0,0,0,0,	//	0,0,2,2,2,2,2,2, 2,2,2,2,2,2,0,0,
	2,2,2,2,0,0,0,0,2,2,2,2,2,0,0,0,	//	0,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,0,
	2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,0,	//	2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,	//	2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	//	1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,	//	1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
	0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,	//	0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
	0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,	//	0,0,1,1,1,1,1,1, 1,1,1,1,1,1,0,0,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	//	0,0,0,1,1,1,1,1, 1,1,1,1,1,0,0,0,
	1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,	//	0,0,0,0,1,1,1,1, 1,1,1,1,0,0,0,0,
	1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,	//	0,0,0,0,0,1,1,1, 1,1,1,0,0,0,0,0,
	1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,	//	0,0,0,0,0,0,1,1, 1,1,0,0,0,0,0,0,
};

u8 plane1[1024] = {

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,2,3,0,0,0,0,0,0,1,4,0,0,0,0,0,0,1,4,0,0,0,0,0,0,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3,1,0,0,0,0,0,0,4,5,0,0,0,0,0,0,6,4,0,0,0,0,0,0,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,8,8,8,8,8,0,0,1,8,8,8,8,6,0,0,1,4,8,8,8,6,0,0,0,1,4,4,8,8,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,1,1,1,1,1,1,8,8,8,8,8,8,8,4,8,8,6,6,6,6,8,4,8,8,6,6,6,6,8,4,8,8,8,8,8,8,8,4,8,8,4,4,4,4,4,4,4,4,0,0,1,1,4,4,4,4,8,8,0,0,0,0,0,0,8,8,9,1,1,1,1,1,8,8,4,8,8,8,8,8,8,8,4,8,6,6,6,6,8,8,4,10,6,6,6,6,8,8,4,4,8,8,4,4,4,4,4,4,4,4,4,1,4,4,4,4,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,8,8,8,8,8,8,11,0,6,8,8,8,8,4,1,0,6,12,8,8,4,1,0,0,4,4,4,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,1,4,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,8,4,4,1,0,0,0,0,0,4,4,0,0,0,0,0,0,3,14,0,0,0,0,0,0,15,3,0,0,0,0,0,0,16,1,0,0,0,0,0,0,17,18,0,0,0,0,0,0,19,20,0,0,0,0,0,0,8,8,21,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,8,8,8,0,0,0,1,4,4,4,22,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8,8,8,8,4,0,0,23,22,4,4,4,4,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

};
u8 plane2[1024] = {

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,2,3,0,0,0,0,0,0,1,4,0,0,0,0,0,0,1,4,0,0,0,0,0,0,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3,1,0,0,0,0,0,0,4,5,0,0,0,0,0,0,6,4,0,0,0,0,0,0,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,8,8,8,8,8,0,0,1,8,8,8,8,6,0,0,1,4,8,8,8,6,0,0,0,1,4,4,8,8,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,1,1,1,1,1,1,8,8,8,8,8,8,8,4,8,8,6,6,6,6,8,4,8,8,6,6,6,6,8,4,8,8,8,8,8,8,8,4,8,8,4,4,4,4,4,4,4,4,0,0,1,1,4,4,4,4,8,8,0,0,0,0,0,0,8,8,9,1,1,1,1,1,8,8,4,8,8,8,8,8,8,8,4,8,6,6,6,6,8,8,4,10,6,6,6,6,8,8,4,4,8,8,4,4,4,4,4,4,4,4,4,1,4,4,4,4,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,8,8,8,8,8,8,11,0,6,8,8,8,8,4,1,0,6,12,8,8,4,1,0,0,4,4,4,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,1,4,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,8,4,4,1,0,0,0,0,0,4,4,0,0,0,0,0,0,3,14,0,0,0,0,0,0,15,3,0,0,0,0,0,0,16,1,0,0,0,0,0,0,17,18,0,0,0,0,0,0,19,20,0,0,0,0,0,0,8,8,21,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,8,8,8,0,0,0,1,4,4,4,22,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8,8,8,8,4,0,0,23,22,4,4,4,4,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


};
u8 plane3[1024] = {

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,2,3,0,0,0,0,0,0,1,4,0,0,0,0,0,0,1,4,0,0,0,0,0,0,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3,1,0,0,0,0,0,0,4,5,0,0,0,0,0,0,6,4,0,0,0,0,0,0,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,8,8,8,8,8,0,0,1,8,8,8,8,6,0,0,1,4,8,8,8,6,0,0,0,1,4,4,8,8,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,1,1,1,1,1,1,8,8,8,8,8,8,8,4,8,8,6,6,6,6,8,4,8,8,6,6,6,6,8,4,8,8,8,8,8,8,8,4,8,8,4,4,4,4,4,4,4,4,0,0,1,1,4,4,4,4,8,8,0,0,0,0,0,0,8,8,9,1,1,1,1,1,8,8,4,8,8,8,8,8,8,8,4,8,6,6,6,6,8,8,4,10,6,6,6,6,8,8,4,4,8,8,4,4,4,4,4,4,4,4,4,1,4,4,4,4,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,8,8,8,8,8,8,11,0,6,8,8,8,8,4,1,0,6,12,8,8,4,1,0,0,4,4,4,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,1,4,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,8,4,4,1,0,0,0,0,0,4,4,0,0,0,0,0,0,3,14,0,0,0,0,0,0,15,3,0,0,0,0,0,0,16,1,0,0,0,0,0,0,17,18,0,0,0,0,0,0,19,20,0,0,0,0,0,0,8,8,21,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,8,8,8,0,0,0,1,4,4,4,22,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8,8,8,8,4,0,0,23,22,4,4,4,4,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


};

u8 erronboHandia[1024] = 
{
	0,0,0,0,0,0,2,2,0,0,0,0,0,2,2,2,0,0,0,0,2,2,2,2,0,0,0,2,2,2,2,2,0,0,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,	

	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	

	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	
 
	2,2,0,0,0,0,0,0,2,2,2,0,0,0,0,0,2,2,2,2,0,0,0,0,2,2,2,2,2,0,0,0,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,	

	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,

	0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	

	1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	

	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,0,0,0,2,2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,0,0,2,2,2,0,0,0,0,0,0,2,2,	

	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,0,0,2,2,2,2,2,0,0,0,2,2,2,2,0,0,0,0,2,2,2,0,0,0,0,0,2,2,0,0,0,0,0,0,	

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,	

	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	

	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,	
};

/* Irudikatutako Spriteak memorian kargatzen ditu. SPRITE bat baino gehiago erakusteko
for bana egin behar da.*/

void SpriteakMemorianGorde(id){ 
	
int i;
	//16*16ko spriteentzako
	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxerronbo[i] = erronbo[i*2] | (erronbo[(i*2)+1]<<8);	
	//	gfxhegazkin1[i] = plane1[i*2] | (plane1[(i*2)+1]<<8);			
	//	switch(id){
	//	case 0:
	//		currentPlane[i] = plane1[i*2] | (plane1[(i*2)+1]<<8);		
	//		break;
	//	case 1:
	//		currentPlane[i] = erronbo[i*2] | (erronbo[(i*2)+1]<<8);
	//		break;
	//	case 2:
	//		currentPlane[i] = plane1[i*2] | (plane1[(i*2)+1]<<8);
	//		break;
	//	default:
	//		currentPlane[i] = plane1[i*2] | (plane1[(i*2)+1]<<8);
	//	}
	}
	//32*32ko spriteentzako
	for(i = 0; i < 32 * 32 / 2; i++) 
	{	switch(id){
		case 0:
		currentPlane[i] = plane1[i*2] | (plane1[(i*2)+1]<<8);			
		break;
		case 1:
		currentPlane[i] = plane2[i*2] | (plane2[(i*2)+1]<<8);
		break;
		case 2:
		currentPlane[i] = plane3[i*2] | (plane3[(i*2)+1]<<8);
		default:
		currentPlane[i] = plane1[i*2] | (plane1[(i*2)+1]<<8);
		}				
	}
}

/* Funtzio honek erronbo bat irudikatuko dut pantailako x-y posizioan. Pantailan ateratzea nahi den erronbo 
   bakoitzari indize desberdin bat esleitu behar zaio, 0 eta 126 balioen arteko indizea izan daiteke. */

void ErakutsiErronboa(int indizea, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indizea,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxerronbo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/*Funtzio honek erronbo baten indizea pasata pantailatik ezabatzen du*/
void EzabatuErronboa(int indizea, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indizea,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxerronbo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}

void ErakutsiErronboHandia(int indizea, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indizea,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxerronboHandia,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 

	  
oamUpdate(&oamMain);  
}

void EzabatuErronboHandia(int indizea, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indizea,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxerronboHandia,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?	
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}


void changePlaneSprite(int id){
SpriteakMemorianGorde(id);
oamSet(&oamMain, //main graphics engine context
		0,           //oam index (0 to 127)  
		112, 80,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		currentPlane,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}
void updateSpritePosition(int id, int x, int y){
oamSet(&oamMain, //main graphics engine context
		id,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		currentPlane,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}
void hideSprite(int id, int x, int y){
oamSet(&oamMain, //main graphics engine context
		id,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		currentPlane,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}
void updatePlanePosition(int x, int y){
updateSpritePosition(0, x, y);
}





