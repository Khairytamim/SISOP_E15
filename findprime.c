#include <stdio.h>
#include <pthread.h>

void *prime1(void *args)
{
	int i ,j,flag=0;
	for(i=0; i<check; i++)
	{
		flag=0;
		for(int j=0; j<i;j++)
		{
			if(i%j==0)
			flag++;
		}
	if(flag==2)
	printf("%d ", check);
			
}

void *prime2(void *args)
{
	int i ,j,flag=0;
	for(i=0; i<check; i++)
	{
		flag=0;
		for(int j=0; j<i;j++)
		{
			if(i%j==0)
			flag++;
		}
	if(flag==2)
	printf("%d ", check);
}

void *prime3(void *args)
{
	int i ,j,flag=0;
	for(i=0; i<check; i++)
	{
		flag=0;
		for(int j=0; j<i;j++)
		{
			if(i%j==0)
			flag++;
		}
	if(flag==2)
	printf("%d ", check);
}

void main ()
{
	pthread_t t1, t2, t3; 
	pthread_create(&t1, NULL, prime1, NULL);
	pthread_create(&t2, NULL, prime2, NULL);
	pthread_create(&t3, NULL, prime3, NULL);

	int inputprime[100];
	
	for(int i =0; i<5; i++)
	{
		scanf("%d", &inputprime[i]);
	}
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
}

