#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


void decoder()
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
		int step = 128;
		for (int i = 0; i < 8; i++) {
			c = fgetc(fin);
			cip += step * (c % 2);
			step /= 2;
		}
		if (feof(fin)) break;
		if (cip == '#') break;
		fputc(cip, fout);
	}

	fclose(fin);
	fclose(fout);
}

void coder()
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
		if ((can %= 8, can == 0) && (end == 1)) end = 2;
		if (end == 0) if (can %= 8, can == 0) {
			cip = fgetc(fcip);
			if (feof(fcip)) {
				cip = '#';
				end = 1;
			}
			int ciphers[8], koli = 0, ii=0;
			while (cip > 0) {
				ciphers[ii] = cip % 2;
				koli++;
				cip = cip / 2;
				ii++;
			}
			for (int i = 0;i<8;i++) {
				cipher[i] = 0;
			}
			for (int i = 0;i < koli;i++) {
				cipher[i+8-koli] = ciphers[koli-1-i];
			}
		}
		if ((feof(fcip)) && (end == 2)) {
			fputc(c, fout);
			continue;
		}
		if (c % 2 == 1) c--;
		fputc((c + cipher[can++]), fout);
	}

	fclose(fin);
	fclose(fcip);
	fclose(fout);
}

int main()
{
	coder();
	decoder();
	return 0;
}