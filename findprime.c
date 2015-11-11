#include <stdio.h>
#include <pthread.h>

int  temp;
void *prime1(void *args)
{
	int i,cek,flag=0;
	cek=*((int *)args);
	for(i=1; i<=cek; i++)
	{
			if(cek%i==0)
			flag++;
	}
	if(flag==2)
	temp++;
}

void main ()
{
	int data,i;
	printf("INPUT LIMIT: ");
	scanf("%d", &data);
	pthread_t t1[data];
	int input[data];
	for(i=2;i<data;i++)
	{
		input[i]=i;
		pthread_create(&t1[i], NULL, prime1,&input[i]);
	}
	for(i=2; i<data; i++)
	pthread_join(t1[i],NULL);

	printf("JUMLAH BILANGAN PRIMA SEBELUM %d = %d\n",data, temp);
}
