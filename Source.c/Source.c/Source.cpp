#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	FILE* fin;
	FILE* fout;

	fin = fopen("Mixno.bmp", "rb");
	fout = fopen("Out.bmp", "wb");
	char c = 0;
	for (int i = 0;i < 54;i++) {
		c = fgetc(fin); fputc(c, fout);
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