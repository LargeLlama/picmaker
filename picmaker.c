#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int red;
int blue;
int green;

char ** rgb;

int main()
{
	int fd = open("pic.ppm", O_CREAT | O_WRONLY, 0666);
	write(fd, "P3\n500 500\n255\n", 14);

	if (fd < 0)
	{
		printf("Error making file\n");
	}

	for (int i = 0; i < 500; i++)
	{
		for(int n = 0; n < 3; n++)
		{
			if (n == 0)
			{
				red = i % 256;
				green = 0;
				blue = 0;
			}
			else if (n == 1)
			{
				red = 0;
				green = i % 256;
				blue = 0;
			}
			else
			{
				red = 0;
				green = 0;
				blue = i % 256;
			}
		}
	}

	close(fd);
	return 0;
}
