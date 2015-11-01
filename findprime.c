#include <stdio.h>
#include <pthread.h>

int  temp=0;
void *prime1(void *args)
{
	int i,j,*cek;
	cek=(int *)args;
	int flag=0;
	for(i=2; i<=*cek; i++)
	{
		for(j=1; j<=i;j++)
		{
			if(i%j==0)
			flag++;
		}
	}
	if(flag==2)
	{
		temp++;
		//return temp;
	}	
}

void main ()
{
	pthread_t t1; 
	int data,loop;
	scanf("%d", &data);
	for(loop=1;loop<data;loop++)
	{
		pthread_create(&t1, NULL, prime1,(void*)&loop);
		pthread_join(t1,NULL);
	}
	printf("%d ", temp);
}

