#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, const char* argv[])
{
	int ret, fd;
	char buff[1];
	int multifile = 0;

	argc-=1;

	if(argc > 1)
	{
		multifile = 1;
	}
	int file_index = 1;
	while(argc--)
	{
		int line = 0;
		fd = open(argv[file_index], O_RDONLY);
		if(fd < 0)
		{
			perror("File Error");
			return 1;
		}
		if(multifile == 1)
		{
			printf("==> %s <==\n",argv[file_index]);
		}
		do
		{
			ret = read(fd, buff, 1);
			if(ret < 0)
			{
				perror("Read Error");
				return 1;
			}
			write(1, buff, ret);
			if(strcmp(buff,"\n") == 0)
			{
				line++;
			}
		}
		while((line < 10) && (ret > 0));
		file_index++;
	}
	close(fd);
	return 0;
}


