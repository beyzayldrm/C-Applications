/*
Program to implement a simple calculator
*********************************************************************
* Author	Dept.		Date		Notes
*********************************************************************
* Beyza Y	Mech. Eng.	Feb 19 2020 	Initial version.
* Beyza Y 	Mech. Eng. 	Feb 20 2020 	Added error handling.
*/
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main(int argc, char *argv[]){
	if (argc != 4){
		puts("Error: usage is simplecalc <x> <op> <y>");
		return 1;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[3]);
	char operand = *argv[2];
	//int o = operand;
	int result = 0;
	switch(operand){
		case '*': 
			printf("%d \n", a*b);
			break;
		case '+':
			printf("%d \n", a+b);
			break;
		case '-':
			printf("%d \n", a-b);
			break;
		case '/':
			printf("%d \n", a/b);
			break;
		default:
			printf("%c not a valid operator\n", operand);
			return 2;
	}
	return 0;
}



