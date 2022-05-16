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
#include "oztopoak.h"
int hegazkinX;
int hegazkinY;

u16* currentPlane;
u16* gfxHodeia;



/* Pantailan erakutsi nahi den sprite bakoitzeko memoria erreserbatu.*/
void memoriaErreserbatu()
{
	/* Pantaila nagusian gehitu nahi den sprite bakoitzarentzako horrelako bat egin behar da. */
	currentPlane = oamAllocateGfx(&oamMain, SpriteSize_32x32,SpriteColorFormat_256Color);
	gfxHodeia = oamAllocateGfx(&oamMain, SpriteSize_32x32,SpriteColorFormat_256Color);
	//gfxHodeia2 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	//gfxHodeia3 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);	
	//gfxHodeia4 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
}

/* Pixel bakoitzak har ditzakeen 256 balioetako bakoitzari kolore bat esleitu PANTAILA NAGUSIAN. 0 balioa gardena da 
   eta definitu gabeko balioak beltzak. SPRITEARI KOLOREAK ESLEITZEKO ALDATU*/
void PaletaNagusiaEzarri() {
//Lehenengo hegazkina:
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
//Bigarren hegazkina:
SPRITE_PALETTE[24] = RGB15(8,9,12);
SPRITE_PALETTE[25] = RGB15(8,9,11);
SPRITE_PALETTE[26] = RGB15(8,9,11);
SPRITE_PALETTE[27] = RGB15(8,9,11);
SPRITE_PALETTE[28] = RGB15(23,21,21);
SPRITE_PALETTE[29] = RGB15(8,9,11);
SPRITE_PALETTE[30] = RGB15(17,25,17);
SPRITE_PALETTE[31] = RGB15(8,9,11);
SPRITE_PALETTE[32] = RGB15(8,9,12);
SPRITE_PALETTE[33] = RGB15(8,9,12);
SPRITE_PALETTE[34] = RGB15(11,10,10);
SPRITE_PALETTE[35] = RGB15(16,16,21);
SPRITE_PALETTE[36] = RGB15(2,2,2);
SPRITE_PALETTE[37] = RGB15(8,9,12);
SPRITE_PALETTE[38] = RGB15(9,9,12);
SPRITE_PALETTE[39] = RGB15(2,2,2);
//Hirugarren hegazkina:
SPRITE_PALETTE[40] = RGB15(30,0,0);
SPRITE_PALETTE[41] = RGB15(8,9,12);
SPRITE_PALETTE[42] = RGB15(8,9,11);
SPRITE_PALETTE[43] = RGB15(8,9,11);
SPRITE_PALETTE[44] = RGB15(0,0,0);
SPRITE_PALETTE[45] = RGB15(0,8,4);
SPRITE_PALETTE[46] = RGB15(8,9,11);
SPRITE_PALETTE[47] = RGB15(17,25,17);
SPRITE_PALETTE[48] = RGB15(31,0,0);
SPRITE_PALETTE[49] = RGB15(8,9,11);
SPRITE_PALETTE[50] = RGB15(16,16,21);
SPRITE_PALETTE[51] = RGB15(2,2,2);
//Hodeia:
SPRITE_PALETTE[52] = RGB15(4,4,4);
SPRITE_PALETTE[53] = RGB15(31,31,31);
SPRITE_PALETTE[54] = RGB15(0,16,31);

}

/* 16x16 pixeleko Sprite baten definizioa erronbo bat marrazteko */
/* Memoriako bankuek duten lan egiteko modua dela eta, lehenengo lau lerroak goiko
   ezkerreko koadrantean erakusten dira, hurrengo lauak goiko eskuineko kuadrantean,
   hurrengo lauak beheko ezkerreko koadrantean eta azkeneko lauak beheko ezkerreko koadrantean. 
   Alboko irudian ikusten den bezala. */


