#include <stdio.h>

int readInput(FILE* input, char* plek);
char winner(char* plek);

int main(){
	extern FILE* stdin;
	char lijst[11]; 

	if(readInput(stdin, lijst)){
		return 1;
	}

	printf("%c\n", winner(lijst));
	return 0;
}


int readInput(FILE* input, char* plek){
	int i = 0;
	int counterX = 0;
	int counterO = 0;
	char c;
	extern FILE* stderr;

	while((c = fgetc(input)) != EOF){
		plek[i] = c;
		i++;
		if (i > 10){
			fputs("Error, too many chars\n", stderr);
			return 1;
		}
		if (c == 'X'){
			counterX ++;
			if (counterX >= 5){
			printf ("X played unfair \n");
			}
		}
		else{
			return 0;
		}
		if (c == 'O'){
			counterX ++;
				if (counterO >= 5){
				printf ("O played unfair \n");
				}
		}
		else {
			return 0;
		}

	plek[10] = '\0';
	return 0;
}
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
