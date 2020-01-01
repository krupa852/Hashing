#include<stdio.h>
int b[40];
int s=0;
int main()
{
 	int i,j,m,n;
 	int a[10][10];
        //scan m value
        scanf("%d",&m);
	//scan n value
	scanf("%d",&n);
 	for(i=0;i<m;i++)
 		{	
  		for(j=0;j<n;j++)
   			{	
     			   scanf("%d",&a[i][j]);
   			}		
		 }	
 	printf("The input matrix is:\n");
 	for(i=0;i<m;i++)
 		{	
  		for(j=0;j<n;j++)
   			{ 
    			   printf("%d",a[i][j]);
   			}
    		printf("\n");

		}
 
 	matrixlayerstraversal(a,0,m-1,0,n-1,m,n,0);

  	for(i=0;i<m*n;i++)
  		{	
        	  printf("%d\n",b[i]);
 		}
}


int matrixlayerstraversal(int a[10][10],int top,int bottom,int left,int right,int m, int n,int i)
{
  
  int j,k,l,p;
  
  if(i<=m/2 && i<=n/2){
  
        for(j=left;j<=right;j++){
	        b[s++]=a[top][j];}
        for(k=top+1;k<=bottom;k++)
                b[s++]=a[k][right];
        for(l=right-1;l>=left;l--)
                b[s++]=a[bottom][l];
        for(p=bottom-1;p>=top+1;p--)
                b[s++]=a[p][left];
  
        
        matrixlayerstraversal(a,top+1,bottom-1,left+1,right-1,m,n,i+1);
   }
  return 0;
}