u8 hodeia[1024] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 52, 52, 0, 0, 0, 0, 52, 52, 53, 53, 0, 0, 52, 52, 52, 53, 53, 53, 0, 0, 52, 53, 53, 53, 53, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 52, 52, 0, 0, 0, 0, 0, 53, 53, 52, 52, 0, 0, 0, 0, 53, 53, 53, 52, 0, 0, 0, 0, 53, 53, 53, 52, 52, 52, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 52, 52, 52, 0, 0, 0, 0, 52, 53, 53, 53, 0, 0, 0, 52, 53, 53, 53, 53, 52, 52, 52, 53, 53, 53, 53, 53, 0, 0, 52, 53, 53, 53, 53, 53, 0, 0, 52, 53, 53, 53, 53, 53, 52, 52, 53, 53, 53, 53, 53, 53, 52, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 52, 52, 53, 53, 53, 53, 53, 53, 53, 52, 53, 53, 53, 53, 53, 53, 53, 52, 53, 53, 53, 53, 53, 53, 53, 52, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 52, 0, 52, 52, 52, 0, 0, 0, 52, 52, 53, 53, 52, 0, 0, 0, 53, 53, 53, 53, 52, 52, 0, 0, 53, 53, 53, 53, 52, 53, 52, 0, 52, 53, 53, 53, 53, 53, 53, 53, 52, 53, 53, 53, 53, 53, 53, 53, 52, 53, 53, 53, 53, 53, 53, 53, 0, 52, 53, 53, 53, 53, 53, 53, 0, 0, 52, 53, 53, 53, 53, 53, 0, 0, 0, 52, 53, 53, 53, 53, 0, 0, 0, 0, 52, 53, 53, 53, 0, 0, 0, 0, 52, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 54, 53, 53, 53, 53, 53, 53, 53, 53, 54, 53, 53, 53, 54, 54, 53, 53, 53, 53, 54, 54, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 54, 53, 53, 53, 53, 53, 53, 53, 53, 54, 53, 53, 53, 53, 53, 53, 53, 53, 54, 54, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 52, 0, 53, 53, 53, 53, 53, 53, 52, 0, 53, 53, 53, 53, 53, 53, 52, 0, 53, 53, 53, 53, 53, 52, 0, 0, 53, 53, 53, 53, 53, 52, 0, 0, 53, 53, 53, 53, 53, 53, 52, 0, 53, 53, 53, 53, 53, 53, 52, 0, 53, 53, 53, 53, 53, 52, 0, 0, 0, 0, 0, 0, 0, 52, 52, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53, 53, 53, 53, 53, 53, 53, 53, 52, 53, 53, 53, 53, 53, 53, 52, 0, 52, 52, 53, 53, 53, 52, 52, 0, 0, 0, 52, 52, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 52, 52, 53, 53, 53, 53, 53, 52, 0, 0, 52, 52, 52, 52, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53, 53, 53, 53, 52, 0, 0, 0, 53, 53, 52, 52, 0, 0, 0, 0, 52, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

u8 plane1[1024] = {

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,2,3,0,0,0,0,0,0,1,4,0,0,0,0,0,0,1,4,0,0,0,0,0,0,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3,1,0,0,0,0,0,0,4,5,0,0,0,0,0,0,6,4,0,0,0,0,0,0,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,8,8,8,8,8,0,0,1,8,8,8,8,6,0,0,1,4,8,8,8,6,0,0,0,1,4,4,8,8,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,1,1,1,1,1,1,8,8,8,8,8,8,8,4,8,8,6,6,6,6,8,4,8,8,6,6,6,6,8,4,8,8,8,8,8,8,8,4,8,8,4,4,4,4,4,4,4,4,0,0,1,1,4,4,4,4,8,8,0,0,0,0,0,0,8,8,9,1,1,1,1,1,8,8,4,8,8,8,8,8,8,8,4,8,6,6,6,6,8,8,4,10,6,6,6,6,8,8,4,4,8,8,4,4,4,4,4,4,4,4,4,1,4,4,4,4,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,8,8,8,8,8,8,11,0,6,8,8,8,8,4,1,0,6,12,8,8,4,1,0,0,4,4,4,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,1,4,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,8,4,4,1,0,0,0,0,0,4,4,0,0,0,0,0,0,3,14,0,0,0,0,0,0,15,3,0,0,0,0,0,0,16,1,0,0,0,0,0,0,17,18,0,0,0,0,0,0,19,20,0,0,0,0,0,0,8,8,21,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,8,8,8,0,0,0,1,4,4,4,22,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8,8,8,8,4,0,0,23,22,4,4,4,4,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

};

