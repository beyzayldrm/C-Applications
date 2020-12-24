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
# include "utils.h"

struct PolyTerm {
        int coeff;
        int expo;
        struct PolyTerm *next;
};

struct PolyTerm *head = NULL;

/*int addPolyTerm(int co, int exp){
	
	struct PolyTerm *addTerm;
	addTerm = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));
	if(addTerm == NULL){
		return -1;
	}
	addTerm->coeff=co;
	addTerm->expo=exp;
	addTerm->next=head;
	head = addTerm;
	return 0;
}*/

int addPolyTerm(int co, int exp){
	
	struct PolyTerm *addTerm;
        addTerm = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));
	//struct PolyTerm *current;
        //current = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));
	struct PolyTerm *p1;
        p1 = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));
	struct PolyTerm *p2;
        p2 = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));

	if(head == NULL) {				//case 1: if the head is empty(no nodes in the list)
        	if(addTerm == NULL){
                	return -1;
			}
        	addTerm->coeff=co;
        	addTerm->expo=exp;
        	addTerm->next=NULL;
        	head = addTerm;
        	return 0;
	}

	p1=head;						//case 3: if head's coefficient is larger(traverse in ll)
	p2=p1->next;
	
	if(exp < (p1->expo)){					// case 2: if head's coefficient is smaller(add before)
		addTerm->coeff=co;
		addTerm->expo=exp;
		addTerm->next=p1;
		head=addTerm;
		return 0;
	}


	while(p2 != NULL){
		if(exp < (p2->expo)){				//3a: if pointer2's expo is larger, add before p2 and after p1
			p1->next=addTerm;
			addTerm->next=p2;
			addTerm->coeff=co;
			addTerm->expo=exp;
			return 0;
		}
		if(exp == (p2->expo)){				//3b: if equal, add coefficient to p2's
			int newcoef;
			newcoef = co + (p2->coeff);
			p2->coeff = newcoef;
			return 0;
		}
	
	p1=p2;
        p2=p1->next;
	}
	
	
	p1->next=addTerm;					//case 4: if no node's coefficient is larger than addTerm,
	addTerm->coeff=co;					//        add the node at the end of ll
        addTerm->expo=exp;
        addTerm->next=NULL;
	return 0;
	
	
}
	
void displayPolynomial(){
	/*
	char addPoly[20];
        strcat(addPoly, coeff);
        strcat(addPoly, "x");
        strcat(addPoly, exp);
        if (coeff > 0){
                strcat(polyLine, "+");
        }
        strcat(polyLine, addPoly);
        return 0;                       */
	struct PolyTerm *current=head;
	int counter=0;
	while(current != NULL){
		if((current->coeff)>-1 && counter!=0){
			printf("+");
			}
		counter=counter+1;
		printf("%d", current->coeff);
		printf("x");
		printf("%d", current->expo);
		current=current->next;
	}
	printf("\n");
}

void evaluatePolynomial(int i){
	/*int i;
	for (i=-2; i<3; ++i){
	do {
	int eval;
	eval = coeff * powi(i, exp);
	} while (temp != NULL)
	fprintf("for x=%d, y=%d \n", i, eval);
	}*/
	struct PolyTerm *current=head;
	int eval=0;
	while(current != NULL){
		eval = eval + ((current->coeff) * powi(i, (current->expo)));
		current=current->next;
	}
		printf("for x=%d, y=%d\n", i, eval);
}

