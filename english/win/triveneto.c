/*
oooooooo_ooooooo___oooo_oo____oo_ooooooo_ooo____oo_ooooooo_oooooooo____oooo____
___oo____oo____oo___oo__oo____oo_oo______oooo___oo_oo_________oo_____oo____oo__
___oo____oo____oo___oo__oo____oo_oooo____oo_oo__oo_oooo_______oo____oo______oo_
___oo____ooooooo____oo___oo__oo__oo______oo__oo_oo_oo_________oo____oo______oo_
___oo____oo____oo___oo____oooo___oo______oo___oooo_oo_________oo_____oo____oo__
___oo____oo_____oo_oooo____oo____ooooooo_oo____ooo_ooooooo____oo_______oooo____
_______________________________________________________________________________(windows edition)

Triveneto is a startegy game where you have to connect the three regions of the Triveneto: Trentino Alto-Adige, Veneto and Friuli Venezia Giulia in order to make more money as possible

inspired by the table game invented by me
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define R 16
#define C 22

int i, j;
int contabile[6][100];
int capitale = 10000;
int capitale1;
int *pcapitale = &capitale;
int *pcapitale1 = &capitale1;
int mantenimento;
int *pmantenimento = &mantenimento;
int fatturato = 0;
int *pfatturato = &fatturato;
int turnicnt = 0;
int *pturnicnt = &turnicnt;
int spese = 0;
int *pspese = &spese;
int p;
int *prestito = &p;
int bilancio = 0;
int *pbilancio = &bilancio;

void startScreen();
int tri(int *pcapitale, int *map, int *pbilancio);
int interfaccia(int *pcapitale, int *map, int *pbilancio);
int costruzione(int *pcapitale, int *pcostoXcella, int *pmanutenzioneXcella, int *pbilancio, int *map, int *pbanda);
void cercaMap(int *map, int *pstart, int *pstop, int *coordinate);
int distanza(int *coordinate);
int conto(int *pcapitale, int *dist, int *pcostoXcella, int *pmanutenzioneXcella, int *pbilancio, int *pmantenimento, int *pfatturato, int *pbanda, int *pspese);
void bancarotta();
void quickData(int *pcapitale, int *pbilancio, int *prestito);
void resoconto(int *pcapitale, int *pbilancio, int *pcontabile, int *pturnicnt, int *pcapitale1, int *pfatturato, int *pmantenimento, int *pspese, int *prestito);


void ADSL(int *pcapitale, int *map, int *pbilancio);
void R3G(int *pcapitale, int *map, int *pbilancio);
void R4G(int *pcapitale, int *map, int *pbilancio);
void R4GLTE(int *pcapitale, int *map, int *pbilancio);
void fibra(int *pcapitale, int *map, int *pbilancio);
void R5G(int *pcapitale, int *map, int *pbilancio);
void R5GP(int *pcapitale, int *map, int *pbilancio);
void informazioni();
void prestitop(int *pcapitale, int *prestito);
void prestitom(int *pcapitale, int *prestito);


int main(){
    /*
    1 = SILANO
    2= BOLZANO
    3 = CORTINA
    4 = TARVISIO
    5 = TOLMEZZO
    6 = TRENTO
    7 = BELLUNO
    8 = UDINE
    9 = PORDENONE
    10 = GORIZIA
    11 = TREVISO
    12 = LIGNANO
    13 = VERONA
    14 = TRIESTE
    15 = PADOVA
    16 = VENEZIA
    */

    int map[R][C] = {
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,4,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,8,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,
        0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,
        0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,
        0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };

    startScreen();

    while(1){
		*pspese = 0;
		*pcapitale1 = *pcapitale;
		if(tri(pcapitale, (int*)map, pbilancio) == -1){
			exit(0);
		}
		turnicnt++;
		printf("pippo\n");
		resoconto(pcapitale, pbilancio, (int*)contabile, pturnicnt, pcapitale1, pfatturato, pmantenimento, pspese, prestito);

    }
	return 0;
}

