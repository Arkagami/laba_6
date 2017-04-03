#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


char cipher(char c, int i) {
	return 0;
}


int main()
{
	FILE* fin;
	FILE* fcip;
	FILE* fout;
	fin = fopen("Mixno.bmp", "rb");
	fcip = fopen("input.txt", "r");
	fout = fopen("Out.bmp", "wb");
	char c = 0, cip = 0;
	int can = 0;
	for (int i = 0;i < 54;i++) {
		c = fgetc(fin); fputc(c, fout);
	}
	while (1) {
		c = fgetc(fin);
		if(can%=8,can==0) cip = fgetc(fcip);
		can++;
		c = cipher(c, cip / int(pow(2.0, 8.0 - double(can))));
		if (feof(fin)) break;
		if (feof(fcip)) cip = '#';

		fputc(c, fout);
	}

	fclose(fin);
	fclose(fcip);
	fclose(fout);
	return 0;
}