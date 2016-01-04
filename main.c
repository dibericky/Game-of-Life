#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include "config.h"

//4-8 cellule vicine -> morte per sovraffollamento
//0 o 1 cellula vicina -> morte per desertificazione
//3 cellule vicine -> nascita cella


int main(){
	Cella c[N][N];
	setRandomCellule(c);
	printCellule(c);
	int q = 0;
	int a, b, nearCell;
	for(q = 0; q < 50; q++){
		Sleep(300);
		system("cls");
		for(a = 0; a < N; a++){
			for(b = 0; b < N; b++){
				nearCell = celluleVicine(c,a,b);
				manageCellule(c,a,b,nearCell);
			}
		}
		checkCellule(c);
		printCellule(c);
	}
	
	return 0;
}



