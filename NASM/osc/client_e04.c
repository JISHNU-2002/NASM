#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <ctype.h>
#define SHMSIZE 100
void main(){
	int shmid,i;
	key_t key;
	char ch,*shm,*s;
	key=5678;
	if((shmid=shmget(key,SHMSIZE,IPC_CREAT|0666))<0){	
		perror("shmget error  \n");
		exit(1);	
	}	
	if((shm=shmat(shmid,NULL,0))==(char *)-1){	
		perror("shmat error \n");
		exit(1);	}	
	s=shm;int l=0;
	while(*(s+l)!='\0') l++;		
	for(int i=0;i<(l/2);i++){	
		char temp=*(s+i);
		*(s+i)=*(s+l-i-1);
		*(s+l-i-1)=temp;
	}	
	*(s+l+2)='z';	
	printf("The client has reversed the word \n");
	printf("The reversed word is \n");
	puts(s);	

exit(0);
}
