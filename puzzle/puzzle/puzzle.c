#include <stdio.h>
#include <stdlib.h> //system();
#include <math.h>
#include <time.h>

#define SIZE 3
#define SPACE SIZE*SIZE

int puzzle[SIZE][SIZE];
int ci, cj;

void init(void) {
	int cnt = 1;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			puzzle[i][j] = cnt++;
	ci = cj = SIZE - 1; 
}

void printP(void) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("+----");
		printf("+\n");

		for (int j = 0; j < SIZE; j++)
			printf("|    ");
		printf("|\n");

		for (int j = 0; j < SIZE; j++)
			if (puzzle[i][j] == SPACE)
				printf("|    ");
			else
				printf("| %2d ", puzzle[i][j]);
		printf("|\n");
		for (int j = 0; j < SIZE; j++)
			printf("|    ");
		printf("|\n");
	}
	for (int j = 0; j < SIZE; j++)
		printf("+----");
	printf("+\n");
}
void swap(int d) {
	// d = 0 , 3 , 6 ,9
	switch (d) {
	case 0:
		if (ci == 0) break;
		puzzle[ci][cj] = puzzle[ci - 1][cj]; // ¾Æ·¡·Î ÇÑ Ä­
		puzzle[ci-1][cj] = SPACE;
		ci--;
		break;
	case 3:
		if (cj == SIZE-1) break;
		puzzle[ci][cj] = puzzle[ci][cj+1]; // ¿À¸¥ÂÊ ÇÑ Ä­
		puzzle[ci][cj+1] = SPACE;
		cj++;
		break;
	case 6:
		if (ci == SIZE - 1) break;
		puzzle[ci][cj] = puzzle[ci + 1][cj]; // À§·Î ÇÑ Ä­
		puzzle[ci + 1][cj] = SPACE;
		ci++;
		break;
	case 9:
		if (cj == 0) break;
		puzzle[ci][cj] = puzzle[ci][cj-1]; // ¿ÞÂÊ ÇÑ Ä­
		puzzle[ci][cj-1] = SPACE;
		cj--;
		break;
	default:
		break;
	}


}

void shuffle(void) { //ÆÛÁñ ÃÊ±âÈ­
	srand(time(NULL));
	init();
	for (int i = 0; i < 1000; i++) {
		int d = (rand() % 4) * 3;
		swap(d);
	}
}

int uncomplete() {
	int cnt = 1;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (puzzle[i][j] != cnt++)
				return 1;
	return 0;
}
int main(void) {
	int d =0;
	init();
	shuffle();
	system("clear");
	printP();

	while (uncomplete()) {
		char c = getchar();
		if (c == 'i') d = 6;
		else if (c == 'l') d = 9;
		else if (c == 'k') d = 0;
		else if (c == 'j') d = 3;
		else continue;
		swap(d);
		system("clear");
		printP();
	}
	printf("Completed!! \n");
	return 0;
}