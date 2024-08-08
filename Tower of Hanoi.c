#include <stdio.h>


void tower(int n, char a, char c, char b){
	
	if(n==1){
		printf("%c - > %c \n", a, c);
		return;	
	}
	tower(n-1, a, b, c);
	printf("%c - > %c \n", a, c);
	
	tower(n-1, b, c, a);
	return;
}

int main(){
	int n;
	printf("Enter the number of Disks \n");
	scanf("%d", &n);
	
	tower(n, 'A', 'C', 'B');
	return 0;	
}
