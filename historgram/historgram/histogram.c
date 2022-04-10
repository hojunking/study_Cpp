#include <stdio.h>	
#include <time.h>
#include <math.h>
#define MAXSIZE 500
#define COUNTSIZE 10
#define max(a,b)  (((a) > (b)) ? (a) : (b))

void normal(int count[], int data[]) {
	printf("\t[히스토그램]\n");
	for (int i = 0; i < 10; i++)
		printf("\t% d | %d\n", i, count[i]);
	printf("\n");
}

void graph1(int count[],int data[]) {
	printf("\n\t[히스토그램 v1.0]\n");
	for (int i = 0; i < 10; i++) {

		printf("  %d | ", i);
		for (int j = 0; j < count[i]; j++)
			printf("*");
		printf("\n");
	}
	printf("\n");

}

void graph2(int count[], int data[]) {
	printf("\n\t[히스토그램 v2.0]\n");
	for (int i = 9; 0 <= i; i--) {

		if (i == 0) printf("  +");
		else printf("% d |", i);
		
		for (int j = 0;  j <10 ; j++) {
			if(i==0) printf("---");
			else{
				if (i <= count[j])
					printf("  *");
				else if (i == count[j] + 1)
					printf("  %d", count[j]);
				else
					printf("   ");
			}
		}
			printf("\n");
	}
	printf("      0  1  2  3  4  5  6  7  8  9\n");
}

void graph3(int count[], int data[]) {
	printf("\n\t[히스토그램 v3.0]\n");
	for (int i = 9; 0 <= i; i--) {

		if (i == 0) printf("   +");
		else if(i==5) printf("% d |", i);
		else printf("   |");

		for (int j = 0; j < 10; j++) {
			if (i == 0) printf("---");
			else {
				if (i <= count[j])
					printf("  %d",i);
				else
					printf("   ");
			}
		}
		printf("\n");
	}
	printf("      0  1  2  3  4  5  6  7  8  9\n");

}

void graph4(int count[], int data[], int size, int high) {
	double top = (double) high / size;
	int i = (top * 100 + 1) / 2;
	printf("%d %lf\n", i, top);
	printf("\n\t[히스토그램 v4.0]\n");
	for (; 0 <= i; i--) {

		if (i == 0) printf("      +");
		else printf("% .2lf | ", (double)i/100*2);

		for (int j = 0; j < 10; j++) { 
			if (i == 0) printf("----");
			else {
				double per = (double)count[j] / size;
				if (per - 0.0199 >= (double)i / 100 * 2) //소수점 반올림 때문
					printf("| |");
				else if (per > (double)i / 100 * 2)
					printf("+-+");
				else if (per == (double)i / 100 * 2)
					printf("+-+");
				else
					printf("   ");
			}
		}
		printf("\n");
	}
	printf("         0  1  2  3  4  5  6  7  8  9\n");
}


int main(void) {

	int data[MAXSIZE];
	int count[COUNTSIZE] = {0};
	int size;
	
	while (1) {
		printf("데이터의 개수를 입력하시오 (0:종료, 30 <= x <= 500): ");
		scanf_s("%d", &size);
		if (size == 0) break;
		else if (size < 30) {
			continue;
		}
		else if (size < 500) {
			srand(time(NULL));
			printf("\t[원 랜덤 데이터]\n");
			for (int i = 0; i < size; i++)
				data[i] = rand() % 10;

			for(int i =0; i <size; i++){
				printf("%5d", data[i]);
				if(i % 10 == 9) puts("");
			}
			int  cnt= 0;
			for (int i = 0; i < size; i++)
				data[i] == count[data[i]]++;

			//count의 최대값
			int high = 0;
			for (int i = 0; i < COUNTSIZE; i++)
				high = max(count[i], high);


			normal(count, data);
			graph2(count, data);
			graph1(count, data);
			graph2(count, data);
			graph3(count, data);
			graph4(count, data, size, high);
		}
	}
}