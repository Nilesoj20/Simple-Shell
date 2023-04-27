#include "main.h"

/**
  * _sigint - reprompts
  * @signal: signal passed
  * unused - To avoid compiler warnings
  * fflush - clear buffer
  * STDERR - standard error stream stderr
  * FILENO - file descriptors
  */
void _sigint(int signal __attribute__((unused)))
{
	fflush(STDIN_FILENO);
	write(STDERR_FILENO, "\n$ ", 3);
}