u8 plane2[1024] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 25, 0, 0, 0, 0, 0, 0, 24, 24, 0, 0, 0, 0, 0, 24, 24, 24, 0, 0, 0, 0, 0, 24, 24, 24, 0, 0, 0, 0, 24, 24, 24, 24, 0, 0, 0, 0, 24, 24, 24, 24, 0, 0, 0, 0, 24, 24, 26, 27, 0, 0, 0, 0, 0, 0, 0, 0, 25, 24, 0, 0, 0, 0, 0, 0, 24, 24, 0, 0, 0, 0, 0, 0, 24, 24, 24, 0, 0, 0, 0, 0, 24, 24, 24, 0, 0, 0, 0, 0, 24, 24, 24, 24, 0, 0, 0, 0, 24, 24, 24, 24, 0, 0, 0, 0, 27, 26, 24, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 24, 0, 0, 0, 0, 0, 0, 24, 24, 0, 0, 0, 0, 0, 0, 24, 24, 0, 0, 0, 0, 24, 24, 29, 30, 0, 0, 0, 24, 24, 24, 30, 30, 0, 0, 24, 24, 24, 24, 30, 30, 0, 24, 24, 24, 24, 24, 30, 30, 0, 24, 24, 24, 24, 24, 30, 30, 0, 24, 24, 24, 24, 24, 30, 30, 24, 24, 24, 24, 24, 24, 30, 30, 24, 24, 24, 24, 24, 31, 30, 30, 30, 29, 24, 24, 0, 0, 0, 0, 30, 30, 24, 24, 24, 0, 0, 0, 30, 30, 24, 24, 24, 24, 0, 0, 30, 30, 24, 24, 24, 24, 24, 0, 30, 30, 24, 24, 24, 24, 24, 0, 30, 30, 24, 24, 24, 24, 24, 0, 30, 30, 24, 24, 24, 24, 24, 24, 30, 30, 31, 24, 24, 24, 24, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 28, 0, 0, 0, 0, 0, 0, 24, 24, 0, 0, 0, 0, 0, 0, 24, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 24, 0, 0, 0, 0, 32, 24, 24, 24, 0, 0, 0, 24, 24, 24, 24, 24, 0, 0, 24, 24, 24, 24, 24, 24, 0, 0, 24, 24, 24, 24, 24, 24, 0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 33, 33, 0, 24, 24, 24, 24, 33, 0, 0, 0, 24, 24, 24, 24, 34, 34, 35, 35, 24, 24, 24, 24, 34, 34, 35, 35, 24, 24, 24, 24, 34, 34, 35, 35, 24, 24, 24, 24, 34, 34, 35, 35, 24, 24, 24, 24, 34, 34, 35, 35, 33, 33, 36, 24, 34, 34, 35, 35, 0, 0, 36, 24, 34, 34, 35, 35, 0, 0, 36, 24, 34, 34, 35, 35, 35, 35, 34, 34, 24, 24, 24, 24, 35, 35, 34, 34, 24, 24, 24, 24, 35, 35, 34, 34, 24, 24, 24, 24, 35, 35, 34, 34, 24, 24, 24, 24, 35, 35, 34, 34, 24, 24, 24, 24, 35, 35, 34, 34, 24, 36, 33, 33, 35, 35, 34, 34, 24, 36, 0, 0, 35, 35, 34, 34, 24, 36, 0, 0, 24, 24, 0, 0, 0, 0, 0, 0, 24, 24, 24, 32, 0, 0, 0, 0, 24, 24, 24, 24, 24, 0, 0, 0, 24, 24, 24, 24, 24, 24, 0, 0, 24, 24, 24, 24, 24, 24, 0, 0, 24, 24, 24, 24, 24, 24, 24, 0, 0, 33, 33, 24, 24, 24, 24, 24, 0, 0, 0, 33, 24, 24, 24, 24, 0, 33, 37, 38, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0, 0, 0, 0, 0, 36, 36, 0, 0, 0, 0, 0, 0, 36, 39, 0, 0, 0, 0, 0, 0, 36, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 36, 24, 34, 34, 35, 35, 36, 36, 39, 24, 34, 34, 35, 35, 36, 39, 39, 24, 34, 34, 35, 35, 39, 39, 39, 24, 34, 34, 35, 35, 39, 39, 39, 24, 34, 34, 35, 35, 39, 39, 39, 39, 39, 39, 39, 39, 0, 0, 0, 39, 39, 39, 39, 39, 0, 0, 0, 0, 0, 0, 0, 0, 35, 35, 34, 34, 24, 36, 36, 0, 35, 35, 34, 34, 24, 39, 36, 36, 35, 35, 34, 34, 24, 39, 39, 36, 35, 35, 34, 34, 24, 39, 39, 39, 35, 35, 34, 34, 24, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 38, 37, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0, 36, 36, 0, 0, 0, 0, 0, 0, 39, 36, 0, 0, 0, 0, 0, 0, 39, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

