#include<stdio.h>
int MAXSIZE = 20;
int stack[8];    
int top = -1;

int main()
{
	int a[20],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
 		scanf("%d",&a[i]);
	}	
	quicksort(a,0,n-1,n);
}


int quicksort(int a[],int left, int right,int n)
{
 int i, j, temp,pivot,piv_idx,l,r;
 push(left);
 push(right);
 while(!isempty()){

	right = pop();
	left = pop();
        
 	
	l = left;
	r = right;
	pivot = a[r]; 
        i = (l - 1); 
  
    	for (int j = l; j <= r - 1; j++) { 
        	if (a[j] <= pivot) { 
            	i++; 
		temp=a[i];
        	a[i]=a[j];
        	a[j]=temp;
            	
        	} 
    	} 
	temp=a[i+1];
        a[i+1]=a[r];
        a[r]=temp;
    	 
    
	piv_idx = i+1;
	if(piv_idx-1>1){
		push(l);
		push(piv_idx-1);
	}
	if(piv_idx+1 < r){
		push(piv_idx+1);
		push(r);
	}

   }
  	printf("print sorted list\n");
	for(i=0;i<n;i++)
	{	
		printf("%d\n",a[i]);
	}	

}	

int isempty() {
   
   if(top == -1)
      return 1;
   else
      return 0;
}
   
int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

      top = top + 1;   
      stack[top] = data;
   
}
