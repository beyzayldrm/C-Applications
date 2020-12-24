/*
Program to implement a banking application
*********************************************************************
* Author        Dept.           Date            Notes
*********************************************************************
* Beyza Y       Mech. Eng.      Mar 12 2020     Initial version.
* Beyza Y       Mech. Eng.      Mar 13 2020     Added error handling.
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

/*struct Bank_account {
        char Account_records[1];
        int Account_number[3];
        char Account_holder_name[29];
        char Transaction_date[9];
        char Change_in_amount[29];
}*/

void Add_new_account();
void Make_deposit();
void Make_withdrawal();
float Check_balance();
int g_argc;
char **g_argv;
float x;

int main(int argc, char *argv[]){
        g_argc = argc;
    	g_argv = argv;
	if (argc == 0 || argc == 1){ 
        fprintf(stderr, "Error, incorrect usage!\n");
        fprintf(stderr, "-a ACCTNUM NAME\n");
        fprintf(stderr, "-d ACCTNUM DATE AMOUNT\n");
        fprintf(stderr, "-w ACCTNUM DATE AMOUNT\n");
        exit(1);
        }
        
	FILE *m = fopen("bankdata.csv","r");
      		if(m == NULL){
                	fprintf(stderr, "Error, unable to locate the data file bankdata.csv\n");
			return 100;
			}
	fclose(m);
	
	char action = argv[1][1];
	int Acc_no;
	Acc_no=atoi(argv[2]);

        switch(action){
                case 'a': 
			if(argc != 4){
				fprintf(stderr, "Error, incorrect usage!\n");
				fprintf(stderr, "-a ACCTNUM NAME\n");
				exit(1);
			}
			FILE *q = fopen("bankdata.csv","r");
			while(!(feof(q))){
				char empty[90];
				fgets(empty, 90, q);
				if(feof(q)) break;
				char *token;
				token = strtok(empty, ",");
				token = strtok(NULL, ",");
				int Acc_no_temp;
				Acc_no_temp = atoi(token);
					if( Acc_no_temp == Acc_no ){
					fprintf (stderr, "Error, account number %s already exists\n", argv[2]);
					fclose(q);
					exit(50);
					}
				}
			fclose(q);
			Add_new_account();
                      	break;
                case 'd':	
			if(argc != 5){
				fprintf(stderr, "Error, incorrect usage!\n");
				fprintf(stderr, "-d ACCTNUM DATE AMOUNT\n");
				exit(1);
			}
                        FILE *b = fopen("bankdata.csv","r");
                        while(!(feof(b))){
                                char empty[90];
                                fgets(empty, 90, b);
                                if(feof(b)) break;
                                char *token;
                                token = strtok(empty, ",");
                                token = strtok(NULL, ",");
                                int Acc_no_temp;
                                Acc_no_temp = atoi(token);
                                        if( Acc_no_temp == Acc_no ){
                                        fclose(b);
                                        Make_deposit();
                        		exit(0);
                                        }
                                }
			fprintf (stderr, "Error, account number %s does not exists\n", argv[2]);
                        exit(50);
                case 'w': 
			if(argc != 5){
				fprintf(stderr, "Error, incorrect usage!\n");
				fprintf(stderr, "-w ACCTNUM DATE AMOUNT\n");
				exit(1);
			}
			float amount;
        		amount = atof(argv[4]);

			FILE *k = fopen("bankdata.csv","r");
                        while(!(feof(k))){
                                char empty[90];
                                fgets(empty, 90, k);
                                if(feof(k)) break;
                                char *token;
                                token = strtok(empty, ",");
                                token = strtok(NULL, ",");
                                int Acc_no_temp;
                                Acc_no_temp = atoi(token);
                                        if( Acc_no_temp == Acc_no ){
						x = Check_balance();
                                        	if(x > amount){
                        				fclose(k);
							Make_withdrawal();
                        				exit(0);
                        				}
                        			else{
							fclose(k);
                                			fprintf(stderr, "Error, account number %s has only %.2f\n", argv[2], x);
							exit(60);
                                        		}
						fclose(k);
                                	}
                        		
				}
			fprintf (stderr, "Error, account number %s does not exists\n", argv[2]);
                        exit(50);
			/*if(balance > amount){
			Make_withdrawal();
                        break;
			}
			else{
				fprintf(stderr, "Error, account number %s has only %f\n", argv[2], balance);
			}*/
                default: fprintf(stderr, "Error, incorrect usage!\n");
                         fprintf(stderr, "-a ACCTNUM NAME\n");
                         fprintf(stderr, "-d ACCTNUM DATE AMOUNT\n");
                         fprintf(stderr, "-w ACCTNUM DATE AMOUNT\n");
                         exit(1);
        		}
	exit(0);
        }

void Add_new_account(){
        char Acc_rec[10];
        char Acc_no[10];
        char Acc_name[15];
	char Line[50];
   	strcpy(Acc_rec, "AC");
        strcpy(Acc_no, g_argv[2]);
        strcpy(Acc_name, g_argv[3]);
	strcat(Line, "AC");
	strcat(Line, ",");
	strcat(Line, Acc_no);
	strcat(Line, ",");
	strcat(Line, Acc_name);
	strcat(Line, "\n");

        FILE *h = fopen("bankdata.csv", "a");
        if (h != NULL){
                fputs(Line, h);
                fclose(h);
		}
	}
void Make_deposit(){
	char Acc_rec[10];
        char Acc_no[10];
        char Date[15];
	char Amount[30];
        char Line[50];
	strcpy(Acc_rec, "TX");
        strcpy(Acc_no, g_argv[2]);
        strcpy(Date, g_argv[3]);
	strcpy(Amount, g_argv[4]);
        strcat(Line, Acc_rec);
	strcat(Line, ",");
	strcat(Line, Acc_no);
	strcat(Line, ",");
	strcat(Line, Date);
	strcat(Line, ",");
	strcat(Line, Amount);
	strcat(Line, "\n");
	
	FILE *r = fopen("bankdata.csv", "a");
        if (r != NULL){
                fputs(Line, r);
                fclose(r);
                }
}
void Make_withdrawal(){
	char Acc_rec[10];
        char Acc_no[10];
        char Date[15];
        char Amount[30];
        char Line[50];
        strcpy(Acc_rec, "TX");
        strcpy(Acc_no, g_argv[2]);
        strcpy(Date, g_argv[3]);
        strcpy(Amount, g_argv[4]);
	strcat(Line, Acc_rec);
	strcat(Line, ",");
        strcat(Line, Acc_no);
	strcat(Line, ",");
	strcat(Line, Date);
	strcat(Line, ",");
	strcat(Line, "-");
	strcat(Line, Amount);
	strcat(Line, "\n");

	FILE *h = fopen("bankdata.csv", "a");
        if (h != NULL){
                fputs(Line, h);
                fclose(h);
                }
}
float Check_balance(){
	float balance;
	float amount;
	amount = atof(g_argv[4]);
	FILE *k = fopen("bankdata.csv","r");
	while(!(feof(k))){
		char empty[90];
		fgets(empty, 90, k);
		if(feof(k)) break;
		char *token;
		token = strtok(empty, ",");
		if ( strcmp(token, "AC") != 0 ) {
			token = strtok(NULL, ",");
			if(strcmp(token, g_argv[2]) != 0 ) continue;
			token = strtok(NULL, ",");
			token = strtok(NULL, ",");
			float balance_temp;
			balance_temp = atof(token);
			balance = balance + balance_temp;
		}
	}
	return balance;
}
