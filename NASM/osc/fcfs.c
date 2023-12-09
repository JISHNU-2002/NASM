#include <stdio.h>

typedef struct process{
	int pid;
	int at;
	int bt;
	int wt;
	int tat;
}Proc;

void main(){
	int i,n;float avgtat,avgwt,totalwt=0,totaltat=0;
	printf("enter n");
	scanf("%d",&n);
	Proc p[n];
	p[i].wt=0;p[i].tat=0;
	for( i=0;i<n;i++){
		printf("enter pid,at,bt of %d:",i);
		scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);}
	p[0].wt=0;p[0].tat=p[0].bt;
	for(int i=1;i<n;i++){
		p[i].wt=p[i-1].tat-(p[i].at-p[i-1].at);
		p[i].tat=p[i].wt+p[i].bt;
		totalwt+=p[i].wt;
		totaltat+=p[i].tat;
	}
	avgwt=(totalwt/n);
	avgtat=(totaltat/n);
	printf("avg waiting time%F\n",avgwt);
	printf("avg tat%F\n",avgtat);
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tat);
}}
