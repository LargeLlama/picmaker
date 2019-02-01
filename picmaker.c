#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

//declare the ints to represent the RGB values
int red;
int green;
int blue;

int main()
{
	//create the file descriptor
	int fd = open("pic.ppm", O_CREAT | O_WRONLY |O_EXCL, 0644);

	//error handling with the file creation
	if (fd < 0)
	{
		printf("Error making file: %s\n", strerror);
		return -1;
	}


	//make the header and write to the file
	char *header = "P3 500 500 255 ";
	write(fd, header, strlen(header));

	//malloc size for the buffer
	char * buff = malloc(20 * sizeof(char));

	//nested for loops for a 500 by 500 image
	for (int i = 0; i < 500; i++)
	{
		for (int n = 0; n < 500; n++)
		{
			//set values for the colors
			red = (i * 20) % 256;
			green = (n * 5) % 256;
			blue = (i * n) % 256;

			//printf("%d %d %d ", n / 2, i / 2, (n + i) / 4); debug
			
			//convert the integers into strings, then write to file
			sprintf(buff, "%d %d %d ", red, green, blue);
			write(fd, buff, strlen(buff));
		}
	}

	//close file, free memory, and return 0 on success
	close(fd);
	free(buff);

	return 0;
}
