#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
	int data;
	struct stack *next;
}stack;
stack *top, *new;
int element;
void push();
void pop();
void display();
void main(){
	top = NULL;
	int c;
	do{
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Display");
		printf("\n 4. Exit");
		printf("\n Enter you choice :- ");
		scanf("%d", &c);
		
		switch(c){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;	
			default:
				exit(0);
				break;
			
		}
	}while(1);
}
void push(){
	new = (stack*)malloc(sizeof(stack));
	if(new==NULL){
		printf("\n Memory not allocated");
		exit(1);
	}
	printf("\n Enter data to Push in stack :- ");
	scanf("%d", &new->data);
	new->next = top;
	top = new;
}
void pop(){
	stack *temp = top;
	
	if(top == NULL){
		printf("\n Stack Underflow ");
		return;
	}
	else{
		printf("\n Popped element is %d ", top->data);
		top = top->next;
		free(temp);
	}
	
}
void display(){
	stack *temp = top;
	if(top==NULL){
		printf("\n Stack Empty ");
		return;
	}
	else{
		while(temp!=NULL){
			printf("\n Element = %d ", temp->data);
			temp = temp->next;
		}	
	}
	
}
