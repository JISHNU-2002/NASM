#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>
#define SHMSIZE 100
void main(){
	int shmid,i;int cdtn=0;
	key_t key;char ch,*shm,*s;	
	char rev[50];key=5678;	
	if((shmid=shmget(key,SHMSIZE,IPC_CREAT|0666))<0){	
		perror("shmget error");
		exit(1);
	}	
	if((shm=shmat(shmid,NULL,0))==(char *)-1){	
		perror("shmat error");
		exit(1);	
	}	
	printf("Enter the string \n");
	s=shm;scanf("%s",s);
	int l=0;
	if(fork()==0){
  		char *args[]={"./client",NULL};
        	execv(args[0],args);
        }		
	while(*(s+l)!='\0'){
		rev[l]=*(s+l);
		l++;
	}	
	*(s+l+2)='Z';
	while(*(s+l+2)=='Z');		
	for(int i=0;i<=l;i++){	
		if(*(s+i)!=rev[i]){		
			cdtn=1;
			break;
		}
	}	
	if(cdtn==0){
		printf("The given string is palindrome \n");
	}else{
		printf("The given string is not a palindrome \n");			
		exit(0);	
	}
}
