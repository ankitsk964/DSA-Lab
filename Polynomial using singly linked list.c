#include <stdio.h>
#include <stdlib.h>
typedef struct poly{
	int coef;
	int exp;
	struct poly *next;
}pol;
pol *start, *link, *new;
pol *start2, *link2;
pol *start3, *link3;
void create();
void create2();
void display();
void add();
void reset();
void main(){
	int c;
	start=NULL;
	start2 = NULL;
	start3 = NULL;
	do{
		printf("\n 1. Create 1st polynomial equation ");
		printf("\n 2. Create 2st polynomial equation ");
		printf("\n 3. Print polynomial equation ");
		printf("\n 4. Add two polynomial ");
		printf("\n 5. Reset Polynomials ");
		printf("\n 6. Exit ");
		printf("\n Enter your choice :- ");
		scanf("%d", &c);
		
		switch(c){
			case 1:
				create();
				break;
			case 2: 
				create2();
				break;
			case 3:
				display();
				break;
			case 4:
				add();
				break;
			case 5:
				reset();
				break;
			default: 
				exit(0);
				break;
		}
	}while(1);
}
void create(){
	new = NULL;
	char choice = 'y';
	while(choice == 'y' || choice == 'Y'){
		new = (pol*)malloc(sizeof(pol));
		if(new==NULL){
			printf("\n Memory not allocated");
			exit(1);
		}
		printf("\n Enter coefficient in node :- ");
		scanf("%d", &new->coef);
		printf("\n Enter exponential power :- ");
		scanf("%d", &new->exp);
		new->next = NULL;
		
		if(start==NULL){
			start = new;
			link = new;
		}
		else{
			link->next = new;
			link = new;
		}
		printf("\n Do you want to add more term ?");
		printf("\n Enter Y for YES and N for NO :- ");
		scanf(" %c", &choice);
	}
} 
void create2(){
	new = NULL;
	char choice = 'y';
	while(choice == 'y' || choice == 'Y'){
		new = (pol*)malloc(sizeof(pol));
		if(new==NULL){
			printf("\n Memory not allocated");
			exit(1);
		}
		printf("\n Enter coefficient in node :- ");
		scanf("%d", &new->coef);
		printf("\n Enter exponential power :- ");
		scanf("%d", &new->exp);
		new->next = NULL;
		
		if(start2==NULL){
			start2 = new;
			link2 = new;
		}
		else{
			link2->next = new;
			link2 = new;
		}
		printf("\n Do you want to add more term ?");
		printf("\n Enter Y for YES and N for NO :- ");
		scanf(" %c", &choice);
	}
} 

void display(){
	link =start;
	link2 = start2;
	link3 = start3;
	int ch;
	printf("\n Which polynomial equation you want to display :- ");
	scanf("%d", &ch);
	if(ch == 1){
		if(start==NULL){
			printf("\n No polynomial ");
			return;
		}
		while(link!=NULL){
			if(link==start){
				printf(" %dx^%d ", link->coef, link->exp);
			}	
			else{
				printf("+ %dx^%d ", link->coef, link->exp);
			
			}
			link = link->next;
		}
		printf(" = 0");
	}
	
	else if(ch == 2){
		if(start2==NULL){
			printf("\n No polynomial ");
			return;
		}
		while(link2!=NULL){
			if(link2==start2){
				printf(" %dx^%d ", link2->coef, link2->exp);
			}
			else{
				printf("+ %dx^%d ", link2->coef, link2->exp);
			
			}
			link2 = link2->next;
		}
		printf(" = 0");
	}
	else if(ch == 3){
		if(start3==NULL){
			printf("\n No polynomial ");
			return;
		}
		while(link3!=NULL){
			if(link3==start3){
				printf(" %dx^%d ", link3->coef, link3->exp);
			}
			else{
				printf("+ %dx^%d ", link3->coef, link3->exp);
			
			}
			link3 = link3->next;
		}
		printf(" = 0");
	}
	
}
void add(){
	pol *temp = start;
	pol *temp2 = start2;
	
	if(start == NULL && start2 == NULL){
		printf("\n Enter polynomials to add them ");
		return;
	}
	else if(start == NULL){
		printf("\n Enter 1st polynomial to add ");
		return;
	} 
	else if(start2 == NULL){
		printf("\n Enter 2nd polynomial to add ");
		return;
	}
	
	while(temp!=NULL && temp2!=NULL){
		new = (pol*)malloc(sizeof(pol));
		if(new == NULL){
			printf("\n Memory not alllocated");
			exit(1);
		}
		if(temp->exp == temp2->exp){
			
			new->coef = temp->coef + temp2->coef;
			new->exp = temp->exp;
			temp = temp->next;
			temp2 = temp2->next;
			
		}
		else if(temp->exp > temp2->exp){
			
			new->coef = temp->coef;
			new->exp = temp->exp;
			temp = temp->next;
			
		}
		else if(temp->exp < temp2->exp){
			new->coef = temp2->coef;
			new->exp = temp2->exp;
			temp2 = temp2->next;
		}
		new->next = NULL;
		if(start3==NULL){
			start3 = new;
			link3 = new;
		}
		else{
			link3->next = new;
			link3 = new;
		}
	
	}	
}
void reset(){
	pol *temp, *temp2, *temp3;
	link = start;
	link2 = start2;
	link3 = start3;
	int ch;
	printf("\n You want to reset which polynomial ? ");
	printf("\n Enter 1 for 1st polynomial ");
	printf("\n ENter 2 for 2nd polynomial ");
	printf("\n ENter 3 for answer polynomial ");
	scanf("%d", &ch);
	if(ch==1){
		if(start == NULL){
			printf("\n 1st polynomial is already empty ");
			return;
		}
		printf("\n Resetting 1st polynomial ");
		while(link!=NULL){
			temp = link;
			link = link->next;
			free(temp);
		}
		start = NULL;
	}
	else if(ch==2){
		if(start2 == NULL){
			printf("\n 2nd Polynomial is already empty ");
			return;
		}
		printf("\n Resetting 2nd polynomial ");
		while(link2!=NULL){
			temp2 = link2;
			link2 = link2->next;
			free(temp2);
		}
		start2 = NULL;
	}
	else if(ch==3){
		if(start3 == NULL){
			printf("\n 3rd polynomial is already empty ");
			return;
		}
		
		printf("\n Resetting 3rd polynomial ");
		while(link3!=NULL){
			temp3 = link3;
			link3 = link3->next;
			free(temp3);
		}
		start3 = NULL;
	}
	
}
