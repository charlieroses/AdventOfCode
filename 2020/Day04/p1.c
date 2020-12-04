#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *fp;
	char buf[256];

	fp = fopen("test1.txt", "r");

	while( fscanf(fp, "%s\n\n", buf) != EOF ) {

		printf("%s PASS\n", buf);

	}

	fclose(fp);
}
