#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct bmpheader
{
	unsigned char	b1, b2;			//������� BM (������ 0, ����� 2)
	unsigned long	bfSize;			//������ ����� � ������	(�������� 2, ����� 4)
	unsigned short	bfReserved1;	        //���������� (�������� 6, ����� 2)
	unsigned short	bfReserved2;	        //���������� (�������� 8, ����� 2)
	unsigned long   bfOffBits;		//�������� �� ������ ����������� (�������� 10, ����� 4)
};

struct bmpinfoheader
{
	unsigned long	BiSize;
	unsigned long	BiWidth;
	unsigned long	BiHeight;
	unsigned short	BiPlanes;
	unsigned short	BiBitCount;
	unsigned long	BiCompression;
	unsigned long	BiSizeImage;	//������ �����������
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