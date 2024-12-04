#include<stdio.h>
#include<stdlib.h>

int buf[10],bufsize,in,out,pro,con,ch;

	int main(){
	
	in=0;
	out=0;
	bufsize=10;

		
		do{
		printf("1.Produce \n 2.Consume \n 3.exit \n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				if((in+1)%bufsize==out){
					printf("Buffer is full \n");
					return 1;
				}
				else{
					printf("Enter the data: ");
					scanf("%d",&pro);
					buf[in]=pro;
					in=((in+1)%bufsize);
					}
				break;
			case 2:
				if(in==out){
					printf("buffer is empty \n");
					}
					else{
					con = buf[out];
					out= ((out+1)%bufsize);
					printf("the consumed value is %d \n",con);
					}
				break;
			case 3:
				printf("Code exited \n");
				break;
			default:
				printf("Invalid choce \n");
				}
				}while(ch!=3);

			return 0;
	}
