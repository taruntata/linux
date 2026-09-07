#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<usr/include/linux/fb.h>

int main(int argc, const char *argv[])
{
	int display_file;
	struct fb_var_screeninfo temp;

	display_file = open(argv[1], O_RDONLY);
	if(display_file < 0)
	{
		perror("File open fail");
		exit(1);
	}

	ioctl()
	return 0;
}

