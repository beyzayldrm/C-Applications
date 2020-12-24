/*
This is a program to implement a basic version of Caesar's cipher.
*********************************************************************
* Author        Dept.           Date            Notes
*********************************************************************
* Beyza Y       Mech. Eng.      Feb 19 2020     Initial version.
* Beyza Y       Mech. Eng.      Feb 20 2020     Added error handling.
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

int main(int argc, char *argv[]){
        if(argc != 2){
                printf("Error: usage is caesarcipher <offset>\n");
                return 1;
        }

        char message[1000];
        int chValue;
        int i=0;
        int offset = atoi(argv[1]);
        //fgets(message, sizeof(message), stdin);
	
	if(offset<0){
                offset=26+offset;
        }
        
	//while (message[i] != '\0' && i<strlen(message)-1) {
        
	while(1){
	    	char ch = fgetc(stdin);
		if (ch == EOF){
                break;
        	}	
                int chint = ch;       
                if (chint<97 | chint>123){
                        printf("%c", ch);
                } 
                else{
                        chValue=(ch -'a' + offset) % 26 + 'a';
		        if (chValue>'z'){
                        	int diff = chValue - 97;
                                chValue = 97 + diff;
                                }
                        printf("%c", chValue);
                }
                i++;
        }
        return 0;
}
