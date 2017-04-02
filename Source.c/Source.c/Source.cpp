#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct bmpheader
{
	unsigned char	b1, b2;			//Символы BM (смение 0, длина 2)
	unsigned long	bfSize;			//Размер файла в байтах	(Смещение 2, длина 4)
	unsigned short	bfReserved1;	        //Бесполезно (Смещение 6, длина 2)
	unsigned short	bfReserved2;	        //Бесполезно (Смещение 8, длина 2)
	unsigned long   bfOffBits;		//Смещение до самого изображения (Смещение 10, длина 4)
};

struct bmpinfoheader
{
	unsigned long	BiSize;
	unsigned long	BiWidth;
	unsigned long	BiHeight;
	unsigned short	BiPlanes;
	unsigned short	BiBitCount;
	unsigned long	BiCompression;
	unsigned long	BiSizeImage;	//Размер изображения
	unsigned long	BiXPelsPerMeter;
	unsigned long	BiYPelsPerMeter;
	unsigned long	BiCirUsed;
	unsigned long	BiCirImportant;
};

int main()
{
	FILE* fin;
	FILE* fout;

	bmpheader hdBMP;
	bmpinfoheader infohdBMP;

	fin = fopen("Mixno.bmp", "rb");
	fout = fopen("Out.bmp", "wb");

	fread(&hdBMP, sizeof(hdBMP), 1, fin);
	fread(&infohdBMP, sizeof(infohdBMP), 1, fin);
	fwrite(&hdBMP, sizeof(hdBMP), 1, fout);
//	fwrite(&infohdBMP, sizeof(infohdBMP), 1, fout);

	printf("%c%c\n", hdBMP.b1, hdBMP.b2);
	printf("%d\n", hdBMP.bfSize);
	printf("%d\n", hdBMP.bfReserved1);
	printf("%d\n", hdBMP.bfReserved2);
	printf("%d\n", hdBMP.bfOffBits);
	printf("%d\n", sizeof(hdBMP));

	fclose(fin);
	fclose(fout);
	return 0;
}