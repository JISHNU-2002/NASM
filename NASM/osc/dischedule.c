#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 100
void fcfs();
void scan();
void cscan();
int head,n,i,j,a[max],start=0,end=199,stime=0,choice;
void main(){
	printf("DISC SCHEDULING ALGORITHMS\n");
	printf("Enter head = ");
	scanf("%d",&head);
	printf("Enter no of locations = ");
	scanf("%d",&n);
	printf("Enter the locations\n");
	for(i=0;i<n;i++){
		printf("loc%d = ",i);
		scanf("%d",&a[i]);
	}
	printf("select algorithm\n\n1.fcfs\n2.scan\n3.cscan\n\nEnter choice = ");
	scanf("%d",&choice);
	switch(choice){
		case 1 :fcfs();
			break;
		case 2 :scan();
			break;
		case 3 :cscan();
			break;
		default:exit(0);
	}
}
void fcfs(){         
	stime = head-a[0];               
	for(i=0;i<n-1;i++){
		stime = stime + abs(a[i]-a[i+1]);
	}
	printf("Total seektime = %d\n",stime);
}
void scan(){
}
void cscan(){
}
