#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	FILE* fin;
	FILE* fout;
	fin = fopen("Out.bmp", "rb");
	fout = fopen("output.txt", "w");
	unsigned char c = 0, cip = 0;
	int can = 0, cipher[8];
	for (int i = 0;i < 54;i++) {
		c = fgetc(fin);
	}
	while (1) {
		cip = 0;
			for (int i = 0; i < 8; i++) {
				c = fgetc(fin);
				cip = (cip * 2) + (c % 2);
			}
			if (feof(fin)) break;
			if (cip == '#') break;
		fputc(cip, fout);
	}
	while (1) {
		c = fgetc(fin);
		if (feof(fin)) break;
		fputc(c, fout);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}