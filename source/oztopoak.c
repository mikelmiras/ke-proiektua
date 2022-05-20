#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"
//Aldagaiak hasieratu, aldagaien informazio zehatza txostenan aurki daiteke
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
	//Funtzio honek for baten bidez hodei guztiak sortzen ditu eta "agerpen puntuan" jartzen ditu
	//partida hasi berri dagoenean
int i;
int pos = 0;
for (i = 0; i < 4; i++){
 updateCloudPos(i, posX[i], posY[i]);
}
}

void moveClouds(int frequency){
 	int i;
	//Funtzio hau denb. eten bakoitzean deitzen da. Hodeiak mugitu eta talkak detektatzen ditu
	for (i = 0; i < 4; i++){
		if ((posX[i] == hegazkinX) && (posY[i] == 160)){
			//Hodeia eta hegazkinaren posizioa bera bada, talka detektatzen da.
			talkak++;
			//Switch honen bidez talkak kudeatzen dira.
			switch (talkak){
				case 1:
				kenduBihotza(5);//Lehenengo biotza ezabatu
				break;
				case 2:
				kenduBihotza(6);//Bigarren biohtza ezabatu
				break;
				case 3:	
				kenduBihotza(7);//Hirugarren bihotza ezabatu eta partida amaitu
				EGOERA = BUKAERA;
				DenbEtenGalarazi(); //Denboragailua kendu moveClouds() funtzioa gehiago ez deitzeko
				//denboragailua aktibatuta egongo balitz, hodeiak mugitzen jarraituko liteke behin
				//partida bukatuta.

				resetCloudstoSpawn();//Hodeien posizioa "agerpen" puntura esartzen ditu, berriz jokatzen badugu
				//aurreko partidan zeukaten posizioa ezabatzeko.
				talkak = 0; //Talkak 0-ra ezarri
				counter_rand = 0; //Counterra berezarri.
				i = 0;
				switchBG(4); //BUKAERA fondoa erakutsi
				hideSprite(0, 112, 80); //Hegazkina ezabatu
				resetTimer(); //Timerra 0-ra jarri
				return;
				break;				
			}
	
		}
		if (talkak == 3){ return; } //Talkak 3 badira, ez da behera jarraituko. Hau ez balego
		//hodeiak ez dira ezabatzen, beheko funtzioek mugitzen dituztelako.
		hideCloud(i, posX[i], posY[i]); //Hodeia okultatu
		posY[i] += abiadura[i]; //Hodeiaren posizioa abiadurarekiko mugitu
		updateCloudPos(i, posX[i], posY[i]); //Erakutsi hodeia bere posizio berrian
		
		if (posY[i] > 192){ //Hodeia "desagertze" puntuan sartzen bada, hurrengoa egin:
			//-- Ausazko metodoa nola egin dugun txostenan azaltzen dugu hobeto --
			int variable = randomArray[counter_rand]; //ausazko bektoretik zenbaki bat atera.
			posY[i] = spawnsY[variable]; //Zenbaki hori erabili "spawn" berri bat aukeratzeko.
			abiadura[i] = 2 + (3*(variable) % 3); //Abiadura berezarri. Abiadura beti 2 eta 4 artean egongo da.
			switch(variable){ //Ausazko aldagaia bidez, "bide" bat aukeratuko da hodeiarentzat.
				case 0:
					posX[i] = 27; //Eskuineko bidea
				break; 
				case 1:
					posX[i] = 112; //Erdiko bidea
				break;
				case 2:
					posX[i] = 197; //Eskubiko bidea
				break;
				default:
					posX[i] = 197;
				
			}
			counter_rand++; //Ausazko aldagaia igo
			if (counter_rand >= 30){ //Ausazko aldagaia 30-era ailegatzen bada
			//(ausazko bektorearen tamaina), ber ezarri.
			counter_rand = 0;
		}
		}
		
	}

}

void hideClouds(){
	// Funtzio honek for baten bidez hodei guztiak eskutatzen ditu aldi berean.
	int i;
	for (i = 0; i < 4; i++){
		hideSprite(i + 1, posX[i], posY[i]);
	}
}
void resetCloudstoSpawn(){
	//Funtzio honek hodeiak pantailaren goiko partean sartzen ditu, partida berri bat asten denean.
	//Ere aldatzen du hodeien posizioa, bestela partida berrian aurreko partidan zeuden bezala
	//agertuko lirateke.
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
	//Funtzio honek hodei guztiak aldi berean erakusten ditu.
	int i;
	for (i = 0; i < 4; i++){
		updateCloudPos(i + 1, posX[i], posY[i]);
	}
}
