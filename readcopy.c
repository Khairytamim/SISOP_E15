#include <stdio.h>
#include <pthread.h>

void *thread1(void *args){
	FILE *in, *out;
	char karakter;
	in=fopen ("contoh.txt", "r");
	out=fopen ("contoh2.txt", "w");
	while ((karakter=fgetc (in))!=EOF)
	{
		(fputc(karakter, out));
	}
	fclose (in);
	fclose (out);	
}
void *thread2(void *args){
	FILE *in, *out;
	char karakter;
	in=fopen ("contoh2.txt", "r");
	out=fopen ("contoh3.txt", "w");
	while ((karakter=fgetc (in))!=EOF)
	{
		(fputc (karakter, out));
	}
	fclose (in);
	fclose (out);
	
}
int main(){
	pthread_t t1, t2;
	pthread_create (&t1, NULL, thread1, NULL);	
	pthread_create (&t2, NULL, thread2, NULL);
	pthread_join (t1,NULL);
	pthread_join (t2, NULL);
}
