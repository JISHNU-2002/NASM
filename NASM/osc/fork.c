#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
void main(){
	int a,b;
	printf("Enter a number = ");
	scanf("%d",&a);
	printf("Enter b number = ");
	scanf("%d",&b);
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("Child Process executing\nId of Parent PPID : %d\nPID = %d\n",getppid(),getpid());
		for(int i=1;i<=10;i++){
			printf("%d\n",i);
		}
	}else if(pid>0){
		printf("Parent Process executing\n");
		printf("Parent Process PID = %d\n",getpid());
		for(int j=11;j<=20;j++){
			printf("%d\n",j);
		}
		printf("Waiting for Child Process to complete\n");
		wait(NULL);
		printf("Child process completed\n");
	}else{
		printf("Unable to create child...fork failed\n");
	}
	printf("Sum = %d\n",a+b);
}
