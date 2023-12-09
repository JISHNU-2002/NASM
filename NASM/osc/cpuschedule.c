#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int at;
	int bt;
	int tat;
	int wt;
	int priority;
}proc;
void main(){
	int n;
	proc p[10];
	printf("Enter the no of process = ");
	scanf("%d",&n);
	printf("Enter Burst time of each process\n");
	for(int i=1;i<=n;i++){
		printf("p%d = ",i);
		scanf("%d",&p[i].bt);
	}
	float ttat=0,twt=0;
	int choice;
	printf("1.FCFS\n2.SJF\n3.ROUND ROBIN\n4.PRIORITY\nEnter choice = ");
	scanf("%d",&choice);
	if(choice==1){
		printf("FCFS\n");
		p[1].wt=0;
		p[1].tat=0;
		for(int i=1;i<=n;i++){
			p[i].tat = p[i-1].tat+p[i].bt;
			p[i].wt = p[i-1].tat;
			printf("TAT of p%d = %d    ||   WT of p%d = %d\n",i,p[i].tat,i,p[i].wt);
			ttat = ttat+p[i].tat;
			twt = twt+p[i].wt;
		}
		float atat=ttat/n,awt=twt/n;
		printf("TTAT = %f || TWT = %f\nATAT = %f   ||   AWT = %f\n",ttat,twt,atat,awt);	
	}else if(choice==2){
		printf("SJF\n");
		for(int q=1;q<=n;q++){
			for(int w=0;w<n-q;w++){
				if(p[w].bt>p[w+1].bt){
					proc temp = p[w];
					p[w]=p[w+1];
					p[w+1]=temp;
				}
			}
		}
		p[1].wt=0;
		p[1].tat=p[1].bt;
		for(int i=1;i<=n;i++){
			p[i].tat = p[i-1].tat+p[i].bt;
			p[i].wt = p[i-1].wt+p[i-1].bt;
			printf("TAT of p%d = %d    ||   WT of p%d = %d\n",i,p[i].tat,i,p[i].wt);
			ttat = ttat+p[i].tat;
			twt = twt+p[i].wt;
		}
		float atat=ttat/n,awt=twt/n;
		printf("TTAT = %f || TWT = %f\nATAT = %f   ||   AWT = %f\n",ttat,twt,atat,awt);
	}else if(choice==3){
		printf("ROUND ROBIN\n");
		int tq;
		printf("Enter time quantum = ");
		scanf("%d",&tq);
	}else if(choice==4){
		printf("PRIORITY\n");
		printf("Enter Priority of each process\n");
		for(int i=1;i<=n;i++){
			printf("p%d = ",i);
			scanf("%d",&p[i].priority);
		}
		for(int q=1;q<=n;q++){
			for(int w=0;w<n-q;w++){
				if(p[w].priority>p[w+1].priority){
					proc temp = p[w];
					p[w]=p[w+1];
					p[w+1]=temp;
				}
			}
		}
		p[1].wt=0;
		p[1].tat=p[1].bt;
		for(int i=1;i<=n;i++){
			p[i].tat = p[i-1].tat+p[i].bt;
			p[i].wt = p[i-1].wt+p[i-1].bt;
			printf("TAT of p%d = %d    ||   WT of p%d = %d\n",i,p[i].tat,i,p[i].wt);
			ttat = ttat+p[i].tat;
			twt = twt+p[i].wt;
		}
		float atat=ttat/n,awt=twt/n;
		printf("TTAT = %f || TWT = %f\nATAT = %f   ||   AWT = %f\n",ttat,twt,atat,awt);
	}else{
		printf("invalid option...\n");
		exit(0);
	}
}
	
		
