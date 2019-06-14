// This is just for testing and isn't turned in for grading.

#include "../../Get_Next_Line/get_next_line.h"
#include <fcntl.h> // open(); // File Control Functions

// Will print all the lines in a file one at a time.
int		main(void)
{
	int fd;
	char *line;

		fd = open("poem.txt", O_RDONLY);
		while (get_next_line(fd, &line) == 1)
			ft_putendl(line);
		close (fd); // delete the file descriptor we're no longer using it.
	
	return (0);
}