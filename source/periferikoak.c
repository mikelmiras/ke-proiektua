/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"


int tekla; //sakatutako tekla gordetzeko aldagaia



int TeklaDetektatu() 
{
	//TRUE itzultzen du teklaren bat sakatu dela detektatzen badu
	if ((~TEKLAK_DAT & 0x03ff)!=0) return 1;
	else return 0;

}

int SakatutakoTekla() 
{
	int tekla = -1;
	//Sakatutako teklaren balioa itzultzen du: A=0;B=1;Select=2;Start=3;Esk=4;Ezk=5;
	//Gora=6;Behera=7;R=8;L=9;
	if ((~TEKLAK_DAT) & (0x1<<A) ) tekla = A;
	else if ((~TEKLAK_DAT) & (0x1<<B)) tekla = B;
	else if ((~TEKLAK_DAT) & (0x1<<SELECT)) tekla = SELECT;
	else if ((~TEKLAK_DAT) & (0x1<<START)) tekla = START;	
	else if ((~TEKLAK_DAT) & (0x1<<ESKUBI)) tekla = ESKUBI;
	else if ((~TEKLAK_DAT) & (0x1<<EZKER)) tekla = EZKER;
	else if ((~TEKLAK_DAT) & (0x1<<GORA)) tekla = GORA;
	else if ((~TEKLAK_DAT) & (0x1<<BEHERA)) tekla = BEHERA;
	else if ((~TEKLAK_DAT) & (0x1<<R)) tekla = R;
	else if ((~TEKLAK_DAT) & (0x1<<L)) tekla = L;
	return tekla;	
}

void konfiguratuTeklatua(int TEK_konf)
{
	//Teklatuaren konfigurazioa bere S/I erregistroak aldatuz
	TEKLAK_KNT |= TEK_konf;
}

void konfiguratuTenporizadorea(int Latch, int TENP_konf)
{
	//Tenporizadorearen konfigurazioa bere S/I erregistroak aldatuz
	DENB0_DAT = Latch;
	DENB0_KNT |= TENP_konf;
	
}

void TekEtenBaimendu()
{
	//Teklatuaren etenak baimendu
	//Lan hau burutzeko lehenengo eten guztiak galarazi behar dira eta bukaeran baimendu 
	IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	IE |= (0x1<<12);
	TEKLAK_KNT |= (0x1<<14);
	IME=1;
}

void TekEtenGalarazi()
{

	//Teklatuaren etenak galarazi
	//Lan hau burutzeko lehenengo eten guztiak galarazi behar dira eta bukaeran baimendu 
	IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	IE &= ~(0x1<<12);
	TEKLAK_KNT &= ~(0x1<<14);
	IME=1;
}  

void DenbEtenBaimendu()
{

//Denboragailu baten etenak baimendu (Timer0)
//Horretarako lehenengo eten guztiak galarazi eta bukaeran berriro baimendu
	IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	IE |= (0X1<<2);
	IME=1;
}

void DenbEtenGalarazi()
{

//Denboragailu baten etenak galarazi (Timer0)
//Horretarako lehenengo eten guztiak galarazi eta bukaeran berriro baimendu
	IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	IE &= ~(0X1<<2);
	IME=1;

}

void ErlojuaMartxanJarri()
{
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	DENB0_KNT |= (0X1<<6);
	
}

void ErlojuaGelditu()
{
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	DENB0_KNT &= ~(0X1<<6);
}
