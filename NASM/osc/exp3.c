#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void main(){
	char c[20];
	printf("enter a string: ");
	scanf("%s",&c);
	char ch[20];int i,u;
	int l=strlen(c);
	pid_t pid=fork();
	if(pid>=0){
		if(pid==0){
			printf("inside child\n");
			for(i=0;c[i]!='\0';i++){
				ch[i]=c[l-(i+1)];
			}
			ch[i]='\0';
			printf("the reversed string is:   ");
			for(u=0;u<l;u++){
				printf("%c",ch[u]);}
			printf("\nchild terminted\n");
		}
		else{
			printf("\ninside parent");
			wait(NULL);
			printf("\nparent terminated");
		}
	}
	else
	printf("error...no fork done");	
}
