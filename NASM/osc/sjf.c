#include<stdio.h>

typedef struct{
	int pid;
	int at;
	int bt;
	int wt;
	int tat;
} Proc;

void main(){
        int n;
	float swt = 0, stat = 0;
	Proc p[10], swap;
	printf("No. of processes         : ");
	scanf("%d", &n);
	printf("pid  ||  arrival time  ||  burst time\n");
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &p[i].pid, &p[i].at, &p[i].bt);
	}
	for (int i = 0 ; i < n - 1; i++){
                for (int j = 0 ; j < n - i - 1; j++){
                        if (p[j].bt > p[j+1].bt){
                                swap = p[j];
                                p[j] = p[j+1];
                                p[j+1] = swap;
                        }
                }
        }
	p[0].tat = p[0].bt;
	stat = p[0].tat;
	for(int i = 1; i < n; i++){
		p[i].wt = p[i - 1].tat;
		p[i].tat = p[i].wt + p[i].bt;
		swt += p[i].wt;
		stat += p[i].tat;
	}
	printf("pid  ||  at  ||  bt  ||  wt  ||  tat\n");
	for(int i = 0; i < n; i++){
	        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
	        
	}
	printf("Average waiting time     : %f\n", swt / n);
	printf("Average turn around time : %f\n", stat / n);
}
