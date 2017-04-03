#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	FILE* fin;
	FILE* fcip;
	FILE* fout;
	fin = fopen("Mixno.bmp", "rb");
	fcip = fopen("input.txt", "r");
	fout = fopen("Out.bmp", "wb");
	unsigned char c = 0, cip = 0;
	int can = 0, cipher[8];
	for (int i = 0;i < 54;i++) {
		c = fgetc(fin); fputc(c, fout);
	}
	while (1) {
		c = fgetc(fin);
		if (feof(fin)) break;
		if (feof(fcip)) {
			cip = '#'; goto suda;
		}
		if (can %= 8, can == 0) {
			cip = fgetc(fcip);
		suda:;
			if(cip == '#') goto tuda;
			for (int i = 7; i >= 0; i--) {
				cipher[i] = cip % 2;
				cip /= 2;
			}
		}
		can++;
		if (feof(fcip)) { 
			fputc(c, fout); 
			continue; 
		}
	tuda:;
		c /= 2;
		c *= 2;
		fputc((c+cipher[8-can]), fout);
	}

	fclose(fin);
	fclose(fcip);
	fclose(fout);
	return 0;
}