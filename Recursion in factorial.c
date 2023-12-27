#include <stdio.h>
int factorial(int n);
void main(){
	int n;
	printf("\n ENter a number to find facotrial :- ");
	scanf("%d", &n);
	printf(" Factorial is = %d ", factorial(n));
}
int factorial(int n){
	int fact=1;
	if(n==1 || n==0){
		return 1;
	}
	else{
		fact = n * factorial(n-1);
		return fact;
	}
}
