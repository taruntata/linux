// Write a program to findout input device name 
// sudo ./a.out /dev/input/event5
#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <linux/input.h>

int main(int argc, char *argv[])
{
	int fd,ret;
	char name[256] = "Unknown";

	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("Open Fails");
		return -1;
	}
        ret = ioctl(fd, EVIOCGNAME(sizeof(name)), name);
	if(ret<0)
	{
		perror("ioctl Fails");
		return -1;
	}
        printf("Input device name: \"%s\"\n", name);

	return 0;
}
		
