#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd = open("41_with_nl", O_RDONLY);
	printf("str: %s\n", get_next_line(fd));
	printf("str: %s\n", get_next_line(fd));
	printf("str: %s\n", get_next_line(fd));
	printf("str: %s\n", get_next_line(fd));
	printf("str: %s\n", get_next_line(fd));
	printf("str: %s\n", get_next_line(fd));
	return 0;
}
