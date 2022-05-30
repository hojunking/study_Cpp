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

int min_twop(int a, int b); // Returns the smaller of a and b.
int min_onep(int a[]); // Returns the smallest element.
void add(int a[], int b[], int c[]); // Add elements by index.
int length(int a[]); // Return the number of elements
void prettyPrint(int a[], char str[]); // Make str a nice looking
void copy(int a[], int b[]); // Copy a separate array b with the
void resize(int a[], int newLength, int b[]); // Returns a new
void append(int a[], int b[], int c[]); // Make b a single array
void subArray(int a[], int start, int end, int b[]); // Make b a
void makeSorted(int a[]); // Sort ascending using any Sort method.
void sort(int a[], int b[]); // Make b an ascending sorted version
void merge(int a[], int b[], int c[]); // ASSUME a AND b ARE

void main(void)
{
	printf("min_twop(3,4)\t3\t%d\n", min_twop(3,4));
	printf("min_twop(4,3)\t3\t%d\n", min_twop(4,3));
	int a[] = {1,5,3,7,2,65,8,-1};
	int b[] = {9,6,34,23,8,6,5,3,2,-1};
	int c[100];
	char str[200];
	printf("min_onep(a)\t\t1\t%d\n", min_onep(a));
	printf("min_onep(b)\t\t2\t%d\n", min_onep(b));
	add(a, b, c);
	prettyPrint(c, str);
	printf("add(a,b)\t{10,11,37,30,10,71,13,3,2}\t%s\n", str);
	copy(a, c);
	c[0] = 5;
	printf("copy(a)\t\t1\t%d\n", a[0]);
	prettyPrint(c, str);
	printf("c = {5,5,3,7,2,65,8}\t%s\n", str);
	resize(a,3,c);
	prettyPrint(c, str);
	printf("resize(a,3)\t{1,5,3}\t%s\n" , str);
	printf("resize(a,3)\t7\t%d\n", length(a));
	resize(a,9,c);
	prettyPrint(c, str);
	printf("resize(a,9)\t{1,5,3,7,2,65,8,0,0}\t%s\n" , str);
	printf("resize(a,3)\t7\t%d\n", length(a));
	int d[] = {1,2,3,4,-1};
	int e[] = {5,6,7,-1};
	int n[] = {-1}; // null
	append(d, e, c);
	prettyPrint(c, str);
	printf("append(d,e)\t{1,2,3,4,5,6,7}\t%s\n", str);
	printf("append(d,e)\t4\t%d\n" , length(d));
	printf("append(d,e)\t3\t%d\n" , length(e));
	append(n, e, c);
	prettyPrint(c, str);
	printf("append(null,e)\t{5,6,7}\t\t%s\n", str);
	append(d, n, c);
	prettyPrint(c, str);
	printf("append(d,null)\t{1,2,3,4}\t%s\n", str);
	subArray(a, 3, 5, c);
	prettyPrint(c, str);
	printf("subArray(a,3,5)\t{7,2}\t%s\n", str);
	printf("subArray(()\t7\t%d\n", length(a));
	subArray(a, 4, 7, c);
	prettyPrint(c, str);
	printf("subArray(a,4,7)\t{2,65,8}\t%s\n", str);
	subArray(a, 3, 3, c);
	prettyPrint(c, str);
	printf("subArray(a,3,3)\tnull\t%s\n", str);
	subArray(a, 5, 3, c);
	prettyPrint(c, str);
	printf("subArray(a,5,3)\tnull\t%s\n", str);
	 makeSorted(a);
	prettyPrint(a, str);
	printf("makeSorted(a)\t{1,2,3,5,7,8,65}\t%s\n", str);
	sort(b, c);
	prettyPrint(c, str);
	printf("sort(b)\t{2,3,5,6,6,8,9,23,34}\t%s\n", str);
	merge(a, d, c);
	prettyPrint(c, str);
	printf("merge(a,d)\t{1,1,2,2,3,3,4,5,7,8,65}\t%s\n", str);
}

