/*
 * Name : Venkata Tarunananda Tata
 * KM_ID: KM64BEAI16
 * Date : 27-08-2026
 * File_Name : 
 * Sample_Input :
 * Sample_Output :
 *
 */

#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

char buff[100];
pid_t val;

int main()
{
	while(1)
	{
		printf("\r\n$ ");
		scanf("%s",buff);
		val = fork();
		if(val == -1)
		{
			perror("Fork Failed");
			exit(1);

		}
		else if(val == 0)
		{
			system(buff);
			exit(0);
		}
		else
		{
			sleep(1);
			//continue;
		}
	}
	return 0;
}

