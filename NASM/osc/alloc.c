#include <stdio.h>
int nb,nf,j,i,temp,flag,highest;
int frag[10],bu[10],block[10],file[10],bn[10];
void main(){
printf("enter no.of blocks:");
scanf("%d",&nb);

printf("enter no.of files:");
scanf("%d",&nf);

printf("enter block size:");
for(i=0;i<nb;i++){
scanf("%d",&block[i]);
}

printf("enter file size:");
for(i=0;i<nf;i++){
scanf("%d",&file[i]);
}

for(i=0;i<nf;i++){
flag=0;
highest=-1;
	for(j=0;j<nb;j++){
	
		if(bu[j]!=1){
		temp=block[j]-file[i];
		
		if(highest<temp && temp>=0){highest=temp;
		bn[i]=j;
		}}}
	
		frag[bn[i]]=highest;
		bu[bn[i]]=1;
		flag=1;
		
		
	}
	

	
	for(i=0;i<nf;i++){
	printf("%d %d %d\n",i,bn[i],frag[bn[i]]);
	}
}
