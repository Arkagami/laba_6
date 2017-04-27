#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char s[100];

void decoder()
{
	FILE* fin;
	FILE* fout;
	fin = fopen("Out.bmp", "rb");
	fout = fopen("output.txt", "w");
	unsigned char c = 0, cip = 0;
	int can = 0, cipher[8], d = 0;
	for (int i = 0;i < 55;i++) {
		c = fgetc(fin);
	}
	d = c % 8;
	while (1) {
		cip = 0;
		c = fgetc(fin);
		int ii = 1;
		int step = 1;
	snova:
		for (int i = ii; i <= 8; i++) {
			ii = (i % 8)+1;
			cip += step * (c % 2);
			c /= 2;
			step *= 2;
			if ((i % d == 0)) {
				fputc(cip, fout);
				printf("%c", cip);
				cip = 0;
				c = fgetc(fin);
				if (feof(fin)) break;
				if (cip == '#') goto all;
				step = 1;
			}
		}
		goto snova;
	all:;
	}

	fclose(fin);
	fclose(fout);
}

void coder(int d)
{
	FILE* fin;
	FILE* fcip;
	FILE* fout;
	fin = fopen(s, "rb");
	fcip = fopen("input.txt", "r");
	fout = fopen("Out.bmp", "wb");
	unsigned char c = 0, cip = 0;
	int can = 0, cipher[8], end = 0;
	for (int i = 0;i < 54;i++) {
		c = fgetc(fin); fputc(c, fout);
	}


	c = fgetc(fin);
	c = c - (c % 8);
	fputc(c+d, fout);

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
		int stepen = 1;
		for (int u = 0; u < d; u++) {
			stepen *= 2;
		}
		//if (c % stepen == 1) c--;
		c /= stepen;
		c *= stepen;
		int outs = 0;
		for (int u = 0; u < d; u++) {
			outs += stepen*cipher[can++];
			stepen /= 2;
		}
		c = c + outs;
			fputc(c, fout);
	}

	fclose(fin);
	fclose(fcip);
	fclose(fout);
}

int main()
{
	int y = 0;
	printf("0^1:");
	scanf(" %d", &y);
	if (y == 0) {
		printf("name:");
		scanf(" %s", &s);
		printf("Stepen' shatiya:");
		int d = 1;
		scanf(" %d", &d);
		coder(d);
	}
	if(y==1) decoder();
	return 0;
}