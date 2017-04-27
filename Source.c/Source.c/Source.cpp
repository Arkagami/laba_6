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
	int stepen = 1;
	for (int u = 0; u < d; u++) {
		stepen *= 2;
	}
	int step = 1;
	while (1) {
		cip = 0;
		c = fgetc(fin);
		if (feof(fin)) break;
		char cip = 0;
			
			c = c % stepen;
			int outs = 0;
			for (int u = 0; u < d; u++) {
				can++;
				cip += step*(c % 2);
				step *= 2;
				c /= 2;
				if(can==8){
					if (cip == '#') goto vihod;
					fputc(cip, fout);
					printf("%c", cip);
					cip = 0;
					step = 1;
					can = 0;
				}
			}
			
	}
vihod:;
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
	int	step = 1;
	int outs = 0, news = 0;
	while (1) {
		c = fgetc(fin);
		if (feof(fin)) break;
		if (news != 1) {
			if ((can %= 8, can == 0) && (end == 1)) end = 2;
			if (end == 0) if (can %= 8, can == 0) {
			newq:;
				cip = fgetc(fcip);
				if (feof(fcip)) {
					cip = '#';
					end = 1;
				}
				int ciphers[8], koli = 0, ii = 0;
				while (cip > 0) {
					ciphers[ii] = cip % 2;
					koli++;
					cip = cip / 2;
					ii++;
				}
				for (int i = 0;i < 8;i++) {
					cipher[i] = 0;
				}
				for (int i = 0;i < koli;i++) {
					cipher[i + 8 - koli] = ciphers[koli - 1 - i];
				}
				if (news == 1) { news = 0; goto obratno; }
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
		c = c - (c % stepen);
		step = 1;
		outs = 0;
		for (int u = 0; u < d; u++) {
			outs += step*cipher[can++];
			step *= 2;
			if (can %= 8, (can == 0) && (can < d)) {
				news = 1;
				goto newq;
			}
		obratno:;
		}
		fputc(c + outs, fout);
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