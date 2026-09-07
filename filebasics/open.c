#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>

int main()
{
	int ret, fd, buff[100];
	ret = read(0, buff, 10);
	if(ret < 0)
	{
		perror("Read Error");
		printf("Error No. = %d", errno);
	}

	fd = open("filepath/abc", O_RDWR);
	if(fd < 0)
	{
		perror("File Error");
		printf("Error No. = %d", errno);
	}

	write(fd,buff,10);

	close(fd);
	return 0;
}

