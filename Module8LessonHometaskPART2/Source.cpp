#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "Header.h"
#include <iostream>
using namespace std;
#define max 50

void main()
{	
	setlocale(LC_ALL, "Rus");
	int task;
	do
	{
		task = TaskNumb();
		cin.get();
		switch (task)
		{
			case 1:
			{
				/*1.	Даны две фамилии.Определить, какая из них длиннее*/
				char lastname1[max], lastname2[max];
				if (!(Surname(lastname1, lastname2)))
					printf("Первое меньше второго\n");
				else
					printf("Первое длиньше второго\n");
			} break;

			case 2:
			{
				//2.	Даны названия трех городов.Вывести на экран самое длинное и самое короткое название.
				char city1[max], city2[max], city3[max];
				int length1, length2, length3;
				ArrFilling(city1, &length1);
				ArrFilling(city2, &length2);
				ArrFilling(city3, &length3);
				int result = WhoIsBigger(&length1, &length2, &length3);
				switch (result)
				{
				case 1: printf("%s - самое длинное слово!!\n", city1); break;
				case 2: printf("%s - самое длинное слово!!\n", city2); break;
				case 3: printf("%s - самое длинное слово!!\n", city3); break;
				case 4: printf("Некоторые из этих слов равны по длине меж собой"); break;
				case 5: printf("Введены неверные символы\n", city1); break;
				}
			} break;

			case 3:
			{
				//3.	Дано слово.Вывести на экран его третий символ
				char word[max];
				int length, numb = 3;
				ArrFilling(word, &length);
				PrintSymbols(word, &length, &numb);
			} break;

			case 4:
			{
				//4.	Введите массив символов из 12 элементов.Замените каждый символ - цифру на символ '!'
				char arr[13] = "Htllo 123 ho";
				ArrChange(arr, 48, 57, 128);
				puts(arr);
			} break;

			case 5:
			{
				//5.	Дана матрица символов размером 2×6.Сколько раз среди данных символов встречаются символы + , -, *.
				char arr[5][6];
				MatrixFillingWithSymbols(&arr[6], 5, 6);
				PrintMatrixWithSymbols(&arr[6], 5, 6);
			} break;

			case 6:
			{
				//6.	Введите массив символов из 15 элементов.Подсчитать количество гласных русских букв.
				char arr[16] = "Привет мой друг";
				puts(arr);
				int length = strlen(arr), sum = 0;
				for (int i = 0; i < length; i++)
				{
					int code = (int)arr[i];
					if (code == 1040 || code == 1045 || code == 1048 || code == 1054 || code == 1059 || code == 1069 || code == 1070 || code == 1071
						|| code == 1025 || code == 1072 || code == 1077 || code == 1080 || code == 1086 || code == 1091 || code == 1101 || code == 1102 || code == 1103)
						sum++;
				}
				printf("Кол-во гласных букв - %d\n", sum);
			} break;

			case 7:
			{
				//7.	Дан массив символов, среди которых есть символ двоеточие ‘ : ’.Определить, сколько символов ему предшествует.
				char arr[] = "Hello my friend: Daniel and Marshal";
				int length = strlen(arr);
				for (int i = 0; i < length; i++)
					if (arr[i] == ':')
						printf("Перед знаком : ещё есть %d знаков\n", i);
			} break;

			case 8:
			{
				//8.	Дан массив символов.Определить, сколько раз входит в него группа букв abc.
				char arr[] = "Hello my friend: Daniel and Marshal";
				int length = strlen(arr), sum = 0;
				for (int i = 0; i < length; i++)
					if (arr[i] == 'a' || arr[i] == 'b' || arr[i] == 'c')
						sum++;
				printf("abc встречается %d раз\n", sum);
			} break;

			case 9:
			{
				//9.	Заданы две строки.Построить новую строку, состоящую из символов, которые входят в первую строку, но не входят во вторую.
				char arr1[max], arr2[max], arr3[max];
				int length1, length2;
				ArrFilling(arr1, &length1);
				ArrFilling(arr2, &length2);
				int length3 = TwoToOne(arr1, arr2, arr3, &length1, &length2);
				PrintStr(arr3, &length3);
			}
		}
	} while (task > 0);
}