#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * intToRoman(int num);

void main(void) {
	int num;
	char *str;

	scanf("%d", &num);
	str = intToRoman(num);

	puts(str);

	free(str);
}

char * intToRoman(int num) {
	char *str1 = malloc(sizeof(char) * 20);
	int time, remain = num;

	memset(str1, 0, 20);

	time = remain / 1000;
	remain = remain % 1000;
	for (int i = 0; i < time; i++)
		strcat(str1, "M");

	time = remain / 100;
	remain = remain % 100;
	if (time >= 5 ){
		if (time == 9){
			strcat(str1, "CM");
			time -= 9;
		}
		else {
			strcat(str1, "D");
			time -= 5;
		}
	}
	else {
		if (time == 4) {
			strcat(str1, "CD");
			time -= 4;
		}
	}

	for (int i = 0; i < time; i++)
		strcat(str1, "C");

	time = remain / 10;
	remain = remain % 10;
	if (time >= 5) {
		if (time == 9) {
			strcat(str1, "XC");
			time -= 9;
		}
		else {
			strcat(str1, "L");
			time -= 5;
		}
	}
	else {
		if (time == 4) {
			strcat(str1, "XL");
			time -= 4;
		}
	}
	
	for (int i = 0; i < time; i++)
		strcat(str1, "X");

	time = remain;
	if (time >= 5) {
		if (time == 9) {
			strcat(str1, "IX");
			time -= 9;
		}
		else {
			strcat(str1, "V");
			time -= 5;
		}
	}
	else {
		if (time == 4) {
			strcat(str1, "IV");
			time -= 4;
		}
	}

	for (int i = 0; i < time; i++)
		strcat(str1, "I");	

	return str1;
}