#include<stdio.h>
#include<stdlib.h>
void safety();
void request();
void display();

int n,m,i,j,k,l=0,ind=0;
int al[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,2,2}};
int max[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int avail[3]={3,3,2};
int need[5][3],f[5],ans[5],req[3];;
void main(){
	printf("BANKERS ALGORITHM\n-----------------\n\n");
	int choice=0;
	while(choice<4){
		printf("1.safe sequence\n2.request\n3.display\n\nEnter choice = ");
		scanf("%d",&choice);
		switch(choice){
			case 1 : safety();
				break;
			case 2 : request();
				break;
			case 3 : display();
				break;
			default:exit(0);
		}
	}
}
void safety(){
	for(k=0;k<5;k++){
		f[k]=0;
	}
	for(i=0;i<5;i++){
		for(j=0;j<3;j++){	
			need[i][j]=max[i][j]-al[i][j];
		}
	}
	for(k=0;k<5;k++){
		for(i=0;i<5;i++){
			if(f[i]==0){
				int flag=0;
				for(j=0;j<3;j++){
					if(need[i][j]>avail[j]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					ans[ind++]=i;
					for(l=0;l<3;l++){
						avail[l]=avail[l]+al[i][l];
					}
					f[i]=1;
				}
			}
		}
	}
}
void request(){}
void display(){
	printf("Need Matrix\n");
	for(i=0;i<5;i++){
		for(j=0;j<3;j++){	
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}
	int flag=1;
	for(i=0;i<n;i++){
		if(f[i]==0){
			flag=0;
			printf("System is not safe\n");
			break;
		}
	}
	if(flag==1){
		printf("Safe sequence\n");
		for(i=0;i<n-1;i++){
			printf("p%d-->",ans[i]);
		}
		printf("p%d\n",ans[n-1]);
	}
}
