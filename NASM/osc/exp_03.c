#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
void main(){
	char ch[50];
	printf("Enter the string : ");
	scanf("%s",ch);
	pid_t pid;
	pid=fork();
	if(pid>=0){
		if(pid==0){
			int i=0,l=0;
			while(ch[i]!='\0'){
				l++;
				i++;
			}
			for(int q=0;q<=(l/2);q++){
				char temp=ch[q];
				ch[q]=ch[l-q-1];
				ch[l-q-1]=temp;
			}
			printf("The reversed word : ");
			puts(ch);
		}else{
		
			wait(NULL);
			printf("child process completed \n");
		}
	}else{
		perror("Error..");
	}
}


