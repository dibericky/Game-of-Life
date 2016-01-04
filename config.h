#define N 20
typedef struct{
	int value;
	int whatToDo; //0: nulla  -1: die   1: born
} Cella;
void setRandomCellule(Cella c[][N]){
	int x = 0;
	int y = 0;
	for(x = 0; x < N; x++){
		for(y = 0; y < N; y++){
			if((rand()%30)%8 == 0){
				(c[x][y]).value = 1;
			}else{
				(c[x][y]).value = 0;
			}
			(c[x][y]).whatToDo = 0;
		}
		
	}
}
void printCellule(Cella c[][N]){
	int i, j;
	printf("\n\n\n");
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%5d", (c[i][j]).value);
		}
		printf("\n\n");
	}
	
}
//4-8 cellule vicine -> morte per sovraffollamento
//0 o 1 cellula vicina -> morte per desertificazione
//3 cellule vicine -> nascita cella
void manageCellule(Cella c[][N], int row, int col, int nVicine){
	if(nVicine == 0 || nVicine == 1 || nVicine > 4 ){
		(c[row][col]).whatToDo = -1;
	}else if(nVicine == 3){
		(c[row][col]).whatToDo = 1;
	}else{
		(c[row][col]).whatToDo = 0;
	}
}
/*
# # #
# @ #
# # #
*/
void checkCellule(Cella c[][N]){
	int x, y;
	int what = 0;
	for(x = 0; x < N; x++){
		for(y = 0; y < N; y++){
			what = c[x][y].whatToDo;
			if(what == 1){
				c[x][y].value = 1;
			}else if(what == -1){	
				c[x][y].value = 0;
			}
			c[x][y].whatToDo = 0;
		}
	}
}
int celluleVicine(Cella c[][N], int row, int col){
	int n = 0;
	Cella cella;
	if(row > 0){
		//controllo row-1
		cella = c[row-1][col];
		if(cella.value == 1){
			n++;
		}
		if(col > 0){
			cella = c[row-1][col-1];
			if(cella.value == 1 ){
				n++;
			}
		}
		if(col < N-1){
			cella = c[row-1][col+1];
			if(cella.value == 1 ){
				n++;
			}
		}
	}
	if(row < N-1){
		//controllo row+1
		cella = c[row+1][col];
		if(cella.value == 1 ){
			n++;
		}
		if(col > 0){
			cella = c[row+1][col-1];
			if(cella.value == 1 ){
				n++;
			}
		}
		if(col < N){
			cella = c[row+1][col+1];
			if(cella.value == 1 ){
				n++;
			}
		}
	}
	if(col > 0){  //controllo col-1
		cella = c[row][col-1];
		if(cella.value == 1 ){
			n++;
		}
	}
	if(col < N-1){ //controllo col+1
		cella = c[row][col+1];
		if(cella.value == 1 ){
			n++;
		}
	}
	
	
	return n;
}

