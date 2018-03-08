#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "Header.h"
#include <iostream>
using namespace std;
#define max 50

int TaskNumb()
{
	setlocale(LC_ALL, "Rus");
	int task;
	printf("¬ведите номер задани€ - ");
	scanf_s("%d", &task);
	return task;
}

int Surname(char* name1, char* name2)
{
	printf("\nEnter 1st surname - ");
	fgets(name1, max, stdin);
	printf("\nEnter 2nd surname - ");
	fgets(name2, max, stdin);
	printf("1st = %d, 2nd = %d\n", (strlen(name1) - 1), (strlen(name2) - 1));
	if (strlen(name1) > strlen(name2))
		return 1;
	else
		return 0;
}
void ArrFilling(char *arr)
{

}

void ArrFilling(char *arr, int *length)
{
	printf("\nEnter a name - ");
	fgets(arr, max, stdin);
	*length = strlen(arr) - 1;
}

int WhoIsBigger(int * length1, int *length2, int *length3)
{
	if (*length1 > *length2 && *length1 > *length3)
		return 1;
	else if (*length2 > *length1 && *length2 > *length3)
		return 2;
	else if (*length3 > *length2 && *length3 > *length1)
		return 3;
	else if (*length3 == *length2 || *length2 == *length1)
		return 4;
	else
		return 5;
}

void PrintSymbols(char *arr, int * length, int * numb)
{
	for (int i = 0; i < *length; i++)
	{
		if (i == *numb)
			printf("%d-й символ это %c\n", *numb, arr[i - 1]);
	}
}

void ArrChange(char *arr, int start, int end, int numb)
{
	for (int i = 0; i <= 256; i++)
	{
		int code = (int)arr[i];
		if (code >= start && code <= end)
			arr[i] = numb;
	}
}

void MatrixFillingWithSymbols(char (*arr)[6], int row, int col)
{
	srand(time(NULL));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			arr[i][j] = 1 + rand() % 250;
		}
	}
}

void PrintMatrixWithSymbols(char(*arr)[6], int row, int col)
{	
	setlocale(LC_ALL, "Rus");
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%c\t", arr[i][j]);
			int code = (int)arr[i][j];
			if (code == 42 || code == 43 || code == 45)
				sum++;
		}
		printf("\n");
	}
	printf("\n%c, %c или %c встречаютс€ %d раз\n", 42, 43, 45, sum);
}

int TwoToOne(char *arr1, char *arr2, char *arr3, int *length1, int *length2)
{	
	int z = 0;
	for (int i = 0; i < *length1; i++)
	{
		for (int j = 0; j < *length2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				arr3[z] = arr1[i];
				z++;
			}
		}
	}
	return z;
}

void PrintStr(char *arr, int *size)
{
	for (int i = 0; i < *size; i++)
	{
		printf("%c", arr[i]);
	}
	printf("%n");
}