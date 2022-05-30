#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define SWAP(x,y,t) (t=x, x=y, y=t)
#define INF 999
/*
	2020118006_º€»£¡ÿ
*/

void prettyPrint(int a[], char str[]); // Make str a nice looking

void createBin1(int binaryNumber, int bin[]); // The first argument

void createBin2(char binaryNumber[], int bin[]); // The first

int intValue(int b[]); // Given a Binary number, evaluate its


void intToBinary(int a, int b[]); // Converts an integer to

void main(void)
{
	int binaryNumber = 10101010;
	char bString[] = "10101000";
	int bin[8];
	char str[200];
	createBin1(binaryNumber, bin);
	prettyPrint(bin, str);
	printf("createBin(10101010)\t{1,0,1,0,1,0,1,0}\t%s\n", str);
	createBin2(bString, bin);
	prettyPrint(bin, str);
	printf("createBin(10101000)\t{1,0,1,0,1,0,0,0}\t%s\n", str);
	createBin2("00000101", bin);
	printf("intValue(00000101)\t5\t%d\n", intValue(bin));
	createBin2("1111011", bin);
	printf("intValue(11111011)\t-5\t%d\n", intValue(bin));
	intToBinary(7, bin);
	prettyPrint(bin, str);
	printf("intToBinary(7)\t{0,0,0,0,0,1,1,1}\t%s\n", str);
	intToBinary(-7, bin);
	prettyPrint(bin, str);
	printf("intToBinary(-7)\t{1,1,1,1,1,0,0,1}\t%s\n", str);
}


void prettyPrint(int a[], char str[]) {
	memset(str, '\0', 200);
	int i = 0;
	str[i++] = 123;

	for (int j = 0; j < 8; j++) {
		str[i++] = a[j] + '0';
		str[i++] = (j < 7) ? ',' : '}';
	}
}

void createBin1(int binaryNumber, int bin[]) {
	int j = 8;
	for (int i = 7; 0<= i; i--) {
		int mod = pow(10, j - i);
		int div = pow(10, j - i - 1);
		bin[i] = (binaryNumber% mod) / div;
	}
}

void createBin2(char binaryNumber[], int bin[]) {
	int i = 0;
	while (binaryNumber[i]) bin[i] = (int)(binaryNumber[i++] - '0');
}

int intValue(int b[]) {
	int len = 8, value = 0;
	
	if (!b[0]) {
		for (int i = 0; i < len; i++)
			if (b[i]) value += pow(2, len - 1 - i);
	}
	else {
		for (int i = 0; i < len; i++)
			if (b[i] == 0) value -= pow(2, len - 2 - i);
		value--;
	}
	return value;
}

void intToBinary(int a, int b[]) {
	memset(b, 0, 8);
	int i = 0, div;
	if (a > 0) {
		while (i < 8) {
			div = pow(2, 7 - i);
			if (a >= div) {
				a -= div;
				b[i++] = 1;
			}
			else b[i++] = 0;
		}
	}
	else {
		a = ~a;
		while (i < 8) {
			div = pow(2, 7 - i);
			if (a >= div) {
				a -= div;
				b[i++] = 0;
			}
			else b[i++] = 1;
		}
	}
}