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
	printf("Stepen' shatiya:%d\n\n", d);
	int stepen = 1;
	for (int u = 0; u < d; u++) {
		stepen *= 2;
	}
	int step = 128;
	cip = 0;
	can = 0;
	while (1) {
		c = fgetc(fin);
		if (feof(fin)) break;

			for (int u = 0; u < d; u++) {
				can++;
				cip =cip + step*(c % 2);
				step /= 2;
				c /= 2;
				if(can==8){
					if (cip == 7) goto vihod;
					fputc(cip, fout);
					printf("%c", cip);
					cip = 0;
					step = 128;
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
	int can = 0, cipher[8], end = 0, count = 0;
	c = fgetc(fin); fputc(c, fout);
	c = fgetc(fin); fputc(c, fout);
	unsigned long size = 0;
	fread(&size, 4, 1, fin);
	fwrite(&size, 4, 1, fout);
	printf("Size - %d\n", size);
	count = (size - 56)*d / 8;
	printf("max - %d\n", count);

	for (int i = 0;i < 48;i++) {
		c = fgetc(fin); fputc(c, fout);
	}


	c = fgetc(fin);
	c = c - (c % 8);
	fputc(c+d, fout);
	int	step = 1;
	int outs = 0;
	int returns = 0;
	goto mimo;
//Здесь функция считывания из файла нового символа
get_message:;
	if (returns == 2) { returns = 0; goto next; }
		cip = fgetc(fcip);
		if ((count==0)&&(feof(fcip))) {
			cip = 7;
			returns = 2;
		}
		else { 
		//printf("%c", cip); 
		returns = 1; }
		count--;
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
		can = 0;
		goto next;
//---------------------------------------------------
	mimo:;

	while (1) {
		c = fgetc(fin);
		if (feof(fin)) break;

		
		int stepen = 1;
		for (int u = 0; u < d; u++) {
			stepen *= 2;
		}
		//if (c % stepen == 1) c--;
		//c = c - (c % (stepen));
		c /= stepen;
		c *= stepen;
		step = 1;
		outs = 0;
		for (int u = 0; u < d; u++) {
			if (can %= 8, can == 0) {  goto get_message; }
		next:;
			if (returns == 0) { fputc(c + outs, fout); goto ext; }
			outs += step*cipher[can++];
			step *= 2;
		}
		fputc(c + outs, fout);
	}
ext:;
	while (!feof(fin)) {
		c = fgetc(fin);
		if (feof(fin)) break;
		fputc(c, fout);
	}

	if (!feof(fcip)) printf("Message was been cutted.\n");

	fclose(fin);
	fclose(fcip);
	fclose(fout);
}

int main()
{
	while (1) {
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
		if (y == 1) decoder();
		printf("\n--------------------------------------------------------------------------------\n");
	}
	return 0;
}