void startScreen(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char x;
	system("cls");
	SetConsoleTextAttribute(hConsole,2);
    printf("oooooooo_ooooooo___oooo_oo____oo_ooooooo_ooo____oo_ooooooo_oooooooo____oooo____\n");
    printf("___oo____oo____oo___oo__oo____oo_oo______oooo___oo_oo_________oo_____oo____oo__\n");
    printf("___oo____oo____oo___oo__oo____oo_oooo____oo_oo__oo_oooo_______oo____oo______oo_\n");
    printf("___oo____ooooooo____oo___oo__oo__oo______oo__oo_oo_oo_________oo____oo______oo_\n");
    printf("___oo____oo____oo___oo____oooo___oo______oo___oooo_oo_________oo_____oo____oo__\n");
    printf("___oo____oo_____oo_oooo____oo____ooooooo_oo____ooo_ooooooo____oo_______oooo____\n");
    printf("_______________________________________________________________________________ (windows edition)\n");
    printf("\nTriveneto is a startegy game where you have to connect the three regions of the \nTriveneto: Trentino Alto-Adige, Veneto and Friuli Venezia Giulia in order to make more money as possible\n");
	printf("Commands: w - up; s - down; x - enter\n");
	printf("(specially advised to a younger age for a sane intrduction of the art of capitalism)\n");
    printf("Press any key to continue\n");
	SetConsoleTextAttribute(hConsole,7);
    getch();
    
}


int tri(int *pcapitale, int *map, int *pbilancio){
	int q;
	q = interfaccia(pcapitale, (int*)map, pbilancio);
	return q;
}


int interfaccia(int *pcapitale, int *map, int *pbilancio){


    int selezione=1;
	int esci=0; //all'inizio non voglio uscire dal ciclo
	int codiceTasto;
	
	
	while(!esci){
	    quickData(pcapitale, pbilancio, prestito);
		printf("Choose an option:\n");
		
		if(selezione == 1){
			printf(">>");
		}
		printf(" Build an ADSL networkL\n");
		
		if(selezione == 2){
			printf(">>");
		}
		printf(" Build a 3G network\n");
		
		if(selezione == 3){
			printf(">>");
		}
		printf(" Build a 4G network\n");

        if(selezione == 4){
			printf(">>");
		}
		printf(" Build a 4G LTE network\n");
 
        if(selezione == 5){
			printf(">>");
		}
		printf(" Build fiber optics\n");

        if(selezione == 6){
			printf(">>");
		}
		printf(" Build a 5G network\n");

        if(selezione == 7){
			printf(">>");
		}
		printf(" Build a 5G+ network\n");
		
		if(selezione == 8){
			printf(">>");
		}
		printf(" Informations\n");
  
        if(selezione == 9){
			printf(">>");
		}
		printf(" Take a loan\n");
        
        if(selezione == 10){
			printf(">>");
		}
		printf(" Pay a loan\n");

		if(selezione == 11){
			printf(">>");
		}
		printf(" Next turn\n");

		if(selezione == 12){
			printf(">>");
		}
		printf(" Exit\n");		
		codiceTasto = getch();
		
		switch(codiceTasto) {
		    case 'w':{ // key up
		    	selezione--;
		    	
		    	if(selezione == 0){ //se sforo verso l'alto, ricomincio dal fondo
					selezione = 12;
		    	}
		    	break;
		    }    		        
		    case 's': { // key down	
				selezione++;
				if(selezione == 13){ //se sforo verso il basso, ricomincio dall'alto
					selezione = 1;
				}			
		    	break;
		    }  
		    case 'x':{ //enter
				
				switch(selezione){
					case 1:{
						ADSL(pcapitale, (int*)map, pbilancio);
						break; //uscire dallo switch
					}
					case 2:{
						R3G(pcapitale, (int*)map, pbilancio);
						break; //uscire dallo switch
					}
					case 3:{
						R4G(pcapitale, (int*)map, pbilancio);
						break; //uscire dallo switch
					}
                    case 4:{
						R4GLTE(pcapitale, (int*)map, pbilancio);
						break; //uscire dallo switch
					}
					case 5:{
						fibra(pcapitale, (int*)map, pbilancio);
						break;				
					}
                    case 6:{
						R5G(pcapitale, (int*)map, pbilancio);
						break;				
					}
                    case 7:{
						R5GP(pcapitale, (int*)map, pbilancio);
						break;				
					}
                    case 8:{
						informazioni();
						break;				
					}
                    case 9:{
						prestitop(pcapitale, prestito);
						break;				
					}
                    case 10:{
						prestitom(pcapitale, prestito);
						break;				
					}
					case 11:{
						return 1;
						break;
					}
					case 12:{
						return -1;
						break;				
					}
				}
				
		    	break;
		    }
		}
	}
}

