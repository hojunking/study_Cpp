#include <stdio.h>	
#include <time.h>
#include <math.h>
#define MAXSIZE 500
#define COUNTSIZE 10

void graph1(int count[],int data[]) {
	printf("\n\t[������׷� v1.0]\n");
	for (int i = 0; i < 10; i++) {
		printf("         %d | ", i);
		for (int j = 0; j < count[i]; j++)
			printf("*");
		printf("\n");
	}
}

void graph2(int count[], int data[]) {
	printf("\n\t[������׷� v2.0]\n");
	for (int i = 9; 0 <= i; i--) {
		printf("%d | ", i);
		//for(int j =)
	}
}

int main(void) {

	int data[MAXSIZE];
	int count[COUNTSIZE] = {0};
	int size;
	
	while (1) {
		printf("�������� ������ �Է��Ͻÿ� (0:����, 30 <= x <= 500): ");
		scanf_s("%d", &size);
		if (size == 0) break;
		else if (size < 30) {
			continue;
		}
		else if (size < 500) {
			//srand(time(NULL));
			printf("\t[�� ���� ������]\n");
			for (int i = 0; i < size; i++)
				data[i] = rand() % 10;

			for(int i =0; i <size; i++){
				printf("%5d", data[i]);
				if(i % 10 == 9) puts("");
			}
			int  cnt= 0;
			for (int i = 0; i < size; i++)
				data[i] == count[data[i]]++;
			printf("\t[������׷�]\n");

			for (int i = 0; i < 10; i++)
				printf("         %d | %d\n", i, count[i]);
		
			graph1(count, data);
		}
	}
}