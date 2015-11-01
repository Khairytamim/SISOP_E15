#include <stdio.h>
#include <pthread.h>

int  temp=0;
void *prime1(void *args)
{
	int i,j,*cek,flag=0;
	//printf("nilai  = flag %d\n",flag);
	cek=(int *)args;
	for(i=2; i<=*cek; i++)
	{
		flag=0;
		for(j=1; j<=i;j++)
		{
			if(i%j==0)
			flag++;
		}
		//printf("nilai flag %d\n",flag);
		if(flag==2)
		{
			//flag=0;
			temp++;
			//printf("%d tempnya adalah %d\n",*cek,temp);
			//return temp;
		}
	}
}

void main ()
{
	pthread_t t1; 
	int data,loop;
	printf("INPUT LIMIT: ");
	scanf("%d", &data);
	pthread_create(&t1, NULL, prime1,(void*)&data);
	pthread_join(t1,NULL);
	printf("JUMLAH BILANGAN PRIMA SEBELUM %d = %d\n",data, temp);
}

