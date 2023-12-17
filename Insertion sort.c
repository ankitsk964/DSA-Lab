#include <stdio.h>

void main(){
	int n,i,j,list[10],temp;
	printf("\n Enter the number of elements :- ");
	scanf("%d", &n);
	printf("\n Enter elements in array :- ");
	for(i=0;i<n;i++){
		scanf("%d", &list[i]);
	}
	for(i=1;i<=n;i++){
		j =i-1;
		temp = list[i];
		while(temp < list[j]){
			list[j+1] = list[j];
			j--;
		}
		list[j+1] = temp;
	}
	printf("\n Sorted array is = ");
	for(i=0;i<n;i++){
		printf("%d", list[i]);
	}
}
