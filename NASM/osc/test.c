#include <stdio.h>

void main(){
int i,j,flag,k,e=0;
int need[5][3];
int ans[5],f[5];
int alloc[5][3] = {{0,1,0},
	          {2,0,0},
	          {3,0,2},
   	          {2,1,1},
	          {0,0,2}};
	          
int max[5][3] =  {{7,5,3},
	          {3,2,2},
	          {9,0,2},
   	          {2,2,2},
	          {4,3,3}};

int avail[3]={3,3,2};	  

        
	          
for(i=0;i<5;i++){
	for(j=0;j<3;j++){
	need[i][j]=max[i][j]-alloc[i][j];
	}

}

for(k=0;k<5;k++){
for(i=0;i<5;i++){
	if(f[i]==0){
	flag=0;
	for(j=0;j<3;j++){
		if(need[i][j]>avail[j]){
		flag=1;
		break;
		}
	if(flag==0){
	for(j=0;j<3;j++){
	avail[j]+=alloc[i][j];
	}
	ans[e]=i;
	f[i]=1;
	e++;
	
	}}	
}

}
}
for(k=0;k<5;k++){
printf("%d ",ans[k]);
}
}
