#include <stdio.h>

int readInput(FILE* input, char* plek);
char winner(char* plek);
int prettyPrint(char* plek);
int cheatDetection(char* plek, int length);

int main(){
	extern FILE* stdin;
	char lijst[11]; 

	if(readInput(stdin, lijst)){
		return 1;
	}
	prettyPrint(lijst);
	cheatDetection(lijst, 11);
	printf("%c\n", winner(lijst));
	return 0;
}

int prettyPrint(char* plek){
	printf(" %c | %c | %c \n", plek[0], plek[1], plek[2]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", plek[3],plek[4],plek[5]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", plek[6],plek[7],plek[8]);
	return 0;
}

int cheatDetection(char* plek, int length){
	int counterX = 0;
	int counterO = 0;
	

	for(int i=0; i < length; i++){
		if (plek[i] == 'X'){
			counterX ++;
		}
		if (plek[i] == 'O'){
			counterO ++;
		}
	}

	if (counterX ==6 || (counterX - counterO) >= 2) {
		printf("X Cheated \n");
	}

	if (counterO ==6 || (counterO - counterX) >= 2) {
		printf("O Cheated \n");
	}
	return 0;
}

int readInput(FILE* input, char* plek){
	int i = 0;
	char c;
	extern FILE* stderr;

	while((c = fgetc(input)) != EOF){
		plek[i] = c;
		i++;
		if (i > 10){
			fputs("Error, too many chars\n", stderr);
			return 1;
		}
	}
	plek[10] = '\0';
	return 0;

}

char winner(char* plek){
	if(plek[0] == 'X' && plek[1] =='X' && plek[2] =='X'){
		return 'X';
	}
	if(plek[3] =='X' && plek[4] =='X' && plek[5] =='X'){
		return 'X';
	}
	if(plek[6] =='X' && plek[7] =='X' && plek[8] =='X'){
		return 'X';
	}

	if(plek[0] =='X' && plek[3] =='X' && plek[6] =='X'){
		return 'X';
	}
	if(plek[1] =='X' && plek[4] =='X' && plek[7] =='X'){
		return 'X';
	}
	if(plek[2] =='X' && plek[5] =='X' && plek[8] =='X'){
		return 'X';
	}

	if(plek[0] =='X' && plek[4] =='X' && plek[8] =='X'){
		return 'X';
	}
	if(plek[2] =='X' && plek[4] =='X' && plek[6] =='X'){
		return 'X';
	}

	if(plek[0] =='O' && plek[1] =='O' && plek[2] =='O'){
		return 'O';
	}
	if(plek[3] =='O' && plek[4] =='O' && plek[5] =='O'){
		return 'O';
	}
	if(plek[6] =='O' && plek[7] =='O' && plek[8] =='O'){
		return 'O';
	}

	if(plek[0] =='O' && plek[3] =='O' && plek[6] =='O'){
		return 'O';
	}
	if(plek[1] =='O' && plek[4] =='O' && plek[7] =='O'){
		return 'O';
	}
	if(plek[2] == 'O' && plek[5] =='O' && plek[8] =='O'){
		return 'O';
	}

	if(plek[0] =='O' && plek[4] =='O' && plek[8] =='O'){
		return 'O';
	}
	if(plek[2] =='O' && plek[4] =='O' && plek[6] =='O'){
		return 'O';
	}
	if(plek[0] =='E' && plek[1] =='E' && plek[2] =='E' && plek[3] =='E' && 
	plek[4] =='E' && plek[5] =='E' && plek[6] =='E' && plek[7] =='E' && plek [8] == 'E'){
		printf("Empty game");
	}
	else {
		printf("No winners");
	}
}
