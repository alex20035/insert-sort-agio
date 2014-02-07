#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
#include<time.h>
#include "issort.h"

int compare(const void *key1,const void *key2)
{
	int k1,k2;
	k1=*(int *)key1;
	k2=*(int *)key2;
	if(k1==k2)
		return 0;
	else if(k1<k2)
		return -1;
	else 
		return 1;
}
int main()
{
	
	int *data;
	int **sdata;
	int nu,i=0,c=0;
	struct timeval tpstart;
	int *h;
	h=(int *)malloc(5*sizeof(int));
	
	while(i<5){
		data=(int *)malloc(sizeof(int));
		gettimeofday(&tpstart,NULL);
             srand(tpstart.tv_usec);
      	*data =(int)(0.0 + (1000.0 *rand()/(RAND_MAX + 1.0)));
		*(h+i)=*data;	
		printf("add %d\n",*(h+i));
		free(data);
		i++;
	}
	if(issort(h,5,sizeof(int),compare)!=0)
		printf("insert sort agio err!!\n");
	i--;
	while(i>=0){
		printf("data is %d\n",*(h+i));
		i--;
	}
	free(h);
		
		
}

