#include<stdio.h>
#include<stdlib.h>
void main(){
	printf("FCFS OPERATION\n");
	for(int k=0;k<14;k++){
		printf("%c",'-');
	}printf("\n");
	int n,i;
	printf("Enter the no of processes = ");
scanf("%d",&n);
struct proc{
int pid;
int at;
int bt;
int wt;
float tt;
};
struct proc A[n];
printf("Enter details of each process\n\n");
A[0].at = 0;
for(i=0;i<n;i++){
printf("Enter id = ");
scanf("%d",&A[i].pid);
printf("Enter Burst Time = ");
scanf("%d",&A[i].bt);
printf("\n");
A[i].at = 0;
}
float TTT = 0.0;
float TWT = 0.0;
for(i=0;i<n;i++){
if(i==0){
A[i].wt = 0;
A[i].tt = A[i].bt;
printf("Turnaroud Time of p%d = %3f\n",i,A[i].tt);
printf("Waiting Time of p%d = %d\n",i,A[i].wt);
TTT = TTT + A[i].tt;
printf("\n");
}else{
A[i].tt = A[i-1].tt + A[i].bt;
printf("Turnaround Time of p%d = %3f\n",i,A[i].tt);
A[i].wt = A[i].tt - A[i].bt;
TTT = TTT + A[i].tt;
printf("Waiting Time of p%d = %d\n",i,A[i].wt);
printf("\n");
TWT = TWT + A[i].wt;
}
}
float ATT = TTT/n;
printf("Average Turnaround Time of %d ps = %3f\n",n,ATT);
float AWT = TWT/n;

printf("Average Waiting Time of %d ps = %3f\n",n,AWT);
}
