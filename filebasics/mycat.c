#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, const char* argv[])
{
	int ret, fd;
	char buff[100];

	argc-=1;

	int file_index = 1;
	while(argc--)
	{
		fd = open(argv[file_index], O_RDONLY);
		if(fd < 0)
		{
			perror("File Error");
			return 1;
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
		}
		while(ret > 0);
		file_index++;
	}
	return 0;
}

