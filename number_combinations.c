#include <stdio.h>
#include <stdlib.h>
int limits(int,int,int *,int *);
void rmatrix (int *,int);
void pmatrix (int *,int);
int search(int *,int,int);
void readonce(int *,int,int,int);
void combination(int *,int,int,int,int,int);
void sort(int *,int);
int control(int *,int,int,int,int,int,int *,int *,int *,int *);
void frequency(int *,int,int *,int,int *,int);

int main(int argc , char **argv)
{   
    int *N,*ptr;
    int n,x1,x2,y1,y2;
	
	N=(int*)malloc(49*sizeof(int));
	
    while(n<=6||n>49)
    {
	printf("How many numbers you want to enter (6<N<=49)? ");
	scanf("%d",&n);
    }
    
	printf("\nEnter numbers (num[1,49]):\n ");
    readonce (N,n,0,50);
    sort(N,n);
	pmatrix (N,n);
	printf("\n_________________________________________________");
	
	printf("\nEnter space [x1,x2] within [0,6]:");
	limits(0,6,&x1,&x2);
	printf("\n[%d,%d]",x1,x2);
	printf("\n_________________________________________________\n");
	
	printf("\nEnter space [y1,y2] within [21,279]:");
	limits(21,279,&y1,&y2);
	printf("\n[%d,%d]",y1,y2);
    printf("\n_________________________________________________\n\n"); 
    
	ptr=(int*)malloc(6*sizeof(int));
	
	combination(N,n,x1,x2,y1,y2);

	return 0;
}

int limits(int l1,int l2,int *x1,int *x2)
{   
	do
	{
	printf("\nEnter first limit: ");
	scanf("%d",x1);
	printf("\nEnter second limit: ");
	scanf("%d",x2);
    }
    while(((*x1<l1||*x1>l2)||(*x2<l1||*x2>l2))||(*x1>*x2));
}

void rmatrix(int *M,int S)
{
	int i,num;
	for(i=0;i<S;i++)
	{
	    scanf("%d",(M+i));
	}
}

void pmatrix(int *M,int S)
{
	int i;
	for(i=0;i<S;i++)
	printf("%2d ",*(M+i));
	printf("\n");
}

int search(int *M,int size,int num)
{
	int i=0;
	while(i<size && *(M+i)!= num)
	    i++;
	if(i==size)
	   return -1;
	return i;
}

void readonce(int *M, int size,int l1,int l2)
{
	int i,num;
	
	for(i=0;i<size;i++)
	{
	
	    do
	    {
		    printf("\nEnter element No %d: ",i+1);
		    scanf("%d",&num);
		    if(num>l1&&num<l2)
	            *(M+i)=num;
	        else
				i--;
	    }
        while(search(M,i,num) != -1);
    } 
}

void combination(int *mat,int N,int x1,int x2,int y1,int y2)
{
	int i,j,k,l,m,n,a,b,x=0,y=0,z=0,w;
	int *ptr,*counters;
	
	ptr=(int*)malloc(6*sizeof(int));
	counters=(int*)calloc(n,sizeof(int));
	
	
	
	    for (i=1;i<=N-5;i++)   
	        for (j=i+1;j<=N-4;j++)   
	            for (k=j+1;k<=N-3;k++)  
                	for (l=k+1;l<=N-2;l++) 
						for (m=l+1;m<=N-1;m++)  
							for(n=m+1;n<=N;n++) 
	       
                	{
					    *ptr=*(mat+(i-1));
					    *(ptr+1)=*(mat+(j-1));
					    *(ptr+2)=*(mat+(k-1));
					    *(ptr+3)=*(mat+(l-1));
					    *(ptr+4)=*(mat+(m-1));
					    *(ptr+5)=*(mat+(n-1));
						control(ptr,6,x1,x2,y1,y2,&x,&y,&z,&w);
						
						if(w==1)
						  frequency(mat,N,ptr,6,counters,N);
						
						a++;
					}
    
	printf("\nCombinations checked: %d",a);
	printf("\nThe combinations that did not meet the first condition: %d",x);
	printf("\nThe combinations that met the first condition but not the second: %d",y);
	printf("\nThe combinations that were finally printed: %d\n\n",z);
	
	for(b=0;b<N;b++)
	   printf("\nNumber %2d has an incidence of: %2d",*(mat+b),*(counters+b));
}

void sort(int *mat,int size)
{
	int i,j,tmp;
	for(i=0;i<size-1;i++)
	   for(j=i+1;j<size;j++)
	   if(*(mat+i) > *(mat+j))
	   {
	       tmp=*(mat+i);
	       *(mat+i)=*(mat+j);
	       *(mat+j)=tmp;
	   }
}

int control(int *mat,int size,int x1,int x2,int y1,int y2,int *a,int *b,int *c,int *d) 
{
	
	int i,j,sum,k=0,l=0,m=0;
	int flag=0;
	
	*d=0;
	
	for(i=0,j=0;i<size;i++)
	if(*(mat+i)%2==0)
	   j++;
	if(j>=x1 && j<=x2)
	   flag=1;
	else k++; 
	
	if(flag==1)
	{
	for(i=0,sum=0;i<size;i++)
	   sum=sum+(*(mat+i));
	if(sum>=y1 && sum<=y2)
	    {
	        pmatrix(mat,size);
	        printf("\n");
	        l++;
	       *d=1;
        }
    else
        m++;
        
    }
    
    *a+=k;
    *b+=m;
    *c+=l;	        
}

void frequency(int *mat1,int size1,int *mat2,int size2,int *counters,int size3)
{
	int i,j,count;
	
    for(i=0,count=0;i<size1;i++,count=0)
	   for(j=0;j<size2;j++) 
	      if(*(mat1+i)==*(mat2+j))
	        {
			    count++;
			   *(counters+i)+=count; 	
		    }
}



