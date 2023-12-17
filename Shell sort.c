#include <stdio.h>

void main(){
	int n,i,shell[10],temp,gap,exchange;
	printf("\n Enter the number of elements :- ");
	scanf("%d", &n);
	
	printf("\n Enter elements in array :- ");
	for(i=0;i<n;i++){
		scanf("%d", &shell[i]);
	}
	do{
		do{
			exchange = 0;
			for(i=0;i<(n-gap);i++){
				if(shell[i] > shell[i+gap]){
					temp = shell[i];
					shell[i] = shell[i+gap];
					shell[i+gap] = temp;
					exchange = 1;
				}
			}
		}while(exchange != 0);
	}while(gap=gap/2);
	printf("\n Sorted array = ");
	for(i=0;i<n;i++){
		printf("\n %d", shell[i]);
	}
}
