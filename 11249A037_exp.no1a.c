#include<stdio.h>
int main(){
	int n,i;
	int a = 0, b =1,c;
    printf("enter number of terms:");
	scanf("%d ",&n);
	printf("fibonacci series :\n");
for(i=1;i<=n;i++){
	printf("%d",c);
	c = a+b;
	a=b;
	b=c;
}
return 0;
}


