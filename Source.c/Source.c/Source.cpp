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
	int can = 0, cipher[8], end = 0;
	for (int i = 0;i < 54;i++) {
		c = fgetc(fin); fputc(c, fout);
	}
	while (1) {
		c = fgetc(fin);
		if (feof(fin)) break;
		if ((can %= 8, can == 0) && (end == 1)) end=2;
		if(end==0) if (can %= 8, can == 0) {
			cip = fgetc(fcip);
			if (feof(fcip)) {
				cip = '#';
				end = 1;
			}
			for (int i = 7; i >= 0; i--) {
				cipher[i] = cip % 2;
				printf("%d", cipher[i]);
				cip /= 2;
			}
			printf("\n");
		}
		if ((feof(fcip)) && (end == 2)) {
			fputc(c, fout);
			continue;
		}
		c /= 2;
		c *= 2;
		fputc((c+cipher[can++]), fout);
	}

	fclose(fin);
	fclose(fcip);
	fclose(fout);
	return 0;
}