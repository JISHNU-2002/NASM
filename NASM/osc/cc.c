#include <stdio.h>
void main(){
int i,j,k,n,temp;
printf("enter n:");
scanf("%d",&n);

for(i=0;i<n;i++){
		j=0;
		temp=i;
		k=i;
		while(temp>=0){
		printf("%d ",n-(k-temp));
		temp--;
		j++;
		}
		while(j<2*n-1){
		printf("%d ",n-(k-temp-1));
		j++;
		}
		
	printf("\n");
	}
	
	
	
for(i=n-2;i>-1;i--){
		j=0;
		temp=i;
		k=i;
		while(temp>=0){
		printf("%d ",n-(k-temp));
		temp--;
		j++;
		}
		while(j<2*n-1){
		printf("%d ",n-(k-temp-1));
		j++;
		}
		
	printf("\n");	
	

		}
		

	}	
