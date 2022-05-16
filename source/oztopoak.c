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
int abiadura[] = {4, 6, 4, 9};
int spawnsX[] = {27, 112, 197};
int spawnsY[] = {-32, -64, -64};
int repetition_counter = 0;
int choques = 0;
int cloudIds[] = {1, 2, 3, 4};
int randomArray[] = {0, 1,0,2, 1, 0, 1, 2, 1, 2,1,0, 2,1,0,0,1,0,1,0,2,0,1,2,1,1,2,0,2,1};
void spawnClouds(){
int i;
int pos = 0;
for (i = 2; i < 3; i++){
 updateCloudPos(i, posX[i], posY[i]);
}
}

void moveClouds(int frequency){
 	int i;
	
	for (i = 2; i < 3; i++){
		if ((posX[i] == hegazkinX) && (posY[i] == 160 || posY[i] == 161 || posY[i] == 162)){
			choques++;
			iprintf("\x1b[05;0HTalka egin duzu: %d", choques);
	
		}
		hideCloud(i, posX[i], posY[i]);
		posY[i] += abiadura[i];
		updateCloudPos(i, posX[i], posY[i]);
		
		if (posY[i] > 192){
			int variable = randomArray[counter_rand];
			posY[i] = spawnsY[variable];
			abiadura[i] = 4 + (4*(variable));
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
int random(int max) {
    srand((unsigned) time(NULL));
    return (rand() % max);
}
