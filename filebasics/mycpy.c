#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc, const char *argv[])
{
	char buff[100];
	int file_index = 2;
	int copy;
	argc--;
	if(argc == 1)
	{
		printf("No files provided");
		exit(1);
	}
	int source_file = open(argv[1], O_RDONLY);
	if(source_file < 0)
	{
		perror("");
		exit(1);
	}
	while(argc--)
	{
		int dest_file = open(argv[file_index], O_CREAT | /*O_TRUNC |*/ O_WRONLY , 0666);
		do
		{
			copy = read(source_file, buff, 1);
			if(copy < 0)
			{
				perror("");
				exit(1);
			}

			write(dest_file, buff, copy);
		}
		while(copy > 0);
		close(dest_file);
	}
	close(source_file);
	return 0;
}

