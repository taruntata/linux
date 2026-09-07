#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, const char *argv[])
{
	//int multifile = 0;
	//argc--;
	unsigned int line = 0;
	int read_file;
	int ret;
	char buff[100];
//	if(argc > 1)
//	{
//		multifile = 1;
//	}
	int file = open(argv[1], O_RDONLY);
	do
	{
		read_file = read(file, buff, 1);
		if(strcmp(buff, "\n") == 0)
		{
			line++;
		}
	}
	while(read_file != 0);
	printf("%d", --line);
	lseek(file, 0, SEEK_SET);
	if(file < 0)
	{
		perror("File Error");
		exit(1);
	}
	if(line < 10)
	{
		do
		{
			ret = read(file, buff, 1);
			if(ret < 0)
			{
				perror("Read Error");
				return 1;
			}
			write(1, buff, ret);
		}
		while(ret > 0);
	}
	else
	{
		int curr_line = 0;
		line -= 10;
		int ret = read(file, buff, 1);
		while(curr_line != line)
		{
			read(file, buff, 1);
			if(strcmp(buff, "\n") == 0)
			{
				curr_line++;
			}
		}
		do
		{
			ret = read(file, buff, 1);
			if(ret < 0)
			{
				perror("Read Error");
				return 1;
			}
			write(1, buff, ret);
		}
		while(ret > 0);
	}
}
