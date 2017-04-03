#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int i = 0;
	char *setNames[5], *word;
	word = "namilonhghjgghj";
	setNames[0] = "namilon";
	while (*setNames[i] == *word) {
		printf("%c %c\n", *setNames[i]++,*word++);
		if (*setNames[i] == '\0') printf("%s\n", word);
	}
	return 0;
}