u8 plane3[1024] = {


0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 40, 40, 0, 0, 0, 0, 0, 41, 41, 41, 0, 0, 0, 0, 0, 41, 41, 41, 0, 0, 0, 0, 41, 41, 41, 41, 0, 0, 0, 0, 41, 41, 41, 41, 0, 0, 0, 0, 41, 41, 42, 43, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 40, 40, 0, 0, 0, 0, 0, 0, 41, 41, 41, 0, 0, 0, 0, 0, 41, 41, 41, 0, 0, 0, 0, 0, 41, 41, 41, 41, 0, 0, 0, 0, 41, 41, 41, 41, 0, 0, 0, 0, 43, 42, 41, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44, 45, 0, 0, 0, 0, 0, 0, 45, 45, 0, 0, 0, 0, 0, 0, 45, 41, 0, 0, 0, 0, 41, 41, 46, 47, 0, 0, 0, 41, 41, 41, 47, 47, 0, 0, 41, 41, 41, 41, 47, 47, 0, 45, 41, 41, 41, 41, 47, 47, 0, 45, 41, 41, 41, 41, 47, 47, 0, 45, 41, 41, 41, 41, 47, 47, 45, 45, 41, 41, 41, 41, 47, 47, 41, 48, 41, 41, 41, 49, 47, 47, 47, 46, 41, 41, 0, 0, 0, 0, 47, 47, 41, 41, 41, 0, 0, 0, 47, 47, 41, 41, 41, 41, 0, 0, 47, 47, 41, 41, 41, 41, 45, 0, 47, 47, 41, 41, 41, 41, 45, 0, 47, 47, 41, 41, 41, 41, 45, 0, 47, 47, 41, 41, 41, 41, 45, 45, 47, 47, 49, 41, 41, 41, 48, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 44, 0, 0, 0, 0, 0, 0, 45, 45, 0, 0, 0, 0, 0, 0, 41, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 41, 0, 0, 0, 0, 45, 45, 45, 48, 0, 0, 0, 45, 41, 41, 48, 48, 0, 0, 45, 41, 48, 48, 48, 41, 0, 0, 45, 41, 48, 48, 41, 41, 0, 45, 41, 41, 41, 41, 41, 41, 45, 41, 41, 41, 41, 0, 0, 0, 45, 45, 45, 45, 0, 0, 0, 0, 48, 48, 41, 41, 45, 45, 50, 50, 48, 41, 41, 41, 45, 45, 50, 50, 41, 41, 41, 41, 45, 45, 50, 50, 41, 41, 41, 41, 45, 45, 50, 50, 41, 41, 41, 41, 45, 45, 50, 50, 0, 0, 0, 41, 45, 45, 50, 50, 0, 0, 0, 41, 45, 45, 50, 50, 0, 0, 0, 41, 45, 45, 50, 50, 50, 50, 45, 45, 41, 41, 48, 48, 50, 50, 45, 45, 41, 41, 41, 48, 50, 50, 45, 45, 41, 41, 41, 41, 50, 50, 45, 45, 41, 41, 41, 41, 50, 50, 45, 45, 41, 41, 41, 41, 50, 50, 45, 45, 41, 0, 0, 0, 50, 50, 45, 45, 41, 0, 0, 0, 50, 50, 45, 45, 41, 0, 0, 0, 41, 45, 0, 0, 0, 0, 0, 0, 48, 45, 45, 45, 0, 0, 0, 0, 48, 48, 41, 41, 45, 0, 0, 0, 41, 48, 48, 48, 41, 45, 0, 0, 41, 41, 48, 48, 41, 45, 0, 0, 41, 41, 41, 41, 41, 41, 45, 0, 0, 0, 0, 41, 41, 41, 41, 45, 0, 0, 0, 0, 45, 45, 45, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41, 45, 45, 50, 50, 0, 0, 51, 41, 45, 45, 50, 50, 0, 51, 51, 41, 45, 45, 50, 50, 51, 51, 51, 41, 45, 45, 50, 50, 51, 51, 51, 41, 45, 45, 50, 50, 51, 51, 51, 51, 51, 51, 51, 51, 0, 0, 0, 51, 51, 51, 51, 51, 0, 0, 0, 0, 0, 0, 0, 0, 50, 50, 45, 45, 41, 0, 0, 0, 50, 50, 45, 45, 41, 51, 0, 0, 50, 50, 45, 45, 41, 51, 51, 0, 50, 50, 45, 45, 41, 51, 51, 51, 50, 50, 45, 45, 41, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

 };

