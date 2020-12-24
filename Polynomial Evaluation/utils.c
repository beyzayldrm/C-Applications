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
//# include "polyapp.h"

void parse(char str[],int *pointerX, int *pointerExp){
	/*FILE *k = fopen(g_argv[1],"r");
	while(!(feof(k))){
		char empty[90];
		fgets(empty, 90, k);
		if(feof(k)) break;*/
		char *token;
		token = strtok(str, " ");
		*pointerX = atoi(token);
		token = strtok(NULL, " ");
		*pointerExp = atoi(token);
		//if ( strcmp(token, " ") == 0 ) {
		//	token = strtok(NULL, " ");
}

int powi(int x, int exp){
	int result = 1;
	while ( exp != 0){
		result = result * x;
		--exp;
	}
	return result;
}
