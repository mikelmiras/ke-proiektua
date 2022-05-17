#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"

int hegazkinX = 112;
int hegazkinY = 80;
int counter_rand = 0;
int posY[] = {-32, -32, -66, -34};
int posX[] = {27, 112, 197, 27};
int abiadura[] = {1, 3, 2, 3};
int spawnsX[] = {27, 112, 197};
int spawnsY[] = {-32, -64, -64};
int repetition_counter = 0;
int talkak = 0;
int cloudIds[] = {1, 2, 3, 4};
int randomArray[] = {0, 1,0,2, 1, 0, 1, 2, 1, 2,1,0, 2,1,0,0,1,0,1,0,2,0,1,2,1,1,2,0,2,1};
void spawnClouds(){
int i;
int pos = 0;
for (i = 0; i < 4; i++){
 updateCloudPos(i, posX[i], posY[i]);
}
}

void moveClouds(int frequency){
 	int i;
	
	for (i = 0; i < 4; i++){
		if ((posX[i] == hegazkinX) && (posY[i] == 160)){
			talkak++;
			
			switch (talkak){
				case 1:
				kenduBihotza(5);
				break;
				case 2:
				kenduBihotza(6);
				break;
				case 3:	
				kenduBihotza(7);
				EGOERA = BUKAERA;
				DenbEtenGalarazi(); //Works
				resetCloudstoSpawn();//Works
				talkak = 0;
				counter_rand = 0;
				i = 0;
				switchBG(4); //Works
				hideSprite(0, 112, 80); //Works
				resetTimer();
				return;
				break;				
			}
	
		}
		if (talkak == 3){ return; }
		hideCloud(i, posX[i], posY[i]);
		posY[i] += abiadura[i];
		updateCloudPos(i, posX[i], posY[i]);
		
		if (posY[i] > 192){
			int variable = randomArray[counter_rand];
			posY[i] = spawnsY[variable];
			abiadura[i] = 2 + (3*(variable) % 3);
			switch(variable){
				case 0:
					posX[i] = 27;
				break; 
				case 1:
					posX[i] = 112;
				break;
				case 2:
					posX[i] = 197;
				break;
				default:
					posX[i] = 197;
				
			}
			counter_rand++;
			if (counter_rand >= 30){
			counter_rand = 0;
		}
		}
		
	}

}

void hideClouds(){
	int i;
	for (i = 0; i < 4; i++){
		hideSprite(i + 1, posX[i], posY[i]);
	}
}
void resetCloudstoSpawn(){
	int i;
	int Y[] = {-32, -32, -66, -34};
	int X[] = {27, 112, 197, 27};
	for (i = 0; i < 4; i++){
		posX[i] = X[i];
		posY[i] = Y[i];
		hideSprite(i + 1, posX[i], posY[i]);
	}
}
void displayClouds(){
	int i;
	for (i = 0; i < 4; i++){
		updateCloudPos(i + 1, posX[i], posY[i]);
	}
}
int random(int max) {
    srand((unsigned) time(NULL));
    return (rand() % max);
}