/* Irudikatutako Spriteak memorian kargatzen ditu. SPRITE bat baino gehiago erakusteko
for bana egin behar da.*/

void SpriteakMemorianGorde(id){ 
	
int i;
	//16*16ko spriteentzako
	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		
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
		break;
		default:
		currentPlane[i] = plane3[i*2] | (plane3[(i*2)+1]<<8);
		}
		gfxHodeia[i] = hodeia[i*2] | (hodeia[(i*2)+1]<<8);
	}
}

/* Funtzio honek erronbo bat irudikatuko dut pantailako x-y posizioan. Pantailan ateratzea nahi den erronbo 
   bakoitzari indize desberdin bat esleitu behar zaio, 0 eta 126 balioen arteko indizea izan daiteke. */








void changePlaneSprite(int id){
SpriteakMemorianGorde(id);
oamSet(&oamMain, //main graphics engine context
		0,           //oam index (0 to 127)  
		hegazkinX, hegazkinY,   //x and y pixle location of the sprite
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
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}
void updatePlanePosition(int x, int y){
updateSpritePosition(0, x, y);
}

void 	updateCloudPos(int id, int x, int y){
	switch(id){
	case 0:
	oamSet(&oamMain, //main graphics engine context
		1,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxHodeia,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	oamUpdate(&oamMain); 
	break;
	case 1:
	oamSet(&oamMain, //main graphics engine context
		2,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxHodeia,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
break;
case 2:
	oamSet(&oamMain, //main graphics engine context
		3,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxHodeia,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
	break;
case 3:
oamSet(&oamMain, //main graphics engine context
		4,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxHodeia,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain);
break; 
default:
oamSet(&oamMain, //main graphics engine context
		1,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxHodeia,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
	}

}
void hideCloud(int id, int x, int y){
	switch(id){
	case 0:
	oamSet(&oamMain, //main graphics engine context
		1,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxHodeia,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	oamUpdate(&oamMain); 
	break;
	case 1:
	oamSet(&oamMain, //main graphics engine context
		2,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxHodeia,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
break;
case 2:
	oamSet(&oamMain, //main graphics engine context
		3,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxHodeia,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
	break;
case 3:
oamSet(&oamMain, //main graphics engine context
		4,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxHodeia,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain);
break; 
default:
oamSet(&oamMain, //main graphics engine context
		4,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		10,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxHodeia,//+16*16/2,                  //pointer to the loaded graphics
		1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
	}

}