int min_twop(int a, int b) { // Returns the smaller of a and b.
	return (a < b ? a : b);
}
int min_onep(int a[]) {
	int min = INF, i = 0;
	while (a[i] != -1) {
		if (min > a[i])
			min = a[i];
		i++;
	}
	return min;
} // Returns the smallest element.
int length(int a[]) {	// Return the number of elements
	int i = 0;
	while (a[i] != -1) i++;
	return i;
}

void add(int a[], int b[], int c[]) {// Add elements by index.
	int alen = length(a), blen = length(b), i;
	int slen = (alen < blen) ? alen : blen;

	for (i = 0; i < slen; i++)
		c[i] = a[i] + b[i];

	if (alen > blen)
		for (; i < alen + 1; i++) c[i] = a[i];
	else for (; i < blen + 1; i++) c[i] = b[i];

}

void prettyPrint(int a[], char str[]) {// Make str a nice looking
	if (!length(a)) {
		strcpy(str, "null");
		return;
	}

	memset(str, '\0', 200);
	int i = 0;
	str[i++] = 123; //{
	for (int j = 0; j < length(a); j++) {
		int k = 0, tmp = a[j];
		if (a[j] == 0) str[i++] = '0';

		else {
			while (tmp) {
				tmp /= 10;
				k++;
			}
			int s = pow(10, k) / 10;
			tmp = a[j];
			while (k) {
				str[i++] = (tmp / s) + '0';
				k--;
				tmp %= s;
				s /= 10;
			}
		}
		str[i++] = (j < length(a) - 1) ? ',' : '}';
	}
}// string such as "{1,2,3}"

void copy(int a[], int b[]) { // Copy a separate array b with the
	int len = length(a);
	memset(b, 0, len);

	for (int i = 0; i < len; i++)
		b[i] = a[i];
	b[len] = -1;
}// same elements of a.

void resize(int a[], int newLength, int b[]) {
	int i = 0;

	while (i < length(a))
		b[i] = a[i++];
	while (i < newLength)
		b[i++] = 0;

	b[newLength] = -1;
} // Returns a new

void append(int a[], int b[], int c[]) {
	int i = 0, j = 0;

	while (i < length(a))
		c[i] = a[i++];

	while (j < length(b))
		c[i++] = b[j++];
	c[i] = -1;
} // Make b a single array

void subArray(int a[], int start, int end, int b[]) {
	int i = 0;
	while (start < end)
		b[i++] = a[start++];

	b[i] = -1;
} // Make b a

void makeSorted(int a[]) {
	int tmp, n = length(a);

	//selection
	for (int i = 0; i < n - 1; i++) {
		int lowest = i;
		for (int j = i + 1; j < n; j++)
			if (a[lowest] > a[j])
				lowest = j;
		if (i != lowest)
			SWAP(a[lowest], a[i], tmp);
	}
	//bubble
	for (int i = n - 1; 0 < i; i--)
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
				SWAP(a[j], a[j + 1], tmp);

	//insertion
	for (int i = 0; i < n; i++)
		for (int j = i; 0 < j; j--)
			if (a[j] < a[j - 1])
				SWAP(a[j], a[j - 1], tmp);

	/*for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");*/
} // Sort ascending using any Sort method.
void sort(int a[], int b[]) {
	int tmp, n = length(a);

	for (int i = 0; i < n; i++)
		for (int j = i; 0 < j; j--)
			if (a[j] < a[j - 1])
				SWAP(a[j], a[j - 1], tmp);

	for (int i = 0; i < n; i++) {
		int least = i;
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
				least = j;
		if (least != i)
			SWAP(a[i], a[least], tmp);
	}

	int j;
	for (j = 0; j < n; j++)
		b[j] = a[j];
	b[j] = -1;
}; // Make b an ascending sorted version
void merge(int a[], int b[], int c[]) {
	int alen = length(a), blen = length(b);
	int i = 0, k = 0, j = 0;

	while ((i < alen) && (j < blen)) {
		if (a[i] < b[j])
			c[k++] = a[i++];
		else c[k++] = b[j++];
	}
	while (i < alen)
		c[k++] = a[i++];

	while (j < blen)
		c[k++] = b[j++];

	c[k] = -1;
} // ASSUME a AND b ARE