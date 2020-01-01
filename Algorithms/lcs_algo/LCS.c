#include<stdio.h>
#include<string.h>
int a[10][10];
char b[20][20];
int main()
{
	char x[10],y[10];	
	int m,n;
	scanf("%s",x);
	scanf("%s",y);
	m=strlen(x);
	n=strlen(y);
	LCSTablecreation(x,y,m,n);
	printLCS(x,m,n);
}

int LCSTablecreation(char x[10], char y[10],int m, int n)
{	
  	int i,j;
	for(i=0;i<=m;i++)
		a[i][0]=0;
	for(i=0;i<=n;i++)
		a[0][i]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
		       
			if(x[i-1]==y[j-1])
			{
				a[i][j]=(a[i-1][j-1])+1;
				b[i][j]='D';
			}
			else if(a[i-1][j]>=a[i][j-1])
			{
				a[i][j]=a[i-1][j];
				b[i][j]='T';
			}
			else
			{
				a[i][j]=a[i][j-1];
				b[i][j]='L';
			}
		//printf("%c ",b[i][j]);
		}
		//printf("\n");
	}
}

int printLCS(char x[10],int i,int j)
{
	
	if(i<0 || j<0)
		return 0;
	if(b[i][j]=='D')
	{	
		printLCS(x,i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if(b[i][j]=='T')
	{
		printLCS(x,i-1,j);
	}
	else
	{
		printLCS(x,i,j-1);
	}
}
	
