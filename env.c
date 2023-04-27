#include "main.h"

void print_env(void)
{
	pid_t ppid;
	int ppid_fd, file_size, n;
	char *ppid_str, ppid_path[20] = "/proc/";
	struct stat st;
	char buf[1024];

	ppid = getppid();

	ppid_str = _itoa(ppid);
	strcat(ppid_path, ppid_str);
	strcat(ppid_path, "/environ");

	if (stat(ppid_path, &st) == -1)
	{
		perror("Failed stat function");
		exit(1);
	}

	file_size = st.st_size;

	ppid_fd = open(ppid_path, O_RDONLY);
	if (ppid_fd == -1)
	{
		perror("Failed open function.");
		exit(1);
	}

	while ((n = read(ppid_fd, buf, sizeof(buf))) > 0)
	{
		file_size = file_size + n;
		if (write(STDOUT_FILENO, buf, n) != n)
		{
			perror("Failed write function");
			exit(1);
		}
	}

	free(ppid_str);

	if (close(ppid_fd) == -1)
	{
		perror("Failed close function");
		exit(1);
	}
}
