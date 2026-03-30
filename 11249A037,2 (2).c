#include<stdio.h>
#include<conio.h>
void towers(int,char,char,char);
int main()
{
	int num; 
	printf("enter the number of disks:");
	scanf("%d",&num);
	printf("The sequence of moves involved in towrs of hanoi:");
	towers(num,'A','C','B');
	return 0;
}
void towers(int num, char source, char dst,char spare)
{
	if(num==1)
	{
		printf("\n move the disc 1 source %c to dst %c",source,dst);
		return ;
	}
	towers(num-1,source,spare,dst);
	printf("\n move the disc%d source%c to dst%c",num,source,dst);
	towers(num-1,spare, dst,source);
	getch();
}