int costruzione(int *pcapitale, int *pcostoXcella, int *pmanutenzioneXcella, int *pbilancio, int *map, int *pbanda){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int coordinate[4], start, stop;
	int *pstart = &start;

    int selezione=1;
	int esci=0; //all'inizio non voglio uscire dal ciclo
	int codiceTasto;

	while(!esci){
	    quickData(pcapitale, pbilancio, prestito);
		printf("Choose the starting point\n");
				
		if(selezione == 1){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,1);
		printf(" Silano\n");
		SetConsoleTextAttribute(hConsole,7);		
		
		if(selezione == 2){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,1);
		printf(" Bolzano\n");
		SetConsoleTextAttribute(hConsole,7);

        if(selezione == 3){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Cortina\n");
		SetConsoleTextAttribute(hConsole,7);

        if(selezione == 4){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Tarvisio\n");
		SetConsoleTextAttribute(hConsole,7);

        if(selezione == 5){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Tolmezzo\n");
		SetConsoleTextAttribute(hConsole,7);

        if(selezione == 6){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,1);
		printf(" Trento\n");
		SetConsoleTextAttribute(hConsole,7);
		
		if(selezione == 7){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Belluno\n");
		SetConsoleTextAttribute(hConsole,7);
        
        if(selezione == 8){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Udine\n");
		SetConsoleTextAttribute(hConsole,7);
        
        if(selezione == 9){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Pordenone\n");
		SetConsoleTextAttribute(hConsole,7);
		
		if(selezione == 10){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Gorizia\n");
		SetConsoleTextAttribute(hConsole,7);

		if(selezione == 11){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Treviso\n");
		SetConsoleTextAttribute(hConsole,7);
		
		if(selezione == 12){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Lignano\n");
		SetConsoleTextAttribute(hConsole,7);

		if(selezione == 13){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Verona\n");
		SetConsoleTextAttribute(hConsole,7);

		if(selezione == 14){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Trieste\n");
		SetConsoleTextAttribute(hConsole,7);

		if(selezione == 15){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Padova\n");
		SetConsoleTextAttribute(hConsole,7);

		if(selezione == 16){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Venezia\n");
		SetConsoleTextAttribute(hConsole,7);


		codiceTasto = getch();
		
		switch(codiceTasto) {
		    case 'w':{ // key up
		    	selezione--;
		    	
		    	if(selezione == 0){ //se sforo verso l'alto, ricomincio dal fondo
					selezione = 16;
		    	}
		    	break;
		    }    		        
		    case 's': { // key down	
				selezione++;
				if(selezione == 17){ //se sforo verso il basso, ricomincio dall'alto
					selezione = 1;
				}			
		    	break;
		    }  
		    case 'x':{ //enter

				start = selezione;
				
				esci = 1;
		    	break;
		    }
		}
	}
	
    selezione=1;
	esci=0; //all'inizio non voglio uscire dal ciclo
	codiceTasto;
	
	while(!esci){
	    quickData(pcapitale, pbilancio, prestito);
		printf("Choose the destination\n");
				
		if(selezione == 1){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,1);
		printf(" Silano\n");
		SetConsoleTextAttribute(hConsole,7);		
		
		if(selezione == 2){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,1);
		printf(" Bolzano\n");
		SetConsoleTextAttribute(hConsole,7);

        if(selezione == 3){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Cortina\n");
		SetConsoleTextAttribute(hConsole,7);

        if(selezione == 4){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Tarvisio\n");
		SetConsoleTextAttribute(hConsole,7);

        if(selezione == 5){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Tolmezzo\n");
		SetConsoleTextAttribute(hConsole,7);

        if(selezione == 6){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,1);
		printf(" Trento\n");
		SetConsoleTextAttribute(hConsole,7);
		
		if(selezione == 7){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Belluno\n");
		SetConsoleTextAttribute(hConsole,7);
        
        if(selezione == 8){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Udine\n");
		SetConsoleTextAttribute(hConsole,7);
        
        if(selezione == 9){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Pordenone\n");
		SetConsoleTextAttribute(hConsole,7);
		
		if(selezione == 10){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Gorizia\n");
		SetConsoleTextAttribute(hConsole,7);

		if(selezione == 11){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Treviso\n");
		SetConsoleTextAttribute(hConsole,7);
		
		if(selezione == 12){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Lignano\n");
		SetConsoleTextAttribute(hConsole,7);

		if(selezione == 13){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Verona\n");
		SetConsoleTextAttribute(hConsole,7);

		if(selezione == 14){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,2);
		printf(" Trieste\n");
		SetConsoleTextAttribute(hConsole,7);

		if(selezione == 15){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Padova\n");
		SetConsoleTextAttribute(hConsole,7);

		if(selezione == 16){
			printf(">>");
		}
		SetConsoleTextAttribute(hConsole,4);
		printf(" Venezia\n");
		SetConsoleTextAttribute(hConsole,7);


		codiceTasto = getch();
		
		switch(codiceTasto) {
		    case 'w':{ // key up
		    	selezione--;
		    	
		    	if(selezione == 0){ //se sforo verso l'alto, ricomincio dal fondo
					selezione = 16;
		    	}
		    	break;
		    }    		        
		    case 's': { // key down	
				selezione++;
				if(selezione == 17){ //se sforo verso il basso, ricomincio dall'alto
					selezione = 1;
				}			
		    	break;
		    }  
		    case 'x':{ //enter

				stop = selezione;
				int *pstop = &stop;
				if(start == stop){
					quickData(pcapitale, pbilancio, prestito);
					printf("The starting point and the destination is the same\n");
					Sleep(2000);
					return -1;
				}
				cercaMap((int*)map, pstart, pstop, coordinate);
				int d = distanza(coordinate);
				int *dist = &d; 
				if(!conto(pcapitale, dist, pcostoXcella, pmanutenzioneXcella, pbilancio, pmantenimento, pfatturato, pbanda, pspese)){
					return- 1;
				}
				esci = 1;
		    	break;
		    }
		}
	}
}

void cercaMap(int *map, int *pstart, int *pstop, int *coordinate){
	int go = 0;
	for(i=0; i<R; i++){
		for (j=0; j<C; j++){
			if((*(map + i*R + j) == *pstart || *(map + i*R + j) == *pstop) && go == 0){
				*coordinate = j;
				*(coordinate + 1) = i;
				go = 1;
			}
			if((*(map + i*R + j) == *pstart || *(map + i*R + j) == *pstop) && go == 1){
				*(coordinate + 2) = j;
				*(coordinate + 3) = i;
			}

		}
	}
}

int distanza(int *coordinate){
	int d;

	//pitagora
	d = sqrt(pow((*coordinate - *(coordinate + 2)), 2) + pow((*(coordinate + 1) - *(coordinate + 3)), 2));
	return d;
}

int conto(int *pcapitale, int *dist, int *pcostoXcella, int *pmanutenzioneXcella, int *pbilancio, int *pmantenimento, int *pfatturato, int *pbanda, int *spese){
	int costo = *pcostoXcella * *dist;
	int costoXturno = *pmanutenzioneXcella * *dist; 
	

    int selezione=1;
	int esci=0; //all'inizio non voglio uscire dal ciclo
	int codiceTasto;

	while(!esci){
		quickData(pcapitale, pbilancio, prestito);
		printf("The cost of construction is: $%d\n", costo);
		printf("The cost of maintenance is: $%d a turno\n\n", costoXturno);
		printf("proceed with the purchase?\n");
		
		if(selezione == 1){
			printf(">> ");
		}
		printf("Yes\n");
		
		if(selezione == 2){
			printf(">> ");
		}
		printf("No\n");
		
		
		
		codiceTasto = getch();
		
		switch(codiceTasto) {
		    case 'w':{ // key up
		    	selezione--;
		    	
		    	if(selezione == 0){ //se sforo verso l'alto, ricomincio dal fondo
					selezione = 2;
		    	}
		    	break;
		    }    		        
		    case 's': { // key down	
				selezione++;
				if(selezione == 3){ //se sforo verso il basso, ricomincio dall'alto
					selezione = 1;
				}			
		    	break;
		    }  
		    case 'x':{ //enter
				
				switch(selezione){
					case 1:{
						if((pcapitale - costo) < 0){
							printf("This network is too expensive\n");
							Sleep(2000);
							return -1;
						}
						*pmantenimento += *pmanutenzioneXcella * *dist;
						*pfatturato += *pbanda;
						*pcapitale -= costo;
						*pspese += costo;
						return 0;
					}
					case 2:{
						return -1;
					}
				}
				
		    	break;
		    }
		}
	}	

}

void ADSL(int *pcapitale, int *map, int *pbilancio){
	int costoXcella = 100, manutenzioneXcella = 1, banda = 6;
	int *pcostoXcella = &costoXcella, *pmanutenzioneXcella = &manutenzioneXcella, *pbanda = &banda;
	costruzione(pcapitale, pcostoXcella, pmanutenzioneXcella, pbilancio, (int*)map, pbanda);
}

void R3G(int *pcapitale, int *map, int *pbilancio){
	int costoXcella = 50, manutenzioneXcella = 3, banda = 14;
	int *pcostoXcella = &costoXcella, *pmanutenzioneXcella = &manutenzioneXcella, *pbanda = &banda;
	costruzione(pcapitale, pcostoXcella, pmanutenzioneXcella, pbilancio, (int*)map, pbanda);
}

void R4G(int *pcapitale, int *map, int *pbilancio){
	int costoXcella = 150, manutenzioneXcella = 5, banda = 50;
	int *pcostoXcella = &costoXcella, *pmanutenzioneXcella = &manutenzioneXcella, *pbanda = &banda;
	costruzione(pcapitale, pcostoXcella, pmanutenzioneXcella, pbilancio, (int*)map, pbanda);
}

void R4GLTE(int *pcapitale, int *map, int *pbilancio){
	int costoXcella = 175, manutenzioneXcella = 13, banda = 200;
	int *pcostoXcella = &costoXcella, *pmanutenzioneXcella = &manutenzioneXcella, *pbanda = &banda;
	costruzione(pcapitale, pcostoXcella, pmanutenzioneXcella, pbilancio, (int*)map, pbanda);
}

void fibra(int *pcapitale, int *map, int *pbilancio){
	int costoXcella = 300, manutenzioneXcella = 10, banda = 500;
	int *pcostoXcella = &costoXcella, *pmanutenzioneXcella = &manutenzioneXcella, *pbanda = &banda;
	costruzione(pcapitale, pcostoXcella, pmanutenzioneXcella, pbilancio, (int*)map, pbanda);
}

void R5G(int *pcapitale, int *map, int *pbilancio){
	int costoXcella = 200, manutenzioneXcella = 15, banda = 1000;
	int *pcostoXcella = &costoXcella, *pmanutenzioneXcella = &manutenzioneXcella, *pbanda = &banda;
	costruzione(pcapitale, pcostoXcella, pmanutenzioneXcella, pbilancio, (int*)map, pbanda);
}

void R5GP(int *pcapitale, int *map, int *pbilancio){
	int costoXcella = 250, manutenzioneXcella = 17, banda = 2000;
	int *pcostoXcella = &costoXcella, *pmanutenzioneXcella = &manutenzioneXcella, *pbanda = &banda;
	costruzione(pcapitale, pcostoXcella, pmanutenzioneXcella, pbilancio, (int*)map, pbanda);
}

void informazioni(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do{
		quickData(pcapitale, pbilancio, prestito);

		SetConsoleTextAttribute(hConsole,2);
		printf("            COST PER CELL     MAINTENANCE PER CELL     BANDWIDTH\n");
		printf("RETE ADSL   $         100                        1            6\n");
		printf("RETE 3G     $          50                        3           14\n");
		printf("RETE 4G     $         150                        5           50\n");
		printf("RETE 4G LTE $         175                       13          200\n");
		printf("FIBRA       $         300                       10          500\n");
		printf("RETE 5G     $         200                       15         1000\n");
		printf("RETE 5G+    $         250                       17         2000\n");
		SetConsoleTextAttribute(hConsole,7);
	
		printf("\n>> ok");
	}while(getch() != 'x');
}

void prestitop(int *pcapitale, int *prestito){
	do{	
		quickData(pcapitale, pbilancio, prestito);
		printf("Choose the amount to borrow greater than 100\n");
		printf("interest: 1% / per turn\n");
		scanf("%d", prestito);
	}while (p < 100);
	*pcapitale += *prestito;
}

void prestitom(int *pcapitale, int *prestito){
	int p;
	if(*prestito > 0){	
		do{	
			quickData(pcapitale, pbilancio, prestito);
			printf("Choose the amount to pay\n");
			scanf("%d", &p);
			if (p > *prestito){
				printf("banks already have lots of money, no need to give them more\n");
			}

		}while (p < 0 && p > *prestito);
		*pcapitale -= p;
		*prestito -= p;
	} else {
		quickData(pcapitale, pbilancio, prestito);
		printf("You are not in debt, you ask for a loan to get yourself completely fuc... er, I mean, to start your business\n");
		Sleep(3000);
	}
}

void bancarotta(){
	printf("You went bankrupt and failed to connect the Triveneto\n");
	printf("bruh\n");
	Sleep(2000);
	exit(0);
}

void quickData(int *pcapitale, int *pbilancio, int *prestito){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	printf("CAPITALE $%d     ", *pcapitale);
	if(*pbilancio >= 0){
		SetConsoleTextAttribute(hConsole,2);
		printf("BILANCIO: $%d     ", *pbilancio);
		SetConsoleTextAttribute(hConsole,7);
	} else {
		SetConsoleTextAttribute(hConsole,4);
		printf("BILANCIO: $%d     ", *pbilancio);
		SetConsoleTextAttribute(hConsole,7);
	}
	printf("DEBITO: $%d\n\n", *prestito);
}

void resoconto(int *pcapitale, int *pbilancio, int *contabile, int *pturnicnt, int *pcapitale1, int *pfatturato, int *pmantenimento, int *pspese, int *prestito){
	*pcapitale -= *pmantenimento;
	*pcapitale += *pfatturato;
	*pcapitale -= (*prestito / 100);

	*(contabile + *pturnicnt) = *pcapitale1;
	*(contabile + 100 + *pturnicnt) = *pfatturato;
	*(contabile + 200 + *pturnicnt) = *pmantenimento;
	*(contabile + 300 + *pturnicnt) = *pspese;
	*(contabile + 400 + *pturnicnt) = (*prestito / 100);
	*(contabile + 500 + *pturnicnt) = *pcapitale;
	
	*pbilancio = *pcapitale - *pcapitale1;

	if(*pcapitale < 0){
		bancarotta();
	}
}