/*
Program to implement a banking application
*********************************************************************
* Author        Dept.           Date            Notes
*********************************************************************
* Beyza Y       Mech. Eng.      Apr 12 2020     Initial version.
* Beyza Y       Mech. Eng.      Apr 13 2020     Added error handling.
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "utils.h"
# include "poly.h"

int main(int argc, char *argv[]){
	int polyline[200];
	char str[50];
	int pointerC;
	int pointerExp;
	int a;
	int b;
	if (argc == 0){
		fprintf(stderr, "Error, please enter a filename!\n");
		exit(1);
		}
	FILE *k = fopen(argv[1], "r");
	if (k == NULL){
		fprintf(stderr, "Error, unable to locate the data file!\n");
		return 1;
	}
        while(!(feof(k))){
                char empty[90];
                fgets(empty, 90, k);
                if(feof(k)) break;
                //parse(empty, &a, &b);
		parse(empty, &pointerC, &pointerExp);
                addPolyTerm(pointerC, pointerExp);
		//addPolyTerm(a,b);
                }
	displayPolynomial();
	int i;
	for(i=-2; i<3; ++i){
		evaluatePolynomial(i);
	}
}

	/*while(fgets(polyline,sizeof(polyLine),b) && !feof(b)){
		parse(str, *pointerX, *pointerExp);
		//addPolyTerm();
		//displayPolynomial();
		//evaluatePolynomial();
		}
	}*/



