#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns the accumulator upon infinite loop
int runProgram(int opl, int opc[], int opa[]);

int main() {
//	File Loading crap
	FILE *fp;
	char buf[4];
	int val;
//	The parallel arrays for the opcodes (opc) and operands (opa)
	int *opc, *opa;
	int opm, opl, output;

	fp = fopen("input.txt", "r");

	opm = 1;
	opc = malloc(opm * sizeof(int));
	opa = malloc(opm * sizeof(int));

	opl = 0;
//	Load the program into memory
	while( fscanf(fp, "%s %d\n", buf, &val) != EOF ) {

		if(strcmp(buf, "acc") == 0) {
			opc[opl] = 1;
		}
		else if( strcmp(buf, "nop") == 0 ) {
			opc[opl] = 2;
		}
		else if( strcmp(buf, "jmp") == 0 ) {
			opc[opl] = 3;
		}
		else {
			opc[opl] = 0;
		}

		opa[opl] = val;

		opl += 1;
		if( opl == opm ) {
			opm *= 2;
			opc = realloc(opc, opm * sizeof(int));
			opa = realloc(opa, opm * sizeof(int));
		}
	}


//	Run the program babeyYY
	output = runProgram(opl, opc, opa);
	printf("%d\n", output);

//	Housekeeping. Free memory and close stuff
	fclose(fp);
	free(opc);
	free(opa);
}

int runProgram(int opl, int opc[], int opa[]) {
	int i, acc;
	int opv[opl];

	memset(opv, 0, opl*sizeof(int));

	acc = 0;
	i = 0;
	while( i < opl ) {
		if( opv[i] ) {
			return acc;
		}

		opv[i] = 1;

		if( opc[i] == 1 ) {
			acc += opa[i];
			i += 1;
		}
		else if( opc[i] == 2 ) {
			i += 1;
		}
		else if( opc[i] == 3 ) {
			i += opa[i];
		}
		else {
			return -1;
		}
	}

	return acc;
}
