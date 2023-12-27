#include <stdio.h>
#include <string.h>

void main(){
	int stack[10], top=-1,i,len;
	char str[10];
	printf("\n Enter string :- ");
	scanf("%s", &str);
	len = strlen(str);
	for(i=0;i<len;i++){
		if(str[i] == '('){
			top++;
		}
		else if(str[i] == ')'){
			top--;
		}
	}
	if(top==-1){
		printf("\n Parenthesis Matched ");
	}
	else{
		printf("\n Parenthesis not matched ");
	}
}
